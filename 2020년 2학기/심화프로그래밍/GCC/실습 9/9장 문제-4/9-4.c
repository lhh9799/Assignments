#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <string.h>

//배열 출력 함수 
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
	
	scanf("%d", &N);		//배열 크기 입력받음 
	getchar();				//버퍼 비움 
	
	//a, b 배열 초기화 
	for(i=0; i<N; i++) {
		for(j=0; j<N; j++) {
			a[i][j] = b[i][j] = 0;
		}
	}
	
	//'array/배열이름/행/열/넣을숫자' 형식의 문자열 입력받아 input배열에 저장 
	while(1) {
		tmp = getchar();
		if(tmp == '\n') {
			break;
		}
		input[idx++] = tmp;
	}
	idx = 0;	
	
	token = strtok(input, "/");	//"/" 문자열을 기준으로 자름 
	while(token != NULL) {
		strtmp[idx++] = token;	//"/" 문자열을 기준으로 잘라 strtmp 변수에 저장 
		token = strtok(NULL, "/");	//잘린 문자열 다음부터 "/"까지의 문자열을 token 포인터로 리턴 
	}

	xval = atoi(strtmp[2]);
	yval = atoi(strtmp[3]);
	coordinate = atoi(strtmp[4]);
	
	//'array/배열이름/행/열/넣을숫자' 형식의 문자열에서 첫번째 키워드가 array인 경우 
	if(strcmp(arr,strtmp[0]) == 0) {
		//a배열을 입력한 경우 
		if(strcmp(strtmp[1],"a") == 0) {
			if(xval < N && yval < N) {		//정상값을 입력한 경우
				a[xval][yval] = coordinate;
				print_array(a, 'a', N);
				print_array(b, 'b', N);
			}
			if(xval >= N) {					//입력한 x좌표가 배열의 크기를 초과하는 경우 
				printf("row size error\n");
			}
			if(yval >= N) {					//입력한 y좌표가 배열의 크기를 초과하는 경우 
				printf("column size error\n");
			}
		}
		//b배열을 입력한 경우 
		if(strcmp(strtmp[1],"b") == 0) {
			if(xval < N && yval < N) {		//정상값을 입력한 경우
				b[xval][yval] = coordinate;
				print_array(b, 'b', N);
				print_array(a, 'a', N);
			}
			if(xval >= N) {					//입력한 x좌표가 배열의 크기를 초과하는 경우 
				printf("row size error\n");
			}
			if(yval >= N) {					//입력한 y좌표가 배열의 크기를 초과하는 경우 
				printf("column size error\n");
			}
		}
	}
	//'array/배열이름/행/열/넣을숫자' 형식의 문자열에서 첫번째 키워드가 array가 아닌 경우 
	else {
		printf("not array");
	}
	
	return 0;
}
