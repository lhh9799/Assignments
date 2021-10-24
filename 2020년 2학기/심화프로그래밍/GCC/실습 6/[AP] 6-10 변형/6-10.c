#include <stdio.h>

int k_min_of(const int v[], int n, int k);

int main() {
	int n, k, i, j;

	scanf("%d", &n);	//배열의 크기 입력받음
	scanf("%d", &k);	//k번째 작은 수
	
	int v[n];

	int k_min_of(const int v[], int n, int k) {
		int copied_v[n], temp;
		
		//배열 복사 
		for(i=0; i<n; i++) {
			copied_v[i] = v[i];
		}

		//선택정렬
		for(i=0; i<n-1; i++) {
			for(j=i+1; j<n; j++) {
				if(copied_v[i] > copied_v[j]) {
					temp = copied_v[i];
					copied_v[i] = copied_v[j];
					copied_v[j] = temp;
				}
			}
		}		
		return copied_v[k-1];
	}

	//배열 내용 채우기
	for(i=0; i<n; i++) {
		scanf("%d", &v[i]);
	}

	printf("%d", k_min_of(v, n, k));

	return 0;
}

