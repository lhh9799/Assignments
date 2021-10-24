#include <cstdio>
#include <iostream>
using namespace std;

int getMinIndexInRange(int data[], int n, int begin, int end) {
	int idx = begin, min = data[begin];	//�ּڰ��� ã�� ���� �ʱⰪ ���� 
	
	for(int it=begin; it<end+1; it++) {	//������ ���ҿ��� �����ϱ� ���� end������ 1�� ���ؾ� �� 
		if(data[it] < min) {			//���� ������ �ִ� �ּڰ����� ���� �ּڰ��� ã�� ��� 
			idx = it;					//�ε��� ���� 
			min = data[it];				//�ּڰ� ����
		}
	}
	
	return idx;
}

void selectionSort(int data[], int n) {
	for(int i=0; i<n; i++) {
		int minIndex = getMinIndexInRange(data, n, i, n-1);
		//���� ��ġ�� �ּڰ��� �����͸� ��ȯ
		int temp = data[i];
		data[i] = data[minIndex];
		data[minIndex] = temp;
	}
}

int main() {
	int n;				//��ü �������� �� 
	int *data;			//�����͵��� ����� �迭�� ������ ���� 
	
	scanf("%d", &n);
	data = new int[n];	//�迭�� ������ �� ��ŭ �迭�� �����Ҵ�
	
	for(int i = 0; i<n; i++) {
		scanf("%d", &data[i]);
	}
	
	selectionSort(data, n);
	
	for(int i=0; i<n; i++) {
		if(i>0) {
			printf(" ");
		}
		printf("%d", data[i]);
	}
	
	delete data;	//�����Ҵ��� �迭�� �޸� ����
	data = nullptr;	//�迭�� ����ġ�� �����Ϳ� ����� �ּҰ� ���� 
	
	return 0;
}
