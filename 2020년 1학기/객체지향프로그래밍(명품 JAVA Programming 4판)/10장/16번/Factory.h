#ifndef FACTORY_H_
#define FACTORY_H_

#include "Shape.h"

class Factory {
public:
	//�ڵ� ������ �׷��� ��ü�� ����
	enum {LINE = 0, CIRCLE = 1, RECT = 2, POLYGON = 3};
	static Shape *create();	//������ �׷��� ��ü�� �ڵ� ������
	static Shape *create(int shapeType);	//shapeType ��ü ����
	static int getSize();	//�ڵ� ������ �׷��� ��ü�� �� ����
};

#endif /* FACTORY_H_ */
