/*
  Copyright � Grame 2008

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

#ifndef __tailOperation__
#define __tailOperation__

#include <map>
#include <string>

#include "export.h"
#include "ARTypes.h"
#include "ARTag.h"
#include "guidoelement.h"
#include "clonevisitor.h"
#include "durationvisitor.h"
#include "operation.h"

namespace guido 
{

/*!
\addtogroup operations
@{
*/

/*!
\brief A visitor that cuts the tail of a score.
*/
class export tailOperation : 
	public operation,
	public clonevisitor,
	public visitor<SARStaff>,
	public visitor<SARKey>,
	public visitor<SARMeter>,
	public visitor<SARClef>
{		
    public:
 				 tailOperation();
		virtual ~tailOperation();

		/*! cuts the head of a score before a given duration
			\param score the score to be cut
			\param duration the score duration to drop
			\return a new score
		*/
		Sguidoelement operator() ( const Sguidoelement& score, const rational& duration );

		/*! cuts the head of a score before a given duration
			\param score1 the score to be cut
			\param score2 a score which duration is used as cut point
			\return a new score
		*/
		SARMusic operator() ( const SARMusic& score1, const SARMusic& score2 );
  
     protected:
		enum state  { kSkip, kStartPending, kCopy };
		rational		fStartPoint;
		durationvisitor	fDuration;
		state			fState;
		bool			fHeaderFlushed;
		int				fCurrentOctave;
		rational		fCurrentNoteDuration;
		int				fCurrentNoteDots;
		// current key, meter, clef and staff are maintained to be flushed 
		Sguidotag		fCurrentKey, fCurrentMeter, fCurrentClef, fCurrentStaff;

		virtual void visitStart( SARStaff& elt );
		virtual void visitStart( SARKey& elt );
		virtual void visitStart( SARMeter& elt );
		virtual void visitStart( SARClef& elt );
		virtual void visitStart( SARVoice& elt );
		virtual void visitStart( SARChord& elt );
		virtual void visitStart( SARNote& elt );
		virtual void visitStart( Sguidotag& elt );

		virtual void visitEnd  ( SARVoice& elt );
		virtual void visitEnd  ( SARChord& elt );
		virtual void visitEnd  ( Sguidotag& elt );
		virtual void visitEnd  ( SARNote& elt );

     private:
		std::map<Sguidotag,int> fPendingTagsMap;
		void checkStart ();
		void checkPendingHead ();
		void checkPendingTags ();
		void cloneTag (Sguidotag tag)		{ clonevisitor::visitStart (tag); }
};

/*! @} */

} // namespace MusicXML


#endif
