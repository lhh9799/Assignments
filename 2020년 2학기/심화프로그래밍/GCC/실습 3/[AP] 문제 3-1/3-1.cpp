#include <stdio.h>

int main() {
	int num;
	
	scanf("%d", &num);
	
	if(num%7==0)
		printf("%d is multiple of 7", num);
		
	else
		printf("%d is not multiple of 7", num);
		
	return 0;
}
