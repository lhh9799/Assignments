#include <stdio.h>

int main() {
	int i, j, N, content = 1, n = 0;
	
	scanf("%d", &N);
	
	int a[N][N]; 
	
	//�迭 ���� ä��� 
	for(i=0; i<N; i++) {
		for(j=0; j<N; j++) {
			a[i][j] = content++;
		}
	}
	
	int mat_add_boundary(const int a[N][N], int n) {
		if(N > 1) {
			//a[i][j]������ �迭�̶�� ���� ��, i�� 0�� ���
			for(i=0; i<N; i++) {
				n += a[0][i];
			}
			//a[i][j]������ �迭�̶�� ���� ��, i�� N-1�� ��� 
			for(i=0; i<N; i++) {
				n += a[N-1][i];
			}
			//a[i][j]������ �迭�̶�� ���� ��, i�� 0�� ���� N-1�� ��츦 ������ �� 
			for(i=1; i<N-1; i++) {
				n += a[i][0] + a[i][N-1];
			}
			return n;
		}
		else
			return 1;
	}
	
	printf("%d", mat_add_boundary(a, n));	
	
	return 0;
}
