//
//  CDGeoInfo.h
//  Glass-Example
//
//  Created by Arun Gupta on 13/07/16.
//  Copyright © 2016 rain. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>

@interface CDGeoInfo : NSObject
@property float lat;
@property float lon;
@property (readonly) NSInteger type;
@property (strong, nonatomic, nonnull) NSString* countryCode;
@property (strong, nonatomic, nonnull) NSString* region;
@property (strong, nonatomic, nonnull) NSString* city;
@property (strong, nonatomic, nonnull) NSString* zip;
@end
