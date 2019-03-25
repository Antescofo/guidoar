//
//  libguidoar.m
//  libguidoar
//
//  Created by Arshia Cont on 09/08/16.
//
//

#import "libguidoar.h"
#include "../../src/interface/libguidoar.h"
#include <iostream>
#include <fstream>
#include <sstream>


@implementation libguidoar

-(NSString *)guidoScoreTranspose:(NSString *)gmn interval:(int)interv
{
    std::ostringstream oss;
    
    const char *gmn_cstyle = [gmn UTF8String];
    
    guido::guidoVTranpose(gmn_cstyle, interv, oss);

    NSString *transposedString = [NSString stringWithCString:oss.str().c_str() encoding:NSUTF8StringEncoding];
    return transposedString;
}

-(NSString *)guidoScoreTranspose:(NSString *)gmn interval:(int)interv onStaff:(NSArray*) staves
{
    int count = [staves count];
    std::vector<int> stavesCArray;
    for (int i = 0; i < count; i++)
    {
        stavesCArray.push_back( [[staves objectAtIndex:i] intValue] );
    }
    
    std::ostringstream oss;
    
    const char *gmn_cstyle = [gmn UTF8String];
    
    guido::guidoVTranposeOnStaff(gmn_cstyle, interv, stavesCArray, oss);
    
    NSString *transposedString = [NSString stringWithCString:oss.str().c_str() encoding:NSUTF8StringEncoding];
    return transposedString;
}

-(NSString *)guidoVTop:(NSString *)gmn nvoices:(int)nvoices
{
    std::ostringstream oss;
    
    const char *gmn_cstyle = [gmn UTF8String];
    
    guido::guidoVTop(gmn_cstyle, nvoices, oss);
    
    NSString *transposedString = [NSString stringWithCString:oss.str().c_str() encoding:NSUTF8StringEncoding];
    return transposedString;
}

-(NSString *)guidoVBottom:(NSString *)gmn nvoices:(int)nvoices
{
    std::ostringstream oss;
    
    const char *gmn_cstyle = [gmn UTF8String];
    
    guido::guidoVBottom(gmn_cstyle, nvoices, oss);
    
    NSString *transposedString = [NSString stringWithCString:oss.str().c_str() encoding:NSUTF8StringEncoding];
    return transposedString;
}

-(NSString *)guidoClefChange:(NSString *)gmn newClef:(NSString *)newClef
{
    std::ostringstream oss;
    
    const char *gmn_cstyle = [gmn UTF8String];
    
    std::string newClefCString = std::string([newClef UTF8String]);
    
    guido::guidoClefChange(gmn_cstyle, newClefCString, oss);
    
    NSString *transposedString = [NSString stringWithCString:oss.str().c_str() encoding:NSUTF8StringEncoding];
    return transposedString;
}

-(NSString *)guidoClefChangeOnStaff:(NSString *)gmn newClef:(NSString *)newClef staff:(NSInteger) staffNum
{
    std::ostringstream oss;
    
    const char *gmn_cstyle = [gmn UTF8String];
    
    std::string newClefCString = std::string([newClef UTF8String]);
    
    guido::guidoClefChangeOnStaff(gmn_cstyle, newClefCString, (int)staffNum, oss);
    
    NSString *transposedString = [NSString stringWithCString:oss.str().c_str() encoding:NSUTF8StringEncoding];
    return transposedString;
}

@end
