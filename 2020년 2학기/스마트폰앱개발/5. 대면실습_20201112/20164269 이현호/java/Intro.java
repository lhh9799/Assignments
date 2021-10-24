package com.example.myapplication5;

import androidx.appcompat.app.AppCompatActivity;

import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;

public class Intro extends AppCompatActivity {
    public static final int REQUEST_CODE_NO1 = 101;
    public static final int REQUEST_CODE_NO2 = 102;
    public static final int REQUEST_CODE_NO3 = 103;
    public static final int REQUEST_CODE_NO4 = 104;
    public static final int REQUEST_CODE_NO5 = 105;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_intro);

        Button button1 = findViewById(R.id.button1);
        button1.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                Intent intent = new Intent(getApplicationContext(), Activity1.class);
                startActivityForResult(intent, REQUEST_CODE_NO1);
            }
        });

        Button button2 = findViewById(R.id.button2);
        button2.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                Intent intent = new Intent(getApplicationContext(), Activity2.class);
                startActivityForResult(intent, REQUEST_CODE_NO2);
            }
        });

        Button button3 = findViewById(R.id.button3);
        button3.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                Intent intent = new Intent(getApplicationContext(), Activity3.class);
                startActivityForResult(intent, REQUEST_CODE_NO3);
            }
        });

        Button button4 = findViewById(R.id.button4);
        button4.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                Intent intent = new Intent(getApplicationContext(), Activity4.class);
                startActivityForResult(intent, REQUEST_CODE_NO4);
            }
        });

        Button button5 = findViewById(R.id.button5);
        button5.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                Intent intent = new Intent(getApplicationContext(), Activity5.class);
                startActivityForResult(intent, REQUEST_CODE_NO5);
            }
        });
    }
}