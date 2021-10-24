#include <cstdio>
#include <iostream>
using namespace std;

int getMinIndexInRange(int data[], int n, int begin, int end) {
	int idx = begin, min = data[begin];	//최솟값을 찾기 위해 초기값 지정 
	
	for(int it=begin; it<end+1; it++) {	//마지막 원소에도 접근하기 위해 end변수에 1을 더해야 함 
		if(data[it] < min) {			//현재 가지고 있는 최솟값보다 작은 최솟값을 찾은 경우 
			idx = it;					//인덱스 갱신 
			min = data[it];				//최솟값 갱신
		}
	}
	
	return idx;
}

void selectionSort(int data[], int n) {
	for(int i=0; i<n; i++) {
		int minIndex = getMinIndexInRange(data, n, i, n-1);
		//현재 위치와 최솟값의 데이터를 교환
		int temp = data[i];
		data[i] = data[minIndex];
		data[minIndex] = temp;
	}
}

int main() {
	int n;				//전체 데이터의 수 
	int *data;			//데이터들이 저장될 배열의 포인터 변수 
	
	scanf("%d", &n);
	data = new int[n];	//배열의 원소의 수 만큼 배열을 동적할당
	
	for(int i = 0; i<n; i++) {
		scanf("%d", &data[i]);
	}
	
	selectionSort(data, n);
	
	for(int i=0; i<n; i++) {
		if(i>0) {
			printf(" ");
		}
		printf("%d", data[i]);
	}
	
	delete data;	//동적할당한 배열의 메모리 해제
	data = nullptr;	//배열을 가리치는 포인터에 저장된 주소값 삭제 
	
	return 0;
}
