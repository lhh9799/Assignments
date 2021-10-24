#include <cstdio>
#include <iostream>
using namespace std;

int getElementTypeCount(int data[], int n) {
	int countType = 1;	//적어도 1개의 고유한 값을 가지고 있음 
	
	for(int i=0; i<n-1; i++) {	//data[i+1]이 비교대상이므로 i값을 n-1 미만으로 지정 
		if(data[i] != data[i+1])//현재값이 다음값과 다르다면 countType 증가 
			countType++;
	}
	
	return countType;
}

int main() {
	int n;		//화보의 수 
	int *data;	//화보의 고유번호를 저장할 정수형 배열의 포인터 변수
	
	scanf("%d", &n);
	data = new int[n];	//화보의 고유번호를 저장할 정수형 배열을 화보의 수 만큼 동적으로 할당 
	
	for(int i=0; i<n; i++) {	//n(화보의 수)번 반복하여 
		scanf("%d", &data[i]);	//화보의 고유번호를 입력 받음
	}
	
	int answer = getElementTypeCount(data, n);	//결과를 계산하는 함수 
	
	printf("%d\n", answer);	//중복을 제외한 화보의 종류의 수를 출력
	
	delete []data;	//동적할당한 배열의 메모리 해제 
	data = nullptr;	//배열을 가리치는 포인터에 저장된 주소값 삭제 
	
	return 0;
}
