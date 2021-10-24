#ifndef SHAPE_H_
#define SHAPE_H_

#include "Point.h"

class Shape {
	Shape* next;
protected:
	virtual void draw() = 0;
public:
	Shape() {next = NULL;}
	virtual ~Shape() {}
	void paint();
	Shape* add(Shape* p);
	Shape* getNext() {return next;}
	//���� ��ü�� x, y�� �������� width, height ��ŭ ���� �̵���
	virtual void move(int width, int height) = 0;
};

#endif /* SHAPE_H_ */
