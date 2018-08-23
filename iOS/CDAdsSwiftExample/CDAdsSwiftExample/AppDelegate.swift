//
//  AppDelegate.swift
//  CDAdsSwiftExample
//
//  Created by Arun Gupta on 01/08/16.
//  Copyright © 2016 Chalkdigital. All rights reserved.
//

import UIKit
import CDAds

@UIApplicationMain
class AppDelegate: UIResponder, UIApplicationDelegate {

    var window: UIWindow?
    var _cdAds: CDAds?


    func application(_ application: UIApplication, didFinishLaunchingWithOptions launchOptions: [UIApplicationLaunchOptionsKey: Any]?) -> Bool {
        // Override point for customization after application launch.
        let params: CDInitialisationParams! = CDInitialisationParams.init()
        params.key = "Your_CDAds_Key"                         //Provided by Chalkdigital;
        params.secret = "Your_CDAds_Secret"                   //Provided by Chalkdigital;
        params.publisherId = "Your_CDAds_Publisher_ID"        //Provided by Chalkdigital;
        params.siteId = "Your_CDAds_Key";                                   //Provided by Chalkdigital;
        params.logLevel = CDLogLevelDetail
        params.applicationIABCategory = "IAB15-10";            //IAB Category of application. In case of multiple IAB Categories use Comma (,) to separate different categories"
        params.showTrackingTerms = false;                      //This is enabed by default. Chalk sdk track user information in background, When its value is true then sdk will automatically show permission dialog for tracking user information. If any publisher disable this then that publisher must show a similar permission dialog in their app.
        params.clientHasUserTrackingPermission = true;       //Enable this flag only if publisher has teken tracking consent from user.
        _cdAds = CDAds.initialise(with: params, launchpOptions: launchOptions, enableTracking: true);
        return true
    }

    func applicationWillResignActive(_ application: UIApplication) {
        // Sent when the application is about to move from active to inactive state. This can occur for certain types of temporary interruptions (such as an incoming phone call or SMS message) or when the user quits the application and it begins the transition to the background state.
        // Use this method to pause ongoing tasks, disable timers, and throttle down OpenGL ES frame rates. Games should use this method to pause the game.
    }

    func applicationDidEnterBackground(_ application: UIApplication) {
        // Use this method to release shared resources, save user data, invalidate timers, and store enough application state information to restore your application to its current state in case it is terminated later.
        // If your application supports background execution, this method is called instead of applicationWillTerminate: when the user quits.
    }

    func applicationWillEnterForeground(_ application: UIApplication) {
        // Called as part of the transition from the background to the inactive state; here you can undo many of the changes made on entering the background.
    }

    func applicationDidBecomeActive(_ application: UIApplication) {
        // Restart any tasks that were paused (or not yet started) while the application was inactive. If the application was previously in the background, optionally refresh the user interface.
    }

    func applicationWillTerminate(_ application: UIApplication) {
        // Called when the application is about to terminate. Save data if appropriate. See also applicationDidEnterBackground:.
    }
    
    func application(_ application: UIApplication, performFetchWithCompletionHandler completionHandler: @escaping (UIBackgroundFetchResult) -> Void) {
        _cdAds?.performUpdate(completionHandler: completionHandler);
    }


}

