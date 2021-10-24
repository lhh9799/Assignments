#ifndef POINT_H_
#define POINT_H_

#include <string>
using namespace std;

class Point {//�� ���� x, y ��ǥ ���� ������ �ִ� Ŭ����
	int x;	//���� x ��ǥ ��
	int y;	//���� y ��ǥ ��
public:
	Point(int x=0, int y=0);
	void move(int width, int height);
	string toString();
	void setXY(int x, int y);//���� x, y�� ��ü�� ��� x, y�� ������
};

#endif /* POINT_H_ */
