#include <stdio.h>

int main() {
	int N, i, j, count = 0;
	char search;

	scanf("%d", &N);
	scanf(" %c", &search);

	char s[N][30];

	for(i=0; i<N; i++) {
		scanf(" %s", s[i]);
	}

	for(i=0; i<N; i++) {
		for(j=0; j<30; j++) {
			if(s[i][j] == search) {
				count++;
			}
		}
	}

	printf("%d", count);

	return 0;
}

