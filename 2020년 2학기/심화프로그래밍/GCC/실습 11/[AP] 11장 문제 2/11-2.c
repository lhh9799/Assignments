#include <stdio.h>

int main() {
	char string[256];
	int i;
	
	scanf("%s", string);
	
	for(i=0; string[i] != '\0'; i++) {
		if(string[i] != 'a')
			printf("%c", string[i] - 1);
		else
			printf(" ");
	}
	
	return 0;
}
