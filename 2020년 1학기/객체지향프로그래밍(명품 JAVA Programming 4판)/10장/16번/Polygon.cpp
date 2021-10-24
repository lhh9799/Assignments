#include "Polygon.h"
#include "UI.h"

//�� �Լ��� �����ڿ� ���� �����ڿ��� ȣ���
void Polygon::copyPoints(int size, Point *points) {
	this->size = size;//�Լ� ���� size�� �� �ٰ����� size ����� ����
	this->points = new Point[size];//size���� Point ��ü�� ���� �Ҵ��Ͽ� �� �ٰ����� points ����� ����
	for(int i=0; i<size; i++)
		this->points[i] = points[i];//�Լ� ���� points[i] ��ü�� �� �ٰ����� points[i] ��ü�� ����
}
//������: ��� �ʱ�ȭ
Polygon::Polygon(int size, Point points[]) {
	copyPoints(size, points);//�� copyPoints() �Լ� ȣ���Ͽ� ��� �ʱ�ȭ
}
//�Ҹ���: �������� �Ҵ� ���� ����� �޸� �ݳ�
Polygon::~Polygon() {
	delete [] points;//�������� �Ҵ� ���� points �迭 �޸� �ݳ�
}
//���� ������: c.points[]�� ���� ���� �޸� �Ҵ��� �� c�� ����
Polygon::Polygon(const Polygon &c) {
	copyPoints(c.size, c.points);//�� copyPoints() �Լ� ȣ���Ͽ� ��� �ʱ�ȭ
}
//ȭ�鿡 �ٰ����� ���� ������ ������ ��ǥ ���� ���
void Polygon::draw() {
	//UI::println("Circle " + to_string(radius) + " " + center.toString());
	UI::print("Polygon " + to_string(size) + " ");
	//for�� ���� ������ŭ �Ʒ� �ݺ�
	for(int i=0; i<size; i++)
		UI::print(points[i].toString());
	UI::println("");//������ UI �Լ��� �̿��Ͽ� �� �ٲٱ� ���
}
//���� �ٰ����� ��ġ�� width, height��ŭ �ű��
void Polygon::move(int width, int height) {
	for(int i=0; i<size; i++)//for�� ���� ������ŭ �Ʒ� �ݺ�
		points[i].move(width, height);//points[i]�� move �Լ� ȣ���Ͽ� ��ġ �̵�
}
//���� ��ü ������ �� ����� ��ü�� ��ġ�� �ű� �� ��ü �����͸� ����
Polygon *Polygon::copy(int width, int height) {
	//���ο� ������ ��ü�� �����ϰ� ��������� ȣ���Ͽ� ���� ��ü�� �����Ѵ�.
	Polygon *polygon = new Polygon(*this);
	//����� ��ü�� width, height��ŭ �ű��.
	polygon->move(width, height);
	//����� ��ü�� �����͸� ����
	return polygon;
}
