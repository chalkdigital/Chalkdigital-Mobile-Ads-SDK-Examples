//
//  CDADView.h
//  Chalkboard
//
//  Created by Arun Gupta on 15/09/15.
//  Copyright (c) 2015 Arun Gupta. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>
#import "CDAdSize.h"
#import "CDADRequest.h"

@class CDADBannerView;
@protocol CDADBannerViewDelegate
@optional
-(BOOL) cdView:(UIWebView *)inWeb shouldStartLoadWithRequest:(NSURLRequest *)inRequest navigationType:(UIWebViewNavigationType)inType;
-(void)cdViewStoppedExecuting;
-(void)cdadNewtorkRequestStarted;
-(void)cdadNetworkRequestFinished;
-(void)cdAdViewPaused;
-(void)cdAdViewStartedExecuting;
@end


@interface CDADBannerView : UIWebView <UIWebViewDelegate>
@property (weak, nonatomic) UIViewController *viewController;
@property CDAdSize cdAdSize;
@property (atomic) BOOL isExecuting;
@property (readonly, strong, nonatomic) CDADRequest *adRequest;
@property (weak, nonatomic) UIViewController<CDADBannerViewDelegate> *cdAdBannerViewDelegate;
@property (nonatomic) BOOL adAutoRefreshEnabled;
@property (nonatomic) float refreshInterval;
-(void)stoppedExecuting;
-(void)newtorkRequestStarted;
-(void)networkRequestFinished;
-(void)loadRequest:(CDADRequest*)request;
-(void)pauseAdRefresh;
-(void)stopAdRefresh;
@end
