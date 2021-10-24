#include <math.h>
#include <stdio.h>

int main() {
	int a, b, c;
	float d;

	scanf("%d %d", &a, &b);
	d = 100 * (float)a/(float) b;
	c = d * 100;	//정수형 변수에 대입함으로서 소수점이하 절삭
	d = (float) c / 100;
	printf("%.2f\n", d);
	
	return 0;
}

