#include <stdio.h>

int set_array(int *v, int i, int j, int k) {
	int it;
	
	for(it=i; it<=j; it++)
		v[it] = k;
}
int main() {
	int n, i, j, k, it;
	
	scanf("%d", &n);	//배열의 크기 입력받음
	int v[n];			//배열 선언 

	//변수 입력받음 - i번 부터 j번까지 원소를 특정값 k로 설정 
	scanf("%d %d %d", &i, &j, &k);
	//배열 내용 입력받음 
	for(it=0; it<n; it++)
		scanf("%d", &v[it]);
	//배열 내용 수정 
	set_array(v, i, j, k);
	//배열 내용 출력 
	for(it=0; it<n; it++)
		printf("%d\n", v[it]);
	
	return 0;	
}
