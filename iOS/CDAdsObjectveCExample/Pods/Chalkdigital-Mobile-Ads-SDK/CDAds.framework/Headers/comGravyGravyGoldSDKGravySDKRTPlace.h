/**
 * The contents of this file are copyrighted by timeRAZOR, Inc. The contents of
 * this file represents the real and intellectual property of timeRAZOR, Inc.
 * Any source code, configuration parameters, documentation, data or database
 * schema may not be copied, modified, reused or distributed without the written
 * consent of timeRAZOR, Inc.
 *
 *
 * Copyright (c) 2016 Gravy. All rights reserved.
 */

#import <Foundation/Foundation.h>
#import <CoreLocation/CoreLocation.h>

typedef NS_ENUM(NSInteger, GravySDKRTPlaceState){
    kGravySDKRTPlaceStateAttend,
    kGravySDKRTPlaceStateExit,
    kGravySDKRTPlaceStateAttendNotified,
    kGravySDKRTPlaceStateExitNotified
};

/**
 * Object storing the information about fences sent by the server.
 * @since v1.3
 */
@interface GravySDKRTPlace : NSObject
@property (nonatomic, readonly) NSInteger fenceID;
@property (nonatomic, readonly) NSInteger objectID;
@property (nonatomic, readonly) NSString *objectType;
@property (nonatomic, readonly) NSString *objectName;
@property (nonatomic, readonly) NSInteger categoryID;
@property (nonatomic, readonly) NSString *categoryName;
@property (nonatomic, readonly) double eventStartDateTimeMS;
@property (nonatomic, readonly) double eventEndDateTimeMS;
@property (nonatomic, readonly) NSString *timeZone;
@property (nonatomic, readonly) BOOL customerCreatedFence;
@property (nonatomic, readonly) GravySDKRTPlaceState state;
@property (nonatomic, readonly) CLLocationDegrees latitude;
@property (nonatomic, readonly) CLLocationDegrees longitude;
@property (nonatomic, readonly) NSTimeInterval timestamp;

-(instancetype)initWithDictionary:(NSDictionary *)dictionary ;
@end