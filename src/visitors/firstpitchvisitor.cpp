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
#include "tree_browser.h"

using namespace std;

namespace guido 
{

//______________________________________________________________________________
int	firstpitchvisitor::firstPitch (const Sguidoelement& score) {
	fInChord = fDone = false;
	fPitch = 9999;								// set to a high value since the lowest pitch is collected
    fPitchLast = 0;
	fCurrentOctave = ARNote::kDefaultOctave;	// the default octave
	//browse (*score);
    
    /// Using Tree Browser
    tree_browser<guidoelement> tb(this);
    tb.browse (*score);
    /// EO Using Tree Browser

	return done() ? fPitch : -1;
}
    
    int	firstpitchvisitor::lastPitch (const Sguidoelement& score) {
        fInChord = fDone = false;
        fPitchLast = 0;	// set to a high value since the lowest pitch is collected
        fCurrentOctave = ARNote::kDefaultOctave;	// the default octave
         //browse (*score);
         
         /// Using Tree Browser
         tree_browser<guidoelement> tb(this);
         tb.browse (*score);
         /// EO Using Tree Browser
        return done() ? fPitchLast : -1;
    }
void firstpitchvisitor::visitStart( SARChord& elt )	{ fInChord=true; }
void firstpitchvisitor::visitEnd  ( SARChord& elt )	{ fInChord=false; fDone = true; }

//______________________________________________________________________________
void firstpitchvisitor::visitStart( SARNote& elt )	
{
	int octave = elt->GetOctave();
	if (!ARNote::implicitOctave(octave)) fCurrentOctave = octave;
	
	int midi = elt->midiPitch (fCurrentOctave);
	if (midi >= 0) {
		if (midi < fPitch) fPitch = midi;
        if (midi > fPitchLast) fPitchLast = midi;
		if (!fInChord) fDone = true;
	}

//	int alter; int midi = -1;
//	ARNote::pitch pitch = elt->GetPitch (alter);
//	if (pitch != ARNote::kNoPitch) {
//		// offset in octave numeration between guido and midi is 3
//		int midioctave = (fCurrentOctave + 3) * 12;
//		midi = midioctave + (pitch*2) + alter;
//		if (pitch > ARNote::E) midi--;
//		if (midi < fPitch) fPitch = midi;
//		if (!fInChord) fDone = true;
//	}
}


}
