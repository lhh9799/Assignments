#include <random>
using namespace std;

#include "Factory.h"
#include "Point.h"
#include "Shape.h"
#include "Line.h"
#include "Circle.h"
#include "Rect.h"

class Rand {
	//������ �����ϴ� ����
	default_random_engine re;
	//�߻��� ���� ������ ���� ������ �յ� ����(uniform)�� ����
	uniform_int_distribution<int> dist;
public:
	//[low, high] ���� ���� ���� �߻��ϵ��� dist �ʱ�ȭ
	Rand(int low, int high) : dist(low, high) {}
	//[low, high] ���� ���� ���� �߻�
	int operator() () {return dist(re);}
};
enum { MAX_XY = 99, MIN_SIZE = 5, MID_SIZE = 10, MAX_SIZE = 20};

// [LINE, POLYGON] ������ ���� �߻���, �ڵ� ������ �׷��� ���� ����
static Rand randShapeType(Factory::LINE, Factory::RECT);
// [0, 99] ������ ���� �߻���, x �Ǵ� y ��ǥ �� ������ ���
static Rand randXY(0, MAX_XY);
// [5, 20] ������ ���� �߻���, ���� ������ ������ Ȱ��
static Rand randRadius(MIN_SIZE, MAX_SIZE);
// [5, 10] ������ ���� �߻���, �ٰ��� ���� ���� �Ǵ� �׷��� ��ü�� ���� ������ Ȱ��
static Rand randSize(MIN_SIZE, MID_SIZE);

//�ٰ����� ���� ��ġ�� �����ϴ� ��ǥ �迭, �Ź� �����Ҵ����� ����
static Point points[MID_SIZE];

//���ο� Point ��ü�� ������: x,y��ǥ�� �ڵ� ����
static Point newPoint() {return Point(randXY(), randXY());}

//�ڵ� ������ �׷��� ��ü�� ������ ������ ����
int Factory::getSize() {
	return randSize();	//[5, 10] ������ ���� ����
}
//shapeType ��ü�� ������: �� ��ü�� ������� �ڵ����� ������
Shape* Factory::create(int shapeType) {
	switch (shapeType) {
	case LINE:	//����
		return new Line(newPoint(), newPoint());
	case CIRCLE://��
		return new Circle(randRadius(), newPoint());
	case RECT:	//�簢��
		return new Rect(newPoint(), newPoint());
	}
	return nullptr;
}

//����, ��, �簢�� �� ���Ƿ� �ϳ��� ��ü�� ������
Shape* Factory::create() {
	//randShapeType(): [LINE, POLYGON] ������ ������ �߻�
	return create(randShapeType());
}
