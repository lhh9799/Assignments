#include <stdio.h>

int main() {
	char num[30];
	int i = 0, cnt = 1;
	
	scanf("%[^\n]", num);

do {
		if(cnt == 7) {
			printf("-");
			cnt++;
		}
		if(num[i] >= '0' && num[i] <= '9') {
			printf("%c", num[i]);
			cnt++;
		}
	} while(num[i++] != '\0');
	
	return 0;
}
