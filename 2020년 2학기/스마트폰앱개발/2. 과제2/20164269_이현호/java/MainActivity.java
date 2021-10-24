package com.example.proposal;

import androidx.annotation.NonNull;
import androidx.appcompat.app.AppCompatActivity;

import android.content.Intent;
import android.net.Uri;
import android.os.Bundle;
import android.view.MenuItem;
import android.view.View;
import android.widget.Toast;

import com.google.android.material.bottomnavigation.BottomNavigationView;

public class MainActivity extends AppCompatActivity {

    fragment1 fragment1;
    fragment2 fragment2;
    fragment3 fragment3;
    fragment4 fragment4;

    public void onButton31Clicked(View v) {
        Intent myIntent = new Intent(Intent.ACTION_VIEW, Uri.parse("http://www.chosun.ac.kr/"));
        startActivity(myIntent);
    }

    public void onButton41Clicked(View v) {
        Intent myIntent = new Intent(Intent.ACTION_VIEW, Uri.parse("http://www.chosun.ac.kr/user/indexMain.do?siteId=ce"));
        startActivity(myIntent);
    }

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        fragment1 = new fragment1();
        fragment2 = new fragment2();
        fragment3 = new fragment3();
        fragment4 = new fragment4();

        getSupportFragmentManager().beginTransaction().replace(R.id.container, fragment1).commit();

        BottomNavigationView bottomNavigation = findViewById(R.id.bottom_navigation);
        bottomNavigation.setOnNavigationItemSelectedListener(
                new BottomNavigationView.OnNavigationItemSelectedListener() {
                    @Override
                    public boolean onNavigationItemSelected(@NonNull MenuItem item) {
                        switch (item.getItemId()) {
                            case R.id.tab1:
                                getSupportFragmentManager().beginTransaction().replace(R.id.container, fragment1).commit();

                                return true;
                            case R.id.tab2:
                                getSupportFragmentManager().beginTransaction().replace(R.id.container, fragment2).commit();

                                return true;
                            case R.id.tab3:
                                getSupportFragmentManager().beginTransaction().replace(R.id.container, fragment3).commit();

                                return true;
                            case R.id.tab4:
                                getSupportFragmentManager().beginTransaction().replace(R.id.container, fragment4).commit();

                                return true;
                        }

                        return false;
                    }
                }
        );
    }
}