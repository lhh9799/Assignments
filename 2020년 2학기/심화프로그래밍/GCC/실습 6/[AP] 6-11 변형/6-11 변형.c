#include <stdio.h>

int rotate_intary(int v[], int n, int k);

int main() {
	int i, n, k;
	
	scanf("%d", &n);	//�迭 ũ�� 
	scanf("%d", &k);	//������Ʈ Ƚ�� 
	
	int v[n], rotatearray[n];	//ũ�Ⱑ n�� int�� �迭 v����
	
	//�迭 ���� ä�� 
	for(i=0; i<n; i++) {
		scanf("%d", &v[i]);
	}
	
	//�迭 v�� ���ҵ��� kĭ�� rotate 
	int rotate_intary(int v[], int n, int k) {
		int temp[k];	//�ӽ� �迭 ����
		
		for(i=0; i<n; i++) {
			rotatearray[(i+k+n)%n] = v[i];
		}
		
		return 1;
	}
	
	rotate_intary(v, n, k);

	for(i=0; i<n; i++) {
		printf("%d ", rotatearray[i]);
	}
	 
	return 0;
}
