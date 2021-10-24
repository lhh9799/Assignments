#include <iostream>	//����� �Լ��� ����ϱ� ���� �������
#include <string>	//.c_str�Լ��� ����ϱ� ���� �������
#include <map>		//map Ŭ������ ����ϱ� ���� �������(�� ��尡 key�� value ������ �̷���� Ʈ��. �ߺ��� ������� ����. �������� ����)
using namespace std;//ǥ�� �̸������� �����

int main() {
	int N;		//��ǥ������ ��
	cin >> N;	//��ǥ������ �� �Է¹���

	//�� �ĺ� �̸��� ��ǥ ���� �����ϴ� key-value Map
	map<string, int> frequencyMap;

	int maxFrequency = 0;	//���� ���� ��ǥ��

	//�� �̸��� �ϳ� �߰��� ������ ��������� �ִ� ��ǥ �� ����. �ִ� ��ǥ �ĺ� ����Ʈ�� �����ذ���.
	for(int i=0; i<N; i++) {		//N(��ǥ������ ��)�� �ݺ��Ͽ�
		string st;					//�ĺ����� �̸� ����
		cin >> st;					//�ĺ����� �̸� �Է¹���
		frequencyMap[st]++;			//�ش� �ĺ����� �󵵼� 1����
		int k = frequencyMap[st];	//�ش� �ĺ����� �󵵼��� ������ ���� k�� ����
		if(k > maxFrequency) {		//k�� ������ ������ �ִ� ��ǥ�� ���� ũ�ٸ�
			maxFrequency = k;		//k�� �ִ� ��ǥ������ ����
		}
	}

	//�ִ� ��ǥ �ĺ� ���� ����Ѵ�.
	cout << maxFrequency << endl;

	//�ִ� ��ǥ�� �� ���� �ĺ��� �̸��� ���������� ����Ѵ�.
	map<string, int>::iterator it;		//map �ݺ��� it ����
	for(it=frequencyMap.begin(); it!=frequencyMap.end(); it++) {	//ù ���� ���ҿ� ���� ������ �ʱ�ȭ. ������ ���� ������ ����Ű�� ������ �ƴҶ� ���� �ݺ�. �ּҰ� ����
		if(it->second == maxFrequency)	//������ ������ value���� maxFrequency(�ִ� ��ǥ��)�� ���ٸ�
			printf("%s ", it->first.c_str());	//�ش� ������ key�� ���
	}
}
