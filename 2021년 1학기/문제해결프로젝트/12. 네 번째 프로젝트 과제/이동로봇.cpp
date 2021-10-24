#include <queue>	//queue Ŭ������ ����ϱ� ���� �������(���ð��� ������: ���Լ���, back ���� ���� ����)
#include <ctime>	//�ڵ� ����ð� ������ ���� �������
#include <iostream>	//����� �Լ��� ����ϱ� ���� �������
using namespace std;//ǥ�� �̸������� �����

//�Ʒ��� const ����� ����(���� ������ �� ����)
const int VERTICAL = 0;		//�������¸� 0�� ����
const int HORIZONTAL = 1;	//������¸� 1�� ����

//�κ��� ��ġ(�� ��)�� �̵��ð��� �����ϴ� Ŭ����
class coord {
public:
	int x1, y1, x2, y2;	//�� 2���� ��ǥ
	int time;			//�̵� �ð�

	//�ʱ�ȭ ����Ʈ ���(������ ȣ��, ������� �ʱ�ȭ ���ÿ� ����)
	coord(int x1, int y1, int x2, int y2, int time) : x1(x1), y1(y1), x2(x2), y2(y2), time(time) {}
};

//�ش�������� �̵� ��������(���� �ִ���)�� �湮������ �ִ��� �����ϴ� �Լ�
bool readyToGo(int x1, int y1, int x2, int y2, int state, int **&board, int ***&visited, int N) {
	//�迭�� ���� �˻�(�κ��� ������ �ϴ� ��ǥ�� ���� ������ �˻�)
	if(x1 >= 0 && y1 >= 0 && x2 >= 0 && y2 >= 0 && x1 < N && y1 < N && x2 < N && y2 < N) {
		//���� �������� �ʴٸ�
		if((board[y1][x1]) == 0 && (board[y2][x2] == 0)) {
			//������ �湮���� �ʾҴٸ�
			if((visited[state][y1][x1]) == 0 || (visited[state][y2][x2] == 0)) {
				return true;	//true ����
			}
		}
	}

	return false;				//������ ��� false ����
}

//�湮�� ��ǥ�� 1�� �����ϴ� �Լ�
void markAsVisited(int x1, int y1, int x2, int y2, int state, int ***&visited, int N) {
	visited[state][y2][x2] = visited[state][y1][x1] = 1;
}

//�κ��� (N, N)��ġ���� �̵��ϴµ� �ʿ��� �ּ� �ð�(�̵��Ұ��� ��� -1)�� �����ϴ� �Լ�
int solution(int **&board, int N) {
	int ***visited = nullptr;				//�湮���θ� �����ϴ� �迭
	int answer = -1;						//�κ��� (N, N)��ġ���� �̵��ϴµ� �ʿ��� �ּ� �ð�(�̵��Ұ��� ��� -1)
	coord initial_position(0, 0, 1, 0, 0);	//���� ��ġ((0,0), (1,0))�� �ð�(0) �ʱ�ȭ
	queue<coord> possible_path;				//Ž���� ��θ� �����ϴ� ť
	possible_path.push(initial_position);	//���� ��ġ�� ť�� ����

	/*�湮���θ� �����ϴ� �迭�� 3�������� �����Ѵ�.
	 *�־��� ����: 2���� + �κ��� ����(����, ����): 1���� = 3����
	 *visited[VERTICAL][row][col]: �κ��� ������ �� ���ƴ��� Ȯ���ϴ� ����
	 *visited[HORIZONTAL][row][col]: �κ��� ������ �� ���ƴ��� Ȯ���ϴ� ����
	 *�ռ� VERTICAL�� HORIZONTAL�� const ����� �����Ͽ���.
	 */
	visited = new int **[2];				//�κ��� ���¿� ���� ������ �迭�� ��ġ�� �ٸ��Ƿ� ������ ������(2(����, ����))��ŭ �����Ҵ�
	for(int i=0; i<2; i++) {
		visited[i] = new int *[N];			//N(row)��ŭ �����Ҵ�

		for(int j=0; j<N; j++) {
			visited[i][j] = new int[N];		//N(col)��ŭ �����Ҵ�

			for(int k=0; k<N; k++) {
				visited[i][j][k] = 0;		//��� �湮���� 0���� �ʱ�ȭ
			}
		}
	}

	//���� ��ġ�� �湮�� ���̹Ƿ� 1�� �ʱ�ȭ
	visited[HORIZONTAL][0][1] = visited[HORIZONTAL][0][0] = 1;

	/*
	 *�˰���: while���� ť�� �� �� �̻� Ž���� �� �ִ� ��ΰ� ���� ������ �ݺ��Ѵ�.
	 *�ܼ��̵� 4����(������, ����, ��, �Ʒ�)�� ȸ�� 8������ �����Ѵ�.
	 *readyToGo�Լ��� ���ϰ��� true��� �湮�� ������ ǥ���ϰ� �̵��� ��ǥ�� ť�� �߰��Ѵ�.
	 *�̸� �ݺ��Ѵ�.
	 */

	//BFS
	while(!possible_path.empty()) {
		coord c = possible_path.front();		//ť�� �� �� ���Ҹ� coord�� �ӽú��� c�� ����
		possible_path.pop();					//�Ʒ����� ���� ����� ���� ����ϱ� ������ ť�� �� �� ���� ����
		int x1 = c.x1; int x2 = c.x2; int y1 = c.y1; int y2 = c.y2; int time = c.time;
		int state = y1 == y2 ? HORIZONTAL : VERTICAL;			//�κ��� ���� ����(���̸� ����, �����̸� ����)
		int opposite_state = y1 == y2 ?  VERTICAL : HORIZONTAL;	//ȸ�� �� �κ��� �湮������ �ݴ�������� �����ؾ���(e.g. ����->�������� ȸ���� �κ��� �湮������ ����迭�� �����ؾ� ��)

		//�κ��� (N, N) ��ġ�� ������ ���
		if((x1 == N-1 && y1 == N-1) || (x2 == N-1 && y2 == N-1)) {
			answer = time;						//�ּ� �ð� ����
			break;								//�ݺ��� Ż��
		}

		//BFS
		else {
			//���������� 1ĭ �̵�
			if(readyToGo(x1+1, y1, x2+1, y2, state, board, visited, N)) {
				markAsVisited(x1+1, y1, x2+1, y2, state, visited, N);
				possible_path.push(coord(x1+1, y1, x2+1, y2, time+1));
			}

			//�������� 1ĭ �̵�
			if(readyToGo(x1-1, y1, x2-1, y2, state, board, visited, N)) {
				markAsVisited(x1-1, y1, x2-1, y2, state, visited, N);
				possible_path.push(coord(x1-1, y1, x2-1, y2, time+1));
			}

			//���� 1ĭ �̵�
			if(readyToGo(x1, y1-1, x2, y2-1, state, board, visited, N)) {
				markAsVisited(x1, y1-1, x2, y2-1, state, visited, N);
				possible_path.push(coord(x1, y1-1, x2, y2-1, time + 1));
			}

			//�Ʒ��� 1ĭ �̵�
			if(readyToGo(x1, y1+1, x2, y2+1, state, board, visited, N)) {
				markAsVisited(x1, y1+1, x2, y2+1, state, visited, N);
				possible_path.push(coord(x1, y1+1, x2, y2+1, time + 1));
			}

			//�κ��� ������ ����(push ��Ģ: x1 < x2 && y1 < y2)
			if(y1 == y2) {
				//������ ������ �ð����(�Ʒ� 2��(y+1��ǥ) ���)
				if(readyToGo(x1, y1+1, x2, y2+1, opposite_state, board, visited, N)) {
					markAsVisited(x1, y1, x1, y1+1, opposite_state, visited, N);
					possible_path.push(coord(x1, y1, x1, y1+1, time + 1));
				}
				//������ ������ �ݽð����(�� 2��(y-1��ǥ) ���)
				if(readyToGo(x1, y1-1, x2, y2-1, opposite_state, board, visited, N)) {
					markAsVisited(x1, y1-1, x1, y1, opposite_state, visited, N);
					possible_path.push(coord(x1, y1-1, x1, y1, time + 1));
				}
				//�������� ������ �ð����(�� 2��(y-1��ǥ) ���)
				if(readyToGo(x1, y1-1, x2, y2-1, opposite_state, board, visited, N)) {
					markAsVisited(x2, y2-1, x2, y2, opposite_state, visited, N);
					possible_path.push(coord(x2, y2-1, x2, y2, time + 1));
				}
				//�������� ������ �ݽð����(�Ʒ� 2��(y+1��ǥ) ���)
				if(readyToGo(x1, y1+1, x2, y2+1, opposite_state, board, visited, N)) {
					markAsVisited(x2, y2, x2, y2+1, opposite_state, visited, N);
					possible_path.push(coord(x2, y2, x2, y2+1, time + 1));
				}
			}
			//�κ��� ������ ����(push ��Ģ: x1 < x2 && y1 < y2)
			else {
				//���� �������� �ð����(���� 2��((x1-1,y1), (x2-1,y2)) ���)
				if(readyToGo(x1-1, y1, x2-1, y2, opposite_state, board, visited, N)) {
					markAsVisited(x1-1, y1, x1, y1, opposite_state, visited, N);
					possible_path.push(coord(x1-1, y1, x1, y1, time + 1));
				}
				//���� �������� �ݽð����(������ 2��((x1+1,y1), (x2+1,y2)) ���)
				if(readyToGo(x1+1, y1, x2+1, y2, opposite_state, board, visited, N)) {
					markAsVisited(x1, y1, x1+1, y1, opposite_state, visited, N);
					possible_path.push(coord(x1, y1, x1+1, y1, time + 1));
				}
				//�Ʒ��� �������� �ð����(������ 2��((x1+1,y1), (x2+1,y2)) ���)
				if(readyToGo(x1+1, y1, x2+1, y2, opposite_state, board, visited, N)) {
					markAsVisited(x2, y2, x2+1, y2, opposite_state, visited, N);
					possible_path.push(coord(x2, y2, x2+1, y2, time + 1));
				}
				//�Ʒ��� �������� �ݽð����(���� 2��((x1-1,y1), (x2-1,y2)) ���)
				if(readyToGo(x1-1, y1, x2-1, y2, opposite_state, board, visited, N)) {
					markAsVisited(x2-1, y2, x2, y2, opposite_state, visited, N);
					possible_path.push(coord(x2-1, y2, x2, y2, time + 1));
				}
			}
		}
	}
	//�����Ҵ� �� visited �迭�� �޸� ����
	for(int i=0; i<2; i++) {
		for(int j=0; j<N; j++) {
			delete []visited[i][j];
		}
		delete []visited[i];
	}
	delete []visited;
	visited = nullptr;

	return answer;			//�κ��� (N, N)��ġ���� �̵��ϴµ� �ʿ��� �ּ� �ð�(�̵��Ұ��� ��� -1) ����
}

int main() {
	int N, **board;			//N: board�� �� ���� ����, board: ����

	cin >> N;				//board�� �� ���� ���� �Է¹���
	board = new int *[N];	//board �迭�� row��ŭ �����Ҵ�

	for(int i=0; i<N; i++) {
		board[i] = new int[N];	//board �迭�� col��ŭ �����Ҵ�

		for(int j=0; j<N; j++) {
			cin >> board[i][j];	//�������� �Է¹���
		}
	}

	clock_t start = clock();	//���� �ð� ����

	cout << solution(board, N) << endl;	//�κ��� (N, N)��ġ���� �̵��ϴµ� �ʿ��� �ּ� �ð�(�̵��Ұ��� ��� -1) ���

	//�����Ҵ� �� board �迭�� �޸� ����
	for(int i=0; i<N; i++) {
		delete []board[i];
	}
	delete []board;
	board = nullptr;					//�迭�� ����Ű�� �����Ϳ� ����� �ּҰ� ����

	clock_t end = clock();				//���� �ð� ����
	cout << "����ð�: " << (double)(end - start) / CLOCKS_PER_SEC << "��";	//����ð�(����: ��) ���

	return 0;							//�����Լ��� ���������� ����
}
