#include <stdio.h>

int set_array(int *v, int i, int j, int k) {
	int it;
	
	for(it=i; it<=j; it++)
		v[it] = k;
}
int main() {
	int n, i, j, k, it;
	
	scanf("%d", &n);	//�迭�� ũ�� �Է¹���
	int v[n];			//�迭 ���� 

	//���� �Է¹��� - i�� ���� j������ ���Ҹ� Ư���� k�� ���� 
	scanf("%d %d %d", &i, &j, &k);
	//�迭 ���� �Է¹��� 
	for(it=0; it<n; it++)
		scanf("%d", &v[it]);
	//�迭 ���� ���� 
	set_array(v, i, j, k);
	//�迭 ���� ��� 
	for(it=0; it<n; it++)
		printf("%d\n", v[it]);
	
	return 0;	
}
