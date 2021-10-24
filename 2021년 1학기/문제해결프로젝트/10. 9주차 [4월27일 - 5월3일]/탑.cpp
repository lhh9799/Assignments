#include <iostream>	//입출력 함수를 사용하기 위한 헤더파일
#include <vector>	//vector 클래스를 사용하기 위한 헤더파일(배열과의 차이점 : 가변형, 입출력 함수 제공)
#include <stack>	//stack 클래스를 사용하기 위한 헤더파일(특징: 리스트의 한 쪽 끝으로만 자료의 삽입과 삭제가 이루어짐. 후입선출)
using namespace std;//표준 이름공간을 사용함

//타워의 인덱스, 높이, 타워의 레이저를 수신하는 대상 타워의 인덱스를 저장하는 클래스
class Tower {
public:
	int index;				//타워의 인덱스
	int height;				//타워의 높이
	int targetTowerIndex;	//이 타워의 레이저를 수신하는 대상 타워의 인덱스

	Tower(int index, int height) {	//매개변수 있는 생성자
		this->index = index;		//매개변수로 받은 index를 이 객체의 index에 저장
		this->height = height;		//매개변수로 받은 height를 이 객체의 height에 저장
		this->targetTowerIndex = 0;	//targetTowerIndex를 0으로 지정(기본값)
	}

	//타워의 레이저를 수신하는 대상 타워의 인덱스를 저장하는 함수
	void setTargetTowerIndex(int targetTowerIndex) {
		this->targetTowerIndex = targetTowerIndex;	//매개변수로 받은 targetTowerIndex를 이 객체(타워)가 송신한 레이저를 수신하는 대상 타워의 인덱스로 저장
	}

	//타워의 레이저를 수신하는 대상 타워의 인덱스를 리턴하는 함수
	int getTargetTowerIndex() {
		return this->targetTowerIndex;				//이 객체의 targetTowerIndex 리턴
	}
};

//각 타워가 송신하는 레이저들을 수신하는 타워들을 저장하는 함수
void findTargetTowers(vector<Tower> &towers) {		//towers벡터를 참조변수로 받아 원본벡터의 값을 수정 가능하게 함
	stack<Tower> stk;	//현재 다른 타워의 신호를 수신할 가능성이 있는 타워들을 저장하는 스택

	//시간복잡도 O(n)
	for(int i=0; i<towers.size(); i++) {	//towers 벡터의 원소의 수 만큼 반복하여
		Tower &t = towers[i];				//각 타워 t에 대해 차례로 고려
		int targetTowerIndex = 0;			//타워 t의 신호를 수신하는 타워의 인덱스를 0으로 지정(초기값 null)

		//타워 t의 높이가 stk 스택의 가장 위 원소(t보다앞에 있는 타워)의 높이보다 크다면
		while(stk.empty() == false && stk.top().height < t.height) {	//스택이 비어있는지 확인한 뒤 pop() 호출(스택이 비어있을 때 pop() 호출 시 런타임 에러 발생 가능)
			stk.pop();
		}

		//t의 높이를 초과하는 높이를 가진 타워가 남아있다면(앞에서 t보다 작은 타워들은 스택에서 삭제했으므로 원소의 수가 0초과인 경우)
		if(stk.size() > 0) {
			targetTowerIndex = stk.top().index;	//targetTowerIndex의 값 갱신
		}
		t.setTargetTowerIndex(targetTowerIndex);//t의 레이저를 수신하는 대상 타워의 인덱스를 targetTowerIndex로 갱신

		//t는 마지막에 등장했으므로 다른 타워의 신호를 수신할 수 있음. 다음 루프를 위해 t를 stk 스택에 저장
		stk.push(t);
	}
}

int main() {
	int n;		//탑의 수
	cin >> n;	//탑의 수 입력받음

	vector<Tower> towers;	//Tower형 인스턴스들을 저장할 벡터
	for(int i=0; i<n; i++) {//n(탑의 수)번 반복하여
		int hi;				//탑의 높이
		cin >> hi;			//탑의 높이 입력받음
		towers.push_back(Tower(i+1, hi));	//Tower형 인스턴스 생성(인덱스: i+1(인덱스는 1부터 시작. 레이저 신호를 수신하는 탑이 존재하지 않으면 0이기 때문), 높이: hi)후 towers벡터의 맨 뒤에 추가
	}

	//각 타워가 송신하는 레이저들을 수신하는 타워들을 저장하는 함수 호출
	findTargetTowers(towers);

	for(int i=0; i<n; i++) {//n(탑의 수)번 반복하여
		if(i>0) {			//0번 원소가 아니라면
			cout << " ";	//공백(" ")을 출력
		}
		cout << towers[i].getTargetTowerIndex();	//각 Tower형 인스턴스들의 수신 탑의 인덱스 번호 출력
	}

	return 0;	//메인함수를 정상적으로 끝냄
}
