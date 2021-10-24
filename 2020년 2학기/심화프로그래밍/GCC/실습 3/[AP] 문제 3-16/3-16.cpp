#include <stdio.h>

int main() {
	int num;
	
	scanf("%d", &num);
	
	switch(num) {
		case 2 : puts("28"); break;
		//31ÀÏ 
		case 1 :
		case 3 :
		case 5 :
		case 7 :
		case 8 :
		case 10 :
		case 12 : puts("31"); break;
		//30ÀÏ 
		case 4 :
		case 6 :
		case 9 :
		case 11 : puts("30"); break;
		default : puts("ERROR"); break;
	}
	
	return 0;
}
