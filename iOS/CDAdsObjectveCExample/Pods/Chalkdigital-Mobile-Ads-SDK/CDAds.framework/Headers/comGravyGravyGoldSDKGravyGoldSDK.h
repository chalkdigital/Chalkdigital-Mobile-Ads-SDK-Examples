/**
 * The contents of this file are copyrighted by timeRAZOR, Inc. The contents of
 * this file represents the real and intellectual property of timeRAZOR, Inc.
 * Any source code, configuration parameters, documentation, data or database
 * schema may not be copied, modified, reused or distributed without the written
 * consent of timeRAZOR, Inc.
 *
 *
 * Copyright (c) 2014 Gravy. All rights reserved.
 */

#import <Foundation/Foundation.h>
#import <CoreLocation/CoreLocation.h>
#import <UIKit/UIKit.h>
#import <AvailabilityMacros.h>
#import "comGravyGravyGoldSDKGravyGoldSDKDefines.h"
#import "comGravyGravyGoldSDKGravyConfig.h"




@class GravyGoldTime;
@class GravyAurumUser;
@class GravyAurumDevice;

typedef void (^DataHandler)(NSDictionary *data, NSError *error);

@interface GravyGoldTime : NSObject<NSCoding>

@property (nonatomic, assign) NSInteger hour;
@property (nonatomic, assign) NSInteger minute;

-(instancetype)initWithHour:(NSInteger)hour minute:(NSInteger) minute;

+(instancetype)timeWithHour:(NSInteger)hour minute:(NSInteger) minute;

@end

@interface GravyAurumSDK:NSObject <CLLocationManagerDelegate, UIAlertViewDelegate> {
    int distanceFilterCounter;
}

/**
 Returns the singleton instance of the Gravy GOLD instance.
 */
+(GravyAurumSDK *)sharedInstance;

/**
 * @deprecated v2.0
 * @brief Starts Real Time Location Processing (RTLP).
 * @param searchType    Defines what type of location search to use. Two options are @b kGravyGoldRTLPSearchTypeWithinPolygon, which will return fences the location provided is contained within.
 * And, kGravyGoldRTLPSearchTypeCenterPointDistance, returning fences that have a center point that is less than or equal to a stated distance away from the location.
 * @param searchDistance    This parameter specifies the search distance when looking for fences with a center point within a given range in meters. As the parameter name suggests,
 * the distance is units of meters.
 * @discussion To use the default configuration for RTLP it is possible to pass kGravyGoldRTLPSearchTypeNone.
 * @version 1.0
 * @since 1.3
 */
-(BOOL)startRTLPWithSearchType:(GravyGoldRTLPSearchType)searchType searchDistance:(NSInteger)searchDistance error:(NSError **)error __attribute__((deprecated("Set through GravySDK.config instead")));

/**
 * @deprecated v2.0
 * Convenience start method for RTLP.
 * @discussion This method will start RTLP with the default values.
 * @since 1.3
 */
-(void)startRTLP __attribute__((deprecated("Set through GravySDK.config instead")));

/**
 * @deprecated v2.0
 * @brief Stops Real Time Location Processing.
 */
-(void)stopRTLP __attribute__((deprecated("Set through GravySDK.config instead")));

/**
 * @deprecated v2.0
 * @brief Method to check if Real Time Location Processing has been set to active.
 */
-(BOOL)isRTLPActive;

/**
 * @deprecated v2.0
 * @brief Sets the maximum dwell time variable used to calculate an expiration date for the attendances.
 * @discussion Use this method for supported attendances of over 12 hours. The default value if not provided will be 12 hrs.
 */
-(void)setRTLPMaximumAllowedDwellTime:(NSInteger)maximumAllowedDwellTime __attribute__((deprecated("Set through GravySDK.config instead")));

/**
 * Sends a locations log to the server, using the oldest record as starting point.
 */
- (void)forceSendLocationLogDeleteRecords;

/**
 * Downloads the batches sent from the device to the server and delivers it in a completion handler.
 *
 * @param limit     Max number of locations logs to be retrieved.
 * @param handler   Completion handler where the data will be delivered.
 */
-(void)verifyLocationLogsWithLimit:(int)limit dataHandler:(DataHandler)handler;

/**
 *  Gets saved information about the current user.
 *
 *  @param handler  Completion handler where the data will be delivered.
 */
-(void)verifyUserDataWithDataHandler:(DataHandler)handler;

#pragma mark -
//MARK: Properties.

 @property (nonatomic, readonly) NSTimeInterval locationSendInterval;

/**
 * Flag to enable or disable logging functionality from the SDK.
 */
@property (nonatomic, assign) BOOL loggingEnabled;

/**
 Location Manager
 */
@property (nonatomic, strong,readonly) CLLocationManager *locationManager;

/**
 Background location timer to send location every X minutes
 */
@property (nonatomic, strong) NSTimer *backgroundTimer;

/**
 Desired accuracy property
 */
@property (nonatomic, assign) CLLocationAccuracy desiredAccuracy;

/**
 Get the current location of the device.  Or, last known location.
 @return CLLocation * object with the coordinates.
 */
-(CLLocation *)deviceCurrentLocation;

/**
 *  @brief Sets the @p SleepMode as active with a start time and end time of the sleep mode.
 *  @discussion This will only be used if sleepMode is turned on. if start time and end time are passed as empty or unitialized, they will be set,
 *  by default, to @b 12:00 am and @b 5:00 am respectively.
 *  @attention Start time must be less than end time. If this is requirement is not met, @p sleepMode will be disabled.
 *  @param startTime_ Time to start @p sleepMode, this must be less than the end time. NSNumber object of the hour to start.
 *  @param endTime_ Time to end @p sleepMode, this must be more than the start time. NSNumber object of the hour to end.
 *  @code
 [GravyGoldTime timeWithHour:5 minute:0];
 *  @endcode
 */
-(void) setSleepMode:(BOOL) active_ startTime: (GravyGoldTime *) startTime_ endTime:(GravyGoldTime *) endTime_;

/**
 @method logString
 posts a kGravyLogEvent notification, with "desc" in the userInfo dictionary.
 */
-(void)logString:(NSString *)str_;

//-----------------------------------------------------------------------------
// Location Services
//-----------------------------------------------------------------------------

/**
 * @deprecated v2.0
 *  @brief Disable/Enable location reporting, location services will continue to be enabled but at the lowest accuracy
 *
 *  @param enable boolean to whether enable or disable location reporting.
 */
-(void)shouldEnableLocationReporting:(BOOL)enable;

/**
 *  @deprecated v2.0
 * @brief Disable/Enable location services. Once stopped, it cannot be turned back on in the background
 *
 *  @param enable boolean to whether enable or disable location services.
 */
-(void)shouldEnableLocationServices:(BOOL)enable;

/**
 simulate a change in device location
 @param newLocation
 The CLLocation object with the new location
 */
-(void)simulateLocationUpdate:(CLLocation *)newLocation_;

/**
 * @deprecated v2.0
 *  @brief Manages locationManager:DidUpdateLocations: method when using significant changes.
 *  @param locationManager_ Instance of CLLocationManager being used to monitor locations.
 *  @param locations_ Array of locations gotten by the location manager.
 */
-(void) locationManager:(CLLocationManager *) locationManager_ updatedLocationsWhileMonitoringSignificantChanges:(NSArray *) locations_;

/**
 @deprecated v2.0
 @brief Setup background location tracking, using default values
 */
-(void)startSendingLocationData;

/**
 @deprecated v2.0
 @brief Setup background location tracking with preset:
 @b low - every 30 minutes, nearest 10 meters
 @b medium - every 12 minutes, nearest 10 meters
 @b default - every 12 minutes, best accuracy (within 3 meters)
 @b high - every 5 minutes, best accuracy (within 3 meters)
 @param preset NSString - @"low", @"medium", @"default", @"high"
 */
-(void)startSendingLocationDataWithPreset:(NSString *)preset;

/**
 Setup background location tracking with preset:
 @b low - every 30 minutes, nearest 10 meters
 @b medium - every 12 minutes, nearest 10 meters
 @b default - every 12 minutes, best accuracy (within 3 meters)
 @b high - every 5 minutes, best accuracy (within 3 meters)
 @param preset Constants - GGLocationServicePreset
 */
-(void)startSendingLocationDataWithConstantPreset:(GGLocationServicePreset)preset;

/**
 @deprecated v2.0
 @brief Setup background location tracking with custom values for accuracy and time interval
 @param kCLLocationAccuracy - kCLLocationAccuracy (like kCLLocationAccuracyNearestTenMeters) However, the location returned must be accurate to within 120 meters, or will not be recorded, so a completely low accuracy would not be ideal.  A location distance change of 20 meters will also need to be met for a location to be recorded.
 @param timeInterval - double - Sends location every X. This value is in seconds, so for every 12 minutes you would send a value of 720. Min 1 second, max 30 minutes (1800 seconds).
 */
-(void)startSendingLocationDataWithCustomAccuracy:(CLLocationAccuracy)kCLLocationAccuracy andTimeInterval:(double)timeInterval;

/**
 * @deprecated v2.0
 * @brief Deletes all data from the NSUserDefaults and databases, if any in use.
 */
-(void) resetAllData;

@end
