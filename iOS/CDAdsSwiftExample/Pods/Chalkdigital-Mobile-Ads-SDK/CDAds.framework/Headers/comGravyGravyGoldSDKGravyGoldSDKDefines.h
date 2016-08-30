/*
 * The contents of this file are copyrighted by timeRAZOR, Inc. The contents of
 * this file represents the real and intellectual property of timeRAZOR, Inc.
 * Any source code, configuration parameters, documentation, data or database
 * schema may not be copied, modified, reused or distributed without the written
 * consent of timeRAZOR, Inc.
 *
 *
 * Copyright (c) 2014 Gravy. All rights reserved.
 */

#import <Availability.h>

static NSString *const GGDBNAME = @"BatchLocation.db";
static NSString *const kFirstDateOfBatchKey = @"FirstDateOfBatchKey";

#define REQUEST_DISTANCE_PRIORITY   YES

//MARK: Enumerations and type definitions
//-------------------------------------------------------------
///@name NSNotification constants
//-------------------------------------------------------------

typedef enum {
    GGSNotReachable = 0,
    GGSReachableViaWiFi,
    GGSReachableViaWWAN
} GGSNetworkStatus;

typedef enum : NSInteger {
    BatchRequestStatusNotPublished = 0,
    BatchRequestStatusPublished = 1,
    BatchRequestStatusInProgress = 2
}BatchRequestStatus;

typedef enum : NSInteger {
    GGLocationServicePresetDefault = 0,
    GGLocationServicePresetLow = 1,
    GGLocationServicePresetMedium = 2,
    GGLocationServicePresetHigh = 3
} GGLocationServicePreset;

typedef NS_ENUM(NSInteger, GravySDKRequestType) {
    kGravySDKRequestTypeGET,
    kGravySDKRequestTypePOST,
    kGravySDKRequestTypePUT,
    kGravySDKRequestTypeDELETE,
    kGravySDKRequestTypeHEAD
};

typedef NS_ENUM(NSInteger, GGSLocationAwarenessSupport){
    GGSLocationAwarenessSupportSignificantChanges,
    GGSLocationAwarenessSupportRegionMonitoring,
    GGSLocationAwarenessSupportNone
};

typedef NS_ENUM(NSInteger, EnvironmentType)
{
    kEnvironmentNone = 0,
    kEnvironmentSystest2 = 1,
    kEnvironmentProduction = 2,
    kEnvironmentSandbox = 3
};

typedef NS_ENUM(NSInteger, GravyGoldRTLPSearchType){
    kGravyGoldRTLPSearchTypeNone,
    kGravyGoldRTLPSearchTypeWithinPolygon,
    kGravyGoldRTLPSearchTypeCenterPointDistance
};

typedef NS_ENUM(NSInteger, GravyRegistrationTime)
{
    GravyRegistrationTimeFiveMinutes       =          60*5,
    GravyRegistrationTimeTenMinutes        =          60*10,
    GravyRegistrationTimeFifteenMinutes    =          60*15,
    GravyRegistrationTimeFiveHours         =          60*60*5,
    GravyRegistrationTimeTwelveHours       =          60*60*12,
    GravyRegistrationTimeTwentyFourHours   =          60*60*24,
    GravyRegistrationTimeNone              =          0

};


#define kLocationRecordVersion @1
#define kLocationLogVersion @2
#define kLocationRTLPVersion @2

//-------------------------------------------------------------
///@name NSNotification constants
//-------------------------------------------------------------
static NSString * const kGravyRegistrationReset = @"kGravyRegistrationReset";
static NSString * const kGravyRegistrationSuccess = @"kGravyRegistrationSuccess";
static NSString * const kGravyLocationServicesStatusChanged = @"kGravyLocationServicesStatusChanged";
static NSString * const kGravyLocationReportingStatusChanged = @"kGravyLocationReportingStatusChanged";
static NSString * const kGravyLocationLogSentSuccessful = @"kGravyLocationLogSentSuccessful";

static NSString * const kGravyLogStatus = @"kGravyLogStatus";

//-------------------------------------------------------------
///@name Time calculation macros
//-------------------------------------------------------------
#define SEC_IN_DAY 86400
#define ONE_HOUR (60 * 60 * 1)
#define FIVE_MINUTES (60 * 5)
#define ONE_MINUTE (60)
#define ONE_HOUR (60 * 60 * 1)
#define ONE_SECOND (1)
#define ONE_DAY (60 * 60 * 24)
#define SEVEN_DAY (60 * 60 * 24 * 7)
#define HighAccuracyTimeThreshold (60 * 30) //30 minutes, change here if you want it changed
#define ONE_DAY_MILLISECONDS (ONE_DAY * 1000)
#define NOW_TIMESTAMP [[NSDate date] timeIntervalSince1970] * 1000

//-------------------------------------------------------------
///@name Location Processing constants
//-------------------------------------------------------------
static float const kTimeBetweenUpdates = 60.0f;

static float const kWalkingDistanceFilter = 4.0f;
static float const kRunningDistanceFilter = 15.0f;
static float const kCyclingDistanceFilter = 30.0f;
static float const kDrivingDistanceFilter = 75.0f;
static float const kWalkingSpeed = 3.0f;
static float const kRunningSpeed = 6.0f;
static float const kDrivingSpeed = 20.0f;


#define kOSVersion [[UIDevice currentDevice] systemVersion]

static NSString *const kGravyVersionModel = @"VersionModel";

//-------------------------------------------------------------
///@name NSUserDefaults Legacy keys
//-------------------------------------------------------------

static NSString *const SDK_USER_USERDEFAULT = @"GravySDKUserKey";
static NSString *const kGravySDKAurumUser = @"GravySDKAurumUserKey";
static NSString *const kGravySDKAurumDevice = @"GravySDKAurumDeviceKey";
static NSString *const kLegacyGravyDeviceID = @"LegacyGravyDeviceID";

static NSString *const kGravySDKLogSignature = @"<GravySDK>";

static int const GRAVY_SDK_REQUIRED_DB_VERSION = 2;

//-------------------------------------------------------------
///@name NSUserDefaults Config Keys
//-------------------------------------------------------------

static NSString *const kLocationServicesON       = @"LocationServices";
static NSString *const kLocationReportingON      = @"LocationReporting";
static NSString *const kLocationSettingsPreset   = @"LocationSettingsPreset";
static NSString *const kLocationAwarenessSupport = @"LocationAwarenessSupport";
static NSString *const kAdvertisersID            = @"AdvertisersID";
static NSString *const kBatchReporting           = @"BatchReporting";
static NSString *const kRealTimeProcessing       = @"RealTimeProcessing";
static NSString *const kMaximumDwellTime         = @"MaximumDwellTime";
static NSString *const kEnvironment              = @"Environment";
static NSString *const kEnvironmentPlist         = @"isProduction";
static NSString *const kTestMode                 = @"TestMode";
static NSString *const kSearchDistance           = @"SearchDistance";
static NSString *const kSearchType               = @"SearchType";
static NSString *const kConfigFileVersion        = @"version";

//-------------------------------------------------------------
///@name NSUserDefaults Config Keys
//-------------------------------------------------------------

static NSString *const kGravyGoldSDKPushNotificationToken = @"GravyGoldSDKPushNotificationToken";
static NSString *const kApplicationLocationServicesEnabled = @"kApplicationLocationServicesEnabled";

//-------------------------------------------------------------
///@name Error Codes
//-------------------------------------------------------------

static NSInteger const kGGSRTLPIntegrationMethodsErrorCode = 950;
static NSInteger const kGGSRTLPIntegrationDelegateErrorCode = 951;
static NSInteger const kGGSRTLPCenterPointErrorCode = 952;
static NSInteger const kGGSRTLPInvalidSearchType = 953;
static NSInteger const kGGSBatchErrorCode = 954;

#define floatToString(x) [NSString stringWithFormat:@"%.0f", x]
#define numberToString(x)  [NSString stringWithFormat:@"%@", x]