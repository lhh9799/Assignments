#include <stdio.h>	//C����� stdio.h�� ���� C�� ����� �Լ��� ������ �������
#include <map>		//map Ŭ������ ����ϱ� ���� �������(�� ��尡 key�� value ������ �̷���� Ʈ��. �ߺ��� ������� ����. �������� ����)
using namespace std;//ǥ�� �̸������� �����

int main() {
	int N;			//������ �� ����
	scanf("%d", &N);//������ �� �Է¹���

	//�� <����,�󵵼�>���·� key-value�� ������ Map �ڷᱸ��
	//frequencyMap := ������ �Էµ� �������� �󵵼��� �����ϰ� �ִ�.
	map<int, int> frequencyMap;

	for(int i=0; i<N; i++) {//N(�������� ��)�� �ݺ��Ͽ�
		int X;				//�Է¹��� ���� ����
		scanf("%d", &X);	//���� �Է¹���
		frequencyMap[X]++;	//�ش� ������ �󵵼� 1����
		printf("%d %d\n", frequencyMap.size(), frequencyMap[X]);	//������ ������ �Է¹��� ������ ������ Ƚ�� ���
	}

	return 0;				//�����Լ��� ���������� ����
}
