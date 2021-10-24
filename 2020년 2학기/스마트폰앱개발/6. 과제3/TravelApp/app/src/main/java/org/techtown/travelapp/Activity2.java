package org.techtown.travelapp;

import androidx.appcompat.app.AppCompatActivity;

import android.content.Intent;
import android.graphics.Color;
import android.os.Bundle;
import android.view.View;
import android.widget.FrameLayout;
import android.widget.ImageButton;

public class Activity2 extends AppCompatActivity {
    public static final int REQUEST_CODE_COUNTRY = 101;

    Fragment4 Fragment4;
    Fragment30 Fragment30;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_2);

        Fragment4 = new Fragment4();
        Fragment30 = new Fragment30();

        //이미지 버튼21(Landmark)을 누른 경우 액티비티3(관광명소)으로 넘어감(국가 선택)
        ImageButton imageButton1 = findViewById(R.id.imageButton21);
        imageButton1.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                Intent intent = new Intent(getApplicationContext(),Activity3.class);
                startActivityForResult(intent, REQUEST_CODE_COUNTRY);
            }
        });

        //이미지 버튼22(Cafe)를 누른 경우 기존 액티비티의 FrameLayout을 하얀색(불투명)으로 바꾼 후 프래그먼트4(카페 소개 화면)로 이동
        ImageButton imageButton2 = findViewById(R.id.imageButton22);
        imageButton2.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                FrameLayout container1 = findViewById(R.id.container1);
                container1.setBackgroundColor(Color.WHITE);
                getSupportFragmentManager().beginTransaction().replace(R.id.container1, Fragment4).commit();
            }
        });

        //이미지 버튼23(Landmark_CardView)을 누른 경우 기존 액티비티의 FrameLayout을 하얀색(불투명)으로 바꾼 후 프래그먼트30(카드뷰)로 이동
        ImageButton imageButton3 = findViewById(R.id.imageButton23);
        imageButton3.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                FrameLayout container1 = findViewById(R.id.container1);
                container1.setBackgroundColor(Color.WHITE);
                getSupportFragmentManager().beginTransaction().replace(R.id.container1, Fragment30).commit();
            }
        });
    }
}