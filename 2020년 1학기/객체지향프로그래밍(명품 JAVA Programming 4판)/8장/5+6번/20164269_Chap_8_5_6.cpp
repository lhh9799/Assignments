#include <iostream>
using namespace std;

//정수값 value를 저장하고 있는 double linked 리스트의 한 노드
class Node {
private:
	friend class BaseList;//BaseList에서만 Node의 모든 멤버에 접근할 수 있게 클래스 전체를 friend로 선언

	Node *prev;	//리스트의 앞 노드를 포인트함
	Node *next;	//리스트의 다음 노드를 포인트함
	int value;	//노드에 저장할 정수값, 생성자에서 저장됨

	Node(int value) {
		prev = next = nullptr;
		this->value = value;
	}

	int getValue() {//노드에 저장된 정수값 리턴
		return value;
	}

	//현재 노드 다음에 n 노드를 추가한다.
	void add(Node *n) {
		next = n;
		n->prev = this;
	}

	//현재 노드를 삭제하고 이 노드의 next 노드를 리턴한다.
	Node *remove() {
		Node *n = next;
		delete this;
		return n;
	}
};

//여러 개의 노드들을 가지고 있는 double linked 리스트
class BaseList {
private:
	Node *head;	//double linked 리스트의 맨 처음 노드를 가리키는 포인터
	Node *tail;	//double linked 리스트의 맨 마지막 노드를 가리키는 포인터
protected:
	int size;	//현재 리스트 내에 있는 노드의 개수

	BaseList() {
		head = tail = nullptr;
		size = 0;
	}

	~BaseList() {//소멸자: 모든 노드를 삭제함
		for(Node *n = head; n!= nullptr; n = n-> remove());
	}

	void add_rear(int value);	//리스트의 맨 마지막에 노드 추가 후, value저장
	int remove_rear();			//리스트의 맨 마지막에 노드 삭제 후, value 값 리턴
	int remove_front();			//리스트의 첫 번째 노드 삭제 후, value 값 리턴
};

//새로운 노드(value 값을 저장하고 있음)를 생성한 후 리스트의 맨 마지막에 추가
void BaseList::add_rear(int value) {
	Node *n = new Node(value);	//Node의 포인터 변수 n을 선언하고 새로운 Node를 동적으로 생성(value 값 전달)하여 n에 저장;

	if(tail != nullptr) {	//만약 tail이 nullptr이 아니면
		tail->add(n);		//tail의 멤버함수 add(n)호출하여 리스트의 맨 끝에 n을 추가
		tail = n;			//리스트 끝에 새로 추가 되었으므로 tail을 n으로 설정
	}
	else					//리스트에 노드가 없을 경우 n이 첫 노드가 됨
		tail = head = n;	//tail과 head 값을 n으로 설정
	size++;					//리스트의 노드 개수를 1 증가
}

//리스트의 마지막 노드를 제거한 후 그 노드에 저장된 value를 리턴
int BaseList::remove_rear() {
	if(size == 0)			//리스트의 노드 개수가 0이면 -1 리턴
		return -1;

	//정수형 변수 val을 선언하고, tail노드에 저장된 value 값을 얻어와 val에 저장
	int val = tail->value;
	//삭제할 노드의 앞 노드를 저장할 변수 prev 선언 및 초기화
	Node *prev = tail->prev;
	delete tail;	//tail노드를 메모리에 반납함
	size--;			//리스트의 노드 개수를 1 감소

	if(prev != nullptr) {		//변수 prev가 nullptr이 아니면 즉, 삭제할 노드의 앞 노드가 존재할 경우
		prev->next = nullptr;	//변수 prev가 포인트하는 노드의 next 멤버를 nullptr로 설정함
		tail = prev;
	}
	else						//변수 prev가 nullptr이면 즉, 더 이상 남은 노드가 없는 경우
		tail = head = nullptr;	//tail과 head 값을 nullptr로 설정

	return val;					//val 값을 리턴
}

//리스트의 맨 처음 노드를 제거한 후 그 노드에 저장된 value를 리턴
int BaseList::remove_front() {
	if(size == 0)	//리스트의 노드 개수가 0이면 -1 리턴
		return -1;

	//정수형 변수 val을 선언하고, head 노드에 저장된 value 값을 얻어와 val에 저장
	int val = head->value;
	//삭제할 노드의 뒤 노드를 저장할 변수 next 선언 및 초기화
	Node *next = head->next;
	delete head;	//head노드를 메모리에 반납함
	size--;			//리스트의 노드 개수를 1 감소

	if(next != nullptr) {		//변수 next가 nullptr이 아니면 즉, 삭제할 노드의 뒤 노드가 존재할 경우
		next->prev = nullptr;	//변수 next가 포인트하는 노드의 prev 멤버를 nullptr로 설정함
		head = next;
	}
	else						//아닌경우 즉, 변수 next가 nullptr이면(더 이상 남은 노드가 없는 경우)
		tail = head = nullptr;	//tail과 head 값을 nullptr로 설정

	return val;					//val 값을 리턴
}

class MyQueue : public BaseList {
public:
	void enqueue(int value) {	//큐의 맨 끝에 노드(value 저장된) 추가
		add_rear(value);
	}
	//큐의 맨 앞의 노드 삭제하고 저장된 value 리턴
	int dequeue() {
		return remove_front();
	}
	//큐의 길이를 리턴
	int length() {
		return size;
	}

	static void test();
};

void MyQueue::test() {
	MyQueue mQ;
	int n;
	cout << "큐에 삽입할 5개의 정수를 입력하라>> ";
	for(int i=0; i<5; i++) {
		cin >> n;
		mQ.enqueue(n);//큐에 삽입
	}
	cout << "큐의 크기:" << mQ.length() << endl;
	cout << "큐의 원소를 순서대로 제거하여 출력한다>> ";
	while(mQ.length() != 0)
		cout << mQ.dequeue() << ' ';	//큐에서 제거하여 출력
	cout  << endl << "큐의 현재 크기 : " << mQ.length() << endl;
}

class MyStack : public BaseList{//MyStack의 test()함수 구현 코드
public:
	//스택의 맨 끝에 노드(value 저장) 추가
	void push(int value) {
		add_rear(value);
	}
	//스택의 맨 끝의 노드 삭제하고 저장된 value 리턴
	int pop() {
		return remove_rear();
	}
	//스택의 길이를 리턴
	int length() {
		return size;
	}

	static void test();
};

void MyStack::test() {
	MyStack mStack;
	int n;
	cout << "스택에 삽입할 5개의 정수를 입력하라>> ";
	for(int i=0; i<5; i++) {
		cin >> n;
		mStack.push(n);				//스택에 푸시
	}
	cout << "스택 크기:" << mStack.length() << endl;
	cout << "스택의 모든 원소를 팝하여 출력한다>> " ;
	while(mStack.length() != 0)
		cout << mStack.pop() << ' ';//스택에서 팝
	cout << endl << "스택의 현재 크기 : " << mStack.length() << endl;
}

int main() {
	MyQueue::test();
	MyStack::test();
}
