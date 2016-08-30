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

/**
 * Handles the simplified registration process and setup of the SDK.
 */
@interface GravyRegistration : NSObject


/**
 * The Gravy Registration ID returned from the server.
 * @since v2.0
 */
@property (nonatomic, readonly) NSString *gravyRegistrationID;

/**
 * The CustomerID linked to the Gravy Registration.
 * @since v2.0
 */
@property (nonatomic, readonly) NSString *customerID;

/**
 * The CustomerTags linked to the Gravy Registration.
 * @since v2.0
 */
@property (nonatomic, readonly) NSString *customerTags;

/**
 * Checks if a registration has already taken place.
 * @since v2.0
 */
+(BOOL)isSDKRegistered;

/**
 * Starts the SDK and registers the instance to the server.
 * @discussion This method performs all necessary setup of the SDK. It registers the SDK instance
 * to the server and starts location services depending on the values provided in the GravyConfig.
 * @since v2.0
 */
+(GravyRegistration *)start;

/**
 * Starts the SDK With CustomerID and CustomerTags (if provided)
 * @discussion This method performs all necessary setup of the SDK. It registers the SDK instance
 * to the server and starts location services depending on the values provided in the GravyConfig.
 *
 * @param customerID    - Unique identifier to be associated with the Gravy Registration, used
 *                      to identify users on client systems
 * @param customerTags  - Generic tag that will be persisted through to output data.
 *                      ex. "id1, id2, id3"  Gravy will not utilize this data but will ensure it
 *                      is passed back to to the consumer with the final output data.
 * @since v2.0
 */
+(GravyRegistration *)startWithCustomerID:(NSString *)customerID customerTags:(NSString *)customerTags;

/**
 * Links a customerID and customerTags to a Gravy Registration.
 * @param customerID    - Unique identifier to be associated with the Gravy Registration, used
 *                      to identify users on client systems
 * @param customerTags  - Generic tag that will be persisted through to output data.
 *                      ex. "id1, id2, id3"  Gravy will not utilize this data but will ensure it
 *                      is passed back to to the consumer with the final output data.
 * @since v2.0
 */
+(void)linkCustomerID:(NSString *)customerID customerTags:(NSString *)customerTags;

/**
 * Removes any stored customerID / customerTag.  Data that is sent to the
 * server after calling Unlink will result in output data that does not
 * contain customerID / customerTag.  Data will still be identifiable using
 * the GravyRegistrationID.
 * @since v2.0
 */
+(void)unlink;

/**
 * Removes Gravy Registration data.
 * @since v2.0
 */
+(void)reset;

/**
 * Removed all Data from SDK.
 * @discussion This will delete all data from the Database and NSUserDefaults.
 * Use with caution.
 * @since v1.2.6
 */
+(void)resetAllData;

@end