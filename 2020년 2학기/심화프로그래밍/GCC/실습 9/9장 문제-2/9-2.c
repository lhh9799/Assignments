/* ���ڿ����� ���� ���� ���� */
#include <stdio.h>

/*--- ���ڿ� s �� ���� ���ڸ� ���� ---*/
void del_non_digit(char s[][10], int n) {
	int i, j, idx = 0;
	char str[n][10];

	for(i=0; i<n; i++) {
		for(j=0; j<10; j++) {
			str[i][j] = '\0';
			if(s[i][j] >= '0' && s[i][j] <= '9') {
				str[i][idx++] = s[i][j];
			}
		}
		idx = 0;	//idx �ʱ�ȭ
	}

	for(i=0; i<n; i++) {
		printf("%s\n", str[i]);
	}
}
int main(void) {
	int N, i;

	scanf("%d", &N);
	char str[N][10];

	for(i=0; i<N; i++) {
		scanf("%s", str[i]);
	}

	del_non_digit(str, N);	/*���ڿ� ���� ���� ���ڸ� ����*/

	return 0;
}

