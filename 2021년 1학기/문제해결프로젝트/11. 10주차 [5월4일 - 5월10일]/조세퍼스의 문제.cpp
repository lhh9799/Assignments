#include <iostream>	//입출력 함수를 사용하기 위한 헤더파일
#include <vector>	//vector 클래스를 사용하기 위한 헤더파일(배열과의 차이점: 가변형, 입출력 함수 제공)
#include <queue>	//queue 클래스를 사용하기 위한 헤더파일(스택과의 차이점: 선입선출, back 원소 접근 가능)
using namespace std;//표준 이름공간을 사용함

//게임을 하는 사람의 정보(번호)를 저장하는 클래스
class Player {
public:
	int index;		//게임을 하는 사람의 번호

	Player(int index) {			//index를 매개변수로 받는 생성자
		this->index = index;	//매개변수로 받은 index를 멤버변수 index에 저장
	}
};

//제외된 사람들의 번호를 벡터에 저장해 리턴하는 함수
vector<Player> getDeadPlayersList(int n, int m, const vector<Player> &players) {
	vector<Player> deadPlayers;	//현재 게임에서 제외된 플레이어들의 리스트
	queue<Player> que;			//아직 게임에서 제외되지 않는 플레이어들의 리스트

	for(int i=0; i<n; i++) {	//n(사람의 수)번 반복하여
		que.push(players[i]);	//players벡터에서 사람의 번호를 가져와 que 큔에 추가(1 2 3 4 5 6 7)
	}

	for(int i=0; i<n; i++) {
		//jump는 벡터의 인덱스이므로 0부터 시작한다. 따라서 1을 빼서 맞춰준다. m이 n보다 큰 수 일 수 있으므로 (m-1) mod(que의 원소의 크기만큼 모듈러) 값을 계산한다.
		//jump는 제외될 사람의 인덱스이기 때문에 1을 더하여 교정한다.
		int jump = 1 + (m - 1) % que.size();
		for(int j=0; j<jump-1; j++) {	//제외될 사람의 번호 직전까지 반복하여
			Player p = que.front();		//que 큐의 앞 원소를 Player형 변수 p에 저장
			que.pop();					//que 큐의 top을 삭제
			que.push(p);				//위에서 추출한 que 큐의 앞 원소를 que 큐에 추가 (2 3 4 5 6 7 1 -> 3 4 5 6 7 1 2)
		}

		//m번째 사람은 게임에서 제외
		Player dead = que.front();
		que.pop();

		//제외 리스트에 추가
		deadPlayers.push_back(dead);
	}

	return deadPlayers;	//제외된 사람들의 번호를 저장하는 벡터 리턴
}

//제외된 사람들의 번호를 출력하는 함수
void process(int caseIndex) {
	int n, m;			//n: 사람의 수, m: 사람을 제외해 나갈 간격
	cin >> n >> m;		//사람의 수와 사람을 제외해 나갈 간격 입력받음

	vector<Player> players;				//게임을 하는 사람의 정보를 저장하는 벡터 players 선언
	for(int i=0; i<n; i++) {			//n(사람의 수)번 반복하여
		players.push_back(Player(i+1));	//사람의 번호를 players 벡터의 맨 뒤에 추가(시작번호는 1이기때문에 i+1)
	}

	vector<Player> deadPlayers = getDeadPlayersList(n, m, players);	//제외된 사람들의 번호를 deadPlayers에 저장

	for(int i=0; i<n; i++) {			//n(사람의 수)번 반복하여
		if(i > 0) {						//0번 원소가 아니라면
			cout << " ";				//공백(" ")을 출력
		}

		Player p = deadPlayers[i];		//벡터에서 제외된 사람 인스턴스를 가져와 Player형 변수 p에 저장
		cout << p.index;				//p의 멤버인 index 변수 출력
	}

	cout << endl;						//줄바꿈
}

int main() {
	int caseSize;			//테스트 케이스의 수
	cin >> caseSize;		//테스트 케이스의 수 입력받음

	for(int caseIndex=0; caseIndex<caseSize; caseIndex++) {	//caseSize(테스트 케이스의 수)번 반복하여
		process(caseIndex);	//제외된 사람들의 번호 출력
	}

	return 0;				//메인함수를 정상적으로 끝냄
}
