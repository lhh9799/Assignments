#ifndef LINE_H_
#define LINE_H_

#include "Shape.h"

class Line : public Shape {
	Point p1;	//라인의 시작 좌표
	Point p2;	//라인의 끝 좌표
protected:
	virtual void draw();
public:
	Line(const Point &p1, const Point &p2);
	void move(int width, int height) override;
};

#endif /* LINE_H_ */
