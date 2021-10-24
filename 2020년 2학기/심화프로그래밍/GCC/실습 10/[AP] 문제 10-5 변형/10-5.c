#include <stdio.h>

int main() {
	int it, n, i, j, k;
	
	scanf("%d %d %d %d", &n, &i, &j, &k);
	int v[n];
	
	int reset_array(int *v, int i, int j, int k) {
		int it;

		for(it=0; it<n; it++)
			if(it<i || it>j)
				v[it] = k;
		
		return 0;
	}
	
	for(it=0; it<n; it++)
		scanf("%d", &v[it]);
	
	reset_array(v, i, j, k);
	
	for(it=0; it<n; it++)
		printf("%d\n", v[it]);
	
	return 0;
}
