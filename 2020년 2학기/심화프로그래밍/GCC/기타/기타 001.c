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
				case 1 : printf("��");	break;
				case 2 : printf("��");	break;
				case 3 : printf("��");	break;
				case 4 : printf("��");	break;
				case 5 : printf("��");	break;
				case 6 : printf("��");	break;
				case 7 : printf("ĥ");	break;
				case 8 : printf("��");	break;
				case 9 : printf("��");	break;
			}
			switch(i) {
				case 8 : printf("��");	break;
				case 7 : printf("õ");	if(array[i-1] == 0 && array[i-2] == 0 && array[i-3] == 0) printf("��"); break;
				case 6 : printf("��");	if(array[i-1] == 0 && array[i-2] == 0) printf("��"); break;
				case 5 : printf("��");	if(array[i-1] == 0) printf("��"); break;
				case 4 : printf("��");	break;
				case 3 : printf("õ");	break;
				case 2 : printf("��"); 	break;
				case 1 : printf("��");	break;
			}
		}
	}

	return 0;
}

