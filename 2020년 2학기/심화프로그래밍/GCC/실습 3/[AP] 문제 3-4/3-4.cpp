#include <stdio.h>

int main() {
	float num;
	
	scanf("%f", &num);
	
	if(num>=0)
		printf("%f", num);
		
	else {
		num = -num;
		printf("%f", num);
	}
	
	return 0;
}
