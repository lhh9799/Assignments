#include <stdio.h>

int main() {
	long double base;
	int exponent;
	
	scanf("%Lf %d", &base, &exponent);
	
	if(exponent > 0) {
		do{
			base *= 10;
			exponent--;
		}while(exponent > 0);
	}
	
	else {
		do{
			base /= 10;
			exponent++;
		}while(exponent < 0);
	}
	
	printf("%.10Lf", base);
	return 0;
}
