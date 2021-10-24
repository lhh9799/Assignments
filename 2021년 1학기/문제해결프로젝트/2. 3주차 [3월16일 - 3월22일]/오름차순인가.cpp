#include <cstdio> 
#include <iostream>
using namespace std;

bool isOrdered(int data[], int n) {
	for(int i=0; i<n-1; i++) {	//data[i+1]�� �񱳴���̹Ƿ� i���� n-1 �̸����� ���� 
		if(data[i] > data[i+1])	//data[i+1]�� data[i]���� ũ�ų� ���ƾ� �� data[i]�� data[i+1]���� ũ�� ������ ���� �ʾ����� �ǹ� 
			return false;		//������������ ���ĵ��� ���� �����Ͱ� �ִ� ��� false ����(������ ��� �Ʒ� ������� ������� ����) 
	}
	return true;	//��� �����Ͱ� ���������� ��� true ���� 
}

int main() {
	int n;		//�л��� �� 
	int *data;	//�л����� Ű�� ������ ������ �迭�� ������ ���� 
	
	scanf("%d", &n);	//�л��� �� �Է¹��� 
	data = new int[n];	//���丮���� Ű�� ������ ������ �迭�� ���丮�� �� ��ŭ �������� �Ҵ� 
	
	for(int i=0; i<n; i++) {	//n(�л��� ��)�� �ݺ��Ͽ� 
		scanf("%d", &data[i]);	//�л����� Ű�� �Է� ����
	}
	
	bool result = isOrdered(data, n);	//����� ����ϴ� �Լ� 
	
	if(result) {		//boolean�� ���� true(�л����� Ű�� ������������ ���ĵǾ��ִ�)��
		printf("YES");	//�ֿܼ� "YES" ��� 
	}
	else {				//boolean�� ���� true(�л����� Ű�� ������������ ���ĵǾ��ִ�)�� �ƴ϶��
		printf("NO");	//�ֿܼ� "NO" ��� 
	}
	
	delete []data;	//�����Ҵ��� �迭�� �޸� ���� 
	data = nullptr;	//�迭�� ����ġ�� �����Ϳ� ����� �ּҰ� ���� 
	
	return 0;
}
