package com.example.jeonghwan.datereservation;

import android.graphics.Color;
import android.icu.util.Calendar;
import android.os.SystemClock;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.CalendarView;
import android.widget.Chronometer;
import android.widget.RadioButton;
import android.widget.TextView;
import android.widget.TimePicker;

public class DateReservation extends AppCompatActivity {
    Chronometer chrono;
    Button btnStart,btnEnd;
    RadioButton rdoCal,rdoTime;
    CalendarView calView;
    TimePicker tPicker;
    TextView tvYear, tvMonth, tvDay, tvHour, tvMinute;
    int selectYear, selectMonth, selectDay;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_date_reservation);
        setTitle("시간 예약");
        btnStart=(Button)findViewById(R.id.btnStart);
        btnEnd=(Button)findViewById(R.id.btnEnd);

        chrono=(Chronometer)findViewById(R.id.chronometer1);
        rdoCal=(RadioButton)findViewById(R.id.rdoCal);
        rdoTime=(RadioButton)findViewById(R.id.rdoTime);

        tPicker=(TimePicker)findViewById(R.id.timePicker1);
        calView=(CalendarView)findViewById(R.id.calendarView1);

        tvYear=(TextView)findViewById(R.id.tvYear);
        tvMonth=(TextView)findViewById(R.id.tvMonth);
        tvDay=(TextView)findViewById(R.id.tvDay);
        tvHour=(TextView)findViewById(R.id.tvHour);
        tvMinute=(TextView)findViewById(R.id.tvMinute);

        tPicker.setVisibility(View.INVISIBLE);
        calView.setVisibility(View.INVISIBLE);

        rdoCal.setOnClickListener(new View.OnClickListener(){
            public void onClick(View v){
                tPicker.setVisibility(View.INVISIBLE);
                calView.setVisibility(View.VISIBLE);
            }
        });
        rdoTime.setOnClickListener(new View.OnClickListener(){
            public void onClick(View v){
                tPicker.setVisibility(View.VISIBLE);
                calView.setVisibility(View.INVISIBLE);
            }
        });

        btnStart.setOnClickListener(new View.OnClickListener(){
            public void onClick(View v){


                chrono.setBase(SystemClock.elapsedRealtime());
                chrono.start();
                chrono.setTextColor(Color.RED);


            }
        });
        btnEnd.setOnClickListener(new View.OnClickListener(){
            public void onClick(View v){

                chrono.stop();
                chrono.setTextColor(Color.BLUE);
                java.util.Calendar curDate=java.util.Calendar.getInstance();
                curDate.setTimeInMillis(calView.getDate());

                tvYear.setText(Integer.toString(curDate.get(Calendar.YEAR)));
                tvMonth.setText(Integer.toString(1+curDate.get(Calendar.MONTH)));
                tvDay.setText(Integer.toString(curDate.get(Calendar.DATE)));
                tvHour.setText(Integer.toString(tPicker.getCurrentHour()));
                tvMinute.setText(Integer.toString(tPicker.getCurrentMinute()));

            }
        });
        calView.setOnDateChangeListener(new CalendarView.OnDateChangeListener(){
            public void onSelectedDayChange(CalendarView view, int year, int month, int dayOfMonth){

                selectYear=year;
                selectMonth=month+1;
                selectDay=dayOfMonth;
            }
        });


    }

}