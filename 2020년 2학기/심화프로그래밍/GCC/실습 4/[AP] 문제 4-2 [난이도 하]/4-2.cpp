#include <stdio.h>

int main() {
	int i;
	
	scanf("%d", &i);
	i /= 2;
	
	while(i > 0) {
		printf("%d ", i*2);
		i--;
	}
	
	return 0;
}
