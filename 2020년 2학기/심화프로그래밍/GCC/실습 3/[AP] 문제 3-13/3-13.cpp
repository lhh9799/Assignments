#include <stdio.h>

int main() {
	int num;
	
	scanf("%d", &num);
	
	switch(num/10) {
		case 9 :
		case 10 : puts("A"); break;
		case 8 : puts("B"); break;
		case 7 : puts("C"); break;
		case 6 : puts("D"); break;
		case 4 :
		case 3 :
		case 2 :
		case 1 :
		case 5 : puts("F"); break;
		default : puts("ERROR"); break;
	}
	
	return 0;
}
