#include <cstdio>	//C언어의 stdio.h와 같음 C의 입출력 함수를 포함하는 헤더파일
#include <iostream>	//C++ 스트림을 포함한 헤더파일
using namespace std;//표준 이름공간을 사용함

/*
*알고리즘 : 연속적인 수열은 최댓값 - 최솟값 + 1 이 수열의 개수와 같다
*예) 5이상 10이하의 자연수가 중복없이 나열되어 있다고 하자. 최댓값 - 최솟값 + 1 = 10 - 5 + 1 = 6이다. 개수 또한 6개이다.
*/
bool isConsecutive(int data[], int n) {
	int max_data = data[0];	//승철이가 본 에피소드의 번호 중 가장 큰 번호를 저장할 변수. data[0]으로 초기화 함
	int min_data = data[0];	//승철이가 본 에피소드의 번호 중 가장 작은 번호를 저장할 변수. data[0]으로 초기화 함

	for(int i=0; i<n; i++) {	//n(승철이가 본 에피소드의 수)번 반복하여
		if(data[i] > max_data)	//검사하고 있는 번호가 가장 큰 번호를 저장하고 있는 변수의 값보다 크다면
			max_data = data[i];	//최댓값 갱신
		if(data[i] < min_data)	//검사하고 있는 번호가 가장 작은 번호를 저장하고 있는 변수의 값보다 작다면
			min_data = data[i];	//최솟값 갱신
	}

	if((max_data - min_data + 1) == n)	//최댓값 - 최솟값 + 1 이 수열의 개수와 같다면
		return true;					//true 리턴
	else								//그렇지 않다면
		return false;					//false 리턴
}

int main() {
	int n;		//승철이가 본 에피소드의 수
	int *data;	//승철이가 본 에피소드를 저장한 배열을 가리키는 포인터 변수

	scanf("%d", &n);	//승철이가 본 에피소드의 수 입력받음
	data = new int[n];	//승철이가 본 에피소드를 저장한 배열을 승철이가 본 에피소드의 수 만큼 동적으로 할당

	for(int i=0; i<n; i++) {	//n(승철이가 본 에피소드의 수)번 반복하여
		scanf("%d", &data[i]);	//승철이가 본 에피소드의 번호를 입력받음
	}

	bool result = isConsecutive(data, n);	//승철이가 본 에피소드의 번호들이 연속적인 수열로 표현할 수 있는지 검사한 후 논리값을 result변수에 저장

	if(result) {			//승철이가 본 에피소드의 번호들이 연속적인 수열로 표현될 수 있다면
		printf("YES");		//"YES" 출력
	}
	else {					//그렇지 않다면
		printf("NO");		//"NO" 출력
	}

	delete []data;	//동적할당한 배열의 메모리 해제
	data = nullptr;	//배열을 가리키는 포인터에 저장된 주소값 삭제

	return 0;		//메인함수를 정상적으로 끝냄
}

