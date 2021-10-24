#ifndef RECT_H_
#define RECT_H_

#include "Shape.h"

class Rect : public Shape {
	Point p1;	//사각형의 왼쪽 위쪽 좌표
	Point p2;	//사각형의 오른쪽 아래쪽 좌표
protected :
	virtual void draw();
public:
	Rect(const Point &p1, const Point &p2);
	void move(int width, int height) override;
};

#endif /* RECT_H_ */
