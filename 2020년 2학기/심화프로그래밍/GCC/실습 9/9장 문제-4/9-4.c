#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <string.h>

//�迭 ��� �Լ� 
void print_array(int arr[][9], char arr_name, int N) {
	int i, j;
	
	printf("%c array\n", arr_name);
	for(i=0; i<N; i++) {
		for(j=0; j<N; j++) {
			printf("%d", arr[i][j]);
		}
		printf("\n");
	}
}
	
int main() {
	int i, j, N, idx, xval, yval, coordinate;
	char tmp, arr[] = "array", input[30], *token, target_arr_name;
	char *strinput;
	char *strtmp[5] = {NULL, };
	int a[9][9], b[9][9];
	
	scanf("%d", &N);		//�迭 ũ�� �Է¹��� 
	getchar();				//���� ��� 
	
	//a, b �迭 �ʱ�ȭ 
	for(i=0; i<N; i++) {
		for(j=0; j<N; j++) {
			a[i][j] = b[i][j] = 0;
		}
	}
	
	//'array/�迭�̸�/��/��/��������' ������ ���ڿ� �Է¹޾� input�迭�� ���� 
	while(1) {
		tmp = getchar();
		if(tmp == '\n') {
			break;
		}
		input[idx++] = tmp;
	}
	idx = 0;	
	
	token = strtok(input, "/");	//"/" ���ڿ��� �������� �ڸ� 
	while(token != NULL) {
		strtmp[idx++] = token;	//"/" ���ڿ��� �������� �߶� strtmp ������ ���� 
		token = strtok(NULL, "/");	//�߸� ���ڿ� �������� "/"������ ���ڿ��� token �����ͷ� ���� 
	}

	xval = atoi(strtmp[2]);
	yval = atoi(strtmp[3]);
	coordinate = atoi(strtmp[4]);
	
	//'array/�迭�̸�/��/��/��������' ������ ���ڿ����� ù��° Ű���尡 array�� ��� 
	if(strcmp(arr,strtmp[0]) == 0) {
		//a�迭�� �Է��� ��� 
		if(strcmp(strtmp[1],"a") == 0) {
			if(xval < N && yval < N) {		//������ �Է��� ���
				a[xval][yval] = coordinate;
				print_array(a, 'a', N);
				print_array(b, 'b', N);
			}
			if(xval >= N) {					//�Է��� x��ǥ�� �迭�� ũ�⸦ �ʰ��ϴ� ��� 
				printf("row size error\n");
			}
			if(yval >= N) {					//�Է��� y��ǥ�� �迭�� ũ�⸦ �ʰ��ϴ� ��� 
				printf("column size error\n");
			}
		}
		//b�迭�� �Է��� ��� 
		if(strcmp(strtmp[1],"b") == 0) {
			if(xval < N && yval < N) {		//������ �Է��� ���
				b[xval][yval] = coordinate;
				print_array(b, 'b', N);
				print_array(a, 'a', N);
			}
			if(xval >= N) {					//�Է��� x��ǥ�� �迭�� ũ�⸦ �ʰ��ϴ� ��� 
				printf("row size error\n");
			}
			if(yval >= N) {					//�Է��� y��ǥ�� �迭�� ũ�⸦ �ʰ��ϴ� ��� 
				printf("column size error\n");
			}
		}
	}
	//'array/�迭�̸�/��/��/��������' ������ ���ڿ����� ù��° Ű���尡 array�� �ƴ� ��� 
	else {
		printf("not array");
	}
	
	return 0;
}
