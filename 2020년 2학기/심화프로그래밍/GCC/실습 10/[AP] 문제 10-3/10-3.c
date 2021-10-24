#include <stdio.h>

int n;

int sort_array(int *v, int m) {
	int i, j, temp;

	//오름차순
	if(m == 0) {
		for(i=0; i<n-1; i++) {
			for(j=i+1; j<n; j++) {
				if(v[i] > v[j]) {
					temp = v[i];
					v[i] = v[j];
					v[j] = temp;
				}
			}
		}
	}
	//내림차순
	else if(m == 1) {
		for(i=0; i<n-1; i++) {
			for(j=i+1; j<n; j++) {
				if(v[i] < v[j]) {
					temp = v[i];
					v[i] = v[j];
					v[j] = temp;
				}
			}
		}
	}
	return 0;
}

int main() {
	int i, m;

	scanf("%d %d", &n, &m);
	int v[n];

	for(i=0; i<n; i++)
		scanf("%d", &v[i]);

	sort_array(v, m);

	for(i=0; i<n; i++)
		printf("%d\n", v[i]);

	return 0;
}

