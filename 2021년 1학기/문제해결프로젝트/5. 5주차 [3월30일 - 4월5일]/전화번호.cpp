#include <cstdio>	//C언어의 stdio.h와 같음 C의 입출력 함수를 포함하는 헤더파일
using namespace std;//표준 이름공간을 사용함

const int MAX_TABLE_LENGTH = 10000;	//0000부터 9999까지 10000개의 경우의 수를 가지는 전화번호를 const 상수로 선언(값을 변경할 수 없음)

//입력받은 전화번호의 빈도를 계산하는 함수
void fillFrequencyTable(int data[], int n, int table[]) {
	for(int i=0; i<MAX_TABLE_LENGTH; i++) {	//MAX_TABLE_LENGTH(10000)번 반복하여
		table[i] = 0;						//배열의 값을 0으로 초기화
	}

	for(int i=0; i<n; i++) {				//n(전화번호의 수)번 반복하여
		table[data[i]]++;					//전화번호(data[i])를 인덱스로 하여 빈도수 증가
	}
}

//계산된 빈도 중 최댓값을 찾는 함수
int getFrequentNumber(int data[], int n) {
	int frequent_number = 0;
	int table[MAX_TABLE_LENGTH];				//0~9999까지 전화번호의 빈도를 저장하는 히스토그램
	fillFrequencyTable(data, n, table);			//입력받은 전화번호를 인자로 넘겨 table 배열에 빈도를 채워넣음

	for(int i=0; i<MAX_TABLE_LENGTH; i++) {		//MAX_TABLE_LENGTH(10000)번 반복하여
		if(table[i] > table[frequent_number])	//i번째 번호가 가장 큰 번호를 저장하고 있는 변수의 값보다 크다면. 등장한 횟수가 같은 번호가 두 개 이상인 경우 사전순으로 빠른 숫자를 출력하기 위해 등호는 넣지 않는다.
			frequent_number = i;				//frequent_number를 i(최댓값을 가리키는 인덱스)로 갱신
	}

	return frequent_number;						//가장 많이 등장한 번호의 인덱스 리턴
}

int main() {
	int n;										//전화번호의 수(1이상 10만이하의 자연수)

	scanf("%d", &n);							//전화번호의 수 입력받음
	int *data = new int[n];						//전화번호를 저장할 배열을 전화번호의 수 만큼 동적으로 할당

	for(int i=0; i<n; i++) {					//n(전화번호의 수)번 반복하여
		scanf("%d", &data[i]);					//전화번호를 입력받음
	}

	int answer = getFrequentNumber(data, n);	//가장 많이 등장한 전화번호를 계산하여 answer 변수에 저장

	printf("%04d", answer);						//4자리로 자릿수를 채워 출력(예 10 -> 0010)

	delete []data;								//동적할당한 배열의 메모리 해제
	data = nullptr;								//배열을 가리키는 포인터에 저장된 주소값 삭제

	return 0;									//메인함수를 정상적으로 끝냄
}

