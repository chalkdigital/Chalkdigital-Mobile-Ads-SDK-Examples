//
//  CDAds.h
//  CDAds
//
//  Created by Arun Gupta on 15/07/16.
//  Copyright © 2016 Chalkdigital. All rights reserved.
//

#import "CDAdBannerView.h"
#import "CDAdSize.h"
#import "CDADRequest.h"
#import "CDDeviceInfo.h"
#import "CDInitialisationParams.h"
#import "CDGeoInfo.h"
#import "CDTrackingRequest.h"
#import "CDADSize.h"
#import "CDADController.h"

//! Project version number for CDAds.
FOUNDATION_EXPORT double CDAdsVersionNumber;

//! Project version string for CDAds.
FOUNDATION_EXPORT const unsigned char CDAdsVersionString[];

// In this header, you should import all the public headers of your framework using statements like #import <CDAds/PublicHeader.h>


@interface CDAds : NSObject

@property (readonly) BOOL limitedTrackingEnabled;
@property BOOL continuousTrackingEnabled;
@property (nonatomic) BOOL locationUpdateServicesEnabled;
@property BOOL ipUpdateServiceEnabled;
@property (readonly, strong, nonatomic) CDInitialisationParams *cdInitialisationParams;
+(CDAds*)initialiseWithParams:(CDInitialisationParams*)cdInitialisationParams;
- (void) startMonitoring;
- (void) stopMonitoring;
- (id) init __unavailable;
+ (BOOL) isTrackingEnabled;
+(float)isContinuousTrackingEnabled;
+(BOOL)isIpUpdateServiceEnabled;
+(BOOL)isLocationUpdateServiceEnabled;
+(CDAds*)runningInstance;
-(void)performUpdateWithCompletionHandler:(void  (^)(UIBackgroundFetchResult))completionHandler;
@end
