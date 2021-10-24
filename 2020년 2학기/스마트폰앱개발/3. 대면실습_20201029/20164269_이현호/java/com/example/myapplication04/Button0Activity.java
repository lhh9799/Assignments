package com.example.myapplication04;

import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;
import android.view.View;
import android.widget.ImageView;

public class Button0Activity extends AppCompatActivity {
    ImageView imageView1;
    ImageView imageView2;

    int imageIndex = 0;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_button0);

        imageView1 = findViewById(R.id.imageView1);
        imageView2 = findViewById(R.id.imageView2);
    }

    public void onButtonClicked(View V) {
        changeImage();
    }

    private void changeImage() {
        if(imageIndex == 0) {
            imageView1.setVisibility(View.VISIBLE);
            imageView2.setVisibility(View.INVISIBLE);

            imageIndex = 1;
        }
        else if(imageIndex == 1) {
            imageView1.setVisibility(View.INVISIBLE);
            imageView2.setVisibility(View.VISIBLE);

            imageIndex = 0;
        }
    }
}