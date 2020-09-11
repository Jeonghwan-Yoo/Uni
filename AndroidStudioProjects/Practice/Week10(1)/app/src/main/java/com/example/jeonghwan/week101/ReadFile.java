package com.example.jeonghwan.week101;

import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.widget.Button;
import android.widget.EditText;

import java.io.FileInputStream;
import java.io.IOException;

import static com.example.jeonghwan.week101.R.styleable.View;

public class ReadFile extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_read_file);
        Button btnRead;
        final EditText edtSD;
        btnRead=(Button)findViewById(R.id.btnRead);
        edtSD=(EditText)findViewById(R.id.edtSD);

        btnRead.setOnClickListener(new View.OnClickListener(){
            public void onClick(View v){
                try{
                    FileInputSteam inFs=new FileInputStream("/sdcard/sd_text.txt");
                    byte[] txt=new byte[inFs.available()];
                    inFs.read(txt);
                    edtSD.setText(new String(txt));
                    inFs.close();
                }catch(IOException e){

                }
            }
        });
    }
}
