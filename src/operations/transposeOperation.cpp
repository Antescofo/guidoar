/*

  Copyright (C) 2007  Grame


    This library is free software; you can redistribute it and/or
    modify it under the terms of the GNU Lesser General Public
    License as published by the Free Software Foundation; either
    version 2.1 of the License, or (at your option) any later version.
    
    This library is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
    Lesser General Public License for more details.
    
    You should have received a copy of the GNU Lesser General Public
    License along with this library; if not, write to the Free Software
    Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA

    Grame Research Laboratory, 9, rue du Garet 69001 Lyon - France
    research@grame.fr

*/

#ifdef WIN32
# pragma warning (disable : 4786)
#endif

#include <iostream>
#include <math.h>

#include "ARNote.h"
#include "ARFactory.h"
#include "AROthers.h"
#include "ARTag.h"
#include "clonevisitor.h"
#include "firstpitchvisitor.h"
#include "transposeOperation.h"
#include "tree_browser.h"

using namespace std;

namespace guido 
{

//________________________________________________________________________
// transposeOperation implementation
//________________________________________________________________________
transposeOperation::transposeOperation ()
{
	initialize();
}

transposeOperation::~transposeOperation() {}

//_______________________________________________________________________________
SARMusic transposeOperation::operator() ( const SARMusic& score1, const SARMusic& score2 )
{
	if (!score1 || !score2) return 0;

	firstpitchvisitor fpv;
	int p1 = fpv.firstPitch (score1);
	int p2 = fpv.firstPitch (score2);
	int steps = ((p1 < 0) || (p2 < 0)) ? 0 : p2 - p1;

	Sguidoelement elt = (*this)(score1, steps);
	return dynamic_cast<ARMusic*>((guidoelement*)elt);
}

//_______________________________________________________________________________
Sguidoelement transposeOperation::operator() ( const Sguidoelement& score, int steps )
{
	fCurrentOctaveIn = fCurrentOctaveOut = ARNote::kDefaultOctave;			// default current octave
	fChromaticSteps = steps;
	fOctaveChange = getOctave(fChromaticSteps);
	fTableShift = getKey (getOctaveStep(fChromaticSteps));

	Sguidoelement transposed;
	if (score) {
        guidoScore = score;
		clonevisitor cv;
		transposed = cv.clone(score);
	}
	if (transposed) {
		tree_browser<guidoelement> tb(this);
		tb.browse (*transposed);
	}
	return transposed;
}
    //_______________________________________________________________________________
    Sguidoelement transposeOperation::operator() ( const Sguidoelement& score, int steps, std::vector<int> st )
    {
        fCurrentOctaveIn = fCurrentOctaveOut = ARNote::kDefaultOctave;
        fChromaticSteps = steps;
        fOctaveChange = getOctave(fChromaticSteps);
        fTableShift = getKey (getOctaveStep(fChromaticSteps));
        staves = st;
        
        Sguidoelement transposed;
        if (score) {
            guidoScore = score;
            clonevisitor cv;
            transposed = cv.clone(score);
        }
        if (transposed) {
            tree_browser<guidoelement> tb(this);
            tb.browse (*transposed);
        }
        return transposed;
    }

//________________________________________________________________________
/*
	The cycle of fifth is a special ordering of notes, beginning, say, with a F 
	double flat, and ending with a B double sharp, with an interval of a perfect 
	fifth between each note. This leads to the following list: 
	Fbb, Cbb, Gbb, Dbb, Abb, Ebb, Bbb, Fb, Cb, Gb, Db, Ab, Eb, Bb, F, C, G, D, 
	A, E, B, F#, C#, G#, D#, A#, E#, B#, F##, C##, G##, D##, A##, E##, B##. 
	To apply transposition, we first look in the table for the correct 
	shifting, and apply the same to every note to transpose.
*/
void transposeOperation::initialize ()
{
	fFifthCycle.clear();
	for (int i=-2; i<=2; i++) {
		fFifthCycle.push_back(make_pair('f', i));
		fFifthCycle.push_back(make_pair('c', i));
		fFifthCycle.push_back(make_pair('g', i));
		fFifthCycle.push_back(make_pair('d', i));
		fFifthCycle.push_back(make_pair('a', i));
		fFifthCycle.push_back(make_pair('e', i));
		fFifthCycle.push_back(make_pair('b', i));
	}
    
    lyricsOffset = 0.0;
    staves.clear();
    visitStaff = true;
}

//________________________________________________________________________
// transpose a pitch using the table of fifth cycle
void transposeOperation::transpose ( char& pitch, int& alter, int& octave, int tableshift ) const
{
	// retrieve first the normaized pitch integer class
	int pitch1 = ARNote::NormalizedName2Pitch(pitch);
	// then browse the fifth cycle table
	for (int i=0; i < fFifthCycle.size(); i++) {
		// until we find the same pitch spelling (ie including name and accident)
		if ((fFifthCycle[i].second == alter) && (fFifthCycle[i].first == pitch)) {
			// then we shift into the table
			i += tableshift;
			// make possible adjustments
			if (i > fFifthCycle.size()) i -= 12;
			else if (i < 0) i += 12;
			// and retrieve the resulting transposed pitch
			pitch = fFifthCycle[i].first;
			alter = fFifthCycle[i].second;
			// check now fro octave changes
			int pitch2 = ARNote::NormalizedName2Pitch(pitch);
			// if pitch is lower but transposition is up: then increase octave
			if ((pitch2 < pitch1) && (fChromaticSteps > 0)) octave++;
			// if pitch is higher but transposition is down: then decrease octave
			else if ((pitch2 > pitch1) && (fChromaticSteps < 0)) octave--;

			return;
		}
	}
	cerr << "transpose: pitch out of fifth cycle table (" << pitch << " " << alter << ")" << endl;
}

//________________________________________________________________________
int transposeOperation::transposeKey (int key, Chromatic steps, int& enharmonicChange)
{
	int newkey = key + getKey(steps);
	if (newkey >= 6) {
		newkey -= 12;
		enharmonicChange = 1;
	}
	else if (newkey < -6) {
		newkey += 12;
		enharmonicChange = -1;
	}
	else enharmonicChange = 0;
	return newkey;
}

//________________________________________________________________________
int transposeOperation::getKey (  Chromatic steps ) 
{
	// the method looks for the key signature corresponding to a chromatic degree
	// the key signature is the simplest between flats and sharps alternatives
	// sharps are positive values and flats are negative
	steps = getOctaveStep(steps);		// first converts into a value modulo 12
	if (steps < 0) steps = 12 + steps;	// works only on positive values

	int sharps = 0;
	int curstep = 0;
	while (curstep != steps) {
		curstep += 7;		 	// add a fifth
		curstep %= 12;			// modulus an octave
		sharps++;
	}
	return (sharps >= 6 ? sharps - 12 : sharps);	// simplest key is chosen here
}

//________________________________________________________________________
int transposeOperation::convertKey ( const string& key ) 
{

	if ((key == "C&") || (key == "a&")) return -7;
	if ((key == "C")  || (key == "a"))  return 0;
	if ((key == "C#") || (key == "a#")) return 7;

	if ((key == "D&") || (key == "b&") || (key == "h&")) return -5;
	if ((key == "D")  || (key == "b")  || (key == "h"))  return 2;
	if ((key == "D#") || (key == "b#") || (key == "h#")) return 9;

	if ((key == "E&") || (key == "c"))  return -3;
	if ((key == "E")  || (key == "c#")) return 4;
	if (key == "E#") return 11;	// double  sharp not supported in key sign

	if ((key == "F&") || (key == "d&")) return -8;
	if ((key == "F")  || (key == "d"))  return -1;
	if ((key == "F#") || (key == "d#")) return 6;

	if ((key == "G&") || (key == "e&")) return -6;
	if ((key == "G")  || (key == "e"))  return 1;
	if ((key == "G#") || (key == "e#")) return 8;

	if ((key == "A&") || (key == "f"))  return -4;
	if ((key == "A")  || (key == "f#")) return 3;
	if (key == "A#") return 10;	// double  sharp not supported in key sign

	if ((key == "B&") || (key == "H&") || (key == "g"))  return -2;
	if ((key == "B")  || (key == "H")  || (key == "g#")) return 5;
	if ((key == "B#") || (key == "H#")) return 12;

	return kUndefinedKey;
}

//________________________________________________________________________
// The visit methods
//________________________________________________________________________
void transposeOperation::visitStart ( SARNote& elt ) 
{
    if (visitStaff==false) return;
	if (elt->isRest() || elt->isEmpty()) return;

	int alter;
	char npitch = elt->NormalizedPitchName (&alter);
	alter += elt->GetAccidental();
	int octaveChge = 0;
	transpose ( npitch, alter, octaveChge, fTableShift );
	int octave = elt->GetOctave();
	if (ARNote::implicitOctave (octave)) octave = fCurrentOctaveIn;
	else fCurrentOctaveIn = octave;
	octave += octaveChge + fOctaveChange;

//cerr << string(*elt) << " -> ";
	string npname; 
	npname += npitch;
	elt->setName(npname);
	if ((octave != fCurrentOctaveOut) || !elt->implicitOctave())
		elt->SetOctave(octave);
	fCurrentOctaveOut = octave;
	elt->SetAccidental(alter);
//cerr << string(*elt) << " oct chge: " << fOctaveChange << endl;
}

//________________________________________________________________________
void transposeOperation::visitStart ( SARKey& elt )
{
    if (visitStaff==false) return;

	Sguidoattribute attr = elt->getAttribute(0);
	if (attr) {
		int key = 0;
		
		if (attr->quoteVal()) {		// key is specified as a string
			string val = attr->getValue();
			if (val.substr(0,4) == "free") 
				return;				// don'tknow how to transpose free keys
			key = convertKey (val);
		}
		else  key = int(*attr);
		int enharmonicChange;
		int newkey = transposeKey (key, fChromaticSteps, enharmonicChange);
		attr->setValue (long(newkey));
		attr->setQuoteVal(false);
//cerr << "visit SARKey value " << key << " -> " << newkey << " enharmonic (" << enharmonicChange << ")" << endl;
	}
}

//________________________________________________________________________
void transposeOperation::visitStart ( SARVoice& elt ) {
	fCurrentOctaveIn = fCurrentOctaveOut = ARNote::kDefaultOctave;				// default current octave
	fTableShift = getKey (getOctaveStep(fChromaticSteps));
    
//    /// Remove Fingerings GUID-152
//    ctree<guidoelement>::iterator element = elt->begin();
//    while (element != elt->end()) {
//        if (element->getName() == "fingering") {
//            auto nestedElements = element->elements();
//            //cerr<<"Found Fingering, with size "<<element->size()<<" "<<nestedElements.size()<<" 1st=";
//            //(*(nestedElements.at(0))).print(cerr);
//            element = elt->erase(element);
//            // Now insert nested elements one by one
//            for (auto ne = nestedElements.begin(); ne != nestedElements.end(); ne++) {
//                // TODO: Put back Element to the first inserted branch in case of >1 size
//                element = elt->insert(element, *ne);
//                //cerr<< " ++ ";(*ne)->print(cerr);
//            }
//            //cerr<< " \n\t Element pointer contains: "; (*element)->print(cerr);cerr<<endl;
//        }else {
//            element++;
//        }
//    }
}
    
    //________________________________________________________________________
    void transposeOperation::visitStart ( Sguidotag& elt )
    {
        Sguidoattributes attr = elt->attributes();
        Sguidoattributes::const_iterator iter;
        
        int type = elt->getType();
        
        if (type == kTStaff) {
            
            int thisStaffNum = atoi(attr.at(0)->getValue().c_str());
            
            if (staves.size() ==0)
            {
                visitStaff = true;
            } else
            {
                if (std::find(staves.begin(), staves.end(), thisStaffNum) != staves.end()) {
                    visitStaff = true;
                }else
                {
                    visitStaff = false;
                }
            }
            
        }
        // We no longer use dY attribute of Lyrics as they are adapted automatically using autoPos
        /*else if (type == kTLyrics)   // (type == kTText) ||(
        {
            if (attr.size() == 2) // there's a dy attribute
            {
                double lyricsDy = atof(attr.at(1)->getValue().c_str());
                //cout<<"Lyrics "<< attr.at(0)->getValue()<<" has dY "<<lyricsDy<<endl;
                
                double newLyricsDy = calculateLyricsDy(lyricsDy);
                
                attr.at(1)->setValue(newLyricsDy);
                
            }
        }*/
        if (visitStaff == false) {
            return;
        }
        
        if (type == kTClef)
        {
            int fLowestPitch;                   // Lowest pitch in score
            int fHighestPitch;                  // Highest pitch in score
            float fMedianPitch;                 // Median pitch in score
            
            /// EXPERIMENTAL: Get statistics from this clef to the next clef (or the end if non other)
            firstpitchvisitor fpv;
            fpv.clef2clefStat(guidoScore, elt);
            fHighestPitch = fpv.getLastPitch();
            fMedianPitch = fpv.getMedianPitch();
            fLowestPitch = fpv.getFirstPitch();

            //cout<<"Clef Visitor with lowest pitch "<<fLowestPitch<<", Highest: "<<fHighestPitch<<" median pitch: "<< fMedianPitch << " value:"<<attr.at(0)->getValue() << "  steps:"<< fChromaticSteps <<endl;
            
            /* Rational:
                    For Octave changes, prefer "+8" and "-8" clef changes.
                    Otherwise:
                    Change key if Median pitch is lower than the lowest on-staff pitch for this clef. For example, if clef is "g2" and median is < 60, change clef to "f4".
             */
            
            switch (fChromaticSteps) {
                case 12:
                    if (isGClef(elt))
                    {
                        attr.at(0)->setValue("g+8", true);
                        lyricsOffset = 0.0;
                    }else
                        if (isFClef(elt))
                        {
                            attr.at(0)->setValue("f+8", true);
                            lyricsOffset = 0.0;
                        }
                    return;
                    break;
                    
                case -12:
                    if (isGClef(elt))
                    {
                        attr.at(0)->setValue("g-8", true);
                        lyricsOffset = 0.0;
                    }else
                        if (isFClef(elt))
                        {
                            attr.at(0)->setValue("f-8", true);
                            lyricsOffset = 0.0;
                        }
                    return;
                    break;

                    
                default:
                    // We should now take into account RANGES!
                    break;
            }
            
            /// Taking into account non-octave cases:
            
            /// Case 1 & 2: -12 < fChromaticSteps < 12
            ///     use +8 and -8 if medianPitch bypasses lowest and highest pitch in each clef
            if ( (fChromaticSteps< 12) && (fChromaticSteps>-12))
            {
                if ( isGClef(elt))
                {
                    if ((fMedianPitch + (float)(fChromaticSteps)) < 60.0 )
                        attr.at(0)->setValue("g-8", true);
                    else if ((fMedianPitch + (float)(fChromaticSteps)) > 84.0)
                        attr.at(0)->setValue("g+8", true);
                    
                    lyricsOffset = (double)(fChromaticSteps)/3.0;
                }
                
                if ( isFClef(elt))
                {
                    if ((fMedianPitch + (float)(fChromaticSteps)) > 60.0 )
                        attr.at(0)->setValue("f+8", true);
                    else if ((fMedianPitch + (float)(fChromaticSteps)) < 41.0)
                        attr.at(0)->setValue("f-8", true);
                    lyricsOffset = (double)(fChromaticSteps)/3.0;
                }
            }else
            {
                /// Case 3 & 4: We have more than one-octave transposition
                if (fChromaticSteps>12)
                {
                    if ( isFClef(elt))
                    {
                        if ((fMedianPitch + (float)(fChromaticSteps)) > 60.0 )
                            attr.at(0)->setValue("f+8", true);
                        else if ((fMedianPitch + (float)(fChromaticSteps)) > 82.0)
                            attr.at(0)->setValue("g+8", true);
                        
                        lyricsOffset = (double)(fChromaticSteps%12)/3.0;
                    }else
                        if (isGClef(elt))
                        {
                            if ((fMedianPitch + (float)(fChromaticSteps)) > 82.0 )
                                attr.at(0)->setValue("g+8", true);
                            
                            lyricsOffset = (double)(fChromaticSteps%12)/3.0;
                        }
                }else if (fChromaticSteps<-12)
                {
                    if ( isFClef(elt))
                    {
                        if ((fMedianPitch + (float)(fChromaticSteps)) < 41.0 )
                            attr.at(0)->setValue("f-8", true);
                        
                        lyricsOffset = (double)(fChromaticSteps%12)/3.0;
                    }else
                        if (isGClef(elt))
                        {
                            if ((fMedianPitch + (float)(fChromaticSteps)) < 60.0 )
                                attr.at(0)->setValue("g-8", true);
                            else if ((fMedianPitch + (float)(fChromaticSteps)) < 41.0 )
                                attr.at(0)->setValue("f-8", true);
                            
                            lyricsOffset = (double)(fChromaticSteps%12)/3.0;
                        }
                }
            }
            
        }
        /// GUID-103: Using "stemsAuto" will lead to collisions on multi-voice staves
        /*else if ((type == kTStemsUp) || (type == kTStemsDown))
        {
            elt->setName("stemsAuto");
        }*/
        
        if ( (type == kTCresc) || (type == kTCrescBegin) || (type == kTDim) || (type == kTDimBegin) || (type == kTLyrics)
            || (type == kTIntens) ) {
            // Use Autopos during Transpose Operations
            auto dyAttr = elt->getAttribute("dy");
            if (dyAttr) {
                //cerr<<"GuidoAR: Going to transform ("<< elt->getType()<<") "<< elt->getName()<< " : ";elt->print(cerr);
                dyAttr->setName("autopos");
                dyAttr->setValue("on", true);
                dyAttr->setUnit("");
                //cerr<<" \t -> ";elt->print(cerr);cerr<<endl;
                
            }
        }
        
    }
    
    double transposeOperation::calculateLyricsDy(double dy)
    {
        double maxLyricsDy = -3, minLyricsDy = -13;

        double newLyricsDy = dy + lyricsOffset/1.0;
        
        if (newLyricsDy>maxLyricsDy)
            newLyricsDy = maxLyricsDy;
        if (newLyricsDy<minLyricsDy)
            newLyricsDy = minLyricsDy;
        
        return newLyricsDy;

    }
    
    bool  transposeOperation::isGClef(Sguidotag & elt)
    {
        Sguidoattributes attr = elt->attributes();
        if ((attr.at(0)->getValue()=="g2")||(attr.at(0)->getValue()=="g")||(attr.at(0)->getValue()=="violin"))
            return true;
        else
            return false;
    }
    
    bool  transposeOperation::isFClef(Sguidotag & elt)
    {
        Sguidoattributes attr = elt->attributes();
        if ((attr.at(0)->getValue()=="f4")||(attr.at(0)->getValue()=="f")||(attr.at(0)->getValue()=="bass"))
            return true;
        else
            return false;
    }
}
