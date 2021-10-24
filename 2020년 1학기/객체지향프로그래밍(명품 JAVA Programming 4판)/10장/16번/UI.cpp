#include <iostream>
#include "UI.h"
using namespace std;

int UI::printGetInt(string msg) {	//msg 문자열 출력 후 정수 값 하나 읽어 리턴
	cout << msg;					//문자열 msg 출력
	int value;						//임의의 정수형 변수 하나를 선언
	cin >> value;	//키보드에서 정수 값 하나 읽어 변수에 저장
	return value;	//변수 값 리턴
}

void UI::println(string msg) {
	cout << msg << endl;	//문자열 msg와 줄바꾸기를 출력
}

void UI::print(string msg) {
	cout << msg;			//문자열 msg 출력
}
//메인 메뉴 종류 출력하고 메인 메뉴 값 입력 받아 리턴
int UI::getMainMenu() {
	return printGetInt("종료:0, 모두보기:1, 자동삽입:2, 모두이동:3, 모두삭제:4, 모두복사:5 >> ");
}
//삽입할 도형 종류 출력하고 종류 값 입력 받아 리턴
void UI::getWidthHeight(int &width, int &height) {
	cout << "X축과 Y축으로 이동할 양은(정수 두개 입력)? >> ";
	cin >> width >> height;
}
