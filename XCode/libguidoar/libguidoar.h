//
//  libguidoar.h
//  libguidoar
//
//  Created by Arshia Cont on 09/08/16.
//
//

#import <Foundation/Foundation.h>

@interface libguidoar : NSObject

/**
 * Returns a transposed Guido Score using semi-tone interval in interv.
 */
-(NSString *)guidoScoreTranspose:(NSString *)gmn interval:(int)interv;

/**
 * Returns a Guido score preserving n Top Voices
 */
-(NSString *)guidoVTop:(NSString *)gmn nvoices:(int)nvoices;

/**
 * Returns a Guido score preserving n Bottom Voices
 */
-(NSString *)guidoVBottom:(NSString *)gmn nvoices:(int)nvoices;


@end
