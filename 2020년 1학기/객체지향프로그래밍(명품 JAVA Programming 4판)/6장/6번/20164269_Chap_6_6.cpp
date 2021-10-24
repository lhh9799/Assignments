#include <iostream>
using namespace std;

class ArrayUtility2 {
public:
	static int* concat(int s1[], int s2[], int size);
	static int* remove(int s1[], int s2[], int size, int&retSize);
};

int* ArrayUtility2::concat(int s1[], int s2[], int size) {
	int *p = new int[size*2];
	if(!p)
		return NULL;
	for(int i=0; i<size; i++)
		p[i] = s1[i];
	for(int i=0; i<size; i++)
		p[i+5] = s2[i];

	return p;
}

int* ArrayUtility2::remove(int s1[], int s2[], int size, int&retSize) {
	int *p = new int[size];
	if(!p) {
		retSize = 0;
		return NULL;
	}
	int k=0; //결과 배열 p의 첨자로 사용할 변수 선언

	for(int i=0; i<size; i++) {
		int j;

		for(j=0; j<size; j++) {
			if(s1[i] == s2[j])
				break;
		} //s1[i] 값이 배열 s2에 존재하면 j는 size보다 작은 값임
		if(j == size) { //s1[i] 값이 배열 s2에 존재하지 않은 경우임
			p[k++] = s1[i];
		}
	}

	retSize = k;
	if(retSize == 0)
		return NULL;

	int *q = new int[retSize];
	if(!q) {
		retSize = 0;
		return NULL;
	}
	for(int i=0; i<retSize; i++)
		q[i] = p[i];

	delete []p;

	return q;
}

int main() {
	int x[5], y[5]; //int 배열 x[5], y[5] 선언

	cout << "정수를 5개 입력하라. 배열 x에 삽입한다>> ";
	for(int i=0; i<5; i++)
		cin >> x[i]; //for문을 이용하여 각 정수를 배열 원소 x[i]에 입력 받음

	cout << "정수를 5개 입력하라. 배열 y에 삽입한다>> ";
	for(int i=0; i<5; i++)
		cin >> y[i]; //for문을 이용하여 각 정수를 배열 원소 y[i]에 입력 받음

	int *p = ArrayUtility2::concat(x, y, 5); //int 포인터 변수 p를 선언함과 동시에 ArrayUtility2의 정적(static) 함수 concat(x, y, 5)를 호출하고 리턴 값을 p에 저장
	cout << "합친 정수 배열을 출력한다" << endl;
	for(int i=0; i<10; i++)
		cout << p[i] << ' ';
	cout << endl;

	int retSize;
	int *q = ArrayUtility2::remove(x, y, 5, retSize);
	cout << "배열 x[]에서 y[]를 뺀 결과를 출력한다. 개수는 " << retSize << endl;
	for(int i=0; i<retSize; i++)
		cout << q[i] << ' ';
	cout << endl;

	delete p, q;
}
