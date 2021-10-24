#include <stdio.h>
#include <stdlib.h>	//atoi 함수가 선언된 헤더파일
#include <math.h>

int main() {
	unsigned int digit;
	char str[8];
	int i;
	double dec = 0;

	scanf("%s", str);

	void print10(char *str) {
		for(i=0; i<8; i++) {
			dec += (str[i] - '0') * pow(2, 7- i);
		}
		printf("%d", (int) dec);
	}

	print10(str);

	return 0;
}

