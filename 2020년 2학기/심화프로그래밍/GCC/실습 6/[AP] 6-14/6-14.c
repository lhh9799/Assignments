#include <stdio.h>

int search_idx(const int v[], int idx[], int key, int n);

int main() {
	int i, n, key, index = 0, count = 0;
	
	scanf("%d", &n);
	scanf("%d", &key);
	
	int v[n], idx[n];
	
	//�迭 ���� ä�� 
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
	
	//Ű�� �����ϴ� �ε��� ��� 
	for(i=0; i<count; i++) {
		printf("%d ", idx[i]);
	}
	
	//Ű�� �����ϴ� �ε����� ���� ��� 
	if(count == 0) {
		printf("-1");
	}
	
	return 0;
}
