#include <stdio.h>

int main() {
	int N, i, j, temp;
	
	scanf("%d", &N);
	
	int a[N*5], b[N*5];
	
	for(i=0; i<N*5; i++) {
		scanf("%d", &a[i]);
	}

	for(i=0; i<N*5-1; i++) {	//j=i+1�̱� ������(10��° ���Ҵ� ����) 
		for(j=i+1; j<N*5; j++) {
			if(a[i] < a[j]) {
				temp = a[j];
				a[j] = a[i];
				a[i] = temp;
			}
		}
	}
	
	for(i=0; i<N*5; i++) {
		b[i] = a[i];
	}
	
	for(i=0; i<N*5; i++) {
		printf("%d ", b[i]);
	}
	
	return 0;
}
