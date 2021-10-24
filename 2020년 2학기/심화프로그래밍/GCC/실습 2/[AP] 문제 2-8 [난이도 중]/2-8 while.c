#include <stdio.h>

int main() {
	long double base;
	int exponent;
	
	scanf("%Lf %d", &base, &exponent);
	
	if(exponent > 0) {
		while(exponent > 0) {
			base *= 10;
			exponent--;
		}
	}
	
	else {
		while(exponent < 0) {
			base /= 10;
			exponent++;
		}
	}
	
	printf("%.10Lf", base);
	
	return 0;
}
