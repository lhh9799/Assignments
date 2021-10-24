package com.example.termproject;

import android.widget.TextView;

public interface DB {
    public void showList(TextView textArea);    //조회
    public void insertRecord(String time, String memo, TextView textArea); //쓰기
    public void executeQuery(String target, TextView textArea); //읽기
    public void executeUpdate(String target, String time, String memo, TextView textArea); //갱신
    public void executeDelete(String target, TextView textArea); //삭제
    public void delete(TextView textArea);       //날림
    public void doesDBexist(TextView textArea);  //DB가 존재하는지 확인
    public void createTable(TextView textArea);    //테이블 생성
    public void println(String data, TextView textArea);    //textArea에 출력
}
