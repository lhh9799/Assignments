#ifndef GRAPHICEDITOR_H_
#define GRAPHICEDITOR_H_

//vector ������� include �� std ����
#include <vector>
using namespace std;

class Shape;	//�Ʒ��� Shape*�� ���Ǿ��� ������ Ŭ���� �̸��� �����ؾ� ��

class GraphicEditor {
	//���� �޴��� ����
	enum {EXIT=0, ALL_PAINT=1, AUTO_INSERT=2, ALL_MOVE=3, ALL_REMOVE=4, ALL_COPY = 5};
	//Shape* pStart;	//���Ե� �׷��� ��ü���� linked ����Ʈ�� �� ó���� ����Ŵ
	//Shape* pLast;		//���Ե� �׷��� ��ü���� linked ����Ʈ�� �� �������� ����Ŵ
	vector<Shape *> v;	//���Ե� �������� ������ vector ��� v ����
	void add(Shape* p);	//���ο� �׷��� ��ü p�� �� �������� pLast ������ �߰�
	bool empty();		//��ü�� �ϳ��� ������ üũ
	void removeAllShape();//��� �׷��� ��ü ����
protected:
	void autoInsert();	//������ ������ �׷��� ��ü�� �ڵ����� ������
	void allRemove();	//��� �׷��� ��ü���� ����
	void allPaint();	//���Ե� ��� �׷��� ��ü���� ȭ�鿡 ���
	void allMove();		//��� ��ü���� ����ڰ� �Է��� x, y �̵� ����ŭ �̵�
	void allCopy();		//���Ե� ��� �������� ������ �� �̵�
public:
	GraphicEditor();
	~GraphicEditor();
	void run();			//���� �޴��� ���� �ְ� ����ڰ� ������ �۾��� ������
};

#endif /* GRAPHICEDITOR_H_ */
