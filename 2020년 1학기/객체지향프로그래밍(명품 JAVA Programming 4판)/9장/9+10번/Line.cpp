#include "Line.h"
#include "UI.h"

//������: ��ü ��� �ʱ�ȭ
Line::Line(const Point &p1, const Point &p2) {
	//�Լ� ���ڷ� �Ѿ� �� p1�� p2�� �� ��ü�� p1, p2�� ����
	this->p1 = p1;
	this->p2 = p2;
}

void Line::draw() {
	//ȭ�鿡 ������ ��ǥ ���� ���
	UI::println("Line " + p1.toString() + " " + p2.toString());
}

//���� ��ü�� ��ġ�� width, height��ŭ �ű��.
void Line::move(int width, int height) {
	//���� p1�� ��ġ�� width, height��ŭ �ű��.
	p1.move(width, height);
	//���� p2�� ��ġ�� width, height��ŭ �ű��.
	p2.move(width, height);
}
