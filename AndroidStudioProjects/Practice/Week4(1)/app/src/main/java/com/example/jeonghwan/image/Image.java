package com.example.jeonghwan.image;

import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.CompoundButton;
import android.widget.ImageView;
import android.widget.RadioButton;
import android.widget.RadioGroup;
import android.widget.Switch;
import android.widget.TextView;

public class Image extends AppCompatActivity {

    TextView text1,text2;
    Switch switchAgree;
    RadioGroup rGroup1;
    RadioButton radioArray[]=new RadioButton[3];
    ImageView imgPet;
    Button btnQuit, btnRerun;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_image);
        setTitle("안드로이드 사진 보기");

        text1=(TextView)findViewById(R.id.Text1);
        switchAgree=(Switch)findViewById(R.id.SwitchAgree);
        text2=(TextView)findViewById(R.id.Text2);
        rGroup1=(RadioGroup)findViewById(R.id.Rgroup1);
        radioArray[0]=(RadioButton)findViewById(R.id.Rdo50);
        radioArray[1]=(RadioButton)findViewById(R.id.Rdo60);
        radioArray[2]=(RadioButton)findViewById(R.id.Rdo70);

        imgPet=(ImageView)findViewById(R.id.ImgPet);
        btnQuit=(Button)findViewById(R.id.BtnQuit);
        btnRerun=(Button)findViewById(R.id.BtnRerun);
        switchAgree.setOnCheckedChangeListener(new CompoundButton.OnCheckedChangeListener(){
            public void onCheckedChanged(CompoundButton arg0,boolean arg1){
                if(switchAgree.isChecked()){
                    text2.setVisibility(android.view.View.VISIBLE);
                    rGroup1.setVisibility(android.view.View.VISIBLE);
                    imgPet.setVisibility(android.view.View.VISIBLE);
                    btnQuit.setVisibility(android.view.View.VISIBLE);
                    btnRerun.setVisibility(android.view.View.VISIBLE);
                }
                else{
                    text2.setVisibility(android.view.View.INVISIBLE);
                    rGroup1.setVisibility(android.view.View.INVISIBLE);
                    imgPet.setVisibility(android.view.View.INVISIBLE);
                    btnQuit.setVisibility(android.view.View.INVISIBLE);
                    btnRerun.setVisibility(android.view.View.INVISIBLE);
                }
            }
        });
        final int draw[]={R.drawable.api50,R.drawable.api60,R.drawable.api70};
        for(int i=0;i<radioArray.length;i++){
            final int index;
            index=i;
            radioArray[index].setOnClickListener(new View.OnClickListener(){
                public void onClick(View v){
                    imgPet.setImageResource(draw[index]);
                }
            });
        }
        btnQuit.setOnClickListener(new View.OnClickListener(){
            public void onClick(View arg0){
                finish();
            }
        });
        btnRerun.setOnClickListener(new View.OnClickListener(){
            public void onClick(View arg0){
                text2.setVisibility(android.view.View.INVISIBLE);
                rGroup1.setVisibility(android.view.View.INVISIBLE);
                imgPet.setVisibility(android.view.View.INVISIBLE);
                btnQuit.setVisibility(android.view.View.INVISIBLE);
                btnRerun.setVisibility(android.view.View.INVISIBLE);

                rGroup1.clearCheck();
                switchAgree.setChecked(false);
            }
        });
    }
}
