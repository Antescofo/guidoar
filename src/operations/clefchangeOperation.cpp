//
//  clefchangeOperation.cpp
//  guidoar
//
//  Created by Arshia Cont on 05/10/16.
//
//

#include "clefchangeOperation.hpp"

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

/*****
 Guido clefs are
    - "violin"="g"="g2" with octave variants "g+8" and "g-8"
    - "bass"="f4"="f"   with octave variants
    -  "alto" = Clef Ut de troisième or alto clef
    - "tenor" = Clef Ut de 4ême or tenor clef!
 
 See https://fr.wikipedia.org/wiki/Clef_(musique) and https://en.wikipedia.org/wiki/Clef for naming
 
 ****/

namespace guido
{
    //________________________________________________________________________
    // transposeOperation implementation
    //________________________________________________________________________
    clefchangeOperation::clefchangeOperation ()
    {
        //initialize();
        staffNumToChange = 0;
        visitStaff = true;
    }
    
    clefchangeOperation::~clefchangeOperation() {}

    SARMusic clefchangeOperation::operator() ( const SARMusic& score1, const SARMusic& score2 )
    {
        return 0;
    }

    
    Sguidoelement clefchangeOperation::operator() ( const Sguidoelement& score, std::string clef )
    {
        // Todo: Check if clef is valid!
        newClef = clef;
        
        staffNumToChange = 0;   // zero for all staves
        
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
    
    Sguidoelement clefchangeOperation::operator() ( const Sguidoelement& score, std::string clef, int staffNumber )
    {
        // Todo: Check if clef is valid!
        newClef = clef;
        
        staffNumToChange = staffNumber;
        
        //cout<<"GuidoARLIB: staffNumToChange="<<staffNumToChange<<endl;
        
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

void clefchangeOperation::visitStart(SARVoice& elt) {
    /// Remove Fingerings GUID-152
    ctree<guidoelement>::iterator element = elt->begin();
    while (element != elt->end()) {
        if (element->getName() == "fingering") {
            //cerr<<"Found Fingering, with size "<<element->size();
            auto nestedElements = element->elements();
            element = elt->erase(element);
            // Now insert nested elements one by one
            for (auto ne = nestedElements.begin(); ne != nestedElements.end(); ne++) {
                // TODO: Put back Element to the first inserted branch in case of >1 size
                element = elt->insert(element, *ne);
                //cerr<< " ++ ";(*ne)->print(cerr);
            }
            //cerr<< " \n\t Element pointer contains: "; (*element)->print(cerr);cerr<<endl;
        }else {
            element++;
        }
    }
}

    
    //________________________________________________________________________
    void clefchangeOperation::visitStart ( Sguidotag& elt )
    {
        Sguidoattributes attr = elt->attributes();
        Sguidoattributes::const_iterator iter;
        
        int type = elt->getType();
        
        switch (type) {
            case kTClef:
            {
                if (visitStaff)
                {
                    // Just change!
                    attr.at(0)->setValue(newClef, true);
                }
                break;
            }
                
            case kTStaff:
            {
                if (staffNumToChange != 0)
                {
                    // Check if visiting staff corresponds!
                    if (attr.size())
                    {
                        int thisStaffNum = atoi(attr.at(0)->getValue().c_str());
                        if (thisStaffNum != staffNumToChange)
                        {
                            visitStaff = false;
                        }else
                            visitStaff = true;
                    }
                }
                break;
            }
                
            case kTCrescBegin: case kTCresc: case kTDimBegin: case kTDim: case kTLyrics: case kTIntens:
            {
                // Use Autopos during Transpose Operations
                auto dyAttr = elt->getAttribute("dy");
                if (dyAttr) {
                    dyAttr->setName("autopos");
                    dyAttr->setValue("on", true);
                    dyAttr->setUnit("");
                }
                break;
            }
                
            default:
                break;
        }
        
    }
    
    
    bool  clefchangeOperation::isGClef(Sguidotag & elt)
    {
        Sguidoattributes attr = elt->attributes();
        if ((attr.at(0)->getValue()=="g2")||(attr.at(0)->getValue()=="g")||(attr.at(0)->getValue()=="violin"))
            return true;
        else
            return false;
    }
    
    bool  clefchangeOperation::isFClef(Sguidotag & elt)
    {
        Sguidoattributes attr = elt->attributes();
        if ((attr.at(0)->getValue()=="f4")||(attr.at(0)->getValue()=="f")||(attr.at(0)->getValue()=="bass"))
            return true;
        else
            return false;
    }

}
