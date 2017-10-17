package com.chalkdigital.www.cdadsexample;

import android.location.Location;
import android.os.Bundle;
import android.os.Handler;
import android.support.v7.app.AppCompatActivity;
import android.webkit.WebView;
import android.webkit.WebViewClient;

import com.chalkdigital.cdads.CDADBannerView;
import com.chalkdigital.cdads.CDAds;
import com.chalkdigital.cdads.listeners.CDAdsListener;
import com.chalkdigital.cdads.model.CDADRequest;

import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.text.SimpleDateFormat;
import java.util.Calendar;
import java.util.Date;

public class MainActivity extends AppCompatActivity implements CDAdsListener{

    private WebView mWebView;
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


        CDAds.runningInstance().setCdAdsListener(this);                                 //implement CDAdsListener set this object as CDAdsListener


        CDADRequest cdadRequest = new CDADRequest.Builder().build(this);
        cdadRequest.keyword = "";
        cdadRequest.targetingAge = "";
        cdadRequest.targetingEducation = "";
        cdadRequest.targetingGender = "";
        cdadRequest.onlySecureImpressionsAllowed = false;       //Use true if you want to see impressions that are available on HTTPS. Set false for enabling HTTP impressions also.

        //    location Auto Update Enabled by Default, If you disable this then location is need to be set by application
        cdadRequest.locationAutoUpdateEnabled = true;

//        CDGeoInfo cdGeoInfo = cdadRequest.geoInfo;
//        cdGeoInfo.setCity("City_Name");
//        cdGeoInfo.setRegion("State_Name");
//        cdGeoInfo.setZip("Zip_Code");
//        cdGeoInfo.setCountryCode("Country_Code");
//
//        cdadRequest.geoInfo = cdGeoInfo;


        CDADBannerView largeBannerView = (CDADBannerView)findViewById(R.id.largeAdView);
        CDADBannerView smallBannerView = (CDADBannerView)findViewById(R.id.smallAdView);
        //    if you want to change the Ad refresh Interval.
        largeBannerView.setRefreshInterval(60);                // default is 30.0 seconds
        smallBannerView.setRefreshInterval(60);

        //    Ad Auto Refresh Enabled by Default, If you disable this then this view will stop refreshing the ad after first successful impression,
        //    In that case you can again hit ad request by calling loadRequest method on View.

        largeBannerView.setAdAutoRefreshEnabled(true);
        largeBannerView.loadRequest(cdadRequest);
        smallBannerView.setAdAutoRefreshEnabled(true);
        smallBannerView.loadRequest(cdadRequest);

    }

    public void refreshTextView(){
        File externalStorageDir = MainActivity.this.getApplicationContext().getFilesDir();
        File myFile = new File(externalStorageDir, "cdads_logs.txt");
        if (mWebView!=null && hasWindowFocus() && myFile.exists()){
            mWebView.loadUrl("file:///"+myFile);
        }
    }

    public void writefile(final String log) {
        new Thread(new Runnable() {
            @Override
            public void run() {
                File externalStorageDir = getApplicationContext().getFilesDir();
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
                                refreshTextView();
                            }
                        });
                    }
                }

            }
        }).start();

    }

    //location callback implemented using CDAdsListener
    @Override
    public void cdAdsLocationUpdated(Location location) {
        writefile(location.getProvider() + String.format(" %.6f, %.6f ", location.getLatitude(), location.getLongitude())  + getStringFromDate(new Date(location.getTime()))+" "+getStringFromDate(Calendar.getInstance().getTime()) +" "+ location.getAccuracy());
    }

    @Override
    public void cdAdsLocationServicesDidFailWithError(Error error) {

    }

    public String getStringFromDate(Date date){
        SimpleDateFormat dateFormat = new SimpleDateFormat("dd-MM-yyyy HH:mm:ss");
        return dateFormat.format(date);
    }
}
