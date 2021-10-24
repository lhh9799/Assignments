#include <stdio.h>

int k_min_of(const int v[], int n, int k);

int main() {
	int n, k, i, j;

	scanf("%d", &n);	//�迭�� ũ�� �Է¹���
	scanf("%d", &k);	//k��° ���� ��
	
	int v[n];

	int k_min_of(const int v[], int n, int k) {
		int copied_v[n], temp;
		
		//�迭 ���� 
		for(i=0; i<n; i++) {
			copied_v[i] = v[i];
		}

		//��������
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

	//�迭 ���� ä���
	for(i=0; i<n; i++) {
		scanf("%d", &v[i]);
	}

	printf("%d", k_min_of(v, n, k));

	return 0;
}

