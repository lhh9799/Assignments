#include "Point.h"

//객체 초기화: x, y 좌표 초기화
Point::Point(int x, int y) {
	//함수 인자인 x, y를 이 객체의 x, y 멤버에 저장
	this->x = x;
	this->y = y;
}

//x, y 좌표를 각각 width, height만큼 이동시킨다.
void Point::move(int width, int height) {
	//이 객체의 x, y 멤버에 각각 width, height를 더하여 좌표를 이동함
	this->x += width;
	this->y += height;
}

//(x, y)좌표를 문자열로 변환하여 리턴
string Point::toString() {
	return "(" + to_string(x) + "," + to_string(y) + ")";
}
