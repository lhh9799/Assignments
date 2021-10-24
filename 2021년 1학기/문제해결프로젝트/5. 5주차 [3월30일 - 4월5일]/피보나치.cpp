#include <cstdio>	//C����� stdio.h�� ���� C�� ����� �Լ��� ������ �������
#include <vector>	//vector Ŭ������ ����ϱ� ���� �������(�迭���� ������ : ������, ����� �Լ� ����)
using namespace std;//ǥ�� �̸������� �����

const int MAX_N = 1000000;		//� �� N�� �ִ��� const ����� ����(���� ������ �� ����)
vector<int> FIBONACCI_TABLE;	//�Ǻ���ġ ������ ������ ���� FIBONACCI_TABLE ����

//�̸� �Ǻ���ġ ������ ����� ���Ϳ� �����ϴ� �Լ�
vector<int> makeFibonacciTable(int n) {
	const int MOD = 100000000;	//������ 8�ڸ� ���� �����ϱ� ���� ��ġ

	vector<int> ret(n+1);		//���� ret�� ũ�⸦ MAX_N + 1�� ����(ũ�⸦ 1000000�� �����ϸ� 999999�� �ε��������� �����Ǳ� ����)
	ret[1] = 0;					//�Ǻ���ġ ������ 1��° ���ڴ� 0
	ret[2] = 1;					//�Ǻ���ġ ������ 2��° ���ڴ� 1

	for(int i=3; i<=n; i++) {			//1���� 2���� ������ �ʿ䰡 �����Ƿ� i�� 3���� ����. n���� ������ ����ؾ� �ϹǷ� n���� �� ������ �ݺ�
		ret[i] = ret[i-1] + ret[i-2];	//�� ��°�� ���� ��� ���� �ٷ� �� �� ���� ���� ������
		ret[i] %= MOD;					//�Ǻ���ġ ���� ������ 8�ڸ� ���ڸ��� �����ϱ� ���� MOD(100000000)�� ���� �������� ����
	}

	return ret;							//�ٷ� �� �� ���� ���� ���� �� 8�ڸ��� ������ ���� ����
}

//n��° �Ǻ���ġ ���� �����ϴ� �Լ�
int getFibo(int n) {
	int answer = FIBONACCI_TABLE[n];	//���Ǿ��ִ� �Ǻ���ġ ���� ���Ϳ��� n��° ���� answer�� ����

	return answer;						//n��° �Ǻ���ġ ��(answer) ����
}

int main() {
	FIBONACCI_TABLE = makeFibonacciTable(MAX_N);				//MAX_N��°������ �Ǻ���ġ ������ ���� FIBONACCI_TABLE�� ����

	int caseSize;					//�׽�Ʈ ���̽��� ��(1�̻� 10�� ����)
	scanf("%d", &caseSize);			//�׽�Ʈ ���̽��� �� �Է¹���

	for(int caseIndex=1; caseIndex<=caseSize; caseIndex++) {	//caseSize(�׽�Ʈ ���̽��� ��)�� �ݺ�. ����� 1������ �ϱ� ������ ������ caseSize ���Ϸ� ����
		int n;						//Ȯ���ϰ��� �ϴ� ��(n��° ��)
		scanf("%d", &n);			//n��° �� �Է¹���

		int answer = getFibo(n);	//n��° ���� answer�� ����
		printf("%d\n", answer);		//n��° �� ���
	}

	FIBONACCI_TABLE.clear();		//���� FIBONACCI_TABLE�� ��� ���� ����

	return 0;						//�����Լ��� ���������� ����
}
