#include <stdio.h>
//문제의 원인은 sum_array의 printf문 

int sum_array(int *v, int i, int j) {
	int it, sum = 0;
	
	for(it=i; it<=j; it++)
		sum += v[it];
	
	return sum;
}

int main() {
	int it, n, i, j;
	
	scanf("%d %d %d", &n, &i, &j);	//배열 크기 입력받음
	int v[n]; 
	
	//배열 내용 입력받음 
	for(it=0; it<n; it++)
		scanf("%d", &v[it]); 
	
	printf("%d", sum_array(v, i, j));
	
	return 0;
}
