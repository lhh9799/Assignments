#include <iostream>	//입출력 함수를 사용하기 위한 헤더파일
using namespace std;//표준 이름공간을 사용함

int maps[10][10];			//간선이 존재하는지를 저장하는 배열 0으로 초기화
int notVisited[10] = {0};	//정점의 정보 0으로 초기화
int num;					//정점의 개수

//배열(인접행렬)을 0으로 초기화 하는 함수
void init() {
	for(int i=0; i<10; i++) {
		for(int j=0; j<10; j++) {
			maps[i][j] = 0;
		}
	}
}

//DFS(깊이 우선 탐색) - 더 이상 방문할 노드가 없을 때까지 순회(저장공간 적게 사용, 해가 없는 경로에 빠질 수 있음, 목표노드가 깊은 단계에 있을 경우 해를 빨리 구할 수 있음, 최단경로를 보장하지 않음)
void dfs(int v) {
	cout << v << endl;			//지금 방문중인 정점의 번호 출력
	notVisited[v] = 0;			//방문하였으므로 0으로 저장
	for(int i=0; i<=num; i++) {	//num(정점의 수)번 반복하여
		if(maps[v][i] && notVisited[i]) {	//간선이 존재하고 방문하지 않은 길이 있다면
			dfs(i);				//DFS
		}
	}
}

int main(void) {
	int v1, v2;	//연결된 간선의 정보를 저장하기 위한 두 정점의 번호
	init();		//간선의 연결 여부를 저장할 2차원 배열 초기화
	cin >> num;	//정점의 개수 입력받음

	for(int i=0; i<num; i++) {	//DFS는 정점의 수만큼 반복함
		cin >> v1 >> v2;		//연결된 간선의 정보를 저장하기 위한 두 정점의 번호 입력받음
		maps[v1][v2] = maps[v2][v1] = 1;	//간선이 존재하면 인접행렬의 값을 1로 저장
		notVisited[v1] = notVisited[v2] = 1;//두 정점(v1, v2)이 존재하고 아직 방문하지 않았으므로 1로 초기화
	}
	dfs(1);		//1번 정점을 시작점으로 DFS

	return 0;	//메인함수를 정상적으로 끝냄
}
