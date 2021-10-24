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
