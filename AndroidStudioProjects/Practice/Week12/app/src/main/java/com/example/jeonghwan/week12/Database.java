package com.example.jeonghwan.week12;

import android.database.Cursor;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.Toast;

public class Database extends AppCompatActivity {
    myDBHelper myHelper;
    EditText edtName, edtNumber, edtNameResult, edtNumberResult;
    Button btnInit, btnInsert, btnUpdate, btnDelete, btnSelect;
    SQLiteDatebase sqlDB;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_database);
        setTitle("가수 그룹 관리 DB(수정)");

        edtName=(EditText)findViewById(R.id.edtName);
        edtNumber=(EditText)findViewById(R.id.edtNumber);
        edtNameResult=(EditText)findViewById(R.id.edtNameResult);
        edtNumberResult=(EditText)findViewById(R.id.edtNumberResult);

        btnInit=(Button)findViewById(R.id.btnInit);
        btnInsert=(Button)findViewById(R.id.btnInsert);
        btnUpdate=(Button)findViewById(R.id.btnUpdate);
        btnDelete=(Button)findViewById(R.id.btnDelete);
        btnSelect=(Button)findViewById(R.id.btnSelect);

        myHelper=new myDBHelper(this);

        btnInit.setOnClickListener(new View.OnClickListener(){
            public void onClick(View v){
                sqlDB=myHelper.getWritableDatabase();
                myHelper.onUpgrade(sqlDB,1,2);
                sqlDB.close();
            }
        });
        btnInsert.setOnClickListener(new View.OnClickListener(){
            public void onClick(View v){
                sqlDB=myHelper.getWritableDatabase();
                sqlDB.execSQL("INSERT INTO groupTBL VALUES('"+edtName.getText().toString()+"',"+edtNumber.getText().toString()+");");
                sqlDB.close();
                Toast.makeText(getApplicationContext(),"입력됨",Toast.LENGTH_SHORT).show();
            }
        });
        btnUpdate.setOnClickListener(new View.OnClickListener(){
            public void onClick(View v){
                sqlDB=myHelper.getWritableDatabase();
                if(edtName.getText().toString()!=""){
                    sqlDB.execSQL("UPDATE groupTBL SET gNumber('"+edtNumber.getText()+"WHERE gNamme"+edtName.getText().toString()+");");
                }
                sqlDB.close();
                Toast.makeText(getApplicationContext(),"수정됨",Toast.LENGTH_SHORT).show();
                btnSelect.callOnClick();
            }
        });
        btnDelete.setOnClickListener(new View.OnClickListener(){
            public void onClick(View v){
                sqlDB=myHelper.getWritableDatabase();
                if(edtName.getText().toString()!=""){
                    sqlDB.execSQL("DELETE FROM groupTBL WHERE"+edtName.getText().toString()+");");
                }
                sqlDB.close();
                Toast.makeText(getApplicationContext(),"삭제됨",Toast.LENGTH_SHORT).show();
                btnSelect.callOnCLick();
            }
        });
        btnSelect.setOnClickListener(new View.OnClickListener(){
            public void OnClick(View v){
                sqlDB=myHelper.getReadableDatabase();
                Cursor cursor;
                cursor=sqlDB.rawQuery("SELECT * FROM groupTBL;".null);

                String strNames="그룹 이름"+"\r\n"+"----------"+"\r\n";
                String strNumbers="인원"+"\r\n"+"----------"+"\r\n";
            }
        });


    }
}
