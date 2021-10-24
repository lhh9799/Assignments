#include <iostream>	//입출력 함수를 사용하기 위한 헤더파일
#include <queue>	//queue 클래스를 사용하기 위한 헤더파일(스택과의 차이점: 선입선출, back 원소 접근 가능)
#include <vector>	//vector 클래스를 사용하기 위한 헤더파일(배열과의 차이점: 가변형, 입출력 함수 제공)
using namespace std;//표준 이름공간을 사용함

//도시의 번호, 소득 수준을 저장하는 클래스
class City {
public:
	int index;	//도시의 인덱스
	int income;	//해당 도시의 소득

	City(int index, int income) {	//index, income을 매개변수로 받는 생성자
		this->index = index;		//매개변수로 받은 index를 멤버변수 index에 저장
		this->income = income;		//매개변수로 받은 income을 멤버변수 income에 저장
	}

	//대소 관계 추가(함수명 뒤의 const의 의미: 해당 함수에서 멤버변수를 읽기만 함(멤버변수 수정 불가)
	bool operator < (const City &o) const {	//멤버변수 income이 매개변수로 받은 o의 income보다 작으면 '<'연산의 리턴값 true
		return this->income < o.income;
	}
	bool operator > (const City &o) const {	//멤버변수 income이 매개변수로 받은 o의 income보다 크면 '>'연산의 리턴값 true
		return this->income > o.income;
	}
};

//가장 큰 소득차를 리턴하는 함수
int getMaximumRangeDifference(int n, int k, const vector<City> &cities) {
	int answer = 0;	//가장 큰 소득차 변수를 0으로 초기화

	/*			[아이디어]
	 * 1. 우선순위 큐 2개 준비(오름차순, 내림차순)
	 * 2. k-1개의 도시를 우선순위 큐 2개에 삽입
	 * 3. k번째 도시를 우선순위 큐 2개에 삽입
	 * 4. top의 인덱스가 i-k+1번 (더 이상 그룹(k개의 도시)에 속하지 않는 원소)보다 작다면 pop함 (더 이상 그룹에 속하지 않더라도 top보다 아래에 있는 원소라면 그대로 남아있게 된다. while문이므로 나중에 발견 시 계속해서 pop하므로 괜찮다.)
	 * 5. 각 큐의 top원소의 차를 구하여 max값 갱신
	 * 6. i가 n-1이 될 때까지 3~5번 반복
	 */

	//소득이 가장 적은 도시부터 pop되는 우선순위 큐
	priority_queue<City, vector<City>, greater<City>> rangeMinimum;

	//소득이 가장 높은 도시부터 pop되는 우선순위 큐
	priority_queue<City> rangeMaximum;


	for(int i=0; i<k-1; i++) {			//k-2개의 원소를
		rangeMaximum.push(cities[i]);	//오름차순 우선순위 큐에 추가
		rangeMinimum.push(cities[i]);	//내림차순 우선순위 큐에 추가
	}
	for(int i=k-1; i<n; i++) {			//마지막 원소(k-1번째)를
		rangeMaximum.push(cities[i]);	//오름차순 우선순위 큐에 추가
		rangeMinimum.push(cities[i]);	//내림차순 우선순위 큐에 추가
		while(rangeMaximum.top().index < i - k + 1) rangeMaximum.pop();	//오름차순 큐의 top의 원소가 그룹에 속하는 원소가 나올때 까지 pop
		while(rangeMinimum.top().index < i - k + 1) rangeMinimum.pop();	//내림차순 큐의 top의 원소가 그룹에 속하는 원소가 나올때 까지 pop
		answer = max(answer, rangeMaximum.top().income - rangeMinimum.top().income);	//각 큐의 top원소의 차를 구하여 max값 갱신
	}

	return answer;	//가장 큰 소득차 리턴
}

//연속한 K개의 도시로 이루어진 영역들 중 가장 큰 소득차를 가지는 영역의 소득차를 출력하는 함수
void process(int caseIndex) {
	int n, k;				//n: 도시의 수, k: 한 조사 영역이 포함하는 연속한 도시의 수
	cin >> n >> k;			//도시의 수, 한 조사 영역이 포함하는 연속한 도시의 수 입력받음
	vector<City> cities;	//도시의 정보를 저장하는 벡터

	for(int i=0; i<n; i++) {	//n(도시의 수)번 반복하여
		int income;				//소득 변수
		cin >> income;			//소득 입력받음
		cities.push_back(City(i, income));	//City형 인스턴스를 생성하여 cities 벡터의 맨 뒤에 추가
	}

	int answer = getMaximumRangeDifference(n, k, cities);	//연속한 K개의 도시로 이루어진 영역들 중 가장 큰 소득차를 가지는 영역의 소득차를 answer에 저장

	cout << answer << endl;	//가장 큰 소득차 출력
}

int main() {
	int caseSize;			//테스트 케이스의 수
	cin >> caseSize;		//테스트 케이스의 수 입력받음

	for(int caseIndex=0; caseIndex<caseSize; caseIndex++) {	//caseSize(테스트 케이스의 수)번 반복하여
		process(caseIndex);	//연속한 K개의 도시로 이루어진 영역들 중 가장 큰 소득차를 가지는 영역의 소득차 출력
	}

	return 0;				//메인함수를 정상적으로 끝냄
}
