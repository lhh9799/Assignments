#include <iostream>
using namespace std;

//������ value�� �����ϰ� �ִ� double linked ����Ʈ�� �� ���
class Node {
private:
	friend class BaseList;//BaseList������ Node�� ��� ����� ������ �� �ְ� Ŭ���� ��ü�� friend�� ����

	Node *prev;	//����Ʈ�� �� ��带 ����Ʈ��
	Node *next;	//����Ʈ�� ���� ��带 ����Ʈ��
	int value;	//��忡 ������ ������, �����ڿ��� �����

	Node(int value) {
		prev = next = nullptr;
		this->value = value;
	}

	int getValue() {//��忡 ����� ������ ����
		return value;
	}

	//���� ��� ������ n ��带 �߰��Ѵ�.
	void add(Node *n) {
		next = n;
		n->prev = this;
	}

	//���� ��带 �����ϰ� �� ����� next ��带 �����Ѵ�.
	Node *remove() {
		Node *n = next;
		delete this;
		return n;
	}
};

//���� ���� ������ ������ �ִ� double linked ����Ʈ
class BaseList {
private:
	Node *head;	//double linked ����Ʈ�� �� ó�� ��带 ����Ű�� ������
	Node *tail;	//double linked ����Ʈ�� �� ������ ��带 ����Ű�� ������
protected:
	int size;	//���� ����Ʈ ���� �ִ� ����� ����

	BaseList() {
		head = tail = nullptr;
		size = 0;
	}

	~BaseList() {//�Ҹ���: ��� ��带 ������
		for(Node *n = head; n!= nullptr; n = n-> remove());
	}

	void add_rear(int value);	//����Ʈ�� �� �������� ��� �߰� ��, value����
	int remove_rear();			//����Ʈ�� �� �������� ��� ���� ��, value �� ����
	int remove_front();			//����Ʈ�� ù ��° ��� ���� ��, value �� ����
};

//���ο� ���(value ���� �����ϰ� ����)�� ������ �� ����Ʈ�� �� �������� �߰�
void BaseList::add_rear(int value) {
	Node *n = new Node(value);	//Node�� ������ ���� n�� �����ϰ� ���ο� Node�� �������� ����(value �� ����)�Ͽ� n�� ����;

	if(tail != nullptr) {	//���� tail�� nullptr�� �ƴϸ�
		tail->add(n);		//tail�� ����Լ� add(n)ȣ���Ͽ� ����Ʈ�� �� ���� n�� �߰�
		tail = n;			//����Ʈ ���� ���� �߰� �Ǿ����Ƿ� tail�� n���� ����
	}
	else					//����Ʈ�� ��尡 ���� ��� n�� ù ��尡 ��
		tail = head = n;	//tail�� head ���� n���� ����
	size++;					//����Ʈ�� ��� ������ 1 ����
}

//����Ʈ�� ������ ��带 ������ �� �� ��忡 ����� value�� ����
int BaseList::remove_rear() {
	if(size == 0)			//����Ʈ�� ��� ������ 0�̸� -1 ����
		return -1;

	//������ ���� val�� �����ϰ�, tail��忡 ����� value ���� ���� val�� ����
	int val = tail->value;
	//������ ����� �� ��带 ������ ���� prev ���� �� �ʱ�ȭ
	Node *prev = tail->prev;
	delete tail;	//tail��带 �޸𸮿� �ݳ���
	size--;			//����Ʈ�� ��� ������ 1 ����

	if(prev != nullptr) {		//���� prev�� nullptr�� �ƴϸ� ��, ������ ����� �� ��尡 ������ ���
		prev->next = nullptr;	//���� prev�� ����Ʈ�ϴ� ����� next ����� nullptr�� ������
		tail = prev;
	}
	else						//���� prev�� nullptr�̸� ��, �� �̻� ���� ��尡 ���� ���
		tail = head = nullptr;	//tail�� head ���� nullptr�� ����

	return val;					//val ���� ����
}

//����Ʈ�� �� ó�� ��带 ������ �� �� ��忡 ����� value�� ����
int BaseList::remove_front() {
	if(size == 0)	//����Ʈ�� ��� ������ 0�̸� -1 ����
		return -1;

	//������ ���� val�� �����ϰ�, head ��忡 ����� value ���� ���� val�� ����
	int val = head->value;
	//������ ����� �� ��带 ������ ���� next ���� �� �ʱ�ȭ
	Node *next = head->next;
	delete head;	//head��带 �޸𸮿� �ݳ���
	size--;			//����Ʈ�� ��� ������ 1 ����

	if(next != nullptr) {		//���� next�� nullptr�� �ƴϸ� ��, ������ ����� �� ��尡 ������ ���
		next->prev = nullptr;	//���� next�� ����Ʈ�ϴ� ����� prev ����� nullptr�� ������
		head = next;
	}
	else						//�ƴѰ�� ��, ���� next�� nullptr�̸�(�� �̻� ���� ��尡 ���� ���)
		tail = head = nullptr;	//tail�� head ���� nullptr�� ����

	return val;					//val ���� ����
}

class MyQueue : public BaseList {
public:
	void enqueue(int value) {	//ť�� �� ���� ���(value �����) �߰�
		add_rear(value);
	}
	//ť�� �� ���� ��� �����ϰ� ����� value ����
	int dequeue() {
		return remove_front();
	}
	//ť�� ���̸� ����
	int length() {
		return size;
	}

	static void test();
};

void MyQueue::test() {
	MyQueue mQ;
	int n;
	cout << "ť�� ������ 5���� ������ �Է��϶�>> ";
	for(int i=0; i<5; i++) {
		cin >> n;
		mQ.enqueue(n);//ť�� ����
	}
	cout << "ť�� ũ��:" << mQ.length() << endl;
	cout << "ť�� ���Ҹ� ������� �����Ͽ� ����Ѵ�>> ";
	while(mQ.length() != 0)
		cout << mQ.dequeue() << ' ';	//ť���� �����Ͽ� ���
	cout  << endl << "ť�� ���� ũ�� : " << mQ.length() << endl;
}

class MyStack : public BaseList{//MyStack�� test()�Լ� ���� �ڵ�
public:
	//������ �� ���� ���(value ����) �߰�
	void push(int value) {
		add_rear(value);
	}
	//������ �� ���� ��� �����ϰ� ����� value ����
	int pop() {
		return remove_rear();
	}
	//������ ���̸� ����
	int length() {
		return size;
	}

	static void test();
};

void MyStack::test() {
	MyStack mStack;
	int n;
	cout << "���ÿ� ������ 5���� ������ �Է��϶�>> ";
	for(int i=0; i<5; i++) {
		cin >> n;
		mStack.push(n);				//���ÿ� Ǫ��
	}
	cout << "���� ũ��:" << mStack.length() << endl;
	cout << "������ ��� ���Ҹ� ���Ͽ� ����Ѵ�>> " ;
	while(mStack.length() != 0)
		cout << mStack.pop() << ' ';//���ÿ��� ��
	cout << endl << "������ ���� ũ�� : " << mStack.length() << endl;
}

int main() {
	MyQueue::test();
	MyStack::test();
}
