#include <stdio.h>

int main() {
	char line[256];
	int i=0;
	
	scanf("%[^\n]", line);
	
	while(line[i] != '\0')
		printf("%c\n", line[i++]);
		
	return 0;
}
