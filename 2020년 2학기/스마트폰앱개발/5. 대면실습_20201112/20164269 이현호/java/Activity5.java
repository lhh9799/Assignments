package com.example.myapplication5;

import android.os.Bundle;
import android.view.View;
import android.widget.Toast;

import androidx.appcompat.app.AppCompatActivity;
import androidx.recyclerview.widget.GridLayoutManager;
import androidx.recyclerview.widget.RecyclerView;

public class Activity5 extends AppCompatActivity {
    RecyclerView recyclerView;
    PersonAdapter adapter;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_5);

        recyclerView = findViewById(R.id.recyclerView);

        GridLayoutManager layoutManager = new GridLayoutManager(this, 4);
        recyclerView.setLayoutManager(layoutManager);


        adapter = new PersonAdapter();

        adapter.addItem(new Person("홍길동", "010-1000-1000"));
        adapter.addItem(new Person("홍길순", "010-2000-2000"));
        adapter.addItem(new Person("조 바이든", "010-3000-3000"));
        adapter.addItem(new Person("존 스미스", "010-4000-4000"));
        adapter.addItem(new Person("이름", "010-4000-4000"));
        adapter.addItem(new Person("이름", "010-4000-4000"));
        adapter.addItem(new Person("이름", "010-4000-4000"));
        adapter.addItem(new Person("이름", "010-4000-4000"));
        adapter.addItem(new Person("이름", "010-4000-4000"));
        adapter.addItem(new Person("이름", "010-4000-4000"));
        adapter.addItem(new Person("이름", "010-4000-4000"));
        adapter.addItem(new Person("이름", "010-4000-4000"));
        adapter.addItem(new Person("이름", "010-4000-4000"));

        recyclerView.setAdapter(adapter);

        adapter.setOnItemClickListener(new OnPersonItemClickListener() {
            @Override
            public void onItemClick(PersonAdapter.ViewHolder holder, View view, int position) {
                Person item = adapter.getItem(position);

                Toast.makeText(getApplicationContext(), "아이템 선택됨 : " + item.getName(), Toast.LENGTH_LONG).show();
            }
        });

    }
}
