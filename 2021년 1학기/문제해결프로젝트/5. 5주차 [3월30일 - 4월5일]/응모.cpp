#include <cstdio>	//C언어의 stdio.h와 같음 C의 입출력 함수를 포함한 헤더파일
#include <vector>	//vector 클래스를 사용하기 위한 헤더파일(배열과의 차이점 : 가변형, 입출력 함수 제공)
#include <algorithm>//탐색, 정렬, 셈, 수정 등 여러 함수를 포함하는 헤더파일
using namespace std;//표준 이름공간을 사용함

const int MAX_SERIAL_NUMBER = 100000;			//시리얼 번호의 최댓값을 const 상수로 선언(값을 변경할 수 없음)

//입력받은 시리얼 번호의 빈도를 계산하는 함수
void fillFrequencyTable(const vector<int> &data, int n, vector<int> &table) {	//data벡터를 참조변수로 받아 불필요한 복사를 피한다
	table.resize(MAX_SERIAL_NUMBER + 1,  0);	//벡터 table의 크기를 MAX_SERIAL_NUMBER + 1로 지정(크기를 100000로 지정하면 99999번 인덱스까지만 생성되기 때문), 0으로 초기화

	for(int i=0; i<n; i++) {					//n(데이터의 수)번 반복하여
		table[data[i]]++;						//시리얼 번호(data[i])를 인덱스로 하여 빈도수 증가
	}
}

//중복없는 시리얼 번호를 리턴하는 함수
vector<int> getUniqueElements(const vector<int> &data, int n) {	//data벡터를 참조변수로 받아 불필요한 복사를 피한다
	vector<int> ret;	//중복없는 시리얼 번호를 저장할 벡터 ret 선언
	vector<int> table;	//시리얼 번호의 빈도를 저장하는 히스토그램

	fillFrequencyTable(data, n, table);	//data(입력받은 시리얼 번호 배열)를 인자로 넘겨 table 배열에 빈도를 채워넣음

	for(int i=1; i<=MAX_SERIAL_NUMBER; i++) {					//MAX_SERIAL_NUMBER(시리얼 번호의 최댓값)번 반복하여
		if(table[i] == 1) {										//전체 데이터에서 한 번 등장한 원소라면
			ret.push_back(i);									//벡터의 맨 뒤에 원소 삽입
		}
	}

	return ret;					//중복없는 시리얼 번호를 저장하는 벡터 ret 리턴
}

int main() {
	int n;						//데이터의 수(1이상 10만이하의 자연수)
	scanf("%d", &n);			//데이터의 수 입력받음

	vector<int> data = vector<int>(n);		//0으로 초기화된, n개의 정수를 저장하는 벡터 data 선언

	for(int i=0; i<n; i++) {	//n(데이터의 수)번 반복하여
		scanf("%d", &data[i]);	//시리얼 번호 입력받음
	}

	const vector<int> answer = getUniqueElements(data, n);	//중복 없는 시리얼 번호를 리턴하는 getUniqueElements 함수를 호출하여 리턴값을 answer 벡터에 저장

	for(int i=0; i<answer.size(); i++) {	//answer 벡터의 원소의 수 만큼 반복하여
		if(i>0) {							//0번 원소가 아니라면
			printf(" ");					//공백(" ")을 출력
		}
		printf("%d", answer[i]);			//중복 없는 시리얼 번호 출력
	}

	return 0;								//메인함수를 정상적으로 끝냄
}

