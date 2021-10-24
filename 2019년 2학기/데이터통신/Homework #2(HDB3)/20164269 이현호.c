#include <stdio.h>
#include <string.h> // ���� strlen() �Լ� ���

#define SIZE 30
 
void hdb3DtoS(char *pulse) {
 	int i, j, k, count = 0, last = 0;
 	
 	pulse[0] = 'S';
	 for(i=1; i<strlen(pulse); i++) { //�迭�� ó������ Ž�� ����, ���� 1�� ��ȣ�� '+'�� �ٲ��ְ� break
	 	if(pulse[i] == '1') {
	 		pulse[i] = '+';
			 break;
		}
	}
	
	for(j=i+1; j<strlen(pulse); j++) { //1�� �ٲ��� ��ȣ ���ĺ��� Ž��
		if(pulse[j] == '1') { //����ģ ��ȣ�� '1'�� ���
			for(k=j-1; k>0; k--) { //�Ųٷ� Ž������
				if(pulse[k] == '+') { //������ '+'��ȣ������ '-'�� �ٲ���
					pulse[j] = '-';
					break;
				}
				else if(pulse[k] == '-') { //������ '-'��ȣ������ '+'�� �ٲ���
					pulse[j] = '+';
					break;
				}
			}
		}
		else if(pulse[j] == '0' && pulse[j+1] == '0' && pulse[j+2] == '0' && pulse[j+3] == '0') { //0�� �������� 4�� ���� ���
			for(k=j-1; k>last; k--) { //(j-1��)���� (last+1��)���� 0�� �ƴ� ��ȣ ���ö�����
				if(pulse[k] == '+' || pulse[k] == '-') { //'+' ��ȣ �Ǵ� '-' ��ȣ�� ���
					count++; //count 1�� ����
				}
			}
			last = k; //last������ �����ν� j-1��° ���Һ��� ���� ��ġ(last)���� Ž���ϰ� ��
			if(count %2 == 0) { //B00V�� ���
				for(k=j-1; k>0; k--) { //�Ųٷ� Ž��
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
			else if(count %2 == 1) { //000V�� ���
				for(k=j-1; k>0; k--) { //�Ųٷ� Ž��
					if(pulse[k] == '+') {
						pulse[j+3] = '+';
						count=0; //count���� �ʱ�ȭ(1�� ���� �ʱ�ȭ )
						break;
					}
					else if(pulse[k] == '-') {
						pulse[j+3] = '-';
						count=0;
						break; //count���� �ʱ�ȭ(1�� ���� �ʱ�ȭ)
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
		if(pulse[i] != '0' && pulse[i+1] == '0' && pulse[i+2] == '0' && pulse[i+3] == pulse[i]) {		//B00V�� ���
			pulse[i] = '0', pulse[i+3] = '0';//'B'�� 'V'�� �ش��ϴ� ���� '0'���� ���� 
			}
		else if(pulse[i+1] == '0' && pulse[i+2] =='0' && pulse[i+3] == '0' && pulse[i+4] == pulse[i]) { //000V�� ���. i+1�� �� ������ i�� ������ ��� ������ ���ǹ��� pulse[i+3] == pulse[i-1]�� �ǰ� �Ǵµ�,
																										// (�̾)�� ���  pulse[i-1]�� ������ ���� ��� ���ǹ���  �ǵ��� ��� �۵� �� �� ����.
			pulse[i+4] = '0';
		}
		if(pulse[i] != '0')																				//B00V, 000V �� �� �ƴ� ���
			pulse[i] = '1';
	}
	printf(" => Output : %s\n", pulse);
}

main() {
	char pulse[SIZE];
	printf("X�� �Է��ϸ� �����մϴ�. \n�Է°��� 'D' �Ǵ� 'S'�� �����ؾ� �մϴ�. \n");
	while(1) {
		printf("\n��ȣ�� �Է��ϼ��� :");
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
