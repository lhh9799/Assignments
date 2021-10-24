package com.example.myapplication5;

import android.os.Bundle;
import android.view.View;
import android.widget.Button;

import androidx.appcompat.app.AppCompatActivity;

public class Activity1 extends AppCompatActivity {
    Layout1 layout1, layout2;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_1);

        layout1 = findViewById(R.id.layout1);
        layout1.setImage(R.drawable.profile1);

        layout2 = findViewById(R.id.layout2);
        layout2.setImage(R.drawable.profile2);
        layout2.setName("이현호");
        layout2.setMobile("010-1111-2222");
    }
}
