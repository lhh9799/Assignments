#include <stdio.h>

int search_char(const char *str, char c) {
	int i, res = -1;
	
	for(i=0; str[i] != '\0'; i++) {
		if(str[i] == c) {
			res = i;
			break;
		}
	}
	
	return res;
}

int main() {
	char string[256], c;
	scanf("%[^\n]", string);
	scanf(" %c", &c);
	
	printf("%d", search_char(string, c));
	
	return 0;
}
