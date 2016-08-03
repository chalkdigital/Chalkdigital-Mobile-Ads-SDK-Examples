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

    @IBOutlet weak var adBannerView: CDADBannerView!
    override func viewDidLoad() {
        super.viewDidLoad()
        
        self.adBannerView.cdAdSize = kCDAdSizeBanner320x50;
        let request : CDADRequest = CDADRequest()
        request.targetingAge = "";
        request.targetingGender = "";
        request.targetingIncome = "";
        request.targetingEducation = "";
        
        self.adBannerView.refreshInterval = 30.0
        self.adBannerView.viewController = self
        self.adBannerView.loadRequest(request)
        // Do any additional setup after loading the view, typically from a nib.
    }

    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
        // Dispose of any resources that can be recreated.
    }


}

