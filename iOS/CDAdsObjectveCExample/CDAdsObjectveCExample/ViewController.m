//
//  ViewController.m
//  CDAdsObjectveCExample
//
//  Created by Arun Gupta on 01/08/16.
//  Copyright © 2016 Chalkdigital. All rights reserved.
//

#import "ViewController.h"
#import <CDAds/CDAds.h>

@interface ViewController ()
@property (weak, nonatomic) IBOutlet CDADBannerView *smallBannerView;
@property (weak, nonatomic) IBOutlet CDADBannerView *largeBannerView;

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    [self.smallBannerView setCdAdSize:kCDAdSizeBanner320x50];
    CDADRequest *request = [[CDADRequest alloc] init];
    request.keyword = @"";
    request.targetingAge = @"";
    request.targetingEducation = @"";
    request.targetingGender = @"";
    
    ////    location Auto Update Enabled by Default, If you disable this then location is need to be set by application which is using this SDK
    //    request.locationAutoUpdateEnabled = NO;
    //
    //    CDGeoInfo *geoInfo = [[CDGeoInfo alloc] init];
    //    geoInfo.city = @"City Name";
    //    geoInfo.region = @"State Name";
    //    geoInfo.zip = @"Zip Code";
    //    geoInfo.country = @"Country Code";
    //
    //    request.geoInfo = geoInfo;
    //
    ////  Ad Auto Refresh Enabled by Default, If you disable this then this view will stop refreshing the ad after first successful impression, you can again hit ad request by calling loadRequest method on View.
    //    request.adAutoRefreshEnabled = NO;
    
    //    if you want to change the Ad refresh Interval.
    self.smallBannerView.refreshInterval = 30.0;                   // default is 30.0;
    self.largeBannerView.refreshInterval = 30.0;
    self.smallBannerView.rootViewController = self;
    [self.smallBannerView loadRequest:request];
    self.largeBannerView.rootViewController = self;
    [self.largeBannerView loadRequest:request];
    // Do any additional setup after loading the view, typically from a nib.
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

@end
