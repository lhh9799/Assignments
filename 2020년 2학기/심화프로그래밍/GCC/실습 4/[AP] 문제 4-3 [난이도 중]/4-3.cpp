#include <stdio.h>

int main() {
	int i = 1, x, y, cipher = 0, count = 0;	//x�� 1000���� 30000������ ����. �� 4~5�ڸ��� ��. y�� x�� ��� 
	int a, b;	//i�� ����� 
	
	scanf("%d", &x);	//Ű����κ��� x�Է� ����

	for(i=1; i<=x; i++) {
		a = b = i;	//y�� i�� ��� 
		while(a > 0) {	//i�� �ڸ��� ��� 
			a /= 10;
			cipher++;
		}
		printf("cipher = %d\n", cipher);
		while(cipher > 0) {
			printf("���� �ܰ� 1\n"); 
			cipher--;
			if(b % 10 == 3) {
				count++;
				printf("���� �ܰ� 2\n"); 
			}
			b /= 10;
		}
	}
		
	printf("count = %d", count);
	
	return 0;
}
