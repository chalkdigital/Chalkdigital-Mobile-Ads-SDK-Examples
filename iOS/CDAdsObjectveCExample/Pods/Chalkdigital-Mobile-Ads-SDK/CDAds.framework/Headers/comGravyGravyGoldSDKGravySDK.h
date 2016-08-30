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
#import "comGravyGravyGoldSDKGravyRegistration.h"
#import "comGravyGravyGoldSDKGravyConfig.h"

/**
 The Gravy SDK provides an easy to implement object that enables device tracking and  geo-tracking/tripwires.
 */

@interface GravySDK : NSObject

/**
 * Gravy Registration object in charge of initializing the SDK.
 * @since v2.0
 */
@property (nonatomic, strong) GravyRegistration *gravyRegistration;

/**
 * Gravy Configuration object to setup the SDK based on parameters from the GravyConfig.plist file.
 * @since v2.0
 */
@property (nonatomic, strong, readonly) GravyConfig *config;

/**
 * @brief Singleton instance of Gravy SDK.
 * @discussion This is the main interface of the SDK.
 * @since v2.0
 */
+(GravySDK *)sharedInstance;

/**
 * Starts the SDK and registers the instance to the server.
 * @discussion This method performs all necessary setup of the SDK. It registers the SDK instance
 * to the server and starts location services depending on the values provided in the GravyConfig.
 * @return The singleton instance of the GravySDK
 * @since v2.0
 */
-(GravySDK *)launch;

/**
 * Starts the gravyConfig property with apiKey, serverId and delegate.
 * @param apiKey    API key to access Gravy services.
 * @param serverId  Server ID to access Gravy services.
 * @param delegate  Object to implement methods from  the GravyAurumSDKDelegate protocol
 * @return The singleton instance of the GravySDK
 * @since v2.0
 */
-(GravySDK *)configWithApiKey:(NSString *)apiKey serverId:(NSString *)serverId delegate:(id<GravySDKDelegate>)delegate;

@end