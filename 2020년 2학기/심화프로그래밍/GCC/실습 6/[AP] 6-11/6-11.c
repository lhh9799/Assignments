#include <stdio.h>

int rev_intary(int v[], int n);

int main() {
	int i, n;
	
	scanf("%d", &n);		//배열 크기 입력받음 
	
	int v[n], revarray[n];	//크기가 n인 int형 배열 선언 
	
	//배열 내용 채움 
	for(i=0; i<n; i++) {
		scanf("%d", &v[i]);
	}
		
	int rev_intary(int v[], int n) {
		//revarray 배열에 역순으로 복사 
		for(i=0; i<n; i++) {
			revarray[n-i-1] = v[i];
		}
		
		return 1;
	}
	
	rev_intary(v, n);
	
	//반전배열 출력 
	for(i=0; i<n; i++) {
		printf("%d ", revarray[i]);
	}
	
	return 0;
}
