#include <iostream>
using namespace std;

//��� ������ ��ġ ������ �߿��ϴ�
#include "Shape.h"
#include "UI.h"
#include "Factory.h"
#include "GraphicEditor.h"

GraphicEditor::GraphicEditor() {
	//������ ��� �ڵ带 ���� �ּ�ó����(���� �� �Լ����� �ϴ� ���� ����)
	//����� vector<Shape *> v�� �⺻ �����ڿ� ���� �ڵ����� �ʱ�ȭ��
	//pStart = pLast = nullptr;
}
void GraphicEditor::removeAllShape() {
	//������ ��� �ڵ带 /* �� */ �� ���� �ּ� ó����
	/*//���� ������ ��� ��ü�� ����
	for(Shape *p = pStart, *q; p != nullptr; p = q) {
		q = p->getNext();	//p�� ���� ��ü�� ���� �����͸� ���� q�� ����
		delete p;			//p�� ����Ʈ�ϴ� ��ü �ݳ�
	}
	pStart = pLast = nullptr;	//pStart�� pLast ��� �����͸� nullptr�� �ʱ�ȭ
	*/
	for (auto p: v)	//������� for���� ����Ͽ�
		delete p;	//���Ե� ������ ������ ���� ��ü �޸𸮸� �ݳ�
	v.clear();		//��� ������ ���� ���� (���͸� ����.)
}
GraphicEditor::~GraphicEditor() {
	removeAllShape();	//removeAllSahpe �Լ� ȣ���Ͽ� ����Ʈ�� ��� ��ü ����
}
//���ο� �׷��� ��ü p�� �� �������� pLast ������ �߰�
void GraphicEditor::add(Shape *p) {
	//������ ��� �ڵ带 /* �� */ �� ���� �ּ� ó����
	/*if(pStart == nullptr) {
		pStart = pLast = p;	//pStart, pLast�� p�� ������ ��
		return;				//����
	}
	else {
		pLast = pLast->add(p);	//pLast�ڿ� p�� �߰��ϰ� ���� ���� pLast�� ����
	}*/
	v.push_back(p);	//���� v�� �������� p�� �߰���
}
//��ü�� �ϳ��� ������ ���� �޽��� ��� �� true ����, ���� ��� false ����
bool GraphicEditor::empty() {
	//if(pStart == nullptr) {
	if(v.size() == 0) {	//if(������ ���� ������ 0�̸�)
		UI::println("�׷��� ������ �����ϴ�.");
		return true;
	}
	return false;
}
//���Ե� ��� �׷��� ��ü���� ȭ�鿡 ���
void GraphicEditor::allPaint() {
	//Shape *p = pStart;	//Shape�� �������� ���� p�� �����ϰ� pStart�� �ʱ�ȭ
	//for(int i=0; p!=nullptr; ++i, p=p->getNext()) {
	//������ "for() {"�� removeAllShapes()�� "for() {"���� ��ü
	for(int i=0; i<v.size(); i++) {//for���� �̿��Ͽ� ���� v�� ù ���Һ��� ������ ���ұ���
		UI::print("[" + to_string(i) + "]: ");	//�ε��� ���
		//p->paint();	//������ �׸��� p�� ��� �Լ� ȣ��
		v[i]->paint();//v[i]�� �̿��Ͽ� ������ �׸��� ��� �Լ� ȣ��
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
	//for(Shape *p = pStart; p!=nullptr; p=p->getNext())	//for�� �̿��Ͽ� ����Ʈ�� ó������ ������ ��ũ�� ���� ���鼭
	for(int i=0; i<v.size(); i++)	//for���� �̿��Ͽ� ���� v�� ù ���Һ��� ������ ���ұ���
		//p->move(width, height);	//�� ������ move �Լ� ȣ��
		v[i]->move(width, height);	//�� ������ move �Լ� ȣ��
	allPaint();	//��� ��ü�� ȭ�鿡 ������
}
//���� ������ ��� ��ü�� �����Ѵ�.
void GraphicEditor::allRemove() {
	if(empty())			//��ü�� ���� ���� ���
		return;			//���� ��� �Ŀ��⼭ ����
	removeAllShape();	//removeAllShape �Լ� ȣ���Ͽ� ����Ʈ�� ��� ��ü ����
}
//���� ������ ��� ��ü���� ������ �� �̵��ϰ� ���Ϳ� �߰��Ѵ�.
void GraphicEditor::allCopy() {
	if(empty())	//��ü�� ���� ���� ���
		return;	//���� ��� �� ���⼭ ����
	int width, height;	//�� ������ �̵��� ��. ������ ���� width, height ����
	UI::getWidthHeight(width, height);	//UI�� getWidthHeight() ȣ���Ͽ� ����ڷκ��� width, height �Է� ����
	int sz = v.size();	//for �տ� ������ ���� sz�� �����ϰ� ������ ���� ����(������ ���� ����)�� �ʱ�ȭ��
	for(int i=0; i<sz; i++) {	//for���� �̿��Ͽ� ���� v�� ù ���Һ��� ������ ���ұ���
		Shape *c = v[i]->copy(width, height);//Shape *���� ���� c�� �����ϰ� v[i]�� move() �Լ� ��ſ� copy() �Լ��� ȣ��(�Լ� ���ڴ� ����)�� �� ���� ���� c�� �ʱ�ȭ��
		add(c);	//����� ���ο� ��ü�� GraphicEditor()�� add() �Լ��� ȣ���Ͽ� ���Ϳ� �߰���
	}
	allPaint();	//��� ��ü�� ȭ�鿡 ������
}
//���� �޴��� ���� �ְ� ����ڰ� ������ �۾��� ������
void GraphicEditor::run() {
	UI::println("�׷��� �������Դϴ�.");
	while(true) {
		int menu = UI::getMainMenu();//������ ���� menu�� �����԰� ���ÿ� UI�� getMainMenu()�� ȣ���Ͽ� ���� ������ �ʱ�ȭ
		switch(menu) {
		case ALL_PAINT :	//��κ���
			allPaint(); break;
		case AUTO_INSERT :	//�ڵ�����
			autoInsert(); break;
		case ALL_MOVE :		//����̵�
			allMove(); break;
		case ALL_REMOVE :	//��λ���
			allRemove(); break;
		case ALL_COPY :		//��κ���
			allCopy(); break;
		case EXIT :			//������, �� �Լ����� ������
			return;
		default :
			UI::println("��� ���� ����");	//�� �� default�� "��� ���� ����" ���
		}
	}
}
