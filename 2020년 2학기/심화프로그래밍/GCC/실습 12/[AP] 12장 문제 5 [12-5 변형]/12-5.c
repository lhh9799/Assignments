#include <stdio.h>
#include <math.h>

#define sqr(n)	((n) * (n))

struct point {
	double x;
	double y;
};

int main() {
	struct point pt[2];
	int i;
	
	for(i=0; i<2; i++)
		scanf("%lf %lf", &pt[i].x, &pt[i].y);
	
	printf("%.2lf", sqrt(sqr(pt[1].x - pt[0].x) + sqr(pt[1].y - pt[0].y)));
	
	return 0;
}
