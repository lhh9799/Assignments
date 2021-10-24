package com.example.myapplication20;

import androidx.appcompat.app.AppCompatActivity;

import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;

public class Intro extends AppCompatActivity {
    public static final int REQUEST_CODE_FRAGMENT = 101;
    public static final int REQUEST_CODE_INTRODUCTION = 102;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_intro);

        Button button = findViewById(R.id.button00);
        button.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                Intent intent = new Intent(getApplicationContext(), MainActivity.class);

                startActivityForResult(intent, REQUEST_CODE_FRAGMENT);
            }
        });

        button = findViewById(R.id.button01);
        button.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                Intent intent = new Intent(getApplicationContext(), IntroductionActivity.class);

                startActivityForResult(intent, REQUEST_CODE_INTRODUCTION);
            }
        });
    }
}