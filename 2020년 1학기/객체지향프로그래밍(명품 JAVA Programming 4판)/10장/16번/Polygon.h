#ifndef POLYGON_H_
#define POLYGON_H_

#include "Shape.h"

class Polygon : public Shape {
	Point *points;	//다각형의 모든 점에 대한 좌표들을 가지고 있는 배열
	int size;		//다각형 점의 개수
	void copyPoints(int size, Point points[]);//함수 인자로 전달된 size개의 points[] 점들을 이 객체 내의 points[]로 복사
protected:
	void draw() override;
public:
	Polygon(int size, Point points[]);//생성자
	//Shape의 ~Shape()소멸자가 virtual이므로 이 함수 호출 시 아래 함수가 자동 호출됨
	~Polygon() override;		//소멸자
	Polygon(const Polygon &c);	//복사 생성자
	void move(int width, int height) override;		//객체의 이동
	Polygon *copy(int width, int height) override;	//객체 복사 후 이동
};



#endif /* POLYGON_H_ */
