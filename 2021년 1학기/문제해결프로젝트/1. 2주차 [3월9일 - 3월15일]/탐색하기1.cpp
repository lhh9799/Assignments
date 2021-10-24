#include <stdio.h>
#include <iostream>
using namespace std;

int findindex(int data[], int n, int m) {
	int RSLT = -1;			//배열에서 찾고자 하는 값을 찾지 못할 경우 -1을 리턴하기 위해 초기값 지정 
	
	for(int i=0; i<n; i++) {//n(배열 원소의 수)번 반복하여 
		if(data[i] == m) {	//배열에서 찾고자 하는 값을 찾은 경우 
			RSLT = i;
			break;			//배열에 중복되는 자료가 없으므로(서로 다른 자연수가 저장) 더 이상 찾고자 하는 값이 있을 수 없다. 불필요한 반복문을 탈출함. 
		}
	}
	
	return RSLT;			//찾고자 하는 값과 배열에 저장된 데이터가 일치하는 인덱스를 리턴 
}

int main() {
	int n, m;	//n : 배열 원소의 수, m : 찾고자 하는 값 
	int *data;	//서로 다른 자연수가 저장되는 정수형 배열의 포인터 변수 
	
	scanf("%d %d", &n, &m);
	data = new int[n];	//배열의 원소의 수 만큼 배열을 동적할당
	
	for(int i=0; i<n; i++) {	//n(배열 원소의 수)번 반복하여 
		scanf("%d", &data[i]);	//자연수를 입력받음 
	}
	
	int answer = findindex(data, n, m);	//결과를 계산하는 함수
	
	printf("%d\n", answer);	//결과 출력 
	
	delete []data;	//동적할당한 배열의 메모리 해제
	data = nullptr;	//배열을 가리치는 포인터에 저장된 주소값 삭제 
	
	return 0;
}
