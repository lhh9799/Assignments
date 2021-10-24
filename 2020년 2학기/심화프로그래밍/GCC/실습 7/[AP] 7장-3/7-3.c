#include <stdio.h>
#include <stdlib.h>	//atoi 함수가 선언된 헤더파일
#include <math.h>

int main() {
	int i;
	char str1[9];

	scanf("%s", str1);

	int b8toUC(char str[]) {
		double dec;

		for(i=0; i<8; i++) {
			dec += (str[i] - '0') * pow(2, 7- i);
		}
		return (int) dec;
	}

	int count1bit(int b8toUC()) {
		int count = 0;

		for(i=0; i<8; i++) {
			if(1 == (str1[i] - '0')){
				count++;
			}
		}
		return count;
	}

	printf("%d\n", b8toUC(str1));
	printf("%d\n", count1bit(b8toUC(str1)));

	return 0;
}

