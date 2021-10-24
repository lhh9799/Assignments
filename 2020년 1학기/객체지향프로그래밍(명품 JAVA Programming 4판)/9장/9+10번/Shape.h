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
	//기존 객체를 x, y축 방향으로 width, height 만큼 각각 이동함
	virtual void move(int width, int height) = 0;
};

#endif /* SHAPE_H_ */
