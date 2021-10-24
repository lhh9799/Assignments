#ifndef GRAPHICEDITOR_H_
#define GRAPHICEDITOR_H_

class Shape;	//아래에 Shape*가 사용되었기 때문에 클래스 이름을 선언해야 함

class GraphicEditor {
	//메인 메뉴의 종류
	enum {EXIT=0, ALL_PAINT=1, AUTO_INSERT=2, ALL_MOVE=3, ALL_REMOVE=4};
	Shape* pStart;		//삽입된 그래픽 객체들의 linked 리스트의 맨 처음을 가리킴
	Shape* pLast;		//삽입된 그래픽 객체들의 linked 리스트의 맨 마지막을 가리킴
	void add(Shape* p);	//새로운 그래픽 객체 p를 맨 마지막인 pLast 다음에 추가
	bool empty();		//객체가 하나도 없는지 체크
	void removeAllShape();//모든 그래픽 객체 삭제
protected:
	void autoInsert();	//임의의 개수의 그래픽 객체를 자동으로 삽입함
	void allRemove();	//모든 그래픽 객체들을 삭제
	void allPaint();	//삽입된 모든 그래픽 객체들을 화면에 출력
	void allMove();		//모든 객체들을 사용자가 입력한 x, y 이동 량만큼 이동
public:
	GraphicEditor();
	~GraphicEditor();
	void run();			//메인 메뉴를 보여 주고 사용자가 선택한 작업을 실행함
};

#endif /* GRAPHICEDITOR_H_ */
