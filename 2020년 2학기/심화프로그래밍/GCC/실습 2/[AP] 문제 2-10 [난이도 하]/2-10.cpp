#include <math.h>
#include <stdio.h>

int main() {
	int a, b, c;
	float d;
	
	scanf("%d %d", &a, &b);
	d = 100 * (float)a/(float) b;
	c = d * 1000;	//������ ������ ���������μ� �Ҽ������� ����
	//printf("c = %d\n", c);
	d = (float) c / 1000;
	//printf("d = %f\n", d);
	printf("%.2f\n", d);
	
	return 0;
}
