#include <stdio.h>
#include <iostream>
using namespace std;

int findindex(int data[], int n, int m) {
	int RSLT = -1;			//�迭���� ã���� �ϴ� ���� ã�� ���� ��� -1�� �����ϱ� ���� �ʱⰪ ���� 
	
	for(int i=0; i<n; i++) {//n(�迭 ������ ��)�� �ݺ��Ͽ� 
		if(data[i] == m) {	//�迭���� ã���� �ϴ� ���� ã�� ��� 
			RSLT = i;
			break;			//�迭�� �ߺ��Ǵ� �ڷᰡ �����Ƿ�(���� �ٸ� �ڿ����� ����) �� �̻� ã���� �ϴ� ���� ���� �� ����. ���ʿ��� �ݺ����� Ż����. 
		}
	}
	
	return RSLT;			//ã���� �ϴ� ���� �迭�� ����� �����Ͱ� ��ġ�ϴ� �ε����� ���� 
}

int main() {
	int n, m;	//n : �迭 ������ ��, m : ã���� �ϴ� �� 
	int *data;	//���� �ٸ� �ڿ����� ����Ǵ� ������ �迭�� ������ ���� 
	
	scanf("%d %d", &n, &m);
	data = new int[n];	//�迭�� ������ �� ��ŭ �迭�� �����Ҵ�
	
	for(int i=0; i<n; i++) {	//n(�迭 ������ ��)�� �ݺ��Ͽ� 
		scanf("%d", &data[i]);	//�ڿ����� �Է¹��� 
	}
	
	int answer = findindex(data, n, m);	//����� ����ϴ� �Լ�
	
	printf("%d\n", answer);	//��� ��� 
	
	delete []data;	//�����Ҵ��� �迭�� �޸� ����
	data = nullptr;	//�迭�� ����ġ�� �����Ϳ� ����� �ּҰ� ���� 
	
	return 0;
}
