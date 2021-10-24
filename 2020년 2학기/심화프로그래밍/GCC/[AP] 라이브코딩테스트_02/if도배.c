#include <stdio.h>

int main() {
	int A, B;
	scanf("%d %d", &A, &B);
	
	switch(B) {
		case 0 : printf("%d", A);								break;
		case 1 : printf("%.1Lf", (long double) A/10);			break;
		case 2 : printf("%.2Lf", (long double) A/100);			break;
		case 3 : printf("%.3Lf", (long double) A/1000);			break;
		case 4 : printf("%.4Lf", (long double) A/10000);		break;
		case 5 : printf("%.5Lf", (long double) A/100000);		break;
		case 6 : printf("%.6Lf", (long double) A/1000000);		break;
		case 7 : printf("%.7Lf", (long double) A/10000000);		break;
		case 8 : printf("%.8Lf", (long double) A/100000000);	break;
		case 9 : printf("%.9Lf", (long double) A/1000000000);	break;
		case 10 : printf("%.10Lf", (long double) A/10000000000);break;
	}
	
	return 0;
}
