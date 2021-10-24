#include <stdio.h>

int main() {
	int i, j, h, p;					//i : 현재 높이, j : 루프용 변수, h : 총 높이

	scanf("%d", &h);

	for(i=1; i<=h; i++) {
		p = i;

		for(j=0; j<h-i; j++) {		//공백으로 채울 수(전체 높이 - 현재 높이)만큼 루프
			printf(" ");
		}
		for(j=i; j<2*i-1; j++) {	//상승세를 출력하는 루프
			p %= 10;
			printf("%d", p++);
		}
		for(j=2*i; j>i; j--) {		//하락세를 출력하는 루프
			p = (p+10) % 10;		//화면에 음수를 출력하는 것을 막기 위함
			printf("%d", p--);
		}
		printf("\n");				//줄바꿈
	}

	return 0;
}

