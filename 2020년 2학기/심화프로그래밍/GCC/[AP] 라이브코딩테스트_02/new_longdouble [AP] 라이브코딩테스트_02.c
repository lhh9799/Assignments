#include <stdio.h>
#include <math.h>

int main() {
	int i, idx = 0, A, B, C, D, F, integer, div = 1;	//integer = 정수부 
	long double result, sosu;
	//double result, sosu;
	int temp[10] = {'\0', };
	int num = 0;
	
	scanf("%d %d", &A, &B);
	F = D = C = B;
	
	/*while(B-- > 0) {
		div *= 10;
	}
	
	integer = A/div;			//정수부 */
	integer = A * pow(0.1, B);
	sosu = A * pow(0.1, B);
	//sosu = (double) A/div;		//original 소수부 
	sosu -= integer;
	
	while(C-- > 0) {
		temp[idx++] = sosu*10;
		sosu *= 10;
	}
	for(i=D-1; i>=1; i--) {
		temp[i] -= temp[i-1] * 10;
	}
	
	sosu = 0;
	for(i=0; i<F; i++) {
		//printf("%Lf\n", pow(0.1, (i+1)) * temp[i]);
		sosu += pow(0.1, (i+1)) * temp[i];
		//printf("%d", temp[i]);
	}
	//printf("integer = %d, sosu = %lf\n", integer, sosu);
	result = integer + sosu;
	//printf("result = %lf", result);
	printf("%Lf", result);
	
	return 0;
}
