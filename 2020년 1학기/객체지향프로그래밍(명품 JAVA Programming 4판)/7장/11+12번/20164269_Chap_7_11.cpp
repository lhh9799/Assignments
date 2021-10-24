#include <iostream>
using namespace std;

// 실습 5에서 복사
class MyIntStack {
	int *p;		//스택 메모리로 사용할 포인터
	int size;	//스택의 최대 크기
	int tos;	//스택의 탑을 가리키는 인덱스
public:
	MyIntStack();
	MyIntStack(int size);
	MyIntStack(const MyIntStack &s);	//복사 생성자
	~MyIntStack();
	bool push(int n);					//정수 n을 스택에 푸시한다. 스택이 꽉 차 있으면 false를, 아니면 true 리턴
	bool pop(int &n);					//스택의 탑에 있는 값을 n에 팝한다. 만일 스택이 비어 있으면 false를, 아니면 true 리턴

	//새로 추가해야 할 연산자 함수
	MyIntStack& operator << (int n);				//push: 객체 자신의 참조자를 리턴
	MyIntStack& operator >> (int& n);				//pop: 객체 자신의 참조자를 리턴
	bool operator !();								//스택이 비었으면 true 리턴
	MyIntStack& operator = (const MyIntStack& s);	//현재 스택에 s 스택의 내용을 대입
	friend MyIntStack operator + (const MyIntStack& s1, const MyIntStack& s2); //외부 + 연산자 함수를 프렌드로 선언
};

//MyStack의 각각의 멤버 함수 구현
MyIntStack::MyIntStack() {
	size = 10;									//할당할 배열의 크기
	this->tos = 0;								//tos변수 0으로 초기화. tos가 0이면 빈 스택을 의미함
	p = new int[size];							//스택용 int배열[size] 할당하여 p에 저장
}

MyIntStack::MyIntStack(int size) {
	this->size = size;							//매개변수 size를 멤버변수 size에 저장
	this->tos = 0;								//tos변수를 0으로 초기화
	p = new int[size];							//스택용 int 배열 할당하여 p에 저장
}

MyIntStack::~MyIntStack() {
	if(!p)										//p가 nullptr이 아니라면, 즉 정상적으로 메모리 할당되었다면 스택 메모리 배열 p를 반환
		delete []p;
}

MyIntStack::MyIntStack(const MyIntStack &s) {	//복사 생성자
	this->size = s.size;						//s의 size 멤버를 현재 객체의 size 멤버에 저장
	this->tos = s.tos;							//s의 tos 멤버를 현재 객체의 tos 멤버에 저장
	this->p = new int[size];					//스택용  int배열[size] 할당하여 p에 저장
	for(int i=0; i<size; i++) {					//for문을 이용하여 s의 p[i]를 현재 객체의 p[i]에 저장
		this->p[i] = s.p[i];
	}
}

bool MyIntStack::push(int n) {
	if(tos == size)								//스택 가득 찬 상태라면(스택 탑 인덱스가 스택 최대 크기와 동일하면), false를 리턴
		return false;
	p[tos] = n;									//스택의 탑에(p[?])에 n을 저장
	tos++;										//스택의 탑을 가리키는 인덱스(?)를 1 증가시킴
	return true;								//true 리턴
}

bool MyIntStack::pop(int &n) {
	if(tos == 0)								//스택이 비어 있으면 false를 리턴
		return false;
	tos--;										//스택의 탑을 가리키는 인덱스를 1 감소
	n = p[tos];									//n에 스택의 탑에 (p[?])의 값을 저장
	return true;
}
// 실습 5에서 복사 끝

MyIntStack& MyIntStack::operator << (int n) {	//push
	push(n);									//멤버 함수인 push()를 호출하여 n을 스택에 푸시함
	return *this;								//이 객체의 참조 리턴
}

MyIntStack& MyIntStack::operator >> (int &n) {	//pop
	pop(n);										//스택에서 팝한 값을 n에 저장
	return *this;								//이 객체의 참조 리턴
}

bool MyIntStack::operator ! () {
	if(tos == 0)								//스택이  비어있으면 true 리턴
		return true;
	else										//그렇지 않으면 false 리턴
		return false;
}

MyIntStack& MyIntStack::operator = (const MyIntStack& s) {
	if(!p)										//포인터 p가 nullptr이 아니면,
		delete []p;								//p가 가리키는 메모리 반환

	this->size = s.size;						//s의 size 멤버를 현재 객체의 size 멤버에 저장
	this->tos = s.tos;							//s의 tos 멤버를 현재 객체의 tos 멤버에 저장
	this->p = new int[size];					//스택용  int배열[size] 할당하여 p에 저장
	for(int i=0; i<size; i++) {					//for문을 이용하여 s의 p[i]를 현재 객체의 p[i]에 저장
		this->p[i] = s.p[i];
	}
	return *this;								//이 객체의 참조 리턴
}

MyIntStack operator + (const MyIntStack& s1, const MyIntStack& s2) {
	MyIntStack tmp(s1.tos+s2.tos);				//MyIntStack 타입의 지역변수 tmp(합친크기) 선언
	tmp.tos = s1.tos + s2.tos;					//s1의 tos와 s2의 tos 멤버를 합친 값을 tmp의 tos 멤버에 저장

	for(int i=0; i<s1.tos; i++)					//s1의 p[i]를 tmp 객체의 p[i]에 저장
		tmp.p[i] = s1.p[i];
	for(int i=0; i<s2.tos; i++)					//s2의 p[i]를 tmp 객체의 p[i+?]에 저장
		tmp.p[i+s1.tos] = s2.p[i];
	return tmp;									//tmp를 리턴함
}

//main() 함수
int main() {
	MyIntStack a(10);
	a.push(10);
	a.push(20);

	MyIntStack b = a;
	b.push(30);

	int n;
	a.pop(n);									//스택 a 팝
	cout << "스택 a에서 팝한 값 " << n << endl;
	b.pop(n);									//스택 b 팝
	cout << "스택 b에서 팝한 값 " << n << endl;;

	//기존  main() 함수의 마지막에 다음을 추가한다.
	a << 3 << 5 << 7;							//3, 5, 7을 순서대로 푸시
	MyIntStack c;
	c = a + b;									//a, b 두 스택을 합친 후 결과를 c에 대입
	while(true) {
		if(!c) break;							//스택이 비었으면 빠져 나감
		c >> n;
		cout << n << ' ';
	}
	cout << endl;
}
