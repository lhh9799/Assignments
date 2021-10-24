#ifndef LINE_H_
#define LINE_H_

#include "Shape.h"

class Line : public Shape {
	Point p1;	//������ ���� ��ǥ
	Point p2;	//������ �� ��ǥ
protected:
	virtual void draw();
public:
	Line(const Point &p1, const Point &p2);
	void move(int width, int height) override;
};

#endif /* LINE_H_ */
