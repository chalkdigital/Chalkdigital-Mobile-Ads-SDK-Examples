//
//  CDInitialisationParams.h
//  Glass-Example
//
//  Created by Arun Gupta on 14/07/16.
//  Copyright © 2016 rain. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

@interface CDInitialisationParams : NSObject
@property (strong, nonatomic, nonnull) NSString *key;
@property (strong, nonatomic, nonnull) NSString *publisherId;
@property (strong, nonatomic, nonnull) NSString *secret;
@property BOOL enableTracking;
@end
