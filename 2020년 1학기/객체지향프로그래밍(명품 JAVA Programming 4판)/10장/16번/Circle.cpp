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
//���� ��ü�� �����ϰ� ��ġ�� �̵��� �� ����� ��ü�� ������ ����
Circle* Circle::copy(int width, int height) {
	//���ο� ���� ��ü�� �����ϰ� ��������� ȣ���Ͽ� ���� ��ü�� �����Ѵ�.
	Circle *circle = new Circle(*this);
	//����� ��ü�� width, height��ŭ �ű��.
	circle->move(width, height);
	//����� ��ü�� �����͸� ����
	return circle;
}
