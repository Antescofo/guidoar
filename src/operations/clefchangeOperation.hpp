//
//  clefchangeOperation.hpp
//  guidoar
//
//  Created by Arshia Cont on 05/10/16.
//
//

#ifndef clefchangeOperation_hpp
#define clefchangeOperation_hpp

#include <stdio.h>
#include <map>
#include <vector>

#include "arexport.h"
#include "ARTypes.h"
#include "guidoelement.h"
#include "operation.h"
#include "visitor.h"


namespace guido
{
    
    /*!
     \addtogroup operations
     @{
     */
    
    /*!
     \brief A visitor that changes Clef of a given score.
     */
    class gar_export clefchangeOperation :
    public operation,
    //public visitor<SARNote>,
    //public visitor<SARKey>,
    public visitor<SARVoice>,
    public visitor<Sguidotag>
    {
    public:
        enum { kUndefinedKey = -99 };
        
        typedef int	Chromatic;
        typedef int	Diatonic;
        
        clefchangeOperation();
        virtual ~clefchangeOperation();
        
        
        SARMusic operator() ( const SARMusic& score1, const SARMusic& score2 );
        
        /*! Changes a score clef for the entire score!
         \param score the score to transpose
         \param clef string destination
         \return a new score
         */
        Sguidoelement operator() ( const Sguidoelement& score, std::string clef );
        
        /*! Changes a score clef for the given voice
         \param score the score to transpose
         \param clef string destination
         \param voice number (staff number in Guido)
         \return a new score
         */
        Sguidoelement operator() ( const Sguidoelement& score, std::string clef, int staffNumber );
        
        
    protected:
        
        std::string newClef;
        int staffNumToChange;
        bool visitStaff;
        
        //virtual void visitStart ( SARNote& elt );
        //virtual void visitStart ( SARKey& elt );
        virtual void visitStart ( SARVoice& elt );
        virtual void visitStart( Sguidotag& elt );
        
        
        bool  isGClef(Sguidotag & elt);
        bool  isFClef(Sguidotag & elt);
        
        Sguidoelement guidoScore;
        
    };
    
    /*! @} */
    
} // namespace MusicXML




#endif /* clefchangeOperation_hpp */
