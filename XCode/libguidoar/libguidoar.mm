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

@end
