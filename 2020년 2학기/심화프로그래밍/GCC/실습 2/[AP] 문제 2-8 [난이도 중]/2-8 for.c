#include <stdio.h>

int main() {
	long double base;
	int exponent, i;
	
	scanf("%Lf %d", &base, &exponent);
	
	if(exponent > 0) {
		for(i=0; i<exponent; i++) {
			base *= 10;
		}
	}
	
	else {
		for(i=0; i>exponent; i--) {
			base /= 10;
		}
	}
	
	printf("%.10Lf", base);
	
	return 0;
}
