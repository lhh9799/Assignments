#include "Polygon.h"
#include "UI.h"

//이 함수는 생성자와 복사 생성자에서 호출됨
void Polygon::copyPoints(int size, Point *points) {
	this->size = size;//함수 인자 size를 이 다각형의 size 멤버에 저장
	this->points = new Point[size];//size개의 Point 객체를 동적 할당하여 이 다각형의 points 멤버에 저장
	for(int i=0; i<size; i++)
		this->points[i] = points[i];//함수 인자 points[i] 객체를 이 다각형의 points[i] 객체에 저장
}
//생성자: 멤버 초기화
Polygon::Polygon(int size, Point points[]) {
	copyPoints(size, points);//위 copyPoints() 함수 호출하여 멤버 초기화
}
//소멸자: 동적으로 할당 받은 멤버의 메모리 반납
Polygon::~Polygon() {
	delete [] points;//동적으로 할당 받은 points 배열 메모리 반납
}
//복사 생성자: c.points[]를 위해 동적 메모리 할당한 후 c를 복사
Polygon::Polygon(const Polygon &c) {
	copyPoints(c.size, c.points);//위 copyPoints() 함수 호출하여 멤버 초기화
}
//화면에 다각형의 점의 개수와 점들의 좌표 값을 출력
void Polygon::draw() {
	//UI::println("Circle " + to_string(radius) + " " + center.toString());
	UI::print("Polygon " + to_string(size) + " ");
	//for로 점의 개수만큼 아래 반복
	for(int i=0; i<size; i++)
		UI::print(points[i].toString());
	UI::println("");//적절한 UI 함수를 이용하여 줄 바꾸기 출력
}
//기존 다각형의 위치를 width, height만큼 옮긴다
void Polygon::move(int width, int height) {
	for(int i=0; i<size; i++)//for로 점의 개수만큼 아래 반복
		points[i].move(width, height);//points[i]의 move 함수 호출하여 위치 이동
}
//기존 객체 복사한 후 복사된 객체의 위치를 옮긴 후 객체 포인터를 리턴
Polygon *Polygon::copy(int width, int height) {
	//새로운 폴리곤 객체를 생성하고 복사생성자 호출하여 기존 객체를 복사한다.
	Polygon *polygon = new Polygon(*this);
	//복사된 객체를 width, height만큼 옮긴다.
	polygon->move(width, height);
	//복사된 객체의 포인터를 리턴
	return polygon;
}
