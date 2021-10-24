#include "Point.h"

//��ü �ʱ�ȭ: x, y ��ǥ �ʱ�ȭ
Point::Point(int x, int y) {
	//�Լ� ������ x, y�� �� ��ü�� x, y ����� ����
	this->x = x;
	this->y = y;
}

//x, y ��ǥ�� ���� width, height��ŭ �̵���Ų��.
void Point::move(int width, int height) {
	//�� ��ü�� x, y ����� ���� width, height�� ���Ͽ� ��ǥ�� �̵���
	this->x += width;
	this->y += height;
}

//(x, y)��ǥ�� ���ڿ��� ��ȯ�Ͽ� ����
string Point::toString() {
	return "(" + to_string(x) + "," + to_string(y) + ")";
}
