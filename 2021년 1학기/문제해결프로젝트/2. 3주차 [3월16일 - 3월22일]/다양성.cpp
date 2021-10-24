#include <cstdio>
#include <iostream>
using namespace std;

int getElementTypeCount(int data[], int n) {
	int countType = 1;	//��� 1���� ������ ���� ������ ���� 
	
	for(int i=0; i<n-1; i++) {	//data[i+1]�� �񱳴���̹Ƿ� i���� n-1 �̸����� ���� 
		if(data[i] != data[i+1])//���簪�� �������� �ٸ��ٸ� countType ���� 
			countType++;
	}
	
	return countType;
}

int main() {
	int n;		//ȭ���� �� 
	int *data;	//ȭ���� ������ȣ�� ������ ������ �迭�� ������ ����
	
	scanf("%d", &n);
	data = new int[n];	//ȭ���� ������ȣ�� ������ ������ �迭�� ȭ���� �� ��ŭ �������� �Ҵ� 
	
	for(int i=0; i<n; i++) {	//n(ȭ���� ��)�� �ݺ��Ͽ� 
		scanf("%d", &data[i]);	//ȭ���� ������ȣ�� �Է� ����
	}
	
	int answer = getElementTypeCount(data, n);	//����� ����ϴ� �Լ� 
	
	printf("%d\n", answer);	//�ߺ��� ������ ȭ���� ������ ���� ���
	
	delete []data;	//�����Ҵ��� �迭�� �޸� ���� 
	data = nullptr;	//�迭�� ����ġ�� �����Ϳ� ����� �ּҰ� ���� 
	
	return 0;
}
