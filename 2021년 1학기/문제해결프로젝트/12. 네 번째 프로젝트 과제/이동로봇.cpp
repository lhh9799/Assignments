#include <queue>	//queue 클래스를 사용하기 위한 헤더파일(스택과의 차이점: 선입선출, back 원소 접근 가능)
#include <ctime>	//코드 실행시간 측정을 위한 헤더파일
#include <iostream>	//입출력 함수를 사용하기 위한 헤더파일
using namespace std;//표준 이름공간을 사용함

//아래를 const 상수로 선언(값을 변경할 수 없음)
const int VERTICAL = 0;		//수직상태를 0로 선언
const int HORIZONTAL = 1;	//수평상태를 1로 선언

//로봇이 위치(두 점)와 이동시간을 저장하는 클래스
class coord {
public:
	int x1, y1, x2, y2;	//점 2개의 좌표
	int time;			//이동 시간

	//초기화 리스트 사용(생성자 호출, 멤버변수 초기화 동시에 수행)
	coord(int x1, int y1, int x2, int y2, int time) : x1(x1), y1(y1), x2(x2), y2(y2), time(time) {}
};

//해당방향으로 이동 가능한지(벽이 있는지)와 방문한적이 있는지 리턴하는 함수
bool readyToGo(int x1, int y1, int x2, int y2, int state, int **&board, int ***&visited, int N) {
	//배열의 범위 검사(로봇이 가고자 하는 좌표가 지도 밖인지 검사)
	if(x1 >= 0 && y1 >= 0 && x2 >= 0 && y2 >= 0 && x1 < N && y1 < N && x2 < N && y2 < N) {
		//벽에 막혀있지 않다면
		if((board[y1][x1]) == 0 && (board[y2][x2] == 0)) {
			//이전에 방문하지 않았다면
			if((visited[state][y1][x1]) == 0 || (visited[state][y2][x2] == 0)) {
				return true;	//true 리턴
			}
		}
	}

	return false;				//나머지 경우 false 리턴
}

//방문한 좌표를 1로 저장하는 함수
void markAsVisited(int x1, int y1, int x2, int y2, int state, int ***&visited, int N) {
	visited[state][y2][x2] = visited[state][y1][x1] = 1;
}

//로봇이 (N, N)위치까지 이동하는데 필요한 최소 시간(이동불가한 경우 -1)을 리턴하는 함수
int solution(int **&board, int N) {
	int ***visited = nullptr;				//방문여부를 저장하는 배열
	int answer = -1;						//로봇이 (N, N)위치까지 이동하는데 필요한 최소 시간(이동불가한 경우 -1)
	coord initial_position(0, 0, 1, 0, 0);	//시작 위치((0,0), (1,0))와 시간(0) 초기화
	queue<coord> possible_path;				//탐색할 경로를 저장하는 큐
	possible_path.push(initial_position);	//시작 위치를 큐에 저장

	/*방문여부를 저장하는 배열은 3차원으로 선언한다.
	 *주어진 지도: 2차원 + 로봇의 상태(수평, 수직): 1차원 = 3차원
	 *visited[VERTICAL][row][col]: 로봇이 수직일 때 거쳤는지 확인하는 지도
	 *visited[HORIZONTAL][row][col]: 로봇이 수평일 때 거쳤는지 확인하는 지도
	 *앞서 VERTICAL과 HORIZONTAL를 const 상수로 선언하였다.
	 */
	visited = new int **[2];				//로봇의 상태에 따라 저장할 배열의 위치가 다르므로 상태의 가짓수(2(수직, 수평))만큼 동적할당
	for(int i=0; i<2; i++) {
		visited[i] = new int *[N];			//N(row)만큼 동적할당

		for(int j=0; j<N; j++) {
			visited[i][j] = new int[N];		//N(col)만큼 동적할당

			for(int k=0; k<N; k++) {
				visited[i][j][k] = 0;		//모든 방문정보 0으로 초기화
			}
		}
	}

	//시작 위치는 방문한 것이므로 1로 초기화
	visited[HORIZONTAL][0][1] = visited[HORIZONTAL][0][0] = 1;

	/*
	 *알고리즘: while문은 큐가 비어서 더 이상 탐색할 수 있는 경로가 없을 때까지 반복한다.
	 *단순이동 4가지(오른쪽, 왼쪽, 위, 아래)와 회전 8가지를 수행한다.
	 *readyToGo함수의 리턴값이 true라면 방문한 것으로 표시하고 이동할 좌표를 큐에 추가한다.
	 *이를 반복한다.
	 */

	//BFS
	while(!possible_path.empty()) {
		coord c = possible_path.front();		//큐의 맨 앞 원소를 coord형 임시변수 c에 저장
		possible_path.pop();					//아래에서 이후 경우의 수를 고려하기 때문에 큐의 맨 앞 원소 제거
		int x1 = c.x1; int x2 = c.x2; int y1 = c.y1; int y2 = c.y2; int time = c.time;
		int state = y1 == y2 ? HORIZONTAL : VERTICAL;			//로봇의 방향 변수(참이면 수평, 거짓이면 수직)
		int opposite_state = y1 == y2 ?  VERTICAL : HORIZONTAL;	//회전 한 로봇의 방문정보는 반대방향으로 저장해야함(e.g. 수직->수평으로 회전한 로봇의 방문정보는 수평배열에 저장해야 함)

		//로봇이 (N, N) 위치에 도달한 경우
		if((x1 == N-1 && y1 == N-1) || (x2 == N-1 && y2 == N-1)) {
			answer = time;						//최소 시간 저장
			break;								//반복문 탈출
		}

		//BFS
		else {
			//오른쪽으로 1칸 이동
			if(readyToGo(x1+1, y1, x2+1, y2, state, board, visited, N)) {
				markAsVisited(x1+1, y1, x2+1, y2, state, visited, N);
				possible_path.push(coord(x1+1, y1, x2+1, y2, time+1));
			}

			//왼쪽으로 1칸 이동
			if(readyToGo(x1-1, y1, x2-1, y2, state, board, visited, N)) {
				markAsVisited(x1-1, y1, x2-1, y2, state, visited, N);
				possible_path.push(coord(x1-1, y1, x2-1, y2, time+1));
			}

			//위로 1칸 이동
			if(readyToGo(x1, y1-1, x2, y2-1, state, board, visited, N)) {
				markAsVisited(x1, y1-1, x2, y2-1, state, visited, N);
				possible_path.push(coord(x1, y1-1, x2, y2-1, time + 1));
			}

			//아래로 1칸 이동
			if(readyToGo(x1, y1+1, x2, y2+1, state, board, visited, N)) {
				markAsVisited(x1, y1+1, x2, y2+1, state, visited, N);
				possible_path.push(coord(x1, y1+1, x2, y2+1, time + 1));
			}

			//로봇이 수평인 상태(push 규칙: x1 < x2 && y1 < y2)
			if(y1 == y2) {
				//왼쪽을 축으로 시계방향(아래 2개(y+1좌표) 고려)
				if(readyToGo(x1, y1+1, x2, y2+1, opposite_state, board, visited, N)) {
					markAsVisited(x1, y1, x1, y1+1, opposite_state, visited, N);
					possible_path.push(coord(x1, y1, x1, y1+1, time + 1));
				}
				//왼쪽을 축으로 반시계방향(위 2개(y-1좌표) 고려)
				if(readyToGo(x1, y1-1, x2, y2-1, opposite_state, board, visited, N)) {
					markAsVisited(x1, y1-1, x1, y1, opposite_state, visited, N);
					possible_path.push(coord(x1, y1-1, x1, y1, time + 1));
				}
				//오른쪽을 축으로 시계방향(위 2개(y-1좌표) 고려)
				if(readyToGo(x1, y1-1, x2, y2-1, opposite_state, board, visited, N)) {
					markAsVisited(x2, y2-1, x2, y2, opposite_state, visited, N);
					possible_path.push(coord(x2, y2-1, x2, y2, time + 1));
				}
				//오른쪽을 축으로 반시계방향(아래 2개(y+1좌표) 고려)
				if(readyToGo(x1, y1+1, x2, y2+1, opposite_state, board, visited, N)) {
					markAsVisited(x2, y2, x2, y2+1, opposite_state, visited, N);
					possible_path.push(coord(x2, y2, x2, y2+1, time + 1));
				}
			}
			//로봇이 수직인 상태(push 규칙: x1 < x2 && y1 < y2)
			else {
				//위를 기준으로 시계방향(왼쪽 2개((x1-1,y1), (x2-1,y2)) 고려)
				if(readyToGo(x1-1, y1, x2-1, y2, opposite_state, board, visited, N)) {
					markAsVisited(x1-1, y1, x1, y1, opposite_state, visited, N);
					possible_path.push(coord(x1-1, y1, x1, y1, time + 1));
				}
				//위를 기준으로 반시계방향(오른쪽 2개((x1+1,y1), (x2+1,y2)) 고려)
				if(readyToGo(x1+1, y1, x2+1, y2, opposite_state, board, visited, N)) {
					markAsVisited(x1, y1, x1+1, y1, opposite_state, visited, N);
					possible_path.push(coord(x1, y1, x1+1, y1, time + 1));
				}
				//아래를 기준으로 시계방향(오른쪽 2개((x1+1,y1), (x2+1,y2)) 고려)
				if(readyToGo(x1+1, y1, x2+1, y2, opposite_state, board, visited, N)) {
					markAsVisited(x2, y2, x2+1, y2, opposite_state, visited, N);
					possible_path.push(coord(x2, y2, x2+1, y2, time + 1));
				}
				//아래를 기준으로 반시계방향(왼쪽 2개((x1-1,y1), (x2-1,y2)) 고려)
				if(readyToGo(x1-1, y1, x2-1, y2, opposite_state, board, visited, N)) {
					markAsVisited(x2-1, y2, x2, y2, opposite_state, visited, N);
					possible_path.push(coord(x2-1, y2, x2, y2, time + 1));
				}
			}
		}
	}
	//동적할당 한 visited 배열의 메모리 해제
	for(int i=0; i<2; i++) {
		for(int j=0; j<N; j++) {
			delete []visited[i][j];
		}
		delete []visited[i];
	}
	delete []visited;
	visited = nullptr;

	return answer;			//로봇이 (N, N)위치까지 이동하는데 필요한 최소 시간(이동불가한 경우 -1) 리턴
}

int main() {
	int N, **board;			//N: board의 한 변의 길이, board: 지도

	cin >> N;				//board의 한 변의 길이 입력받음
	board = new int *[N];	//board 배열을 row만큼 동적할당

	for(int i=0; i<N; i++) {
		board[i] = new int[N];	//board 배열을 col만큼 동적할당

		for(int j=0; j<N; j++) {
			cin >> board[i][j];	//지도정보 입력받음
		}
	}

	clock_t start = clock();	//시작 시간 저장

	cout << solution(board, N) << endl;	//로봇이 (N, N)위치까지 이동하는데 필요한 최소 시간(이동불가한 경우 -1) 출력

	//동적할당 한 board 배열의 메모리 해제
	for(int i=0; i<N; i++) {
		delete []board[i];
	}
	delete []board;
	board = nullptr;					//배열을 가리키는 포인터에 저장된 주소값 삭제

	clock_t end = clock();				//종료 시간 저장
	cout << "실행시간: " << (double)(end - start) / CLOCKS_PER_SEC << "초";	//실행시간(단위: 초) 출력

	return 0;							//메인함수를 정상적으로 끝냄
}
