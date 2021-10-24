#include <math.h>
#include <stdio.h>

int main() {
	int a, b, c;
	float d;
	
	scanf("%d %d", &a, &b);
	d = 100 * (float)a/(float) b;
	c = d * 1000;	//정수형 변수에 대입함으로서 소수점이하 절삭
	//printf("c = %d\n", c);
	d = (float) c / 1000;
	//printf("d = %f\n", d);
	printf("%.2f\n", d);
	
	return 0;
}
