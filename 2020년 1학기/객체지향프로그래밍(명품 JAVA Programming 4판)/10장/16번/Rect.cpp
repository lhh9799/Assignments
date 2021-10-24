#include "Rect.h"
#include "UI.h"

Rect::Rect(const Point &p1, const Point &p2) {
	//�Լ� ���ڷ� �Ѿ� �� p1�� p2�� �� ��ü�� p1, p2�� ����
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
//���� ��ü�� �����ϰ� ��ġ�� �̵��� �� ����� ��ü�� ������ ����
Rect* Rect::copy(int width, int height) {
	//���ο� ���� ��ü�� �����ϰ� ��������� ȣ���Ͽ� ���� ��ü�� �����Ѵ�.
	Rect *rect = new Rect(*this);
	//����� ��ü�� width, height��ŭ �ű��.
	rect->move(width, height);
	//����� ��ü�� �����͸� ����
	return rect;
}
