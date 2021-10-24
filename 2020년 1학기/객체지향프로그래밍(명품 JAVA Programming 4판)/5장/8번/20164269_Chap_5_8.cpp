#include <iostream>
using namespace std;

class MyIntStack {
	int *p; //���� �޸𸮷� ����� ������
	int size; //������ �ִ� ũ��
	int tos; //������ ž�� ����Ű�� �ε���
public:
	MyIntStack();
	MyIntStack(int size);
	MyIntStack(const MyIntStack &s); //���� ������
	~MyIntStack();

	bool push(int n); //���� n�� ���ÿ� Ǫ���Ѵ�. ������ �� �� ������ false��, �ƴϸ� true ����
	bool pop(int &n); //������ ž�� �ִ� ���� n�� ���Ѵ�. ���� ������ ��� ������ false��, �ƴϸ� true ����
};

//MyStack�� ������ ��� �Լ� ����
MyIntStack::MyIntStack() {
	size = 10; //�Ҵ��� �迭�� ũ��
	this->tos = 0; //tos���� 0���� �ʱ�ȭ. tos�� 0�̸� �� ������ �ǹ���
	p = new int[size]; //���ÿ� int�迭[size] �Ҵ��Ͽ� p�� ����
}

MyIntStack::MyIntStack(int size) {
	this->size = size; //�Ű����� size�� ������� size�� ����;
	this->tos = 0; //tos������ 0���� �ʱ�ȭ
	p = new int[size]; //���ÿ� int �迭 �Ҵ��Ͽ� p�� ����
}

MyIntStack::~MyIntStack() {
	if(!p) //p�� nulptr�� �ƴ϶��, �� ���������� �޸� �Ҵ�Ǿ��ٸ� ���� �޸� �迭 p�� ��ȯ
		delete []p;
}

MyIntStack::MyIntStack(const MyIntStack &s) { //���� ������
	this->size = s.size; //s�� size ����� ���� ��ü�� size ����� ����
	this->tos = s.tos; //s�� tos ����� ���� ��ü�� tos ����� ����
	this->p = new int[size]; //���ÿ�  int�迭[size] �Ҵ��Ͽ� p�� ����
	for(int i=0; i<size; i++) { //for���� �̿��Ͽ� s�� p[i]�� ���� ��ü�� p[i]�� ����
		this->p[i] = s.p[i];
	}
}

bool MyIntStack::push(int n) {
	if(tos == size)//���� ���� �� ���¶��(���� ž �ε����� ���� �ִ� ũ��� �����ϸ�), false�� ����
		return false;
	p[tos] = n; //������ ž��(p[?])�� n�� ����
	tos++; //������ ž�� ����Ű�� �ε���(?)�� 1 ������Ŵ
	return true; //true ����
}

bool MyIntStack::pop(int &n) {
	if(tos == 0)//������ ��� ������ false�� ����
		return false;
	tos--; //������ ž�� ����Ű�� �ε����� 1 ����
	n = p[tos]; //n�� ������ ž�� (p[?])�� ���� ����
	return true;
}

//main() �Լ�
int main() {
	MyIntStack a(10);
	a.push(10);
	a.push(20);

	MyIntStack b = a; // ���� ����: ���� ������ ȣ��
	b.push(30);

	int n;
	a.pop(n); //���� a ��
	cout << "���� a���� ���� �� " << n << endl;
	b.pop(n); //���� b ��
	cout << "���� b���� ���� �� " << n << endl;;
}
