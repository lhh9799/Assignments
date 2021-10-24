package com.example.termproject;

import androidx.appcompat.app.AppCompatActivity;
import androidx.fragment.app.Fragment;
import androidx.fragment.app.FragmentActivity;
import androidx.viewpager2.adapter.FragmentStateAdapter;
import androidx.viewpager2.widget.ViewPager2;

import android.database.Cursor;
import android.database.sqlite.SQLiteDatabase;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.TextView;

import org.w3c.dom.Text;

import java.util.ArrayList;

public class MapandRecordActivity extends AppCompatActivity implements DB {
    public static final String databaseName = "DB";
    public static final String tableName = "recordTable";

    ViewPager2 viewpager;
    SQLiteDatabase database;


    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_mapandrecord);

        database = openOrCreateDatabase("DB", MODE_PRIVATE, null);  //데이터베이스를 열거나 생성

        viewpager = findViewById(R.id.viewpager);
//        viewpager.setOffscreenPageLimit(2);
        viewpager.setOffscreenPageLimit(1);

        MyPageAdapter adapter = new MyPageAdapter(this);

        Record record = new Record();
        adapter.addItem(record);
//        Map map = new Map();
//        adapter.addItem(map);

        viewpager.setAdapter(adapter);

        Button button2 = findViewById(R.id.button31);
        button2.setOnClickListener(new View.OnClickListener() {
            public void onClick(View v) {
                //고정 + 고정해제
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

    //메모 ID와 제목을 보여줌
    @Override
    public void showList(TextView textArea) {
        println("showList 호출됨.", textArea);

        Cursor cursor = database.rawQuery("select _id, time from " + tableName, null);
        int recordCount = cursor.getCount();
        println("메모 리스트 개수 : " + recordCount, textArea);

        for (int i = 0; i < recordCount; i++) {
            cursor.moveToNext();

            int id = cursor.getInt(0);
            String time = cursor.getString(1);

            println("메모 ID #" + id + " | " + "내용 " + time, textArea);
        }

        cursor.close();
    }

    //테이블 생성
    public void createTable(TextView textArea) {
//        println("createTable 호출됨.", textArea);
        database.execSQL("create table if not exists " + tableName + "(" + " _id integer PRIMARY KEY autoincrement, " + " time text, " + " memo text)"); //테이블이 존재하지 않으면 생성
//        println("테이블 생성함 : " + tableName, textArea);
    }

    //데이터 삽입
    @Override
    public void insertRecord(String time, String memo, TextView textArea) {
        println("insertRecord 호출됨.", textArea);

        database.execSQL("insert into " + tableName + "(time, memo) " + " values ('" + time + "','" +  memo + "');");   //time과 memo에 배개변수로 받은 time과 memo를 저장

        println("메모 추가함.", textArea);
    }

    //메모 내용 보여줌
    @Override
    public void executeQuery(String target, TextView textArea) {
        println("executeQuery 호출됨.", textArea);

        Cursor cursor = database.rawQuery("select * from " +  tableName + " where " + "_id" + " = ?", new String[]{target});
        /*if(cursor.getCount() == 1) {    //cursor.getCount가 1이면 _id가 일치하는 행(Row)이 있다는 뜻이다. _id는 기본키이므로 >=를 사용할 필요가 없다.
        (Cursor는 null을 리턴하지 않는다. 따라서 cursor != null 은 의미없는 비교식이다.)
        cursor.moveToFirst() : Cursor를_id가 일치하는 행 중 가장 첫 번째 행으로 이동시킨다. 일치하는 행이 있는 경우 true, 없는 경우 false 리턴
        해당 식을 if문에 넣어 cursor를 첫 번째 행으로 이동시킴과 동시에 _id가 일치하는 행이 있는지 검사할 수 있다. 즉 한 줄을 아낄 수 있다.*/

        if(cursor.moveToFirst()) {
            int id = cursor.getInt(0);
            String time = cursor.getString(1);
            String memo = cursor.getString(2);

            println("메모 ID #" + id + " | " + "시간 : " + time + "\n내용 : " + memo, textArea);
        }
        else {
            println("메모 ID #" + target + "없음", textArea);
        }
        cursor.close();
    }

    //메모 내용 갱신
    @Override
    public void executeUpdate(String target, String time, String memo, TextView textArea) {
        println("executeUpdate 호출됨.", textArea);

        Cursor cursor = database.rawQuery("select * from " +  tableName + " where " + "_id" + " = ?", new String[]{target});
        //일치하는 결과가 있는 경우 갱신
        if(cursor.moveToFirst()) {
            database.execSQL("update " + tableName + " set memo = ?, memo = ? where "+ "_id" + " = " + target, new String[]{time, memo});
            println("메모 업데이트됨", textArea);
            cursor.close();
        }
        //일치하는 결과가 없는 경우
        else {
            println("메모#" + target + "없음", textArea);
        }
    }

    //메모 내용 삭제
    @Override
    public void executeDelete(String target, TextView textArea) {  //작동하지 않으면 매개변수 자료형 int로 바꾸기
        println("executeDelete 호출됨.", textArea);

        Cursor cursor = database.rawQuery("select * from " +  tableName + " where " + "_id" + " = ?", new String[]{target});
        //일치하는 결과가 있는 경우 삭제
        if(cursor.moveToFirst()) {
            database.execSQL("delete from " + tableName + " where "+ "_id" + "=" + target);
            println("메모 삭제됨", textArea);
        }
        //일치하는 결과가 없는 경우
        else {
            println("메모#" + target + "없음", textArea);
        }
    }

    @Override
    public void delete(TextView textArea) {
        getApplicationContext().deleteDatabase(databaseName);
        println("데이터베이스 삭제함.", textArea);
    }

    @Override
    public void doesDBexist(TextView textArea) {
        if (database == null) {
            println("데이터베이스 없음", textArea);
        }
    }

    //textView에 로그 출력
    public void println(String data, TextView textArea) {
        textArea.append(data + "\n");
    }
}