package com.example.myapplication5;

import android.os.Bundle;
import android.view.View;
import android.widget.Button;

import androidx.appcompat.app.AppCompatActivity;

public class Activity2 extends AppCompatActivity {
    Layout1 layout1, layout2;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_2);

        layout1 = findViewById(R.id.layout3);
        layout1.setImage(R.drawable.profile1);
        layout1.setName("이름");
        layout1.setMobile("전화번호");

        layout2 = findViewById(R.id.layout4);
        layout2.setImage(R.drawable.profile2);
        layout2.setName("이현호");
        layout2.setMobile("010-1111-2222");

        Button button21 = findViewById(R.id.button21);
        button21.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                layout1.setImage(R.drawable.profile1);
            }
        });

        Button button22 = findViewById(R.id.button22);
        button22.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                layout1.setImage(R.drawable.profile2);
            }
        });

        Button button23 = findViewById(R.id.button23);
        button23.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                layout2.setImage(R.drawable.profile3);
            }
        });

        Button button24 = findViewById(R.id.button24);
        button24.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                layout2.setImage(R.drawable.profile4);
            }
        });
    }
}
