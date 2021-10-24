package org.techtown.travelapp;

import androidx.appcompat.app.AppCompatActivity;
import androidx.fragment.app.FragmentManager;

import android.graphics.Color;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.FrameLayout;

public class Activity3 extends AppCompatActivity {
    Fragment1 Fragment1;
    Fragment2 Fragment2;
    Fragment3 Fragment3;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_3);

        Fragment1 = new Fragment1();
        Fragment2 = new Fragment2();
        Fragment3 = new Fragment3();

        Button Button31 = findViewById(R.id.button31);
        Button31.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                FrameLayout container = findViewById(R.id.container);
                container.setBackgroundColor(Color.WHITE);
                getSupportFragmentManager().beginTransaction().replace(R.id.container, Fragment1).commit();
            }
        });

        Button Button32 = findViewById(R.id.button32);
        Button32.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                FrameLayout container = findViewById(R.id.container);
                container.setBackgroundColor(Color.WHITE);
                getSupportFragmentManager().beginTransaction().replace(R.id.container, Fragment2).commit();
            }
        });

        Button Button33 = findViewById(R.id.button33);
        Button33.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                FrameLayout container = findViewById(R.id.container);
                container.setBackgroundColor(Color.WHITE);
                getSupportFragmentManager().beginTransaction().replace(R.id.container, Fragment3).commit();
            }
        });
    }
}