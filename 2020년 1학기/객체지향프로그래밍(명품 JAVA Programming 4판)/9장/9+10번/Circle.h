#ifndef CIRCLE_H_
#define CIRCLE_H_

#include "Shape.h"

class Circle : public Shape {
	Point center;	//���� �߽� ��ǥ
	int radius;		//�������� ����
protected :
	virtual void draw();
public :
	Circle(int radius, const Point &center);
	void move(int width, int height) override;
};

#endif /* CIRCLE_H_ */
