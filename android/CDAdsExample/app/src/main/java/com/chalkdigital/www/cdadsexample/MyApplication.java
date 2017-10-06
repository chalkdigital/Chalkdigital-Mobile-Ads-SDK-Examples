package com.chalkdigital.www.cdadsexample;

import android.app.Application;
import android.util.Log;

import com.chalkdigital.cdads.CDAds;
import com.chalkdigital.cdads.CDAdsInitialisationParams;
import com.chalkdigital.cdads.CDDefines;

/**
 * Created by arungupta on 06/10/17.
 */

public class MyApplication extends Application {
    @Override
    public void onCreate() {
        super.onCreate();
        CDAdsInitialisationParams cdAdsInitialisationParams = new CDAdsInitialisationParams(this.getApplicationContext());
        cdAdsInitialisationParams.setLocationUpdateInterval(60);                       //Set interval at which location update is required, default value is 900 seconds
        cdAdsInitialisationParams.setAdLocationExpiryInterval(60);                      //Set time after which new location for ad request is required, default value is 120
        cdAdsInitialisationParams.setDistanceFilter(3.0f);                              //Set distance after which you want SDK to record location update, default value is 100.0 meters
        cdAdsInitialisationParams.setLogLevel(Log.VERBOSE);                               //Set log level to see SDK logs, default value is Log.ERROR
        cdAdsInitialisationParams.setEnvironment(CDDefines.CDEnvironment.CDEnvironmentTest);            //change environment attribute to CDEnvironmentProduction when you are using it for production
        CDAds.initialiseWithParams(cdAdsInitialisationParams, this.getApplicationContext()).start();
    }
}
