#ifndef POLYGON_H_
#define POLYGON_H_

#include "Shape.h"

class Polygon : public Shape {
	Point *points;	//�ٰ����� ��� ���� ���� ��ǥ���� ������ �ִ� �迭
	int size;		//�ٰ��� ���� ����
	void copyPoints(int size, Point points[]);//�Լ� ���ڷ� ���޵� size���� points[] ������ �� ��ü ���� points[]�� ����
protected:
	void draw() override;
public:
	Polygon(int size, Point points[]);//������
	//Shape�� ~Shape()�Ҹ��ڰ� virtual�̹Ƿ� �� �Լ� ȣ�� �� �Ʒ� �Լ��� �ڵ� ȣ���
	~Polygon() override;		//�Ҹ���
	Polygon(const Polygon &c);	//���� ������
	void move(int width, int height) override;		//��ü�� �̵�
	Polygon *copy(int width, int height) override;	//��ü ���� �� �̵�
};



#endif /* POLYGON_H_ */
