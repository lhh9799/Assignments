package com.example.notepad;

import androidx.appcompat.app.AppCompatActivity;

import android.database.Cursor;
import android.database.sqlite.SQLiteDatabase;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.LinearLayout;
import android.widget.TextView;

public class MainActivity extends AppCompatActivity {
    public static final String databaseName = "MemoDB";
    public static final String tableName = "MemoTable";

    SQLiteDatabase database;
    EditText editText0, editText1, editText2;
    TextView textView3;
    LinearLayout WritingArea;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        editText0 = findViewById(R.id.editText0);
        editText1 = findViewById(R.id.editText1);
        editText2 = findViewById(R.id.editText2);
        textView3 = findViewById(R.id.textView3);
        WritingArea = findViewById(R.id.WritingArea);
        WritingArea.setVisibility(View.GONE);

        //버튼1 - 메모 리스트 조회
        Button button1 = findViewById(R.id.button1);
        button1.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                try {
                    if (database == null) {
                        println("데이터베이스 없음");
                        return;
                    }
                    else {
                        showList();
                    }
                } catch (Exception e) {
                    e.printStackTrace();
                }
            }
        });

        //버튼2 - 생성
        Button button2 = findViewById(R.id.button2);
        button2.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                //데이터베이스가 없다면 데이터베이스와 테이블을 생성한다
                if (database == null) {
                    println("데이터베이스 없음");
                    createDatabase(databaseName);   //데이터베이스 생성
                    createTable(tableName);         //테이블 생성
                }
                //입력공간이 보이지 않는다면 입력공간을 보여줌
                if(WritingArea.getVisibility() == View.GONE) {
                    WritingArea.setVisibility(View.VISIBLE);
                }
                //입력공간이 보인다면 editText의 값을 가져와 테이블에 저장하고 입력공간을 보이지 않게 함
                else if(WritingArea.getVisibility() == View.VISIBLE) {
                    insertRecord(editText1.getText().toString(), editText2.getText().toString());
                    editText1.setText("");  editText2.setText("");  //editText 내용 초기화
                    WritingArea.setVisibility(View.GONE);
                }
            }
        });

        //버튼3 - 읽기
        Button button3 = findViewById(R.id.button3);
        button3.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                executeQuery(editText0.getText().toString());
            }
        });

        //버튼4 - 갱신
        Button button4 = findViewById(R.id.button4);
        button4.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                //editText가 공란인 경우
                if(editText0.getText().toString().equals("")) {
                    println("메모번호 입력 바람");
                }
                //editText에 값이 있는 경우
                else {
                    //입력공간이 보이지 않는다면 입력공간을 보여줌
                    if (WritingArea.getVisibility() == View.GONE) {
                        WritingArea.setVisibility(View.VISIBLE);
                    }
                    //입력공간이 보인다면 editText의 값을 가져와 테이블에 갱신하고 입력공간을 보이지 않게 함
                    else if(WritingArea.getVisibility() == View.VISIBLE) {
                        executeUpdate(editText0.getText().toString(), editText1.getText().toString(), editText2.getText().toString());  //갱신 대상 메모 ID, 제목, 내용 전달
                        editText1.setText("");  editText2.setText("");  //editText 내용 초기화
                        WritingArea.setVisibility(View.GONE);
                    }
                }
            }
        });

        //버튼5 - 삭제
        Button button5 = findViewById(R.id.button5);
        button5.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                executeDelete(editText0.getText().toString());
            }
        });

        //버튼6 - 날림
        Button button6 = findViewById(R.id.button6);
        button6.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                getApplicationContext().deleteDatabase(databaseName);
                println("데이터베이스 삭제함.");
            }
        });
    }

    //데이터베이스 생성
    private void createDatabase(String name) {
        println("createDatabase 호출됨.");

        database = openOrCreateDatabase(name, MODE_PRIVATE, null);  //데이터베이스를 열거나 생성

        println("데이터베이스 생성함 : " + name);
    }

    //테이블 생성
    private void createTable(String name) {
        println("createTable 호출됨.");
        database.execSQL("create table if not exists " + name + "(" + " _id integer PRIMARY KEY autoincrement, " + " title text, " + " content text)"); //테이블이 존재하지 않으면 생성
        println("테이블 생성함 : " + name);
    }

    //데이터 삽입
    private void insertRecord(String title, String content) {
        println("insertRecord 호출됨.");

        database.execSQL("insert into " + tableName + "(title, content) " + " values ('" + title + "','" +  content + "');");   //title과 content에 배개변수로 받은 title과 content를 저장

        println("메모 추가함.");
    }

    //메모 ID와 제목을 보여줌
    public void showList() {
        println("showList 호출됨.");

        Cursor cursor = database.rawQuery("select _id, title from " + tableName, null);
        int recordCount = cursor.getCount();
        println("메모 리스트 개수 : " + recordCount);

        for (int i = 0; i < recordCount; i++) {
            cursor.moveToNext();

            int id = cursor.getInt(0);
            String title = cursor.getString(1);

            println("메모 ID #" + id + " | " + "제목 " + title);
        }

        cursor.close();
    }

    //메모 내용 보여줌
    public void executeQuery(String target) {
        println("executeQuery 호출됨.");

        Cursor cursor = database.rawQuery("select * from " +  tableName + " where " + "_id" + " = ?", new String[]{target});
        /*if(cursor.getCount() == 1) {    //cursor.getCount가 1이면 _id가 일치하는 행(Row)이 있다는 뜻이다. _id는 기본키이므로 >=를 사용할 필요가 없다.
        (Cursor는 null을 리턴하지 않는다. 따라서 cursor != null 은 의미없는 비교식이다.)
        cursor.moveToFirst() : Cursor를_id가 일치하는 행 중 가장 첫 번째 행으로 이동시킨다. 일치하는 행이 있는 경우 true, 없는 경우 false 리턴
        해당 식을 if문에 넣어 cursor를 첫 번째 행으로 이동시킴과 동시에 _id가 일치하는 행이 있는지 검사할 수 있다. 즉 한 줄을 아낄 수 있다.*/
        
        if(cursor.moveToFirst()) {
            int id = cursor.getInt(0);
            String title = cursor.getString(1);
            String content = cursor.getString(2);

            println("메모 ID #" + id + " | " + "제목 : " + title + "\n내용 : " + content);
        }
        else {
            println("메모 ID #" + target + "없음");
        }
        cursor.close();
    }

    //메모 내용 갱신
    public void executeUpdate(String target, String title, String content) {
        println("executeUpdate 호출됨.");

        Cursor cursor = database.rawQuery("select * from " +  tableName + " where " + "_id" + " = ?", new String[]{target});
        //일치하는 결과가 있는 경우 갱신
        if(cursor.moveToFirst()) {
            database.execSQL("update " + tableName + " set title = ?, content = ? where "+ "_id" + " = " + target, new String[]{title, content});
            println("메모 업데이트됨");
            cursor.close();
        }
        //일치하는 결과가 없는 경우
        else {
            println("메모#" + target + "없음");
        }
    }

    //메모 내용 삭제
    public void executeDelete(String target) {  //작동하지 않으면 매개변수 자료형 int로 바꾸기
        println("executeDelete 호출됨.");

        Cursor cursor = database.rawQuery("select * from " +  tableName + " where " + "_id" + " = ?", new String[]{target});
        //일치하는 결과가 있는 경우 삭제
        if(cursor.moveToFirst()) {
            database.execSQL("delete from " + tableName + " where "+ "_id" + "=" + target);
            println("메모 삭제됨");
        }
        //일치하는 결과가 없는 경우
        else {
            println("메모#" + target + "없음");
        }
    }

    //textView에 로그 출력
    public void println(String data) {
        textView3.append(data + "\n");
    }
}