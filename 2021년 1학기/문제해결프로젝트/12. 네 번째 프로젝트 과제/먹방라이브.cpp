#include <queue>	//queue 클래스를 사용하기 위한 헤더파일(스택과의 차이점: 선입선출, back 원소 접근 가능)
#include <vector>	//vector 클래스를 사용하기 위한 헤더파일(배열과의 차이점: 가변형, 입출력 함수 제공)
#include <algorithm>//sort함수를 사용하기 위한 헤더파일
#include <ctime>	//코드 실행시간 측정을 위한 헤더파일
#include <iostream>	//입출력 함수를 사용하기 위한 헤더파일
using namespace std;//표준 이름공간을 사용함

//음식의 번호와 섭취 소요 시간을 저장하는 클래스
class food {
public:
	int index;		//음식의 번호
	int time_left;	//음식 섭취 소요 시간

	//index와 time_left를 매개변수로 받는 생성자
	food(int index, int time_left) {
		this->index = index;		//매개변수로 받은 index를 멤버변수 index에 저장
		this->time_left = time_left;//매개변수로 받은 time_left를 멤버변수 time_left에 저장
	}

	/*대소 관계 추가(함수명 뒤의 const의 의미: 해당 함수에서 멤버변수를 읽기만 함(멤버변수 수정 불가)
	 *두 인스턴스의 time_left가 같으면 index가 작은것이 우선순위가 높음(1번 음식부터 먹기 시작하므로)
	 *time_left가 다르다면 time_left가 작은 인스턴스의 우선순위가 높음(가장 먼저 먹어치울수 있기 때문)
	 */
	bool operator < (const food &o) const {
		if(this->time_left == o.time_left)
			return this->index < o.index;
		return this->time_left < o.time_left;
	}
	bool operator > (const food &o) const {
		if(this->time_left == o.time_left)
			return this->index > o.index;
		return this->time_left > o.time_left;
	}
};

//음식번호를 기준으로 오름차순 정렬하는 함수
bool sort_by_index (const food &a, const food &b) {
	return a.index < b.index ? true : false;
}

int main() {
	int N, *time = nullptr;			//N: 음식의 개수, *time: 음식의 소요 시간을 저장하는 배열을 가리키는 포인터 변수
	int acc = 0;					//음식이 회전한 사이클(accumulation)
	long long k;					//방송 중단 시간(1 <= k <= 2*10^13) -> long long
	long long input_time_sum = 0;	//방송 중단 시간 이전에 음식을 다 먹을 수 있는지 검사하기 위한 변수
	priority_queue<food, vector<food>, greater<food>> food_list;	//무지가 먹어야 할 음식의 우선순위 큐(소요 시간이 적은 것부터, 같다면 인덱스가 적은 순)
	vector<food> food_list_order_by_index;	//음식번호를 기준으로 오름차순 정렬할 벡터(답을 출력하기 위함)

	cin >> N;					//음식의 개수 입력받음
	time = new int[N];			//음식의 소요 시간을 저장하는 배열 동적할당

	for(int i=0; i<N; i++) {	//N(음식의 수)번 반복하여
		cin >> time[i];			//음식 섭취 소요 시간 저장
	}

	cin >> k;					//방송 중단 시간 입력받음

	clock_t start = clock();	//시작 시간 저장

	//k를 입력받기 전 for문에서 인스턴스 생성 및 우선순위 큐 추가를 하면 더 효율적이겠지만, 프로그램 실행시간 측정에 영향을 주기 때문에 아래 별도 for문에서 처리
	for(int i=0; i<N; i++) {				//N(음식의 수)번 반복하여
		food_list.push(food(i+1, time[i]));	//food형 인스턴스 생성 후 food_list 큐의 맨 뒤에 추가(i+1 이유: 음식번호는 1번부터 시작)
		input_time_sum += time[i];
	}

	if(input_time_sum <= k) {		//방송 중단 시간 이전에 음식을 다 먹을 수 있는 경우
		cout << "-1" << endl;		//더 섭취해야 할 음식이 없으므로 -1 출력
		clock_t end = clock();		//종료 시간 저장
		cout << "실행시간: " << (double)(end - start) / CLOCKS_PER_SEC << "초";	//실행시간(단위: 초) 출력

		return 0;					//함수 종료
	}

	/*
	 *알고리즘: 남은 k초 안에 모든 음식을 한 번씩(최소 소요시간 동안) 손댈 수 있다면 (필요 시간: 최소 소요시간 * 음식의 수)
	 *k -= (최소 소요시간 * 음식의 수)를 거듭해 나가며 연산량을 줄여나간다.
	 *더 이상 k를 줄여나가지 못할 때 while문에서 빠져나간다.
	 */
	while(k >= 0) {
		food f = food_list.top();				//우선순위 큐의 가장 위 원소를 food형 임시변수 f에 저장
		//한 가지 음식을 없애는데 걸리는 시간 계산(우선순위 큐에서 모든 원소들(top은 이미 pop되었음)은 time_left 멤버변수가 갱신되지 않았으므로 acc(음식이 회전한 사이클)만큼 빼줌)
		long long  required_time = food_list.size() * (f.time_left - acc);

		if(k >= required_time) {				//k >= (최소 남은 소요 시간 * 음식의 수) == (k초 동안 한 가지 음식을 모두 먹어치울 수 있다면)
			acc = food_list.top().time_left;	//음식이 회전한 사이클 갱신
			k -= required_time;					//남은 시간 갱신
		}
		else									//한 가지 음식을 모두 먹어치울 시간이 안된다면
			break;								//루프 탈출

		//top원소의 time_left가 acc 이하라면 while문을 이용해 빼냄(time_left가 같은 원소가 있을 수 있기 때문)
		while(food_list.top().time_left <= acc) {
			food_list.pop();
		}
	}

	//우선순위 큐의 원소를 벡터에 복사
	while(!food_list.empty()) {
		food_list_order_by_index.push_back(food_list.top());	//벡터의 맨 뒤에 추가
		food_list.pop();										//우선순위 큐 top 원소 삭제
	}

	//벡터를 음식 번호순으로 정렬
	sort(food_list_order_by_index.begin(), food_list_order_by_index.end(), sort_by_index);

	int target = k % food_list_order_by_index.size();			//k % v.size()가 방송이 재개된 후 먹어야 하는 음식의 정보가 저장된 번호. 음식번호가 1번부터 시작했으므로 추가로 1(다음 음식번호)을 더하지 않음
	cout << food_list_order_by_index[target].index << endl;		//큐의 맨 앞 원소의 index 출력(방송이 재개되었을 때 섭취해야 할 음식의 번호)

	delete []time;				//동적할당한 배열의 메모리 해제
	time = nullptr;				//배열을 가리키는 포인터에 저장된 주소값 삭제

	clock_t end = clock();		//종료 시간 저장
	cout << "실행시간: " << (double)(end - start) / CLOCKS_PER_SEC << "초";	//실행시간(단위: 초) 출력

	return 0;					//메인함수를 정상적으로 끝냄
}
