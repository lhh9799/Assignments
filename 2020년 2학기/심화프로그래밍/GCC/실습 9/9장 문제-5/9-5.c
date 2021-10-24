#include <stdio.h>
#include <string.h>

void change_string(char cs[][128], int n) {
	char temp;
	
	temp = cs[0][n];
	cs[0][n] = cs[1][n];
	cs[1][n] = temp;
}

int main() {
	int n, i;
	char cs[2][128];
	
	scanf("%s", cs[0]);
	scanf("%s", cs[1]);
	scanf("%d", &n);
	
	change_string(cs, n);
	//정방향 출력 
	printf("%s", cs[0]);
	printf(" ");
	printf("%s", cs[1]);
	printf("\n");
	//역방향 출력
	for(i=strlen(cs[0])-1; i>=0; i--)
		printf("%c", cs[0][i]);
	printf(" ");
	for(i=strlen(cs[1])-1; i>=0; i--)
		printf("%c", cs[1][i]);
	return 0;
}
