#include <stdio.h>

int main(void) {
	unsigned int a;
	int index = 0, i, array[8] = {0, };

	scanf("%d", &a);

	void print8bit(int a) {
		for(i=7; i>=0; i--) {
			printf("%d", array[i]);
		}
	}

	do {
		if(a % 2 == 0) {
			array[index++] = 0;
		}
		else {
			array[index++] = 1;
		}
		a /= 2;
	}while(a > 0);

	print8bit(a);

	return 0;
}

