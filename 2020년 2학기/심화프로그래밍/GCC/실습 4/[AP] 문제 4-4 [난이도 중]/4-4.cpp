#include <stdio.h>

int main() {
	int i, j;
	
	for(i=0; i<26; i++) {
		for(j=i; j<26; j++) {
			printf("%c", (char) j+65);
		}
		printf("\n");
	}
	return 0;
}
