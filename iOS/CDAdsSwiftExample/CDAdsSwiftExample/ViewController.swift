//
//  ViewController.swift
//  CDAdsSwiftExample
//
//  Created by Arun Gupta on 01/08/16.
//  Copyright © 2016 Chalkdigital. All rights reserved.
//

import UIKit
import CDAds

class ViewController: UIViewController {

    @IBOutlet weak var largeBannerView: CDADBannerView!
    @IBOutlet weak var smallBannerView: CDADBannerView!
    override func viewDidLoad() {
        super.viewDidLoad()
        
        self.smallBannerView.cdAdSize = kCDAdSizeBanner320x50;
        let request : CDADRequest = CDADRequest()
        request.targetingAge = "";
        request.targetingGender = "";
        request.targetingIncome = "";
        request.targetingEducation = "";
        
        self.smallBannerView.refreshInterval = 30.0
        self.smallBannerView.rootViewController = self
        self.smallBannerView.loadRequest(request)

        self.largeBannerView.refreshInterval = 30.0
        self.largeBannerView.rootViewController = self
        self.largeBannerView.loadRequest(request)

    }

    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
        // Dispose of any resources that can be recreated.
    }


}

