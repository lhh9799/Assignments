#include <iostream>		//����� �Լ��� ����ϱ� ���� �������
#include <ctime>		//�ڵ� ����ð� ������ ���� �������
#include <cstring>		//memset �Լ��� ����ϱ� ���� �������
using namespace std;	//ǥ�� �̸������� �����

/*
*�������� �� ������ �����ϴ� �Լ�
*�˰��� : �����̴� �� ���� �� ���� ģ���� ����Ѵ�. �� ���� ģ���� ������ ������ ���� ģ���� ����Ѵ�. �� ���� ������ R�� �ݺ��ǰ� �ٱ��� ������ N�� �ݺ��ȴ�.
*/
int scoring(char chonnam_card[], string friend_card[], int N, int R)  {	//chonnam_card : �����̰� �� ����� �����ϴ� ������ �迭, friend_card : ģ���� �� ����� �����ϴ� ���ڿ� �迭, N : ģ���� ��, R : ���� ��
	int total_score = 0;												//�������� ���� ����

	for(int i=0; i<N; i++) {
		for(int j=0; j<R; j++) {
			if(chonnam_card[j] == friend_card[i][j])					//�����̿� ģ���� �� ����� ���� -> ��� -> 1��
				total_score += 1;
			else if(chonnam_card[j] == 'S' && friend_card[i][j] == 'P')	//���� : ����, ģ�� : �� -> �� -> 2��
				total_score += 2;
			else if(chonnam_card[j] == 'S' && friend_card[i][j] == 'R')	//���� : ����, ģ�� : �ָ� -> �� -> 0��
				total_score += 0;
			else if(chonnam_card[j] == 'P' && friend_card[i][j] == 'S')	//���� : ��, ģ�� : ���� -> �� -> 0��
				total_score += 0;
			else if(chonnam_card[j] == 'P' && friend_card[i][j] == 'R')	//���� : ��, ģ�� : �ָ� -> �� -> 2��
				total_score += 2;
			else if(chonnam_card[j] == 'R' && friend_card[i][j] == 'S')	//���� : �ָ�, ģ�� : ���� -> �� -> 2��
				total_score += 2;
			else if(chonnam_card[j] == 'R' && friend_card[i][j] == 'P')	//���� : �ָ�, ģ�� : �� -> �� -> 0��
				total_score += 0;
		}
	}

	return total_score;													//���� ���� ����
}

/*
*�����̰� ���� �� �ִ� �ְ� ������ �����ϴ� �Լ�
*�˰��� : �����̰� �� �� �ִ� ����� ����� ���� �迭�� �����Ѵ�. �� ���帶�� �����̰� �� �� �ִ� ����� �̹� ģ������ �� ������ ���� � ����� ���� �� ���� ���� ������ �޴��� ����� ��, ���� �� �ִ� �ְ� ������ ���Ѵ�.
*
*---����---
*	[1����]		[2����]		[3����]		[4����]
*ģ�� 1: SSPP		SSPP		SSPP		SSPP
*ģ�� 2: RSRP		RSRP		RSRP		RSRP
*ģ�� 3: PSPR		PSPR		PSPR		PSPR
*����:   ?		 ?			  ?			   ?
*
*1���� ?�� {����, ��, �ָ�}�� ���� �����Ͽ� ���� ���� ������ �޴� �и� ����� �� ���� �� �ִ� �ְ� ������ ���Ѵ�.
*��� ���带 ���� ���� ������� �ݺ��Ѵ�.
*�̴� 3�� for ������ ������ �� �ִ�. ���� ���� �ݺ����� �����̰� �� �� �ִ� ����� ���� 3��. ����� �ִ� �ݺ����� ģ���� ���� N��. ���� �ٱ��ʿ� �ִ� �ݺ����� R�� �ݺ��ϸ� �ȴ�.
*/
int best_scoring(string friend_card[], int N, int R) {							//friend_card : ģ���� �� ����� �����ϴ� ���ڿ� �迭, N : ģ���� ��, R : ���� ��
	int best_score = 0;															//�����̰� ���� �� �ִ� �ְ� ����
	int temp_score[3];															//�����̰� ���� '����', '��', '�ָ�'�� ���� ���� ������ �����ϴ� �迭
	char possible_card[3] = {'S', 'P', 'R'};									//�����̰� �� �� �ִ� ����� ����� ���� �迭�� �����ؼ� ���� �����ϵ��� ��

	for(int i=0; i<R; i++) {													//�� R���� ���� �����Ƿ� �����̰� ���� �� ����� ���� R�� ���ؾ� ��
		memset(temp_score, 0, sizeof(temp_score));								//�ش� �迭�� ���� �ݺ������� �ٽ� ���ǹǷ� �迭�� 0���� �ʱ�ȭ��

		for(int j=0; j<N; j++) {												//ģ���� ����ŭ �ݺ�
			for(int k=0; k<3; k++) {											//�����̰� �� �� �ִ� ����� 3����(����, ����, ��) �̹Ƿ� 3�� �ݺ�
				if(possible_card[k] == friend_card[j][i])						//�����̿� ģ���� �� ����� ���� -> ��� -> 1��
					temp_score[k] += 1;
				else if(possible_card[k] == 'S' && friend_card[j][i] == 'P')	//���� : ����, ģ�� : �� -> �� -> 2��
					temp_score[k] += 2;
				else if(possible_card[k] == 'S' && friend_card[j][i] == 'R')	//���� : ����, ģ�� : �ָ� -> �� -> 0��
					temp_score[k] += 0;
				else if(possible_card[k] == 'P' && friend_card[j][i] == 'S')	//���� : ��, ģ�� : ���� -> �� -> 0��
					temp_score[k] += 0;
				else if(possible_card[k] == 'P' && friend_card[j][i] == 'R')	//���� : ��, ģ�� : �ָ� -> �� -> 2��
					temp_score[k] += 2;
				else if(possible_card[k] == 'R' && friend_card[j][i] == 'S')	//���� : �ָ�, ģ�� : ���� -> �� -> 2��
					temp_score[k] += 2;
				else if(possible_card[k] == 'R' && friend_card[j][i] == 'P')	//���� : �ָ�, ģ�� : �� -> �� -> 0��
					temp_score[k] += 0;
			}
		}
		//�ְ��� ���
		if(temp_score[0] >= temp_score[1] && temp_score[0] >= temp_score[2])		//�����̰� "����"�� ���� ���� ���� ������ ���� �� �ִ� ��� �ش� ���忡�� ������ ���� ���� ������ �ְ� ������ ���Ѵ�.
			best_score += temp_score[0];
		else if(temp_score[1] >= temp_score[0] && temp_score[1] >= temp_score[2])	//�����̰� "��"�� ���� ���� ���� ������ ���� �� �ִ� ��� �ش� ���忡�� ���� ���� ���� ������ �ְ� ������ ���Ѵ�.
			best_score += temp_score[1];
		else if(temp_score[2] >= temp_score[0] && temp_score[2] >= temp_score[1])	//�����̰� "�ָ�"�� ���� ���� ���� ������ ���� �� �ִ� ��� �ش� ���忡�� �ָ��� ���� ���� ������ �ְ� ������ ���Ѵ�.
			best_score += temp_score[2];
	}

	return best_score;																//�����̰� ���� �� �ִ� �ְ� ������ ����
}

int main() {
	int R, N;					//R : ���� ��, N : ģ���� ��
	char *chonnam_card;			//�������� �и� ������ ������ �迭�� ������ ����
	string *friend_card;		//ģ���� �и� ������ ���ڿ� �迭�� ������ ����

	cin >> R;					//���� ���� �Է¹���
	chonnam_card = new char[R];	//�����̰� �� ���忡 �� ����� ������ �迭�� ���� �� ��ŭ �������� �Ҵ�

	for(int i=0; i<R; i++)		//R(���� ��)�� �ݺ��Ͽ�
		cin >> chonnam_card[i];	//�����̰� �� ���忡 �� ����� �Է¹���

	cin >> N;					//ģ���� �� �Է¹���
	friend_card = new string[N];//ģ������ �� ����� ������ �迭�� ģ���� �� ��ŭ �������� �Ҵ�

	for(int i=0; i<N; i++) 		//N(ģ���� ��)�� �ݺ��Ͽ�
		cin >> friend_card[i];	//ģ������ �� ����� ���ڿ� �迭�� �Է¹���

	clock_t start = clock();	//���� �ð� ����

	cout << scoring(chonnam_card, friend_card, N, R) << endl;	//�������� �� ������ ���
	cout << best_scoring(friend_card, N, R) << endl;			//�����̰� ���� �� �ִ� �ְ� ������ ���
	cout << endl;												//����ð�(����: ��) ���

	delete []chonnam_card;	//�����Ҵ��� �迭�� �޸� ����
	delete []friend_card;	//�����Ҵ��� �迭�� �޸� ����
	chonnam_card = nullptr;	//�迭�� ����ġ�� �����Ϳ� ����� �ּҰ� ����
	friend_card = nullptr;	//�迭�� ����ġ�� �����Ϳ� ����� �ּҰ� ����

	clock_t end = clock();	//�ڵ尡 ���� �ð� ����

	cout << "����ð�: " << (double) (end - start) / CLOCKS_PER_SEC << "��" << endl;	//����ð�(����: ��) ���

	return 0;				//�����Լ��� ���������� ����
}
