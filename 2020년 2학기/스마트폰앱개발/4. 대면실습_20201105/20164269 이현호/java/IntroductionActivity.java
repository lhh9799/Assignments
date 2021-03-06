package com.example.myapplication20;

import androidx.appcompat.app.AppCompatActivity;
import androidx.fragment.app.Fragment;
import androidx.fragment.app.FragmentActivity;
import androidx.viewpager2.adapter.FragmentStateAdapter;
import androidx.viewpager2.widget.ViewPager2;

import android.os.Bundle;
import android.view.View;
import android.widget.Button;

import java.util.ArrayList;

public class IntroductionActivity extends AppCompatActivity {
    ViewPager2 viewpager;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_introduction);

        viewpager = findViewById(R.id.viewpager);
        viewpager.setOffscreenPageLimit(2);

        MyPageAdapter adapter = new MyPageAdapter(this);

        Introduction1 Introduction1 = new Introduction1();
        adapter.addItem(Introduction1);
        Introduction2 Introduction2 = new Introduction2();
        adapter.addItem(Introduction2);

        viewpager.setAdapter(adapter);

        Button button6 = findViewById(R.id.button6);
        button6.setOnClickListener(new View.OnClickListener() {
            public void onClick(View v) {
                finish();
            }
        });
    }

    private MyPageAdapter getAdapter(MyPageAdapter adapter) {
        return adapter;
    }

    class MyPageAdapter extends FragmentStateAdapter {
        ArrayList<Fragment> items = new ArrayList<Fragment>();

        public MyPageAdapter(FragmentActivity fm) {
            super(fm);
        }

        public void addItem(Fragment item) {
            items.add(item);
        }

        @Override
        public Fragment createFragment(int position) {
            return items.get(position);
        }

        @Override
        public int getItemCount() {
            return items.size();
        }
    }
}