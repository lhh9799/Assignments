#include <stdio.h>

int main() {
	char line[256], num[256];
	int i = 0, idx = 0, val;

	scanf("%[^\n]", line);	

	for(i=0; line[i] != '\0'; i++) {
		if(line[i] >= '0' && line[i] <= '9')
			num[idx++] = line[i];
	}

	val = atoi(num);	//문자열 숫자를 타입캐스팅 하여 정수형 변수 val에 저장
	val *= 2;
	printf("%d\n", val);

	for(i=0; line[i] != '\0'; i++) {
		if(!(line[i] >= '0' && line[i] <= '9'))
			printf("%c", line[i]);
	}

	return 0;
}

