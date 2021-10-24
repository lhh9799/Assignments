#include <random>
using namespace std;

#include "Factory.h"
#include "Point.h"
#include "Shape.h"
#include "Line.h"
#include "Circle.h"
#include "Rect.h"
#include "Polygon.h"//다각형 헤드 파일 include 추가

class Rand {
	//난수를 생성하는 엔진
	default_random_engine re;
	//발생된 난수 값들이 일정 범위의 균등 분포(uniform)로 매핑
	uniform_int_distribution<int> dist;
public:
	//[low, high] 범위 내의 값이 발생하도록 dist 초기화
	Rand(int low, int high) : dist(low, high) {}
	//[low, high] 범위 내의 난수 발생
	int operator() () {return dist(re);}
};
enum { MAX_XY = 99, MIN_SIZE = 5, MID_SIZE = 10, MAX_SIZE = 20};

// [LINE, POLYGON] 범위의 난수 발생기, 자동 생성할 그래픽 종류 생성
static Rand randShapeType(Factory::LINE, Factory::POLYGON);//기존 난수발생기 수정: [LINE, POLYGON] 범위의 객체 종류 발생
// [0, 99] 범위의 난수 발생기, x 또는 y 좌표 값 생성시 사용
static Rand randXY(0, MAX_XY);
// [5, 20] 범위의 난수 발생기, 원의 반지름 생성시 활용
static Rand randRadius(MIN_SIZE, MAX_SIZE);
// [5, 10] 범위의 난수 발생기, 다각형 점의 개수 또는 그래픽 객체의 개수 생성시 활용
static Rand randSize(MIN_SIZE, MID_SIZE);

//다각형의 점들 위치를 저장하는 좌표 배열, 매번 동적할당하지 않음
static Point points[MID_SIZE];

//새로운 Point 객체를 생성함: x,y좌표는 자동 지정
static Point newPoint() {return Point(randXY(), randXY());}

//자동 생성할 그래픽 객체의 개수를 난수로 생성
int Factory::getSize() {
	return randSize();	//[5, 10] 범위의 난수 생성
}
//shapeType 객체를 생성함: 각 객체의 멤버들은 자동으로 설정됨
Shape* Factory::create(int shapeType) {
	switch (shapeType) {
	case LINE:	//라인
		return new Line(newPoint(), newPoint());
	case CIRCLE://원
		return new Circle(randRadius(), newPoint());
	case RECT:	//사각형
		return new Rect(newPoint(), newPoint());
	case POLYGON://다각형 도형 객체 자동 생성
		int size = randSize();//다각형 점의 개수 자동 생성
		for(int i=0; i<size; ++i)
			points[i].setXY(randXY(), randXY());
		//전역 변수 배열 points[] 저장된 각 점의 x, y 좌표 자동설정
		Shape* s = new Polygon(size, points);
		return s;
	}
	return nullptr;
}

//라인, 원, 사각형 중 임의로 하나의 객체를 생성함
Shape* Factory::create() {
	//randShapeType(): [LINE, POLYGON] 범위의 난수를 발생
	return create(randShapeType());
}
