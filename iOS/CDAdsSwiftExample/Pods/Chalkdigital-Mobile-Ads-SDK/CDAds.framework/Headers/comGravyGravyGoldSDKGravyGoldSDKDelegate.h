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

@class GravySDKRTPlace;
@class CLLocation;

/**
 @protocol GravyAurumSDKDelegate
 Implement these optional methods in your delegate to be notified of various events triggered from the SDK
 @discussion You can also implement all methods from GravySDKDelegate.
 */
@protocol GravySDKDelegate <NSObject>
@optional
/*!
 * @brief Method to deliver an array of RTPlace objects on attendances.
 * @discussion Invoked when a new attendance is available. This method is required for Real Time Location Processing.
 */
-(void)GravyRTLPOnAttendPlaces:(NSArray <GravySDKRTPlace *>*)places;

/*!
 * @brief Method to deliver an array of RTPlace objects on Exit.
 * @discussion Invoked when a user has exited a POI.
 */
-(void)GravyRTLPOnExitPlaces:(NSArray <GravySDKRTPlace *>*)places;

/*!
 * @brief Delivers an error if there was any during the RTLP process.
 */
-(void)GravyRTLPOnError:(NSError *)error;

/*!
 *  Called to delegate if location services were not accepted by the user or become unavailable. An error object is passed that will contain the CLError constants code, for the developer to decide what action to take.
 *
 *  @param error object thrown by the location manager when an error is encountered.
 */
-(void)locationServicesDidFailWithError:(NSError *)error;

/**
 Called to delegate when the network becomes offline.
 */
-(void)networkNotAvailable;

/**
 Called to delegate whenever the device has moved passed the internal monitoring threshold.
 @param location_
 The CLLocation object with the new location.
 */
-(void)deviceLocationChanged:(CLLocation *)location_;

@end
