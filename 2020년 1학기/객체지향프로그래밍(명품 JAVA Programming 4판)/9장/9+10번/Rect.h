#ifndef RECT_H_
#define RECT_H_

#include "Shape.h"

class Rect : public Shape {
	Point p1;	//�簢���� ���� ���� ��ǥ
	Point p2;	//�簢���� ������ �Ʒ��� ��ǥ
protected :
	virtual void draw();
public:
	Rect(const Point &p1, const Point &p2);
	void move(int width, int height) override;
};

#endif /* RECT_H_ */
