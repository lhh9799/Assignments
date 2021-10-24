#include <cstdio>
#include <cmath>
#include <iostream>
using namespace std;

int findIndex(int data[], int n) {
	int sum = 0, diff, idx = 0;
	
	for(int i=0; i<n; i++) {
		sum += data[i];							//전체 데이터의 합 계산 
	}
	
	diff = abs(data[0] * n - sum);				//배열의 첫번째 원소와 자료의 수인 n을 곱한 값에 sum(전체 데이터 합의 차)과의 차에 대한 절댓값 
	
	for(int i=0; i<n; i++) {
		if (diff > abs(data[i] * n - sum)) {	//절댓값이 더 작은 원소를 찾은 경우 
			idx = i;							//idx값 갱신 
			diff = abs(data[i] * n - sum);		//최소 절댓값 갱신 
		}
	}
	
	return idx;
}

int main() {
	int n;				//전체 데이터의 수 
	int *data;			//데이터들이 저장될 배열의 포인터 변수 
	
	scanf("%d", &n);
	data = new int[n];	//배열의 원소의 수 만큼 배열을 동적할당
	
	for(int i=0; i<n; i++) {
		scanf("%d", &data[i]);
	}
	
	int answer = findIndex(data, n);
	printf("%d %d\n", answer+1, data[answer]);	//index값이 1부터 시작하도록 만들기 위해 answer에 1을 더함
	
	delete []data;	//동적할당한 배열의 메모리 해제
	data = nullptr;	//배열을 가리치는 포인터에 저장된 주소값 삭제 
	
	return 0;
}
