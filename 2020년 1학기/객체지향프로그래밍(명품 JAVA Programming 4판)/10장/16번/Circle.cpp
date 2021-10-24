#include "Circle.h"
#include "UI.h"

Circle::Circle(int radius, const Point &center) {
	this->radius = radius;
	this->center = center;
}
void Circle::draw() {
	UI::println("Circle " + to_string(radius) + " " + center.toString());
}
void Circle::move(int width, int height) {
	center.move(width, height);
}
//기존 객체를 복사하고 위치를 이동한 후 복사된 객체의 포인터 리턴
Circle* Circle::copy(int width, int height) {
	//새로운 라인 객체를 생성하고 복사생성자 호출하여 기존 객체를 복사한다.
	Circle *circle = new Circle(*this);
	//복사된 객체를 width, height만큼 옮긴다.
	circle->move(width, height);
	//복사된 객체의 포인터를 리턴
	return circle;
}
