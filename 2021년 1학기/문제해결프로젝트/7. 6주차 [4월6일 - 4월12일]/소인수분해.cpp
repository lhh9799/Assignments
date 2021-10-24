#include <cstdio>	//C����� stdio.h�� ���� C�� ����� �Լ��� ������ �������
#include <vector>	//vector Ŭ������ ����ϱ� ���� �������(�迭���� ������ : ������, ����� �Լ� ����)
using namespace std;//ǥ�� �̸������� �����

//n�� ������� ����Ͽ� ���Ϳ� ������ �� �����ϴ� �Լ�
vector<int> factorize(int n) {
	vector<int> factors;				//������� ������ ����

	/*����� ���� �̷��. ���� ��� 169�� ���� ��� a�� b�� ������ �ִٰ� �ϸ� a * b = 169�̴�.
	a * b = 169�̹Ƿ� ���� �̷�� �� �� ���� ���� ���� �� �ִ� �ִ��� sqrt(169)�� 13�̴�. ���� ����� �˻��� �� sqrt(�Է°�)������ �˻��ϰ� ���� �̷�� ����� �߰��ϸ� ����Ƚ���� ���� �� �ִ�*/
	for(int div=2; div*div<=n; div+=1) {
		while(n % div == 0) {			//n�� div�� ������ �������ٸ� div�� n�� ������ �ǹ��̹Ƿ�
			factors.push_back(div);		//factors ������ �� �ڿ� �߰�
			n /= div;					//�������� ����
		}
	}
	if(n>1) {							//�� for������ ������ ������ ������ �� div�� sqrt(n)���� Ŀ�� n�� �߰����� ���ϴ� ��찡 �ִ�. 28 -> 14 -> 7�� ���̴�.
		factors.push_back(n);			//���� n�� 1���� ũ�ٸ� �� ���� ����� �����ϴ� factors ������ �� �ڿ� �߰��Ѵ�
	}

	return factors;						//��� ���� ����
}

//�׽�Ʈ���̽��� ��ȣ�� ����� ������ ���͸� ����ϴ� �Լ�
void process(int caseIndex) {
	int n;								//���μ� ������ ��
	scanf("%d", &n);					//���μ� ������ ���� �Է¹���

	vector<int> factors = factorize(n);	//n�� ������� ����Ͽ� factors ���Ϳ� ����

	printf("#%d:\n", caseIndex);		//�׽�Ʈ���̽��� ��ȣ�� ���
	for(int i=0; i<factors.size(); i++) {//factors ������ ������ �� ��ŭ �ݺ��Ͽ�
		if(i>0) {						//����ϴ� ���Ұ� ù ��° ���Ұ� �ƴ� ���
			printf(" ");				//�տ� ����(" ")�� ���
		}
		printf("%d", factors[i]);		//��� ���
	}
	printf("\n");						//new line
}

int main() {
	int caseSize;			//�׽�Ʈ ���̽��� ��
	scanf("%d", &caseSize);	//�׽�Ʈ ���̽��� ���� �Է¹���

	for(int caseIndex=1; caseIndex<=caseSize; caseIndex++) {	//caseSize(�׽�Ʈ ���̽��� ��)�� �ݺ�. ����� Case #1���� �����ϱ� ���� �ʱⰪ�� 1, ������ caseSize ���Ϸ� ����
		process(caseIndex);	//caseIndex�� ���ڷ� process �Լ� ����
	}

	return 0;				//�����Լ��� ���������� ����
}
