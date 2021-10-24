#include <stdio.h>

int main() {
	int i, j, num, tmp, rank;
	
	scanf("%d", &num);	//�л� �� 
	
	int score[num];	//���� �迭
	
	for(i=0; i<num; i++) {
		scanf("%d", &tmp);
		if(tmp >= 0 && tmp <= 100)
			score[i] = tmp;
		else
			i--;
	}
	
	//��������
	for(i=0; i<num-1; i++) {
		for(j=i; j<num; j++) {
			if(score[i] > score[j]) {
				tmp = score[i];
				score[i] = score[j];
				score[j] = tmp;
			}
		}
	}
	
	rank = num * 0.3;	//���� 30�� �л��� �� ���
	for(i=num-1; i>num-rank-1; i--) {
		printf("%d ", score[i]);
	}
	
	return 0;
}
