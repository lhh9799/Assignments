#include <stdio.h>

int rev_intary(int v[], int n);

int main() {
	int i, n;
	
	scanf("%d", &n);		//�迭 ũ�� �Է¹��� 
	
	int v[n], revarray[n];	//ũ�Ⱑ n�� int�� �迭 ���� 
	
	//�迭 ���� ä�� 
	for(i=0; i<n; i++) {
		scanf("%d", &v[i]);
	}
		
	int rev_intary(int v[], int n) {
		//revarray �迭�� �������� ���� 
		for(i=0; i<n; i++) {
			revarray[n-i-1] = v[i];
		}
		
		return 1;
	}
	
	rev_intary(v, n);
	
	//�����迭 ��� 
	for(i=0; i<n; i++) {
		printf("%d ", revarray[i]);
	}
	
	return 0;
}
