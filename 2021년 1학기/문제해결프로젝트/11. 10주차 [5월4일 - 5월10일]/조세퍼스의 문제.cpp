#include <iostream>	//����� �Լ��� ����ϱ� ���� �������
#include <vector>	//vector Ŭ������ ����ϱ� ���� �������(�迭���� ������: ������, ����� �Լ� ����)
#include <queue>	//queue Ŭ������ ����ϱ� ���� �������(���ð��� ������: ���Լ���, back ���� ���� ����)
using namespace std;//ǥ�� �̸������� �����

//������ �ϴ� ����� ����(��ȣ)�� �����ϴ� Ŭ����
class Player {
public:
	int index;		//������ �ϴ� ����� ��ȣ

	Player(int index) {			//index�� �Ű������� �޴� ������
		this->index = index;	//�Ű������� ���� index�� ������� index�� ����
	}
};

//���ܵ� ������� ��ȣ�� ���Ϳ� ������ �����ϴ� �Լ�
vector<Player> getDeadPlayersList(int n, int m, const vector<Player> &players) {
	vector<Player> deadPlayers;	//���� ���ӿ��� ���ܵ� �÷��̾���� ����Ʈ
	queue<Player> que;			//���� ���ӿ��� ���ܵ��� �ʴ� �÷��̾���� ����Ʈ

	for(int i=0; i<n; i++) {	//n(����� ��)�� �ݺ��Ͽ�
		que.push(players[i]);	//players���Ϳ��� ����� ��ȣ�� ������ que Ŧ�� �߰�(1 2 3 4 5 6 7)
	}

	for(int i=0; i<n; i++) {
		//jump�� ������ �ε����̹Ƿ� 0���� �����Ѵ�. ���� 1�� ���� �����ش�. m�� n���� ū �� �� �� �����Ƿ� (m-1) mod(que�� ������ ũ�⸸ŭ ��ⷯ) ���� ����Ѵ�.
		//jump�� ���ܵ� ����� �ε����̱� ������ 1�� ���Ͽ� �����Ѵ�.
		int jump = 1 + (m - 1) % que.size();
		for(int j=0; j<jump-1; j++) {	//���ܵ� ����� ��ȣ �������� �ݺ��Ͽ�
			Player p = que.front();		//que ť�� �� ���Ҹ� Player�� ���� p�� ����
			que.pop();					//que ť�� top�� ����
			que.push(p);				//������ ������ que ť�� �� ���Ҹ� que ť�� �߰� (2 3 4 5 6 7 1 -> 3 4 5 6 7 1 2)
		}

		//m��° ����� ���ӿ��� ����
		Player dead = que.front();
		que.pop();

		//���� ����Ʈ�� �߰�
		deadPlayers.push_back(dead);
	}

	return deadPlayers;	//���ܵ� ������� ��ȣ�� �����ϴ� ���� ����
}

//���ܵ� ������� ��ȣ�� ����ϴ� �Լ�
void process(int caseIndex) {
	int n, m;			//n: ����� ��, m: ����� ������ ���� ����
	cin >> n >> m;		//����� ���� ����� ������ ���� ���� �Է¹���

	vector<Player> players;				//������ �ϴ� ����� ������ �����ϴ� ���� players ����
	for(int i=0; i<n; i++) {			//n(����� ��)�� �ݺ��Ͽ�
		players.push_back(Player(i+1));	//����� ��ȣ�� players ������ �� �ڿ� �߰�(���۹�ȣ�� 1�̱⶧���� i+1)
	}

	vector<Player> deadPlayers = getDeadPlayersList(n, m, players);	//���ܵ� ������� ��ȣ�� deadPlayers�� ����

	for(int i=0; i<n; i++) {			//n(����� ��)�� �ݺ��Ͽ�
		if(i > 0) {						//0�� ���Ұ� �ƴ϶��
			cout << " ";				//����(" ")�� ���
		}

		Player p = deadPlayers[i];		//���Ϳ��� ���ܵ� ��� �ν��Ͻ��� ������ Player�� ���� p�� ����
		cout << p.index;				//p�� ����� index ���� ���
	}

	cout << endl;						//�ٹٲ�
}

int main() {
	int caseSize;			//�׽�Ʈ ���̽��� ��
	cin >> caseSize;		//�׽�Ʈ ���̽��� �� �Է¹���

	for(int caseIndex=0; caseIndex<caseSize; caseIndex++) {	//caseSize(�׽�Ʈ ���̽��� ��)�� �ݺ��Ͽ�
		process(caseIndex);	//���ܵ� ������� ��ȣ ���
	}

	return 0;				//�����Լ��� ���������� ����
}
