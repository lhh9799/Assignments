#include <cstdio>	//C����� stdio.h�� ���� C�� ����� �Լ��� �����ϴ� �������
using namespace std;//ǥ�� �̸������� �����

const int MAX_TABLE_LENGTH = 10000;	//0000���� 9999���� 10000���� ����� ���� ������ ��ȭ��ȣ�� const ����� ����(���� ������ �� ����)

//�Է¹��� ��ȭ��ȣ�� �󵵸� ����ϴ� �Լ�
void fillFrequencyTable(int data[], int n, int table[]) {
	for(int i=0; i<MAX_TABLE_LENGTH; i++) {	//MAX_TABLE_LENGTH(10000)�� �ݺ��Ͽ�
		table[i] = 0;						//�迭�� ���� 0���� �ʱ�ȭ
	}

	for(int i=0; i<n; i++) {				//n(��ȭ��ȣ�� ��)�� �ݺ��Ͽ�
		table[data[i]]++;					//��ȭ��ȣ(data[i])�� �ε����� �Ͽ� �󵵼� ����
	}
}

//���� �� �� �ִ��� ã�� �Լ�
int getFrequentNumber(int data[], int n) {
	int frequent_number = 0;
	int table[MAX_TABLE_LENGTH];				//0~9999���� ��ȭ��ȣ�� �󵵸� �����ϴ� ������׷�
	fillFrequencyTable(data, n, table);			//�Է¹��� ��ȭ��ȣ�� ���ڷ� �Ѱ� table �迭�� �󵵸� ä������

	for(int i=0; i<MAX_TABLE_LENGTH; i++) {		//MAX_TABLE_LENGTH(10000)�� �ݺ��Ͽ�
		if(table[i] > table[frequent_number])	//i��° ��ȣ�� ���� ū ��ȣ�� �����ϰ� �ִ� ������ ������ ũ�ٸ�. ������ Ƚ���� ���� ��ȣ�� �� �� �̻��� ��� ���������� ���� ���ڸ� ����ϱ� ���� ��ȣ�� ���� �ʴ´�.
			frequent_number = i;				//frequent_number�� i(�ִ��� ����Ű�� �ε���)�� ����
	}

	return frequent_number;						//���� ���� ������ ��ȣ�� �ε��� ����
}

int main() {
	int n;										//��ȭ��ȣ�� ��(1�̻� 10�������� �ڿ���)

	scanf("%d", &n);							//��ȭ��ȣ�� �� �Է¹���
	int *data = new int[n];						//��ȭ��ȣ�� ������ �迭�� ��ȭ��ȣ�� �� ��ŭ �������� �Ҵ�

	for(int i=0; i<n; i++) {					//n(��ȭ��ȣ�� ��)�� �ݺ��Ͽ�
		scanf("%d", &data[i]);					//��ȭ��ȣ�� �Է¹���
	}

	int answer = getFrequentNumber(data, n);	//���� ���� ������ ��ȭ��ȣ�� ����Ͽ� answer ������ ����

	printf("%04d", answer);						//4�ڸ��� �ڸ����� ä�� ���(�� 10 -> 0010)

	delete []data;								//�����Ҵ��� �迭�� �޸� ����
	data = nullptr;								//�迭�� ����Ű�� �����Ϳ� ����� �ּҰ� ����

	return 0;									//�����Լ��� ���������� ����
}

