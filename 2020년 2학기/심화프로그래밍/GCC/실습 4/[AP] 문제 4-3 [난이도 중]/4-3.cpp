#include <stdio.h>

int main() {
	int i = 1, x, y, cipher = 0, count = 0;	//x는 1000부터 30000까지의 숫자. 즉 4~5자리의 수. y는 x의 백업 
	int a, b;	//i값 백업용 
	
	scanf("%d", &x);	//키보드로부터 x입력 받음

	for(i=1; i<=x; i++) {
		a = b = i;	//y에 i값 백업 
		while(a > 0) {	//i의 자릿수 계산 
			a /= 10;
			cipher++;
		}
		printf("cipher = %d\n", cipher);
		while(cipher > 0) {
			printf("실행 단계 1\n"); 
			cipher--;
			if(b % 10 == 3) {
				count++;
				printf("실행 단계 2\n"); 
			}
			b /= 10;
		}
	}
		
	printf("count = %d", count);
	
	return 0;
}
