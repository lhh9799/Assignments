#include <cstdio> 
#include <iostream>
using namespace std;

bool isOrdered(int data[], int n) {
	for(int i=0; i<n-1; i++) {	//data[i+1]이 비교대상이므로 i값을 n-1 미만으로 지정 
		if(data[i] > data[i+1])	//data[i+1]이 data[i]보다 크거나 같아야 함 data[i]가 data[i+1]보다 크면 정렬이 되지 않았음을 의미 
			return false;		//오름차순으로 정렬되지 않은 데이터가 있는 경우 false 리턴(리턴할 경우 아래 문장들은 실행되지 않음) 
	}
	return true;	//모든 데이터가 오름차순인 경우 true 리턴 
}

int main() {
	int n;		//학생의 수 
	int *data;	//학생들의 키를 저장할 정수형 배열의 포인터 변수 
	
	scanf("%d", &n);	//학생의 수 입력받음 
	data = new int[n];	//도토리들의 키를 저장할 정수형 배열을 도토리의 수 만큼 동적으로 할당 
	
	for(int i=0; i<n; i++) {	//n(학생의 수)번 반복하여 
		scanf("%d", &data[i]);	//학생들의 키를 입력 받음
	}
	
	bool result = isOrdered(data, n);	//결과를 계산하는 함수 
	
	if(result) {		//boolean의 값이 true(학생들의 키가 오름차순으로 정렬되어있다)면
		printf("YES");	//콘솔에 "YES" 출력 
	}
	else {				//boolean의 값이 true(학생들의 키가 오름차순으로 정렬되어있다)가 아니라면
		printf("NO");	//콘솔에 "NO" 출력 
	}
	
	delete []data;	//동적할당한 배열의 메모리 해제 
	data = nullptr;	//배열을 가리치는 포인터에 저장된 주소값 삭제 
	
	return 0;
}
