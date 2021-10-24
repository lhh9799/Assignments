#include <stdio.h>

int main () {
	int mx[3][3], my[3][3], i, j;
	
	for(i=0; i<3; i++) {
		for(j=0; j<3; j++) {
			scanf("%d", &mx[i][j]);
		}
	}
	
	for(i=0; i<3; i++) {
		for(j=0; j<3; j++) {
			scanf("%d", &my[i][j]);
		}
	}
	
	for(i=0; i<3; i++) {
		for(j=0; j<3; j++) {
			mx[i][j] -= my[i][j];
		}
	}
	
	for(i=0; i<3; i++) {
		for(j=0; j<3; j++) {
			printf("%d", mx[i][j]);
		}
		printf("\n");
	}
	
	return 0;
}
