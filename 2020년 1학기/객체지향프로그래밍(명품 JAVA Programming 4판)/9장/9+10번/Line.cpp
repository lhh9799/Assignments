#include "Line.h"
#include "UI.h"

//생성자: 객체 멤버 초기화
Line::Line(const Point &p1, const Point &p2) {
	//함수 인자로 넘어 온 p1과 p2를 이 객체의 p1, p2에 저장
	this->p1 = p1;
	this->p2 = p2;
}

void Line::draw() {
	//화면에 라인의 좌표 값을 출력
	UI::println("Line " + p1.toString() + " " + p2.toString());
}

//기존 객체의 위치를 width, height만큼 옮긴다.
void Line::move(int width, int height) {
	//기존 p1의 위치를 width, height만큼 옮긴다.
	p1.move(width, height);
	//기존 p2의 위치를 width, height만큼 옮긴다.
	p2.move(width, height);
}
