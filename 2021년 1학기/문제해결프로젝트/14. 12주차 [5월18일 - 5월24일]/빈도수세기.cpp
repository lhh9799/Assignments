#include <stdio.h>	//C언어의 stdio.h와 같음 C의 입출력 함수를 포함한 헤더파일
#include <map>		//map 클래스를 사용하기 위한 헤더파일(각 노드가 key와 value 쌍으로 이루어진 트리. 중복을 허용하지 않음. 오름차순 정렬)
using namespace std;//표준 이름공간을 사용함

int main() {
	int N;			//정수의 수 선언
	scanf("%d", &N);//정수의 수 입력받음

	//각 <정수,빈도수>평태로 key-value를 저장할 Map 자료구조
	//frequencyMap := 이전에 입력된 정수들의 빈도수를 저장하고 있다.
	map<int, int> frequencyMap;

	for(int i=0; i<N; i++) {//N(정수들의 수)번 반복하여
		int X;				//입력받을 정수 선언
		scanf("%d", &X);	//정수 입력받음
		frequencyMap[X]++;	//해당 정수의 빈도수 1증가
		printf("%d %d\n", frequencyMap.size(), frequencyMap[X]);	//숫자의 종류와 입력받은 정수가 등장한 횟수 출력
	}

	return 0;				//메인함수를 정상적으로 끝냄
}
