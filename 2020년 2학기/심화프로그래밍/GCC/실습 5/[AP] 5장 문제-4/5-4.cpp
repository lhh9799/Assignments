#include <stdio.h>

int main() {
	int mx[100], N, i, sum = 0;

	scanf("%d", &N);

	for(i=0; i<100; i++) {
		mx[i] = N + i + 1;
	}

	for(i=0; i<50; i++) {
		sum = sum + mx[i] + mx[100-i-1];
	}

	printf("%d", sum);

	return 0;
}

