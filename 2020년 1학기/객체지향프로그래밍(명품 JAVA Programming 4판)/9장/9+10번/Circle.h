#ifndef CIRCLE_H_
#define CIRCLE_H_

#include "Shape.h"

class Circle : public Shape {
	Point center;	//원의 중심 좌표
	int radius;		//반지름의 길이
protected :
	virtual void draw();
public :
	Circle(int radius, const Point &center);
	void move(int width, int height) override;
};

#endif /* CIRCLE_H_ */
