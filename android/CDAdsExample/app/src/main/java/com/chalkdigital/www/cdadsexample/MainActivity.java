package com.chalkdigital.www.cdadsexample;

import android.content.BroadcastReceiver;
import android.content.Context;
import android.content.Intent;
import android.content.IntentFilter;
import android.location.Location;
import android.location.LocationManager;
import android.os.Handler;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.util.Log;
import android.webkit.WebView;
import android.webkit.WebViewClient;

import com.chalkdigital.cdads.CDADBannerView;
import com.chalkdigital.cdads.CDAds;
import com.chalkdigital.cdads.CDAdsInitialisationParams;
import com.chalkdigital.cdads.CDDefines;
import com.chalkdigital.cdads.CDUtil;
import com.chalkdigital.cdads.constants.CDActions;
import com.chalkdigital.cdads.model.CDADRequest;

import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Calendar;
import java.util.Date;

public class MainActivity extends AppCompatActivity {

    private WebView mWebView;
    private MyReceiver mReceiver;
    private Handler mHandler;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        mHandler = new Handler(getMainLooper());
        mWebView = (WebView)findViewById(R.id.webview);
        mWebView.setWebViewClient(new WebViewClient() {
            public void onPageFinished(WebView view, String url) {
                mWebView.pageDown(true);
            }
        });
        refreshTextView();


        CDAdsInitialisationParams cdAdsInitialisationParams = new CDAdsInitialisationParams(this);
        cdAdsInitialisationParams.setLocationUpdateInterval(30);                       //Set interval at which location update is required, default value is 900 seconds
        cdAdsInitialisationParams.setAdLocationExpiryInterval(60);                      //Set time after which new location for ad request is required, default value is 120
        cdAdsInitialisationParams.setDistanceFilter(3.0f);                              //Set distance after which you want SDK to record location update, default value is 100.0 meters
        cdAdsInitialisationParams.setLogLevel(Log.DEBUG);                               //Set log level to see SDK logs, default value is Log.ERROR
        cdAdsInitialisationParams.setProvider(CDDefines.CDADProvider.CDAD_PROVIDER_Chalkdigital);   //Choose from different ad providers supported by ChalkDigital SDK, default value is CDAD_Provider_Chalkdigital

        CDAds cdAds = CDAds.initialiseWithParams(cdAdsInitialisationParams, this);
        cdAds.setEnableTracking(true);                                                  //Set false to disable device information tracking
        cdAds.start();

        CDADRequest cdadRequest = new CDADRequest.Builder().build(this);
        cdadRequest.keyword = "";
        cdadRequest.targetingAge = "";
        cdadRequest.targetingEducation = "";
        cdadRequest.targetingGender = "";

        //    location Auto Update Enabled by Default, If you disable this then location is need to be set by application
        cdadRequest.locationAutoUpdateEnabled = true;

//        CDGeoInfo cdGeoInfo = cdadRequest.geoInfo;
//        cdGeoInfo.setCity("City_Name");
//        cdGeoInfo.setRegion("State_Name");
//        cdGeoInfo.setZip("Zip_Code");
//        cdGeoInfo.setCountryCode("Country_Code");
//
//        cdadRequest.geoInfo = cdGeoInfo;


        CDADBannerView cdadBannerView = (CDADBannerView)findViewById(R.id.adView);
        //    if you want to change the Ad refresh Interval.
        cdadBannerView.setRefreshInterval(60);                // default is 30.0 seconds

        //    Ad Auto Refresh Enabled by Default, If you disable this then this view will stop refreshing the ad after first successful impression,
        //    In that case you can again hit ad request by calling loadRequest method on View.

        cdadBannerView.setAdAutoRefreshEnabled(true);
        cdadBannerView.loadRequest(cdadRequest);

        IntentFilter filter = new IntentFilter(CDActions.LOCATION_CHANGED);
        mReceiver = new MyReceiver(this);
        this.registerReceiver(mReceiver, filter);
    }

    public void refreshTextView(){
        File externalStorageDir = MainActivity.this.getApplicationContext().getFilesDir();
        File myFile = new File(externalStorageDir, "cdads_logs.txt");
        if (mWebView!=null && hasWindowFocus() && myFile.exists()){
            mWebView.loadUrl("file:///"+myFile);
        }
    }

    public static class MyReceiver extends BroadcastReceiver {
        private MainActivity mActivity;

        public MyReceiver() {
        }

        public MyReceiver(MainActivity mActivity) {
            this.mActivity = mActivity;
        }

        @Override
        public void onReceive(Context context, Intent intent) {
            Location location = (Location)intent.getExtras().getParcelable(LocationManager.KEY_LOCATION_CHANGED);
            if (mActivity!=null){
                if (location!=null)
                    mActivity.writefile(mActivity, location.getProvider() + String.format(" %.6f, %.6f ", location.getLatitude(), location.getLongitude())  + CDUtil.getStringFromDate(new Date(location.getTime()))+" "+CDUtil.getStringFromDate(Calendar.getInstance().getTime()) +" "+ location.getAccuracy());
                if (mActivity.hasWindowFocus())
                    mActivity.refreshTextView();
            }
        }
    }

    @Override
    protected void onDestroy() {
        this.unregisterReceiver(mReceiver);
        super.onDestroy();
    }

    public void writefile(final MainActivity activity, final String log) {
        new Thread(new Runnable() {
            @Override
            public void run() {
                File externalStorageDir = activity.getApplicationContext().getFilesDir();
                File myFile = new File(externalStorageDir, "cdads_logs.txt");

                if (!myFile.exists()) {
                    try {
                        myFile.createNewFile();
                    } catch (IOException e) {
                        e.printStackTrace();
                        return;
                    }
                }

                try {
                    FileWriter fw = new FileWriter(myFile, true);
                    fw.write(log+"\n\n");
                    fw.close();
                } catch (IOException e) {
                    e.printStackTrace();
                }finally {
                    if (mHandler!=null){
                        mHandler.post(new Runnable() {
                            @Override
                            public void run() {
                                activity.refreshTextView();
                            }
                        });
                    }
                }

            }
        }).start();

    }
}
