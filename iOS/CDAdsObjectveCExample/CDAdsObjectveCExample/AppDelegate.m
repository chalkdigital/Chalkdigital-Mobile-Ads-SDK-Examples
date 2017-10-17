//
//  AppDelegate.m
//  CDAdsObjectveCExample
//
//  Created by Arun Gupta on 01/08/16.
//  Copyright © 2016 Chalkdigital. All rights reserved.
//

#import "AppDelegate.h"

@interface AppDelegate ()
@property (strong, nonatomic) CDAds *cdAds;
@end

@implementation AppDelegate
- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions {

    CDInitialisationParams *params = [[CDInitialisationParams alloc] init];
    params.key = @"Your_CDAds_Key";                         //Provided by Chalkdigital;
    params.secret = @"Your_CDAds_Secret";                   //Provided by Chalkdigital;
    params.publisherId = @"Your_CDAds_Publisher_ID";        //Provided by Chalkdigital;
    params.logLevel = CDLogLevelDetail;
    params.environment = CDEnvironmentTest;                 //Use CDEnvironmentProduction for production
    params.applicationIABCategory = @"IAB15-10";            //IAB Category of application. In case of multiple IAB Categories use Comma (,) to separate different categories"
    params.locationUpdateInterval = 60;                     //Set interval at which location update is required, default value is 900 seconds
    params.adLocationExpiryInterval = 40;                   //Set time after which new location for ad request is required, default value is 120 seconds
    params.distanceFilter = 65.0;                           //Set distance after which you want SDK to record location update, default value is 100.0 meters
    params.logLevel = CDLogLevelDetail;                     //Set log level to see SDK logs, default value is CDLogLevelNone
    params.provider = CDADProviderChalk;                    //Choose from ad providers supported by ChalkDigital SDK, default value is CDADProviderChalk
    
    _cdAds = [CDAds initialiseWithParams:params launchpOptions:launchOptions enableTracking:YES];

    return YES;
}

- (void)applicationWillResignActive:(UIApplication *)application {
    // Sent when the application is about to move from active to inactive state. This can occur for certain types of temporary interruptions (such as an incoming phone call or SMS message) or when the user quits the application and it begins the transition to the background state.
    // Use this method to pause ongoing tasks, disable timers, and throttle down OpenGL ES frame rates. Games should use this method to pause the game.
}

- (void)applicationDidEnterBackground:(UIApplication *)application {
    // Use this method to release shared resources, save user data, invalidate timers, and store enough application state information to restore your application to its current state in case it is terminated later.
    // If your application supports background execution, this method is called instead of applicationWillTerminate: when the user quits.
}

- (void)applicationWillEnterForeground:(UIApplication *)application {
    // Called as part of the transition from the background to the inactive state; here you can undo many of the changes made on entering the background.
}

- (void)applicationDidBecomeActive:(UIApplication *)application {
    // Restart any tasks that were paused (or not yet started) while the application was inactive. If the application was previously in the background, optionally refresh the user interface.
}

- (void)applicationWillTerminate:(UIApplication *)application {
    // Called when the application is about to terminate. Save data if appropriate. See also applicationDidEnterBackground:.
}

-(void)application:(UIApplication *)application performFetchWithCompletionHandler:(void (^)(UIBackgroundFetchResult))completionHandler{
    [_cdAds performUpdateWithCompletionHandler:completionHandler];
}


@end
