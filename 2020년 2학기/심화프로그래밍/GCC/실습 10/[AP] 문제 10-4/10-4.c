#include <stdio.h>
//������ ������ sum_array�� printf�� 

int sum_array(int *v, int i, int j) {
	int it, sum = 0;
	
	for(it=i; it<=j; it++)
		sum += v[it];
	
	return sum;
}

int main() {
	int it, n, i, j;
	
	scanf("%d %d %d", &n, &i, &j);	//�迭 ũ�� �Է¹���
	int v[n]; 
	
	//�迭 ���� �Է¹��� 
	for(it=0; it<n; it++)
		scanf("%d", &v[it]); 
	
	printf("%d", sum_array(v, i, j));
	
	return 0;
}
