#include <cstdio>	//C����� stdio.h�� ���� C�� ����� �Լ��� ������ �������
#include <vector>	//vector Ŭ������ ����ϱ� ���� �������(�迭���� ������ : ������, ����� �Լ� ����)
#include <algorithm>//Ž��, ����, ��, ���� �� ���� �Լ��� �����ϴ� �������
using namespace std;//ǥ�� �̸������� �����

const int MAX_SERIAL_NUMBER = 100000;			//�ø��� ��ȣ�� �ִ��� const ����� ����(���� ������ �� ����)

//�Է¹��� �ø��� ��ȣ�� �󵵸� ����ϴ� �Լ�
void fillFrequencyTable(const vector<int> &data, int n, vector<int> &table) {	//data���͸� ���������� �޾� ���ʿ��� ���縦 ���Ѵ�
	table.resize(MAX_SERIAL_NUMBER + 1,  0);	//���� table�� ũ�⸦ MAX_SERIAL_NUMBER + 1�� ����(ũ�⸦ 100000�� �����ϸ� 99999�� �ε��������� �����Ǳ� ����), 0���� �ʱ�ȭ

	for(int i=0; i<n; i++) {					//n(�������� ��)�� �ݺ��Ͽ�
		table[data[i]]++;						//�ø��� ��ȣ(data[i])�� �ε����� �Ͽ� �󵵼� ����
	}
}

//�ߺ����� �ø��� ��ȣ�� �����ϴ� �Լ�
vector<int> getUniqueElements(const vector<int> &data, int n) {	//data���͸� ���������� �޾� ���ʿ��� ���縦 ���Ѵ�
	vector<int> ret;	//�ߺ����� �ø��� ��ȣ�� ������ ���� ret ����
	vector<int> table;	//�ø��� ��ȣ�� �󵵸� �����ϴ� ������׷�

	fillFrequencyTable(data, n, table);	//data(�Է¹��� �ø��� ��ȣ �迭)�� ���ڷ� �Ѱ� table �迭�� �󵵸� ä������

	for(int i=1; i<=MAX_SERIAL_NUMBER; i++) {					//MAX_SERIAL_NUMBER(�ø��� ��ȣ�� �ִ�)�� �ݺ��Ͽ�
		if(table[i] == 1) {										//��ü �����Ϳ��� �� �� ������ ���Ҷ��
			ret.push_back(i);									//������ �� �ڿ� ���� ����
		}
	}

	return ret;					//�ߺ����� �ø��� ��ȣ�� �����ϴ� ���� ret ����
}

int main() {
	int n;						//�������� ��(1�̻� 10�������� �ڿ���)
	scanf("%d", &n);			//�������� �� �Է¹���

	vector<int> data = vector<int>(n);		//0���� �ʱ�ȭ��, n���� ������ �����ϴ� ���� data ����

	for(int i=0; i<n; i++) {	//n(�������� ��)�� �ݺ��Ͽ�
		scanf("%d", &data[i]);	//�ø��� ��ȣ �Է¹���
	}

	const vector<int> answer = getUniqueElements(data, n);	//�ߺ� ���� �ø��� ��ȣ�� �����ϴ� getUniqueElements �Լ��� ȣ���Ͽ� ���ϰ��� answer ���Ϳ� ����

	for(int i=0; i<answer.size(); i++) {	//answer ������ ������ �� ��ŭ �ݺ��Ͽ�
		if(i>0) {							//0�� ���Ұ� �ƴ϶��
			printf(" ");					//����(" ")�� ���
		}
		printf("%d", answer[i]);			//�ߺ� ���� �ø��� ��ȣ ���
	}

	return 0;								//�����Լ��� ���������� ����
}

