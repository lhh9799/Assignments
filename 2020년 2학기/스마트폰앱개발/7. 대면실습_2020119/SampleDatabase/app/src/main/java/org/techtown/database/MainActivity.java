package org.techtown.database;

import android.database.Cursor;
import android.database.sqlite.SQLiteDatabase;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.TextView;

import androidx.appcompat.app.AppCompatActivity;

public class MainActivity extends AppCompatActivity {
    EditText editText;
    EditText editText2;
    TextView textView;

    SQLiteDatabase database;

    String tableName;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        editText = findViewById(R.id.editText);
        editText2 = findViewById(R.id.editText2);
        textView = findViewById(R.id.textView);

        Button button = findViewById(R.id.button);
        button.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                String databaseName = editText.getText().toString();
                createDatabase(databaseName);
            }
        });

        Button button2 = findViewById(R.id.button2);
        button2.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                tableName = editText2.getText().toString();
                createTable(tableName);

                //insertRecord();
            }
        });

        Button button3 = findViewById(R.id.button3);
        button3.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
//                tableName = editText2.getText().toString();
//                createTable(tableName);

                insertRecord();
            }
        });

        Button button4 = findViewById(R.id.button4);
        button4.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
//                tableName = editText2.getText().toString();
//                createTable(tableName);
//
//                insertRecord();
                executeQuery();
            }
        });

        Button button5 = findViewById(R.id.button5);
        button5.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
//                tableName = editText2.getText().toString();
//                createTable(tableName);
//
//                insertRecord();
//                executeQuery();
                deleteTable();
            }
        });
    }


    public void executeQuery() {
        println("executeQuery ?????????.");

        Cursor cursor = database.rawQuery("select _id, name, age, mobile from emp", null);
        int recordCount = cursor.getCount();
        println("????????? ?????? : " + recordCount);

        for (int i = 0; i < recordCount; i++) {
            cursor.moveToNext();

            int id = cursor.getInt(0);
            String name = cursor.getString(1);
            int age = cursor.getInt(2);
            String mobile = cursor.getString(3);

            println("????????? #" + i + " : " + id + ", " + name + ", " + age + ", " + mobile);
        }

        cursor.close();
    }

    private void createDatabase(String name) {
        println("createDatabase ?????????.");

        database = openOrCreateDatabase(name, MODE_PRIVATE, null);

        println("?????????????????? ????????? : " + name);
    }

    private void createTable(String name) {
        println("createTable ?????????.");

        if (database == null) {
            println("????????????????????? ?????? ???????????????.");
            return;
        }

        database.execSQL("create table if not exists " + name + "("
            + " _id integer PRIMARY KEY autoincrement, "
            + " name text, "
            + " age integer, "
            + " mobile text)");

        println("????????? ????????? : " + name);
    }

    private void insertRecord() {
        println("insertRecord ?????????.");

        if (database == null) {
            println("????????????????????? ?????? ???????????????.");
            return;
        }

        if (tableName == null) {
            println("???????????? ?????? ???????????????.");
            return;
        }

        database.execSQL("insert into " + tableName
                        + "(name, age, mobile) "
                        + " values "
                        + "('John', 20, '010-1000-1000')");

        println("????????? ?????????.");
    }

    private void deleteTable() {
        println("deleteRecord ?????????.");

        if (database == null) {
            println("????????? ????????????????????? ????????????.");
            return;
        }

        if (tableName == null) {
            println("????????? ???????????? ????????????.");
            return;
        }

        database.execSQL("DELETE FROM " + tableName);

//        database.execSQL("insert into " + tableName
//                + "(name, age, mobile) "
//                + " values "
//                + "('John', 20, '010-1000-1000')");

        println("????????? ?????????.");
    }

    public void println(String data) {
        textView.append(data + "\n");
    }

}
