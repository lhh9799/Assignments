#include "Rect.h"
#include "UI.h"

Rect::Rect(const Point &p1, const Point &p2) {
	//함수 인자로 넘어 온 p1과 p2를 이 객체의 p1, p2에 저장
	this->p1 = p1;
	this->p2 = p2;
}

void Rect::draw() {
	UI::println("Rectangle " + p1.toString() + " " + p2.toString());
}

void Rect::move(int width, int height) {
	p1.move(width, height);
	p2.move(width, height);
}
//기존 객체를 복사하고 위치를 이동한 후 복사된 객체의 포인터 리턴
Rect* Rect::copy(int width, int height) {
	//새로운 라인 객체를 생성하고 복사생성자 호출하여 기존 객체를 복사한다.
	Rect *rect = new Rect(*this);
	//복사된 객체를 width, height만큼 옮긴다.
	rect->move(width, height);
	//복사된 객체의 포인터를 리턴
	return rect;
}
