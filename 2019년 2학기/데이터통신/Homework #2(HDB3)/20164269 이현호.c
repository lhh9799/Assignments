#include <stdio.h>
#include <string.h> // 이후 strlen() 함수 사용

#define SIZE 30
 
void hdb3DtoS(char *pulse) {
 	int i, j, k, count = 0, last = 0;
 	
 	pulse[0] = 'S';
	 for(i=1; i<strlen(pulse); i++) { //배열의 처음부터 탐색 시작, 최초 1인 신호를 '+'로 바꿔주고 break
	 	if(pulse[i] == '1') {
	 		pulse[i] = '+';
			 break;
		}
	}
	
	for(j=i+1; j<strlen(pulse); j++) { //1로 바꿔준 신호 이후부터 탐색
		if(pulse[j] == '1') { //마주친 신호가 '1'인 경우
			for(k=j-1; k>0; k--) { //거꾸로 탐색시작
				if(pulse[k] == '+') { //이전의 '+'신호였으면 '-'로 바꿔줌
					pulse[j] = '-';
					break;
				}
				else if(pulse[k] == '-') { //이전의 '-'신호였으면 '+'로 바꿔줌
					pulse[j] = '+';
					break;
				}
			}
		}
		else if(pulse[j] == '0' && pulse[j+1] == '0' && pulse[j+2] == '0' && pulse[j+3] == '0') { //0이 연속으로 4번 나온 경우
			for(k=j-1; k>last; k--) { //(j-1번)부터 (last+1번)까지 0이 아닌 신호 나올때까지
				if(pulse[k] == '+' || pulse[k] == '-') { //'+' 신호 또는 '-' 신호인 경우
					count++; //count 1씩 증가
				}
			}
			last = k; //last변수를 둠으로써 j-1번째 원소부터 직전 대치(last)까지 탐색하게 함
			if(count %2 == 0) { //B00V인 경우
				for(k=j-1; k>0; k--) { //거꾸로 탐색
					if(pulse[k] == '+') {
						pulse[j] = '-', pulse[j+3] = '-';
						break;
					}
					else if(pulse[k] == '-') {
						pulse[j] = '+', pulse[j+3] = '+';
						break;
					}
				}
			}
			else if(count %2 == 1) { //000V인 경우
				for(k=j-1; k>0; k--) { //거꾸로 탐색
					if(pulse[k] == '+') {
						pulse[j+3] = '+';
						count=0; //count변수 초기화(1의 개수 초기화 )
						break;
					}
					else if(pulse[k] == '-') {
						pulse[j+3] = '-';
						count=0;
						break; //count변수 초기화(1의 개수 초기화)
					}
				}
			}
		}
	}
	printf(" => Output : %s\n", pulse);
}

void hdb3StoD(char *pulse) {
	int i, j, k, value;
	
	pulse[0] = 'D';
	for(i=1; i<strlen(pulse); i++) {
		if(pulse[i] != '0' && pulse[i+1] == '0' && pulse[i+2] == '0' && pulse[i+3] == pulse[i]) {		//B00V인 경우
			pulse[i] = '0', pulse[i+3] = '0';//'B'와 'V'에 해당하는 원소 '0'으로 수정 
			}
		else if(pulse[i+1] == '0' && pulse[i+2] =='0' && pulse[i+3] == '0' && pulse[i+4] == pulse[i]) { //000V인 경우. i+1로 둔 이유는 i로 설정할 경우 마지막 조건문이 pulse[i+3] == pulse[i-1]이 되게 되는데,
																										// (이어서)이 경우  pulse[i-1]이 수정된 값일 경우 조건문이  의도한 대로 작동 할 수 없음.
			pulse[i+4] = '0';
		}
		if(pulse[i] != '0')																				//B00V, 000V 둘 다 아닌 경우
			pulse[i] = '1';
	}
	printf(" => Output : %s\n", pulse);
}

main() {
	char pulse[SIZE];
	printf("X를 입력하면 종료합니다. \n입력값은 'D' 또는 'S'로 시작해야 합니다. \n");
	while(1) {
		printf("\n신호를 입력하세요 :");
		scanf("%s", &pulse);
		printf("\nInput : %s", pulse);
		if(pulse[0] == 'X')
			break;
		else if(pulse[0] == 'D')
			hdb3DtoS(pulse);
		else if(pulse[0] == 'S')
			hdb3StoD(pulse);
	}
}
