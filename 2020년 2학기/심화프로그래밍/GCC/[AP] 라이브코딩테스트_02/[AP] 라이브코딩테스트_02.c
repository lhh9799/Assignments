#include <stdio.h>

int main() {
	int i, idx = 0, A, B, C, D, F, integer, div = 1;	//integer = 정수부 
	//long double result, sosu;
	double result, sosu;
	int temp[10] = {'\0', };
	int num = 0;
	
	scanf("%d %d", &A, &B);
	F = D = C = B;
	
	while(B-- > 0) {
		div *= 10;
	}
	
	integer = A/div;		//정수부 
	sosu = (double) A/div;	//original 소수부 
	sosu -= integer;
	
	while(C-- > 0) {
		temp[idx++] = sosu*10;
		sosu *= 10;
	}
	for(i=D-1; i>=1; i--) {
		temp[i] -= temp[i-1] * 10;
	}
		
	
	printf("%d", integer);
	if(F != 0) {
		printf(".");
		for(i=0; i<F; i++) {
			printf("%d", temp[i]);
		}
	}
	
	return 0;
}
