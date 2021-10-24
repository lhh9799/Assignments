#include <iostream>
using namespace std;

// �ǽ� 5���� ����
class MyIntStack {
	int *p;		//���� �޸𸮷� ����� ������
	int size;	//������ �ִ� ũ��
	int tos;	//������ ž�� ����Ű�� �ε���
public:
	MyIntStack();
	MyIntStack(int size);
	MyIntStack(const MyIntStack &s);	//���� ������
	~MyIntStack();
	bool push(int n);					//���� n�� ���ÿ� Ǫ���Ѵ�. ������ �� �� ������ false��, �ƴϸ� true ����
	bool pop(int &n);					//������ ž�� �ִ� ���� n�� ���Ѵ�. ���� ������ ��� ������ false��, �ƴϸ� true ����

	//���� �߰��ؾ� �� ������ �Լ�
	MyIntStack& operator << (int n);				//push: ��ü �ڽ��� �����ڸ� ����
	MyIntStack& operator >> (int& n);				//pop: ��ü �ڽ��� �����ڸ� ����
	bool operator !();								//������ ������� true ����
	MyIntStack& operator = (const MyIntStack& s);	//���� ���ÿ� s ������ ������ ����
	friend MyIntStack operator + (const MyIntStack& s1, const MyIntStack& s2); //�ܺ� + ������ �Լ��� ������� ����
};

//MyStack�� ������ ��� �Լ� ����
MyIntStack::MyIntStack() {
	size = 10;									//�Ҵ��� �迭�� ũ��
	this->tos = 0;								//tos���� 0���� �ʱ�ȭ. tos�� 0�̸� �� ������ �ǹ���
	p = new int[size];							//���ÿ� int�迭[size] �Ҵ��Ͽ� p�� ����
}

MyIntStack::MyIntStack(int size) {
	this->size = size;							//�Ű����� size�� ������� size�� ����
	this->tos = 0;								//tos������ 0���� �ʱ�ȭ
	p = new int[size];							//���ÿ� int �迭 �Ҵ��Ͽ� p�� ����
}

MyIntStack::~MyIntStack() {
	if(!p)										//p�� nullptr�� �ƴ϶��, �� ���������� �޸� �Ҵ�Ǿ��ٸ� ���� �޸� �迭 p�� ��ȯ
		delete []p;
}

MyIntStack::MyIntStack(const MyIntStack &s) {	//���� ������
	this->size = s.size;						//s�� size ����� ���� ��ü�� size ����� ����
	this->tos = s.tos;							//s�� tos ����� ���� ��ü�� tos ����� ����
	this->p = new int[size];					//���ÿ�  int�迭[size] �Ҵ��Ͽ� p�� ����
	for(int i=0; i<size; i++) {					//for���� �̿��Ͽ� s�� p[i]�� ���� ��ü�� p[i]�� ����
		this->p[i] = s.p[i];
	}
}

bool MyIntStack::push(int n) {
	if(tos == size)								//���� ���� �� ���¶��(���� ž �ε����� ���� �ִ� ũ��� �����ϸ�), false�� ����
		return false;
	p[tos] = n;									//������ ž��(p[?])�� n�� ����
	tos++;										//������ ž�� ����Ű�� �ε���(?)�� 1 ������Ŵ
	return true;								//true ����
}

bool MyIntStack::pop(int &n) {
	if(tos == 0)								//������ ��� ������ false�� ����
		return false;
	tos--;										//������ ž�� ����Ű�� �ε����� 1 ����
	n = p[tos];									//n�� ������ ž�� (p[?])�� ���� ����
	return true;
}
// �ǽ� 5���� ���� ��

MyIntStack& MyIntStack::operator << (int n) {	//push
	push(n);									//��� �Լ��� push()�� ȣ���Ͽ� n�� ���ÿ� Ǫ����
	return *this;								//�� ��ü�� ���� ����
}

MyIntStack& MyIntStack::operator >> (int &n) {	//pop
	pop(n);										//���ÿ��� ���� ���� n�� ����
	return *this;								//�� ��ü�� ���� ����
}

bool MyIntStack::operator ! () {
	if(tos == 0)								//������  ��������� true ����
		return true;
	else										//�׷��� ������ false ����
		return false;
}

MyIntStack& MyIntStack::operator = (const MyIntStack& s) {
	if(!p)										//������ p�� nullptr�� �ƴϸ�,
		delete []p;								//p�� ����Ű�� �޸� ��ȯ

	this->size = s.size;						//s�� size ����� ���� ��ü�� size ����� ����
	this->tos = s.tos;							//s�� tos ����� ���� ��ü�� tos ����� ����
	this->p = new int[size];					//���ÿ�  int�迭[size] �Ҵ��Ͽ� p�� ����
	for(int i=0; i<size; i++) {					//for���� �̿��Ͽ� s�� p[i]�� ���� ��ü�� p[i]�� ����
		this->p[i] = s.p[i];
	}
	return *this;								//�� ��ü�� ���� ����
}

MyIntStack operator + (const MyIntStack& s1, const MyIntStack& s2) {
	MyIntStack tmp(s1.tos+s2.tos);				//MyIntStack Ÿ���� �������� tmp(��ģũ��) ����
	tmp.tos = s1.tos + s2.tos;					//s1�� tos�� s2�� tos ����� ��ģ ���� tmp�� tos ����� ����

	for(int i=0; i<s1.tos; i++)					//s1�� p[i]�� tmp ��ü�� p[i]�� ����
		tmp.p[i] = s1.p[i];
	for(int i=0; i<s2.tos; i++)					//s2�� p[i]�� tmp ��ü�� p[i+?]�� ����
		tmp.p[i+s1.tos] = s2.p[i];
	return tmp;									//tmp�� ������
}

//main() �Լ�
int main() {
	MyIntStack a(10);
	a.push(10);
	a.push(20);

	MyIntStack b = a;
	b.push(30);

	int n;
	a.pop(n);									//���� a ��
	cout << "���� a���� ���� �� " << n << endl;
	b.pop(n);									//���� b ��
	cout << "���� b���� ���� �� " << n << endl;;

	//����  main() �Լ��� �������� ������ �߰��Ѵ�.
	a << 3 << 5 << 7;							//3, 5, 7�� ������� Ǫ��
	MyIntStack c;
	c = a + b;									//a, b �� ������ ��ģ �� ����� c�� ����
	while(true) {
		if(!c) break;							//������ ������� ���� ����
		c >> n;
		cout << n << ' ';
	}
	cout << endl;
}
