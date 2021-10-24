#include <stdio.h>

int main() {
	char strarray[20][128];
	int i, no;

	for(i=0; i<20; i++) {
		scanf("%s", strarray[i]);
		if(strarray[i][0] == '@' && strarray[i][1] == '@' && strarray[i][2] == '@' && strarray[i][3] == '@' && strarray[i][4] == '\0') {
			no = i;
			break;
		}
	}

	for(i=no; i>=0; i--)
		printf("s[%d] = %s\n", i, strarray[i]);

	return 0;
}
