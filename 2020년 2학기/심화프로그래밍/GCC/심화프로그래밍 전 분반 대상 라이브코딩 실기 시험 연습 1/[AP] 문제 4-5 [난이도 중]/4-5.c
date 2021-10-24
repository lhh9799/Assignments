#include <stdio.h>

int main() {
	int i, j = 1, k = 1, l, space, num, h=1;	//k출력용 변수 h = 현재 높이 
	
	scanf("%d", &num);
	
	for(i=0; i<num; i++) {
		k = i+1;
		//공백 출력 단계
		for(space=0; space<num-i; space++) {
			printf(" "); 
		}
		for(l=0; l<j; l++) {
			printf("%d", (k++)%10);
		}
		for(l=0; l<j-1; l++) { 
			printf("%d", ((--k)+9)%10);
		}
		j++;
		printf("\n");
	}
	
	return 0;
}
