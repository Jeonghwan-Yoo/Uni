package com.example.jeonghwan.project;

import android.content.Context;
import android.content.Intent;
import android.database.Cursor;
import android.database.sqlite.SQLiteDatabase;
import android.database.sqlite.SQLiteOpenHelper;
import android.media.MediaPlayer;
import android.net.Uri;
import android.provider.MediaStore;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.ArrayAdapter;
import android.widget.AutoCompleteTextView;
import android.widget.Button;
import android.widget.TextView;
import android.widget.Toast;
import java.io.IOException;
import java.text.SimpleDateFormat;
import java.util.Date;

public class MainActivity extends AppCompatActivity {

    AutoCompleteTextView auto; //자동완성텍스트뷰
    MediaPlayer mPlayer; //노래재생을 위한 미디어플레이어
    Button button1,button2; //이동과 노래버튼
    TextView selectResult; //이전 기록
    myDBHelper myHelper; //DB, Table 생성 및 관리를 포괄적으로 하는 역할인 SQLite OpenHelper 상속받은 클래스 변수
    SQLiteDatabase sqlDB; //Table 안에 데이터 입력 수정 삭제하는 SQLiteDatabase 클래스 변수

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        String[] items = { "전화", "지도", "인터넷", "문자", "사진", "연락처", "구글", "카메라"}; //어댑터 뷰를 이용하기 위한 배열
        setTitle("퀵서브");

        auto = (AutoCompleteTextView) findViewById(R.id.autoCompleteTextView);
        ArrayAdapter<String> adapter = new ArrayAdapter<String>(this, android.R.layout.simple_dropdown_item_1line, items);
        auto.setAdapter(adapter); //어댑터 뷰

        myHelper=new myDBHelper(this); //객체 생성
        selectResult=(TextView)findViewById(R.id.selectResult);

        button1 = (Button) findViewById(R.id.button1);
        button2 = (Button) findViewById(R.id.button2);

        button1.setOnClickListener(new View.OnClickListener(){
            public void onClick(View v){
                //약속된 액션을 지정하여 안드로이드에서 제공하는 기존 응용프로그램인 암시적 인텐트로 실행
                if(auto.getText().toString().equals("전화")) { //전화입력시 전화로 이동
                    Toast.makeText(getApplicationContext(),auto.getText()+"로 이동합니다",Toast.LENGTH_LONG).show(); //토스트생성
                    Uri uri = Uri.parse("tel:");
                    Intent intent = new Intent(Intent.ACTION_DIAL, uri);
                    startActivity(intent);
                    insertData("전화"); //데이터베이스에 순번과 날짜와 전화를 입력
                }
                else if(auto.getText().toString().equals("지도")) { //지도입력시 지도로 이동
                    Toast.makeText(getApplicationContext(),auto.getText()+"로 이동합니다",Toast.LENGTH_LONG).show(); //토스트생성
                    Uri uri = Uri.parse("http://maps.google.com/maps?q= ");
                    Intent intent = new Intent(Intent.ACTION_VIEW, uri);
                    startActivity(intent);
                    insertData("지도"); //데이터베이스에 순번과 날짜와 지도를 입력
                }
                else if(auto.getText().toString().equals("사진")){ //사진입력시 사진으로 이동
                    Toast.makeText(getApplicationContext(),auto.getText()+"으로 이동합니다",Toast.LENGTH_LONG).show(); //토스트생성
                    Intent intent=new Intent(Intent.ACTION_VIEW,Uri.parse("content://media/internal/images/media"));
                    startActivity(intent);
                    insertData("사진"); //데이터베이스에 순번과 날짜와 사진을 입력
                }
                else if(auto.getText().toString().equals("카메라")){ //카메라입력시 카메라로 이동
                    Toast.makeText(getApplicationContext(),auto.getText()+"로 이동합니다",Toast.LENGTH_LONG).show(); //토스트생성
                    Intent intent=new Intent(MediaStore.ACTION_IMAGE_CAPTURE);
                    startActivity(intent);
                    insertData("카메라"); //데이터베이스에 순번과 날짜와 카메라를 입력
                }
                else if(auto.getText().toString().equals("구글")) { //구글입력시 구글로 이동
                    Toast.makeText(getApplicationContext(),auto.getText()+"로 이동합니다",Toast.LENGTH_LONG).show(); //토스트생성
                    Uri uri = Uri.parse("http://www.google.com/");
                    Intent intent = new Intent(Intent.ACTION_VIEW, uri);
                    startActivity(intent);
                    insertData("구글"); //데이터베이스에 순번과 날짜와 구글을 입력
                }
                else if(auto.getText().toString().equals("연락처")){ //연락처입력시 연락처로 이동
                    Toast.makeText(getApplicationContext(),auto.getText()+"로 이동합니다",Toast.LENGTH_LONG).show(); //토스트생성
                    Intent intent=new Intent(Intent.ACTION_VIEW,Uri.parse("content://contacts/people/"));
                    startActivity(intent);
                    insertData("연락처"); //데이터베이스에 순번과 날짜와 연락처를 입력
                }
                else if(auto.getText().toString().equals("문자")) { //문자입력시 문자로 이동
                    Toast.makeText(getApplicationContext(),auto.getText()+"로 이동합니다",Toast.LENGTH_LONG).show(); //토스트생성
                    Intent intent=new Intent(Intent.ACTION_VIEW);
                    intent.putExtra("sms_body","");
                    intent.setType("vnd.android-dir/mms-sms");
                    startActivity(intent);
                    insertData("문자"); //데이터베이스에 순번과 날짜와 문자를 입력
                }
                else { //잘못 입력 했을 경우
                    Toast.makeText(getApplicationContext(),"다시 입력 해주세요.",Toast.LENGTH_LONG).show(); //토스트생성
                }
                selectData(); //이전 기록을 보여줌
            }


        });
        selectData(); //버튼을 누르기 전에도 이전 기록을 보여줌

        mPlayer = MediaPlayer.create(this,R.raw.song1); //노래 객체 생성
        mPlayer.setLooping(true); //노래 반복
        mPlayer.start(); //시작하자마자 노래틀기

        button2.setOnClickListener(new View.OnClickListener(){
            public void onClick(View v){ //노래 ON, OFF 할 수 있는 버튼
                if(button2.getText().toString().equals("노래 OFF")) {
                    stopMp3();
                }
                else if(button2.getText().toString().equals("노래 ON")) {
                    mPlayer.start();
                    button2.setText("노래 OFF"); //노래켜져있을 때 OFF버튼
                }
            }
        });
    }
    private void stopMp3(){ //노래 멈추고 준비
        try {
            mPlayer.stop();
            mPlayer.prepare();
        }catch (IOException e){
            Toast.makeText(getApplicationContext(),"다시 실행해보세요",Toast.LENGTH_LONG).show(); //토스트생성
        }
        button2.setText("노래 ON"); //노래꺼져있을 때 ON버튼
    }
    protected void selectData(){ //데이터베이스 이전 기록을 조회
        sqlDB = myHelper.getWritableDatabase(); //읽기 쓰지전용
        Cursor cursor;
        cursor = sqlDB.rawQuery("SELECT * FROM groupTable order by gNumber desc;", null); //역순으로 조회

        String strNames = "";
        int i = 1;
        while (cursor.moveToNext() && i <= 10) { //최근 10개의 순번과 날짜와 입력된 값을 만들기 위해
            strNames += i + ". "+cursor.getString(1) +" "+ cursor.getString(2) +"\r\n";
            i++;
        }
        selectResult.setText(strNames); //이전 기록 표시
        cursor.close();
        sqlDB.close();
    }
    protected void insertData(String str){ //데이터베이스에 입력
        sqlDB = myHelper.getWritableDatabase();
        Cursor cursor;
        cursor = sqlDB.rawQuery("SELECT MAX(gNumber) FROM groupTable ;", null); //최근 값 조회하고 커서값 반환
        int number = 0;
        cursor.moveToNext(); //커서 비어져있는 칸으로 이동
        number = cursor.getInt(0)+1; //순번

        SimpleDateFormat date1 = new SimpleDateFormat("yyyy-MM-dd hh:mm:ss"); //날짜 생성을 위해
        Date date2=new Date();
        String date=date1.format(date2); //날짜

        sqlDB.execSQL("INSERT INTO groupTable(gNumber, date, purpose) VALUES ( "
                + number + " , '" //순번 날짜 입력된 값 순으로 데이터베이스에 입력
                + date + "' , '"
                + str + "');");
        sqlDB.close();
    }

    public class myDBHelper extends SQLiteOpenHelper { //SQLiteOpenHelper 상속받고 생성자, onCreate, onUpgrade 메소드를 수정(Overriding)
        public myDBHelper(Context context){
            super(context,"groupDB",null,1);
        }
        public void onCreate(SQLiteDatabase db){
            db.execSQL("CREATE TABLE groupTable (gNumber INTEGER PRIMARY KEY, date CHAR(50), purpose CHAR(20));");
        }
        public void onUpgrade(SQLiteDatabase db,int oldVersion, int newVersion){
            db.execSQL("DROP TABLE IF EXISTS groupTable");
            onCreate(db);
        }
    }
    @Override
    protected void onUserLeaveHint(){ //홈버튼 누를시에 정지후 준비
        if(button2.getText().toString().equals("노래 OFF")) {
            stopMp3();
        }
        super.onUserLeaveHint();
    }
    @Override
    public void onDestroy(){ //앱이 아예 정지되었을때 정지후 준비
        if(button2.getText().toString().equals("노래 OFF")) {
            stopMp3();
        }
        super.onDestroy();
    }
    @Override
    public void onBackPressed(){ //백버튼으로 나갈때 정지후 준비
        if(button2.getText().toString().equals("노래 OFF")) {
            stopMp3();
        }
        super.onBackPressed();
    }
}