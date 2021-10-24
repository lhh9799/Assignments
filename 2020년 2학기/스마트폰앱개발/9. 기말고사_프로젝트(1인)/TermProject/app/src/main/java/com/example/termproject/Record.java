package com.example.termproject;

import android.app.Activity;
import android.database.Cursor;
import android.database.sqlite.SQLiteDatabase;
import android.os.Bundle;

import androidx.fragment.app.Fragment;

import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.Button;
import android.widget.EditText;
import android.widget.LinearLayout;
import android.widget.SearchView;
import android.widget.TextView;

import org.w3c.dom.Text;

import java.text.SimpleDateFormat;
import java.util.Date;

import static com.example.termproject.MapandRecordActivity.databaseName;

/**
 * A simple {@link Fragment} subclass.
 * Use the {@link Record#newInstance} factory method to
 * create an instance of this fragment.
 */
public class Record extends Fragment {
    EditText editText30, editText31;
    TextView textArea;
    LinearLayout WritingArea;
    DB MyDB;

    @Override
    public void onAttach(Activity activity) {
        super.onAttach(activity);
        MyDB = (DB) activity;
    }

    // TODO: Rename parameter arguments, choose names that match
    // the fragment initialization parameters, e.g. ARG_ITEM_NUMBER
    private static final String ARG_PARAM1 = "param1";
    private static final String ARG_PARAM2 = "param2";

    // TODO: Rename and change types of parameters
    private String mParam1;
    private String mParam2;

    public Record() {
        // Required empty public constructor
    }

    /**
     * Use this factory method to create a new instance of
     * this fragment using the provided parameters.
     *
     * @param param1 Parameter 1.
     * @param param2 Parameter 2.
     * @return A new instance of fragment Record.
     */
    // TODO: Rename and change types and number of parameters
    public static Record newInstance(String param1, String param2) {
        Record fragment = new Record();
        Bundle args = new Bundle();
        args.putString(ARG_PARAM1, param1);
        args.putString(ARG_PARAM2, param2);
        fragment.setArguments(args);
        return fragment;
    }

    @Override
    public void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
//        if (getArguments() != null) {
//            mParam1 = getArguments().getString(ARG_PARAM1);
//            mParam2 = getArguments().getString(ARG_PARAM2);
//        }
    }

    @Override
    public View onCreateView(LayoutInflater inflater, ViewGroup container,
                             Bundle savedInstanceState) {
        View v = (View) inflater.inflate(R.layout.fragment_record, container, false);

        editText30 = v.findViewById(R.id.editText30);
        editText31 = v.findViewById(R.id.editText31);
        textArea = v.findViewById(R.id.textArea);
        WritingArea = v.findViewById(R.id.WritingArea);

        MyDB.createTable(textArea); //표가 없다면 생성

        //버튼1 - 메모 리스트 조회
        Button button30 = v.findViewById(R.id.button30);
        button30.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                MyDB.showList(textArea);
            }
        });

        //버튼2 - 생성
        Button button31 = v.findViewById(R.id.button31);
        button31.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                //입력공간이 보이지 않는다면 입력공간을 보여줌
                if (WritingArea.getVisibility() == View.GONE) {
                    WritingArea.setVisibility(View.VISIBLE);
                }
                //입력공간이 보인다면 editText의 값을 가져와 테이블에 저장하고 입력공간을 보이지 않게 함
                else if (WritingArea.getVisibility() == View.VISIBLE) {
                    long now = System.currentTimeMillis();   //현재 시간을 가져옴
                    Date mDate = new Date(now); //Date 형식으로 고침
                    SimpleDateFormat simpleDate = new SimpleDateFormat("yyyy-MM-dd hh:mm:ss");  //가져오고 싶은 형태
                    String getTime = simpleDate.format(mDate);

                    MyDB.insertRecord(getTime, editText31.getText().toString(), textArea);
                    editText30.setText("");
                    editText31.setText("");  //editText 내용 초기화
                    WritingArea.setVisibility(View.GONE);
                }
            }
        });

        //버튼3 - 읽기
        Button button32 = v.findViewById(R.id.button32);
        button32.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                MyDB.executeQuery(editText30.getText().toString(), textArea);
            }
        });

        //버튼4 - 갱신
        Button button33 = v.findViewById(R.id.button33);
        button33.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                //editText가 공란인 경우
                if (editText30.getText().toString().equals("")) {
                    MyDB.println("메모번호 입력 바람", textArea);
                }
                //editText에 값이 있는 경우
                else {
                    //입력공간이 보이지 않는다면 입력공간을 보여줌
                    if (WritingArea.getVisibility() == View.GONE) {
                        WritingArea.setVisibility(View.VISIBLE);
                    }
                    //입력공간이 보인다면 editText의 값을 가져와 테이블에 갱신하고 입력공간을 보이지 않게 함
                    else if (WritingArea.getVisibility() == View.VISIBLE) {
                        long now = System.currentTimeMillis();   //현재 시간을 가져옴
                        Date mDate = new Date(now); //Date 형식으로 고침
                        SimpleDateFormat simpleDate = new SimpleDateFormat("yyyy-MM-dd hh:mm:ss");  //가져오고 싶은 형태
                        String getTime = simpleDate.format(mDate);

                        MyDB.executeUpdate(editText30.getText().toString(), getTime, editText31.getText().toString(), textArea);  //갱신 대상 메모 ID, 제목, 내용 전달
                        editText30.setText("");
                        editText31.setText("");  //editText 내용 초기화
                        WritingArea.setVisibility(View.GONE);
                    }
                }
            }
        });

        //버튼5 - 삭제
        Button button34 = v.findViewById(R.id.button34);
        button34.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                MyDB.executeDelete(editText30.getText().toString(), textArea);
            }
        });

        //버튼6 - 날림
        Button button35 = v.findViewById(R.id.button35);
        button35.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
//                getActivity().getApplicationContext().deleteDatabase(databaseName);
                MyDB.delete(textArea);
            }
        });

        // Inflate the layout for this fragment
        return v;
    }

//    //테이블 생성
//    private void createTable(String name, TextView textArea) {
//        println("createTable 호출됨.", textArea);
//        database.execSQL("create table if not exists " + name + "(" + " _id integer PRIMARY KEY autoincrement, " + " time text, " + " memo text)"); //테이블이 존재하지 않으면 생성
////        println("테이블 생성함 : " + name);
//    }
//
//    //데이터 삽입
//    @Override
//    private void insertRecord(String time, String memo, TextView textArea) {
//        println("insertRecord 호출됨.", textArea);
//
//        database.execSQL("insert into " + tableName + "(time, memo) " + " values ('" + time + "','" +  memo + "');");   //time과 memo에 배개변수로 받은 time과 memo를 저장
//
//        println("메모 추가함.", textArea);
//    }
//
//    //메모 ID와 제목을 보여줌
//    public void showList(TextView textArea) {
//        println("showList 호출됨.", textArea);
//
//        Cursor cursor = database.rawQuery("select _id, memo from " + tableName, null);
//        int recordCount = cursor.getCount();
//        println("메모 리스트 개수 : " + recordCount, textArea);
//
//        for (int i = 0; i < recordCount; i++) {
//            cursor.moveToNext();
//
//            int id = cursor.getInt(0);
//            String memo = cursor.getString(1);
//
//            println("메모 ID #" + id + " | " + "제목 " + memo, textArea);
//        }
//
//        cursor.close();
//    }
//
//    //메모 내용 보여줌
//    @Override
//    public void executeQuery(String target, TextView textArea) {
//        println("executeQuery 호출됨.");
//
//        Cursor cursor = database.rawQuery("select * from " +  tableName + " where " + "_id" + " = ?", new String[]{target});
//        /*if(cursor.getCount() == 1) {    //cursor.getCount가 1이면 _id가 일치하는 행(Row)이 있다는 뜻이다. _id는 기본키이므로 >=를 사용할 필요가 없다.
//        (Cursor는 null을 리턴하지 않는다. 따라서 cursor != null 은 의미없는 비교식이다.)
//        cursor.moveToFirst() : Cursor를_id가 일치하는 행 중 가장 첫 번째 행으로 이동시킨다. 일치하는 행이 있는 경우 true, 없는 경우 false 리턴
//        해당 식을 if문에 넣어 cursor를 첫 번째 행으로 이동시킴과 동시에 _id가 일치하는 행이 있는지 검사할 수 있다. 즉 한 줄을 아낄 수 있다.*/
//
//        if(cursor.moveToFirst()) {
//            int id = cursor.getInt(0);
//            String time = cursor.getString(1);
//            String memo = cursor.getString(2);
//
//            println("메모 ID #" + id + " | " + "제목 : " + memo + "\n내용 : " + memo, textArea);
//        }
//        else {
//            println("메모 ID #" + target + "없음", textArea);
//        }
//        cursor.close();
//    }
//
//    //메모 내용 갱신
//    @Override
//    public void executeUpdate(String target, String time, String memo, TextView textArea) {
//        println("executeUpdate 호출됨.", textArea);
//
//        Cursor cursor = database.rawQuery("select * from " +  tableName + " where " + "_id" + " = ?", new String[]{target});
//        //일치하는 결과가 있는 경우 갱신
//        if(cursor.moveToFirst()) {
//            database.execSQL("update " + tableName + " set memo = ?, memo = ? where "+ "_id" + " = " + target, new String[]{time, memo});
//            println("메모 업데이트됨", textArea);
//            cursor.close();
//        }
//        //일치하는 결과가 없는 경우
//        else {
//            println("메모#" + target + "없음", textArea);
//        }
//    }
//
//    //메모 내용 삭제
//    @Override
//    public void executeDelete(String target, TextView textArea) {  //작동하지 않으면 매개변수 자료형 int로 바꾸기
//        println("executeDelete 호출됨.", textArea);
//
//        Cursor cursor = database.rawQuery("select * from " +  tableName + " where " + "_id" + " = ?", new String[]{target});
//        //일치하는 결과가 있는 경우 삭제
//        if(cursor.moveToFirst()) {
//            database.execSQL("delete from " + tableName + " where "+ "_id" + "=" + target);
//            println("메모 삭제됨", textArea);
//        }
//        //일치하는 결과가 없는 경우
//        else {
//            println("메모#" + target + "없음", textArea);
//        }
//    }
//
//    //textView에 로그 출력
//    public void println(String data, TextView textArea) {
//        textArea.append(data + "\n");
//    }
}