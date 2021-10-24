#include <stdio.h>

int main() {
	int x;
	float a, b;
	
	scanf("%f %f", &a, &b);
	x = a*b*100;
	printf("%.2f", (float)x/100);
	
	return 0;
}
