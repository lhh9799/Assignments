#include <math.h>
#include <stdio.h>

int main() {
	int a, b, c;
	float d;

	scanf("%d %d", &a, &b);
	d = 100 * (float)a/(float) b;
	c = d * 100;	//������ ������ ���������μ� �Ҽ������� ����
	d = (float) c / 100;
	printf("%.2f\n", d);
	
	return 0;
}

