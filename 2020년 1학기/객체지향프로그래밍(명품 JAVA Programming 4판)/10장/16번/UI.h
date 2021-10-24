#ifndef UI_H_
#define UI_H_

#include <string>
using namespace std;

class UI {
public:
	static void println(string msg);	//msg 문자열 및 줄 바꾸기 출력
	static void print(string msg);		//msg 문자열 출력
	static int printGetInt(string msg);	//msg 문자열 출력 후 정수 하나 읽어 리턴
	static int getMainMenu();			//메인 메뉴 종류 출력하고 메인 메뉴 값 입력 받아 리턴
	//사용자로부터 x, y축으로 이동할 량 width와 height값을 입력 받음
	static void getWidthHeight(int &width, int &height);//정수 두 개 입력 받음
};

#endif /* UI_H_ */
