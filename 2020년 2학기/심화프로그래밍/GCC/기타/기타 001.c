#include <stdio.h>

int main() {
	int num, array[9], idx = 0, i;

	scanf("%d", &num);

	do {
		array[idx++] = num % 10;
		num /= 10;
	} while(num > 0);

	for(i=idx-1; i>=0; i--) {
		if(array[i] != 0) {
			switch(array[i]) {
				case 1 : printf("ÀÏ");	break;
				case 2 : printf("ÀÌ");	break;
				case 3 : printf("»ï");	break;
				case 4 : printf("»ç");	break;
				case 5 : printf("¿À");	break;
				case 6 : printf("À°");	break;
				case 7 : printf("Ä¥");	break;
				case 8 : printf("ÆÈ");	break;
				case 9 : printf("±¸");	break;
			}
			switch(i) {
				case 8 : printf("¾ï");	break;
				case 7 : printf("Ãµ");	if(array[i-1] == 0 && array[i-2] == 0 && array[i-3] == 0) printf("¸¸"); break;
				case 6 : printf("¹é");	if(array[i-1] == 0 && array[i-2] == 0) printf("¸¸"); break;
				case 5 : printf("½Ê");	if(array[i-1] == 0) printf("¸¸"); break;
				case 4 : printf("¸¸");	break;
				case 3 : printf("Ãµ");	break;
				case 2 : printf("¹é"); 	break;
				case 1 : printf("½Ê");	break;
			}
		}
	}

	return 0;
}

