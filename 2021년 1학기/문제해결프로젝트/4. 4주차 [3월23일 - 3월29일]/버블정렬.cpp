#include <cstdio>	//C언어의 stdio.h와 같음 C의 입출력 함수를 포함하는 헤더파일
#include <iostream>	//C++ 스트림을 포함한 헤더파일
using namespace std;//표준 이름공간을 사용함

void bubbleSort(int data[], int n) {
	for(int i=0; i<n; i++) {				//i는 어디까지 비교해야할지 위치를 알려줌
		for(int j=0; j<n-1-i; j++) {		//아래 조건문에서 j+1을 인덱스로 사용하기 때문에 1만큼 빼줌. 오른쪽의 i개의 수는 정렬되어 있기 때문에 i만큼 빼줌.
			if(data[j] > data[j+1]) {		//왼쪽의 수가 오른쪽의 수보다 큰 경우
				//임시 변수 temp에 data[j]를 저장하여 두 값을 바꿈
				int temp = data[j];
				data[j] = data[j+1];
				data[j+1] = temp;
			}
		}
	}
}

int main() {
	int n;						//데이터의 수
	int *data;					//Point2D형 인스턴스들의 배열을 가리키는 포인터 변수

	scanf("%d", &n);			//데이터의 수 입력받음
	data = new int[n];			//하늘에 떠 있는 천체의 정보를 저장할 배열을 천체의 수 만큼 동적으로 할당

	for(int i=0; i<n; i++) {	//n(데이터의 수)번 반복하여
		scanf("%d", &data[i]);	//데이터를 입력받아 data배열에 저장
	}
	
	bubbleSort(data, n);		//배열 안의 데이터를 버블정렬 함

	for(int i=0; i<n; i++) {	//n(데이터의 수)번 반복하여
		if(i > 0) {				//출력할 데이터가 남아있다면
			printf(" ");		//공백(" ")을 출력
		}
		printf("%d", data[i]);	//정렬된 데이터 출력
	}

	delete []data;				//동적할당한 배열의 메모리 해제
	data = nullptr;				//배열을 가리키는 포인터에 저장된 주소값 삭제

	return 0;					//메인함수를 정상적으로 끝냄
}

