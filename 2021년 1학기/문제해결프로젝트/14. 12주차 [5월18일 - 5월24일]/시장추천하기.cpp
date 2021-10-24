#include <iostream>	//입출력 함수를 사용하기 위한 헤더파일
#include <string>	//.c_str함수를 사용하기 위한 헤더파일
#include <map>		//map 클래스를 사용하기 위한 헤더파일(각 노드가 key와 value 쌍으로 이루어진 트리. 중복을 허용하지 않음. 오름차순 정렬)
using namespace std;//표준 이름공간을 사용함

int main() {
	int N;		//투표용지의 수
	cin >> N;	//투표용지의 수 입력받음

	//각 후보 이름과 득표 수를 저장하는 key-value Map
	map<string, int> frequencyMap;

	int maxFrequency = 0;	//가장 많은 득표수

	//각 이름이 하나 추가될 때마다 현재까지의 최다 득표 값 갱신. 최다 득표 후보 리스트를 갱신해간다.
	for(int i=0; i<N; i++) {		//N(투표용지의 수)번 반복하여
		string st;					//후보자의 이름 선언
		cin >> st;					//후보자의 이름 입력받음
		frequencyMap[st]++;			//해당 후보자의 빈도수 1증가
		int k = frequencyMap[st];	//해당 후보자의 빈도수를 정수형 변수 k에 저장
		if(k > maxFrequency) {		//k가 이전에 저장한 최다 득표값 보다 크다면
			maxFrequency = k;		//k를 최다 득표값으로 갱신
		}
	}

	//최대 득표 후보 수를 출력한다.
	cout << maxFrequency << endl;

	//최대 득표를 한 동점 후보들 이름을 사전순으로 출력한다.
	map<string, int>::iterator it;		//map 반복자 it 선언
	for(it=frequencyMap.begin(); it!=frequencyMap.end(); it++) {	//첫 번재 원소에 대한 참조로 초기화. 마지막 원소 다음을 가리키는 참조가 아닐때 까지 반복. 주소값 증가
		if(it->second == maxFrequency)	//벡터의 원소중 value값이 maxFrequency(최다 득표값)와 같다면
			printf("%s ", it->first.c_str());	//해당 원소의 key값 출력
	}
}
