#include <cstdio>
#include <iostream>
using namespace std;

int getMaximumHeight(int height[], int month[], int n, int m) {
	for(int i=n-1; i>=0; i--) {	//도토리들의 키가 오름차순으로 입력되어 있기 때문에 뒤에서부터 탐색
		if(month[i] == m)
			return height[i];	//이번 달에 생일이 있는 도토리들 중 가장 키가 큰 도토리의 키를 리턴(리턴할 경우 아래 문장들은 실행되지 않음) 
	}
	
	return -1;					//생일에 해당 달에 속한 도토리가 없는 경우 -1을 리턴 
}

int main() {
	int n, m;		//n : 도토리의 수, m : 현재 달 
	int *height;	//도토리들의 키를 저장할 정수형 배열의 포인터 변수 
	int *month;		//도토리들의 생일이 속한 달을 저장할 정수형 배열의 포인터 변수 
	
	scanf("%d", &n);
	height = new int[n];	//도토리들의 키를 저장할 정수형 배열을 도토리의 수 만큼 동적으로 할당 
	month = new int[n];		//도토리들의 생일이 속한 달을 저장할 정수형 배열을 도토리의 수 만큼 동적으로 할당 
	
	for(int i=0; i<n; i++) {		//n(도토리의 수)번 반복하여 
		scanf("%d", &height[i]);	//도토리들의 키를 입력 받음
	}
	
	for(int i=0; i<n; i++) {	//n(도토리의 수)번 반복하여 
		scanf("%d", &month[i]);	//도토리들의 생일이 속한 달을 입력 받음 
	}
	
	scanf("%d", &m);	//현재 달을 입력 받음 
	
	int answer = getMaximumHeight(height, month, n, m);	//결과를 계산하는 함수 
	
	printf("%d\n", answer);	//이번 달에 생일이 있는 도토리들 중 가장 키가 큰 도토리의 키를 출력 
	
	delete []height;	//동적할당한 배열의 메모리 해제 
	delete []month;		//동적할당한 배열의 메모리 해제 
	height = nullptr;	//배열을 가리치는 포인터에 저장된 주소값 삭제 
	month = nullptr;	//배열을 가리치는 포인터에 저장된 주소값 삭제 
	
	return 0;
}
