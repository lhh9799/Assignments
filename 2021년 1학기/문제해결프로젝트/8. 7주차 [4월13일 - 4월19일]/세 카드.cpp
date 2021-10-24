#include <stdio.h>	//ǥ������� ���̺귯��
#include <vector>	//vector Ŭ������ ����ϱ� ���� �������(�迭���� ������ : ������, ����� �Լ� ����)
#include <algorithm>//Ž��, ����, ��, ���� �� ���� �Լ��� �����ϴ� �������
using namespace std;//ǥ�� �̸������� �����

//�Է¹��� ī�� �� ��÷��ȣ�� ���Ϳ� �����Ͽ� �����ϴ� �Լ� 
vector<int> getPossibleTargets(int n, int m, int *cards, int *targets) {
	vector<int> possibleTargets;	//���� �� �ִ� ��÷ ��ȣ��

	sort(cards, cards+n);			//�Է¹��� ī�带 ������������ ����

	for(int i=0; i<m; i++) {		//m(�˻��� �ĺ� ��÷��ȣ�� ��)�� �ݺ��Ͽ� ��÷��ȣ�� ��ġ�ϴ��� ��
		int k = targets[i];			//i��° ��÷��ȣ�� ������ k�� ����
		bool possible = false;		//�⺻���� false�� ����

		for(int j=0; j<n; j++) {	//n(ī���� ��)�� �ݺ��Ͽ�
			int x = cards[j];		//ù ��° ī�� ����(j��° ī�带 x�� ����)

			for(int p=0; p<=j; p++) {	//p(j���ϱ����� ����)�� �ݺ��Ͽ�(�ߺ��� ����ϹǷ� j'����'��)
				int y = cards[p];		//�� ��° ī�� ����(p��° ī�带 y�� ����)
				int z = k - (x + y);	//ù ��°�� �� ��° ī�带 �̹� ���������Ƿ� ��÷�� �Ǵµ� �ʿ��� �� ��° ī���� ������ z�� ���

				//����Ž���Ͽ� �� Ƚ���� ����
				if(binary_search(cards, cards+n, z) == true) {	//�� ��° ī���� z�� ã�Ҵٸ�(��÷�� �����ϹǷ�)
					possible = true;	//possible������ true�� �����ϰ�
					break;				//��÷ �����ϹǷ� x�� ���� y�� z ���� ã�� �ʿ䰡 ����. �������� Ż��
				}
			}
			if(possible) {				//��÷ �����ϸ�
				break;					//������ Ż���Ͽ� ù ��° ī�带 �ٽ� �̵��� ��
			}
		}
		if(possible) {						//��÷ �����ϸ�
			possibleTargets.push_back(k);	//��÷��ȣ�� possibleTargets ������ �� �ڿ� �߰�
		}
	}
	sort(possibleTargets.begin(), possibleTargets.end());	//��÷��ȣ���� ������������ ����
	return possibleTargets;				//possibleTargets ���� ����
}

int main() {
	int n;	//ī���� ��
	int m;	//�˻��� �ĺ� ��÷��ȣ�� ��

	scanf("%d %d", &n, &m);		//ī���� ��, �˻��� �ĺ� ��÷��ȣ�� �� �Է¹���

	int *cards = new int[n];	//ī�带 ������ �迭�� ī���� �� ��ŭ �������� �Ҵ�
	int *targets = new int[m];	//��÷��ȣ�� ������ �迭�� ��÷��ȣ�� �� ��ŭ �������� �Ҵ�

	//�� ī�� ������ �Է¹޴´�
	for(int i=0; i<n; i++) {
		scanf("%d", &cards[i]);
	}

	//�� �ĺ� ��÷��ȣ�� �Է¹޴´�
	for(int i=0; i<m; i++) {
		scanf("%d", &targets[i]);
	}

	vector<int> answers = getPossibleTargets(n, m, cards, targets);	//�Է¹��� �ĺ� ��÷ ��ȣ �� ��÷�� ��ȣ���� answers ���Ϳ� ����

	if(answers.size() == 0) {	//������ ũ�Ⱑ 0�̶�� �� ��÷��ȣ�� ���ٸ�
		printf("NO");			//"NO"�� ���
	}
	else {						//��÷��ȣ�� �ִٸ�
		for(int i=0; i<answers.size(); i++) {	//answers ������ ������ �� ��ŭ �ݺ��Ͽ�
			if(i>0) {							//0�� ���Ұ� �ƴ϶��
				printf(" ");					//����(" ")�� ���
			}
			printf("%d", answers[i]);			//�ߺ� ���� �ø��� ��ȣ ���
		}
	}

	delete[] cards;			//�����Ҵ��� �迭�� �޸� ����
	delete[] targets;		//�����Ҵ��� �迭�� �޸� ����
	cards = nullptr;		//�迭�� ����Ű�� �����Ϳ� ����� �ּҰ� ����
	targets = nullptr;		//�迭�� ����Ű�� �����Ϳ� ����� �ּҰ� ����

	return 0;				//�����Լ��� ���������� ����
}
