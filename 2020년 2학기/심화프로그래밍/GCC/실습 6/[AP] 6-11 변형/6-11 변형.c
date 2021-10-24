#include <stdio.h>

int rotate_intary(int v[], int n, int k);

int main() {
	int i, n, k;
	
	scanf("%d", &n);	//배열 크기 
	scanf("%d", &k);	//로테이트 횟수 
	
	int v[n], rotatearray[n];	//크기가 n인 int형 배열 v선언
	
	//배열 내용 채움 
	for(i=0; i<n; i++) {
		scanf("%d", &v[i]);
	}
	
	//배열 v의 원소들을 k칸씩 rotate 
	int rotate_intary(int v[], int n, int k) {
		int temp[k];	//임시 배열 선언
		
		for(i=0; i<n; i++) {
			rotatearray[(i+k+n)%n] = v[i];
		}
		
		return 1;
	}
	
	rotate_intary(v, n, k);

	for(i=0; i<n; i++) {
		printf("%d ", rotatearray[i]);
	}
	 
	return 0;
}
