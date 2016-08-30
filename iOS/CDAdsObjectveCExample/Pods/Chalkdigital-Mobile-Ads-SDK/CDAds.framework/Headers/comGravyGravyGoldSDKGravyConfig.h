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
#import "comGravyGravyGoldSDKGravyGoldSDKDelegate.h"
#import "comGravyGravyGoldSDKGravyGoldSDKDefines.h"

/**
 * Property class to enable developers to specify global states that impact the
 * SDKs behavior.
 */
@interface GravyConfig : NSObject

/**
 * Property to enable or disable Location Services.
 * @discussion If Location Services are stopped, they cannot be re-enabled from the
 * background.
 * @since v2.0
 */
@property (nonatomic, assign) BOOL locationServices;

/**
 * Property to enable or disable Location Reporting.
 * @discussion Location services will continue to be enabled but at the lowest accuracy.
 * @since v2.0
 */
@property (nonatomic, assign) BOOL locationReporting;

/**
 * Property to enable or disable Batch Location Services Framework.
 * @since v2.0
 */
@property (nonatomic, readonly) BOOL batchReporting;

/**
 * Property to enable or disable Real Time Location Processing Framework.
 * @since v2.0
 */
@property (nonatomic, assign) BOOL realTimeProcessing;

/**
 * Property to set the maximum allowed dwell time variable used to calculate an
 * expiration date for the attendances.
 */
@property (nonatomic, assign) NSInteger maximumAllowedDwellTime;

/**
 * Property to define what type of location search to use. There are two options;
 * @b kGravyGoldRTLPSearchTypeWithinPolygon, which will return fences the location
 * provided is contained within. And, @b kGravyGoldRTLPSearchTypeCenterPointDistance,
 * returning fences that have a center point that is less than or equal to a stated
 * distance away from the location.
 */
@property (nonatomic, assign) GravyGoldRTLPSearchType searchType;

/**
 * Property that specifies the search distance when looking for fences with a center
 * point within a given range in meters.
 * @discussion The distance is units of meters.
 */
@property (nonatomic, assign) NSInteger searchDistance;

/**
 * Property to enable or disable use of the platform AdvertisersID.
 * @since v2.0
 */
@property (nonatomic, assign) BOOL enableAdvertiserId;

/**
 * Property to enable or disable Test Mode in the SDK.
 * @since v2.0
 */
@property (nonatomic, assign) BOOL sdkTestMode;

/**
 *  Property to set the type of location awareness support for the background.
 *  @since v2.0
 */
@property (nonatomic, assign) GGSLocationAwarenessSupport locationAwarenessSupport;

/**
 * Property to set the location setting preset to be used
 * @since v2.0
 */
@property (nonatomic, assign) GGLocationServicePreset  locationSettingsPreset;

/**
 * Property to set the environment of the SDK.
 * @since v2.0
 */
@property (nonatomic, readonly) EnvironmentType   environment;

/**
 * Property to get the current version of the Config plist.
 * @since v2.0
 */
@property (nonatomic, readonly) NSInteger configVersion;

/**
 * Property to set the API key, a unique key for each application to access Gravy services.
 * @since v2.0
 */
@property (nonatomic, readonly) NSString *apiKey;

/**
 * Property to set the Server ID to access Gravy services.
 * @since v2.0
 */
@property (nonatomic, readonly) NSString *serverId;

/**
 * Property to set a delegate object to implement methods from  the GravySDKDelegate protocol.
 * @since v2.0
 */
@property (nonatomic, weak) id <GravySDKDelegate> delegate;

/**
 * Handling of the device token obtained from a registration with APNS. This will update
 * the Gravy Registration.
 * @discussion The token needs to be submitted to APN Servers every time a remote push
 * notification is sent to the device.
 *
 * @param token a 32 bytes unique identifier of the device with APNS.
 * @since v2.0
 */
-(void)applicationRegisteredForRemoteNotificationsWithDeviceToken:(NSData *)token;

@end
