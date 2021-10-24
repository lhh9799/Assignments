#include <iostream>
using namespace std;

//헤더 파일의 배치 순서가 중요하다
#include "Shape.h";
#include "UI.h";
#include "Factory.h";
#include "GraphicEditor.h";

GraphicEditor::GraphicEditor() {
	pStart = pLast = nullptr;
}
void GraphicEditor::removeAllShape() {
	//현재 생성된 모든 객체를 삭제
	for(Shape *p = pStart, *q; p != nullptr; p = q) {
		q = p->getNext();	//p의 다음 객체에 대한 포인터를 구해 q에 저장
		delete p;			//p가 포인트하는 객체 반납
	}
	pStart = pLast = nullptr;	//pStart와 pLast 멤버 데이터를 nullptr로 초기화
}
GraphicEditor::~GraphicEditor() {
	removeAllShape();	//removeAllSahpe 함수 호출하여 리스트의 모든 객체 삭제
}
//새로운 그래픽 객체 p를 맨 마지막인 pLast 다음에 추가
void GraphicEditor::add(Shape *p) {
	if(pStart == nullptr) {
		pStart = pLast = p;	//pStart, pLast를 p로 설정한 후
		return;				//리턴
	}
	else {
		pLast = pLast->add(p);	//pLast뒤에 p를 추가하고 리턴 값을 pLast에 저장
	}
}
//객체가 하나도 없으면 에러 메시지 출력 후 true 리턴, 있을 경우 false 리턴
bool GraphicEditor::empty() {
	if(pStart == nullptr) {
		UI::println("그려진 도형이 없습니다.");
		return true;
	}
	return false;
}
//삽입된 모든 그래픽 객체들을 화면에 출력
void GraphicEditor::allPaint() {
	Shape *p = pStart;	//Shape의 포인터형 변수 p를 선언하고 pStart로 초기화
	for(int i=0; p!=nullptr; ++i, p=p->getNext()) {
		UI::print("[" + to_string(i) + "]: ");	//인덱스 출력
		p->paint();	//도형을 그리는 p의 멤버 함수 호출
	}
}
//자동으로 객체를 생성하여 리스트에 추가한다.
void GraphicEditor::autoInsert() {
	//자동 삽입할 그래픽 객체의 개수를 얻어 옴(난수 발생)
	int size = Factory::getSize();	//정수형 변수 size를 선언하고 Factory::getSize()를 호출하여 리턴 값으로 초기화
	for(int i=0; i<size; i++) {		//for문을 이요하여 size만큼 반복 수행
		add(Factory::create());		//생성된 객체를 GraphicEditor의 add()함수 호출하여 리스트에 추가
	}
	allPaint();	//모든 객체를 화면에 보여줌
}
//현재 생성된 모든 객체를 이동한다.
void GraphicEditor::allMove() {
	if(empty())	//객체가 전혀 없을 경우
		return;	//에러 출력 후 여기서 리턴
	int width, height;	//각 도형이 이동할 양. 정수형 변수 width, height 선언
	UI::getWidthHeight(width, height);	//UI의 getWidthHeight() 호출하여 사용자로부터 width, height 입력 받음
	for(Shape *p = pStart; p!=nullptr; p=p->getNext())	//for를 이용하여 리스트의 처음부터 끝까지 링크를 따라 가면서
		p->move(width, height);	//각 도형의 move 함수 호출
	allPaint();	//모든 객체를 화면에 보여줌
}
//현재 생성된 모든 객체를 삭제한다.
void GraphicEditor::allRemove() {
	if(empty())			//객체가 전혀 없을 경우
		return;			//에러 출력 후여기서 리턴
	removeAllShape();	//removeAllShape 함수 호출하여 리스트의 모든 객체 삭제
}
//메인 메뉴를 보여 주고 사용자가 선택한 작업을 실행함
void GraphicEditor::run() {
	UI::println("그래픽 에디터입니다.");
	while(true) {
		int menu = UI::getMainMenu();	//정수형 변수 menu를 선언함과 동시에 UI의 getMainMenu()를 호출하여 리턴 값으로 초기화
		switch(menu) {
		case ALL_PAINT :	//모두보기
			allPaint(); break;
		case AUTO_INSERT :	//자동삽입
			autoInsert(); break;
		case ALL_MOVE :		//모두이동
			allMove(); break;
		case ALL_REMOVE :	//모두삭제
			allRemove(); break;
		case EXIT :			//끝내기, 이 함수에서 리턴함
			return;
		default :
			UI::println("명령 선택 오류");	//그 외 default는 "명령 선택 오류" 출력
		}
	}
}
