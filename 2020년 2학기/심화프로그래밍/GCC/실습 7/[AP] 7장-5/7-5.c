#include <stdio.h>
#include <math.h>

int main() {
	char a[9], b[9];

	scanf("%s", a);
	scanf("%s", b);

	void printADD(char a[],char b[]) {
		int i, dec1 = 0, dec2 = 0, sum = 0;

		//각 배열마다 십진수로 변환
		for(i=0; i<8; i++) {
			dec1 += (a[i] - '0') * pow(2, 7-i);
			dec2 += (b[i] - '0') * pow(2, 7-i);
		}
		printf("%d", dec1 + dec2);
	}

	printADD(a,b);

	return 0;
}

