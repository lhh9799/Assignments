#ifndef POINT_H_
#define POINT_H_

#include <string>
using namespace std;

class Point {//한 점의 x, y 좌표 값을 가지고 있는 클래스
	int x;	//점의 x 좌표 값
	int y;	//점의 y 좌표 값
public:
	Point(int x=0, int y=0);
	void move(int width, int height);
	string toString();
	void setXY(int x, int y);//인자 x, y를 객체의 멤버 x, y에 설정함
};

#endif /* POINT_H_ */
