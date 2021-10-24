#include <iostream>
using namespace std;

//��� ������ ��ġ ������ �߿��ϴ�
#include "Shape.h";
#include "UI.h";
#include "Factory.h";
#include "GraphicEditor.h";

GraphicEditor::GraphicEditor() {
	pStart = pLast = nullptr;
}
void GraphicEditor::removeAllShape() {
	//���� ������ ��� ��ü�� ����
	for(Shape *p = pStart, *q; p != nullptr; p = q) {
		q = p->getNext();	//p�� ���� ��ü�� ���� �����͸� ���� q�� ����
		delete p;			//p�� ����Ʈ�ϴ� ��ü �ݳ�
	}
	pStart = pLast = nullptr;	//pStart�� pLast ��� �����͸� nullptr�� �ʱ�ȭ
}
GraphicEditor::~GraphicEditor() {
	removeAllShape();	//removeAllSahpe �Լ� ȣ���Ͽ� ����Ʈ�� ��� ��ü ����
}
//���ο� �׷��� ��ü p�� �� �������� pLast ������ �߰�
void GraphicEditor::add(Shape *p) {
	if(pStart == nullptr) {
		pStart = pLast = p;	//pStart, pLast�� p�� ������ ��
		return;				//����
	}
	else {
		pLast = pLast->add(p);	//pLast�ڿ� p�� �߰��ϰ� ���� ���� pLast�� ����
	}
}
//��ü�� �ϳ��� ������ ���� �޽��� ��� �� true ����, ���� ��� false ����
bool GraphicEditor::empty() {
	if(pStart == nullptr) {
		UI::println("�׷��� ������ �����ϴ�.");
		return true;
	}
	return false;
}
//���Ե� ��� �׷��� ��ü���� ȭ�鿡 ���
void GraphicEditor::allPaint() {
	Shape *p = pStart;	//Shape�� �������� ���� p�� �����ϰ� pStart�� �ʱ�ȭ
	for(int i=0; p!=nullptr; ++i, p=p->getNext()) {
		UI::print("[" + to_string(i) + "]: ");	//�ε��� ���
		p->paint();	//������ �׸��� p�� ��� �Լ� ȣ��
	}
}
//�ڵ����� ��ü�� �����Ͽ� ����Ʈ�� �߰��Ѵ�.
void GraphicEditor::autoInsert() {
	//�ڵ� ������ �׷��� ��ü�� ������ ��� ��(���� �߻�)
	int size = Factory::getSize();	//������ ���� size�� �����ϰ� Factory::getSize()�� ȣ���Ͽ� ���� ������ �ʱ�ȭ
	for(int i=0; i<size; i++) {		//for���� �̿��Ͽ� size��ŭ �ݺ� ����
		add(Factory::create());		//������ ��ü�� GraphicEditor�� add()�Լ� ȣ���Ͽ� ����Ʈ�� �߰�
	}
	allPaint();	//��� ��ü�� ȭ�鿡 ������
}
//���� ������ ��� ��ü�� �̵��Ѵ�.
void GraphicEditor::allMove() {
	if(empty())	//��ü�� ���� ���� ���
		return;	//���� ��� �� ���⼭ ����
	int width, height;	//�� ������ �̵��� ��. ������ ���� width, height ����
	UI::getWidthHeight(width, height);	//UI�� getWidthHeight() ȣ���Ͽ� ����ڷκ��� width, height �Է� ����
	for(Shape *p = pStart; p!=nullptr; p=p->getNext())	//for�� �̿��Ͽ� ����Ʈ�� ó������ ������ ��ũ�� ���� ���鼭
		p->move(width, height);	//�� ������ move �Լ� ȣ��
	allPaint();	//��� ��ü�� ȭ�鿡 ������
}
//���� ������ ��� ��ü�� �����Ѵ�.
void GraphicEditor::allRemove() {
	if(empty())			//��ü�� ���� ���� ���
		return;			//���� ��� �Ŀ��⼭ ����
	removeAllShape();	//removeAllShape �Լ� ȣ���Ͽ� ����Ʈ�� ��� ��ü ����
}
//���� �޴��� ���� �ְ� ����ڰ� ������ �۾��� ������
void GraphicEditor::run() {
	UI::println("�׷��� �������Դϴ�.");
	while(true) {
		int menu = UI::getMainMenu();	//������ ���� menu�� �����԰� ���ÿ� UI�� getMainMenu()�� ȣ���Ͽ� ���� ������ �ʱ�ȭ
		switch(menu) {
		case ALL_PAINT :	//��κ���
			allPaint(); break;
		case AUTO_INSERT :	//�ڵ�����
			autoInsert(); break;
		case ALL_MOVE :		//����̵�
			allMove(); break;
		case ALL_REMOVE :	//��λ���
			allRemove(); break;
		case EXIT :			//������, �� �Լ����� ������
			return;
		default :
			UI::println("��� ���� ����");	//�� �� default�� "��� ���� ����" ���
		}
	}
}
