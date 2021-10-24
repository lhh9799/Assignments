#include <cstdio>
#include <iostream>
using namespace std;

int getMaximumHeight(int height[], int month[], int n, int m) {
	for(int i=n-1; i>=0; i--) {	//���丮���� Ű�� ������������ �ԷµǾ� �ֱ� ������ �ڿ������� Ž��
		if(month[i] == m)
			return height[i];	//�̹� �޿� ������ �ִ� ���丮�� �� ���� Ű�� ū ���丮�� Ű�� ����(������ ��� �Ʒ� ������� ������� ����) 
	}
	
	return -1;					//���Ͽ� �ش� �޿� ���� ���丮�� ���� ��� -1�� ���� 
}

int main() {
	int n, m;		//n : ���丮�� ��, m : ���� �� 
	int *height;	//���丮���� Ű�� ������ ������ �迭�� ������ ���� 
	int *month;		//���丮���� ������ ���� ���� ������ ������ �迭�� ������ ���� 
	
	scanf("%d", &n);
	height = new int[n];	//���丮���� Ű�� ������ ������ �迭�� ���丮�� �� ��ŭ �������� �Ҵ� 
	month = new int[n];		//���丮���� ������ ���� ���� ������ ������ �迭�� ���丮�� �� ��ŭ �������� �Ҵ� 
	
	for(int i=0; i<n; i++) {		//n(���丮�� ��)�� �ݺ��Ͽ� 
		scanf("%d", &height[i]);	//���丮���� Ű�� �Է� ����
	}
	
	for(int i=0; i<n; i++) {	//n(���丮�� ��)�� �ݺ��Ͽ� 
		scanf("%d", &month[i]);	//���丮���� ������ ���� ���� �Է� ���� 
	}
	
	scanf("%d", &m);	//���� ���� �Է� ���� 
	
	int answer = getMaximumHeight(height, month, n, m);	//����� ����ϴ� �Լ� 
	
	printf("%d\n", answer);	//�̹� �޿� ������ �ִ� ���丮�� �� ���� Ű�� ū ���丮�� Ű�� ��� 
	
	delete []height;	//�����Ҵ��� �迭�� �޸� ���� 
	delete []month;		//�����Ҵ��� �迭�� �޸� ���� 
	height = nullptr;	//�迭�� ����ġ�� �����Ϳ� ����� �ּҰ� ���� 
	month = nullptr;	//�迭�� ����ġ�� �����Ϳ� ����� �ּҰ� ���� 
	
	return 0;
}
