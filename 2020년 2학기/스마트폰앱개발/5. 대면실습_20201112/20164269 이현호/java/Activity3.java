package com.example.myapplication5;

import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.ImageView;

public class Activity3 extends AppCompatActivity {
    ImageView imageView;

    @Override
    protected void onCreate(Bundle savedInstanceState) {

        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_3);

        Button button31 = findViewById(R.id.button31);
        button31.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                imageView = findViewById(R.id.imageView31);
                imageView.setImageResource(R.drawable.profile1);
            }
        });
        Button button32 = findViewById(R.id.button32);
        button32.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                imageView = findViewById(R.id.imageView31);
                imageView.setImageResource(R.drawable.profile2);
            }
        });
        Button button33 = findViewById(R.id.button33);
        button33.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                imageView = findViewById(R.id.imageView32);
                imageView.setImageResource(R.drawable.profile3);
            }
        });
        Button button34 = findViewById(R.id.button34);
        button34.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                imageView = findViewById(R.id.imageView32);
                imageView.setImageResource(R.drawable.profile4);
            }
        });
    }
}