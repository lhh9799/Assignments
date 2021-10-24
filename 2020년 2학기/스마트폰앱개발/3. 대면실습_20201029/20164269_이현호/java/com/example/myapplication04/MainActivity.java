package com.example.myapplication04;

import androidx.appcompat.app.AppCompatActivity;

import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;

public class MainActivity extends AppCompatActivity {
    public static final int REQUEST_CODE_ImgSlide = 200;
    public static final int REQUEST_CODE_FrameLayout = 201;
    public static final int REQUEST_CODE_LinearLayout = 202;
    public static final int REQUEST_CODE_RelativeLayout = 203;
    public static final int REQUEST_CODE_TableLayout = 204;
    public static final int REQUEST_CODE_GridLayout = 205;


    @Override
    public void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        Button button = findViewById(R.id.button0);
        button.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                Intent intent = new Intent(getApplicationContext(), Button0Activity.class);
                startActivityForResult(intent, REQUEST_CODE_ImgSlide);
            }
        });

        button = findViewById(R.id.button1);
        button.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                Intent intent = new Intent(getApplicationContext(), Button1Activity.class);
                startActivityForResult(intent, REQUEST_CODE_FrameLayout);
            }
        });

        button = findViewById(R.id.button2);
        button.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                Intent intent = new Intent(getApplicationContext(), Button2Activity.class);
                startActivityForResult(intent, REQUEST_CODE_LinearLayout);
            }
        });

        button = findViewById(R.id.button3);
        button.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                Intent intent = new Intent(getApplicationContext(), Button3Activity.class);
                startActivityForResult(intent, REQUEST_CODE_RelativeLayout);
            }
        });

        button = findViewById(R.id.button4);
        button.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                Intent intent = new Intent(getApplicationContext(), Button4Activity.class);
                startActivityForResult(intent, REQUEST_CODE_TableLayout);
            }
        });

        button = findViewById(R.id.button5);
        button.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                Intent intent = new Intent(getApplicationContext(), Button5Activity.class);
                startActivityForResult(intent, REQUEST_CODE_GridLayout);
            }
        });
    }
}