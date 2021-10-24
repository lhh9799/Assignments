#ifndef FACTORY_H_
#define FACTORY_H_

#include "Shape.h"

class Factory {
public:
	//자동 생성할 그래픽 객체의 종류
	enum {LINE = 0, CIRCLE = 1, RECT = 2, POLYGON = 3};
	static Shape *create();	//임의의 그래픽 객체를 자동 생성함
	static Shape *create(int shapeType);	//shapeType 객체 생성
	static int getSize();	//자동 생성할 그래픽 객체의 수 리턴
};

#endif /* FACTORY_H_ */
