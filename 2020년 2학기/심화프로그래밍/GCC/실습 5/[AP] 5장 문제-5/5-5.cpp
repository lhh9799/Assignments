#include <stdio.h>

int main() {
	int score[10], N, i, j, dist[10] = {0, };

	for(i=0; i<10; i++) {
		do {
			scanf("%d", &score[i]);
			if(score[i] < 0 || score[i] > 100)
				printf("\a0~100 ���̷� �Է��ϼ���.");
		}while (score[i] < 0 || score[i] > 100);
	}

	scanf("%d", &N);

	for(i=0; i<10; i++) {
		dist[score[i] / N]++;
	}
	
	printf("----------���� �׷���---------\n");
    i=0;
	do{
		if((i+1)*N-1 >= 99)
			break;
    	printf("%3d~%3d : ", i*N, (i+1)*N-1);
    	for(j=0; j<dist[i]; j++) {
    		putchar('*');
    	}
    	printf("\n");
    	i++;
    }while(i<=100/N-1);

	printf("%3d~%3d : ", i*N, 100);	//������ ���� ���
	for(j=0; j<dist[i]; j++) {
    	putchar('*');
    }
    if(i<9) {
    	for(j=0; j<dist[i+1]; j++) {
	    	putchar('*');
	    }
	}
    return 0;
}

