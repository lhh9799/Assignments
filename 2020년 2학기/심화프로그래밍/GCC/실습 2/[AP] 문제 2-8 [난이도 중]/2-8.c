#include <stdio.h>
#include <math.h>

int main() {
	long double a;
	int b;

	scanf("%Lf %d", &a, &b);
	//printf("%Lf\n", a);
	printf("%.10Lf", a*pow(10, b));

	return 0;
}

