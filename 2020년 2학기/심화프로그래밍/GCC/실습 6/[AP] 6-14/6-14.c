#include <stdio.h>

int search_idx(const int v[], int idx[], int key, int n);

int main() {
	int i, n, key, index = 0, count = 0;
	
	scanf("%d", &n);
	scanf("%d", &key);
	
	int v[n], idx[n];
	
	//배열 내용 채움 
	for(i=0; i<n; i++) {
		scanf("%d", &v[i]);
	}
	
	int search_idx(const int v[], int idx[], int key, int n) {
		for(i=0; i<n; i++) {
			if(v[i] == key) {
				idx[index++] = i;
				count++;
			}
		}
		return count;
	}
	
	search_idx(v, idx, key, n);
	
	//키가 존재하는 인덱스 출력 
	for(i=0; i<count; i++) {
		printf("%d ", idx[i]);
	}
	
	//키가 존재하는 인덱스가 없는 경우 
	if(count == 0) {
		printf("-1");
	}
	
	return 0;
}
