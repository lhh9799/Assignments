#include <cstdio>
#include <cmath>
#include <iostream>
using namespace std;

int findIndex(int data[], int n) {
	int sum = 0, diff, idx = 0;
	
	for(int i=0; i<n; i++) {
		sum += data[i];							//��ü �������� �� ��� 
	}
	
	diff = abs(data[0] * n - sum);				//�迭�� ù��° ���ҿ� �ڷ��� ���� n�� ���� ���� sum(��ü ������ ���� ��)���� ���� ���� ���� 
	
	for(int i=0; i<n; i++) {
		if (diff > abs(data[i] * n - sum)) {	//������ �� ���� ���Ҹ� ã�� ��� 
			idx = i;							//idx�� ���� 
			diff = abs(data[i] * n - sum);		//�ּ� ���� ���� 
		}
	}
	
	return idx;
}

int main() {
	int n;				//��ü �������� �� 
	int *data;			//�����͵��� ����� �迭�� ������ ���� 
	
	scanf("%d", &n);
	data = new int[n];	//�迭�� ������ �� ��ŭ �迭�� �����Ҵ�
	
	for(int i=0; i<n; i++) {
		scanf("%d", &data[i]);
	}
	
	int answer = findIndex(data, n);
	printf("%d %d\n", answer+1, data[answer]);	//index���� 1���� �����ϵ��� ����� ���� answer�� 1�� ����
	
	delete []data;	//�����Ҵ��� �迭�� �޸� ����
	data = nullptr;	//�迭�� ����ġ�� �����Ϳ� ����� �ּҰ� ���� 
	
	return 0;
}
