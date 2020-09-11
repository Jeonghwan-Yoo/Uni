package com.example.jeonghwan.calculator;

import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.TextView;
import android.widget.Toast;

public class Calculator extends AppCompatActivity {
    EditText edit1,edit2;
    Button btnAdd, btnSub, btnMul, btnDiv, btnRem;
    TextView textResult;
    String num1, num2;
    Double result;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_calculator);
        setTitle("초간단 계산기(수정)");

        edit1=(EditText)findViewById(R.id.Edit1);
        edit2=(EditText)findViewById(R.id.Edit2);

        btnAdd=(Button)findViewById(R.id.BtnAdd);
        btnSub=(Button)findViewById(R.id.BtnSub);
        btnMul=(Button)findViewById(R.id.BtnMul);
        btnDiv=(Button)findViewById(R.id.BtnDiv);
        btnRem=(Button)findViewById(R.id.BtnRem);

        textResult=(TextView)findViewById(R.id.TextResult);

        btnAdd.setOnClickListener(new View.OnClickListener(){
            public void onClick(View arg0){
                num1=edit1.getText().toString();
                num2=edit2.getText().toString();
                if(num1.trim().equals("")||num2.trim().equals("")){
                    Toast.makeText(getApplicationContext(),"입력 값이 비었습니다", Toast.LENGTH_SHORT).show();

                }
                else{
                    result=Double.parseDouble(num1)+Double.parseDouble(num2);
                    textResult.setText("계산 결과 : "+result.toString());
                }
            }
        });
        btnSub.setOnClickListener(new View.OnClickListener(){
            public void onClick(View arg0){
                num1=edit1.getText().toString();
                num2=edit2.getText().toString();
                if(num1.trim().equals("")||num2.trim().equals("")){
                    Toast.makeText(getApplicationContext(),"입력 값이 비었습니다", Toast.LENGTH_SHORT).show();

                }
                else{
                    result=Double.parseDouble(num1)-Double.parseDouble(num2);
                    textResult.setText("계산 결과 : "+result.toString());
                }
            }
        });
        btnMul.setOnClickListener(new View.OnClickListener(){
            public void onClick(View arg0){
                num1=edit1.getText().toString();
                num2=edit2.getText().toString();
                if(num1.trim().equals("")||num2.trim().equals("")){
                    Toast.makeText(getApplicationContext(),"입력 값이 비었습니다", Toast.LENGTH_SHORT).show();

                }
                else{
                    result=Double.parseDouble(num1)*Double.parseDouble(num2);
                    textResult.setText("계산 결과 : "+result.toString());
                }
            }
        });
        btnDiv.setOnClickListener(new View.OnClickListener(){
            public void onClick(View arg0){
                num1=edit1.getText().toString();
                num2=edit2.getText().toString();
                if(num1.trim().equals("")||num2.trim().equals("")){
                    Toast.makeText(getApplicationContext(),"입력 값이 비었습니다", Toast.LENGTH_SHORT).show();

                }
                else{
                    if(num2.trim().equals("0")){
                        Toast.makeText(getApplicationContext(),"0으로 나누면 안됩니다!",Toast.LENGTH_SHORT).show();
                    }
                    else{
                        result=Double.parseDouble(num1)/Double.parseDouble(num2);
                        result=(int)(result*10)/10.0;
                        textResult.setText("계산 결과 : "+result.toString());
                    }
                }
            }
        });
        btnRem.setOnClickListener(new View.OnClickListener(){
            public void onClick(View arg0){
                num1=edit1.getText().toString();
                num2=edit2.getText().toString();
                if(num1.trim().equals("")||num2.trim().equals("")){
                    Toast.makeText(getApplicationContext(),"입력 값이 비었습니다", Toast.LENGTH_SHORT).show();

                }
                else{
                    if(num2.trim().equals("0")){
                        Toast.makeText(getApplicationContext(),"0으로 나누면 안됩니다!",Toast.LENGTH_SHORT).show();
                    }
                    else{
                        result=Double.parseDouble(num1)%Double.parseDouble(num2);
                        textResult.setText("계산 결과 : "+result.toString());
                    }
                }
            }
        });
    }
}
