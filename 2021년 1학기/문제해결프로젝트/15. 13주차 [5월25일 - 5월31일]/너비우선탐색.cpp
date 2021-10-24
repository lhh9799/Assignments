#include <iostream>	//입출력 함수를 사용하기 위한 헤더파일
#include <queue>	//queue 클래스를 사용하기 위한 헤더파일(스택과의 차이점: 선입선출, back 원소 접근 가능)
using namespace std;//표준 이름공간을 사용함

int map[10][10] = {0};	//간선이 존재하는지를 저장하는 배열 0으로 초기화
int visit[10] = {0};	//정점의 정보 0으로 초기화
queue<int> q;			//탐색할 간선을 저장하는 큐
int num, edge_num;		//num: 정점의 수, edge_num: 간선의 수

//BFS(너비 우선 탐색) - 인접한 노드들을 차례대로 방문(저장공간 많이 사용, 최단경로 보장)
void bfs(int v) {
	cout << v << "\n";	//BFS함수를 시작할 정점의 번호를 출력
	q.push(v);			//BFS함수를 시작할 정점의 번호를 큐에 저장

	while(!q.empty()) {	//큐가 빌 때까지(더 이상 탐색할 간선이 없을 때까지)
		int node = q.front();	//큐의 맨 앞 원소를 node에 저장
		q.pop();		//큐의 맨 앞 원소 삭제
		for(int i=1; i<=num; i++) {			//1번노드부터 시작하여 탐색(루프는 num번 돌아야 함)
			if(map[node][i] == 1 && visit[i] == 0 ) {	//간선이 존재하고 방문하지 않았다면
				visit[i] = visit[node] = 1;	//두 정점을 방문한것으로 표시
				cout << i << "\n";			//나중에 탐색해야 할 정점의 번호 출력
				q.push(i);					//나중에 탐색해야 할 정점의 번호를 큐에 저장
			}
		}
	}
}

int main() {
	cin >> num >> edge_num;	//정점의 수, 간선의 수 입력받음

	for(int i=0; i<edge_num; i++) {		//간선의 수만큼 반복하여
		int v1, v2;						//간선의 양 끝 정점 선언
		cin >> v1 >> v2;				//간선의 양 끝 정점 입력받음
		map[v1][v2] = map[v2][v1] = 1;	//간선이 존재하면 인접행렬의 값을 1로 저장
	}
	bfs(1);			//1번 정점을 시작점으로 BFS

	return 0;		//메인함수를 정상적으로 끝냄
}
