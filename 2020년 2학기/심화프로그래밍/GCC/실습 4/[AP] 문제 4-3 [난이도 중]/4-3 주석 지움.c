#include <stdio.h>

int main() {
	int i, x, cipher = 0, count = 0;
	int a, b;
	
	scanf("%d", &x);

	for(i=1; i<=x; i++) {
		a = b = i;
		while(a > 0) {
			a /= 10;
			cipher++;
		} 
		while(cipher > 0) {
			if(b % 10 == 3) {
				count++;
			}
			b /= 10;
			cipher--;
		}
	}
		
	printf("count = %d", count);
	
	return 0;
}
