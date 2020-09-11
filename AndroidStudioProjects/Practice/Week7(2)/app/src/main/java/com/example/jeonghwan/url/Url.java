package com.example.jeonghwan.url;

import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.webkit.WebSettings;
import android.webkit.WebView;
import android.webkit.WebViewClient;
import android.widget.Button;
import android.widget.EditText;

public class Url extends AppCompatActivity {
    EditText edtUrl;
    Button btnGo,btnBack;
    WebView web;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_url);

        edtUrl=(EditText)findViewById(R.id.edtUrl);
        btnGo=(Button)findViewById(R.id.btnGo);
        btnBack=(Button)findViewById(R.id.btnBack);
        web=(WebView)findViewById(R.id.webView1);

        web.setWebViewClient(new CookWebViewClient());

        WebSettings webSet=web.getSettings();
        webSet.setBuiltInZoomControls(true);

        btnGo.setOnClickListener(new View.OnClickListener(){
            public void onClick(View v){
                web.loadUrl(edtUrl.getText().toString());
            }
        });
        btnBack.setOnClickListener(new View.OnClickListener(){
            public void onClick(View v){
                web.goBack();
            }
        });
    }
    class CookWebViewClient extends WebViewClient {
        public boolean shouldOverrideUrlLoading(WebView view,String url){
            return super.shouldOverrideUrlLoading(view, url);
        }
    }
}
