/* 문자열에서 숫자 문자 삭제 */
#include <stdio.h>

/*--- 문자열 s 중 숫자 문자만 남김 ---*/
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
		idx = 0;	//idx 초기화
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

	del_non_digit(str, N);	/*문자열 안의 숫자 문자만 남김*/

	return 0;
}

