#include <stdio.h>

int main() {
	int N, i, j, k = 0, row = 1;

	scanf("%d", &N);

	int arr[N*4], buf[4];

	for(i=0; i<N*4; i++) {
		arr[i] = i;
	}

	while(N-- != 0) {
		for(i=0; i<4; i++) {
			buf[i] = arr[k++];
		}
		if(row%2 == 1) {			//홀수번째 가로줄일 경우
			for(j=0; j<4; j++) {
				printf("%d", buf[j]);
			}
			printf("\n");
		}
		else {
			for(j=3; j>=0; j--) {	//역순 출력
				printf("%d", buf[j]);
			}
			printf("\n");
		}
		row++;
	}
	return 0;
}

