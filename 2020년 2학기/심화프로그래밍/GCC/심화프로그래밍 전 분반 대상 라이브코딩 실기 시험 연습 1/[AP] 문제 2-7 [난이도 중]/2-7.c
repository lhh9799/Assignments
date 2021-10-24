#include <stdio.h>

int main() {
	float a, b;
	int c;
	
	scanf("%f %f", &a, &b);
	c = a*b*100;
	
	printf("%.2f", (float)c/100);
	
	return 0;
}
