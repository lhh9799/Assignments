#include <stdio.h>

int main() {
	char a, b;
	int array[9] = {0, };

	scanf("%c %c", &a, &b);

	void cleararray() {
		int i;

		for(i=0; i<9; i++) {
			array[i] = 0;
		}
	}

	int* make8bit(char c) {
		int i, index = 0, code = (int) c;

		cleararray();
		//�������� ��ȯ
		do {
			if(code % 2 == 0) {
				array[index++] = 0;
			}
			else {
				array[index++] = 1;
			}
			code /= 2;
		}while(code > 0);

		return array;
	}

	void print8bit(char c) {
		int i, *arr;

		arr = make8bit(c);
		//������ �迭 ���
		for(i=7; i>=0; i--) {
			printf("%d", arr[i]);
		}
	}

	void printAND(char a, char b) {
		int i, temp1[8] = {0, }, temp2[8] = {0, }, AND[8] = {0, }, *arr1, *arr2;
		//*arr1�� �������̱� ������ arr2 = make8bit(b)�� �����ϸ� ���� Ʋ������. ���� �ӽù迭�� ����� ���� �Լ� ȣ�� �� ������ �����Ѵ�.

		arr1 = make8bit(a);
		for(i=7; i>=0; i--) {
			temp1[i] = arr1[i];
		}

		arr2 = make8bit(b);
		for(i=7; i>=0; i--) {
			temp2[i] = arr1[i];
		}

		//AND����
		for(i=7; i>=0; i--) {
			AND[i] = temp1[i] & temp2[i];
		}
		//AND������ �迭 ���
		for(i=7; i>=0; i--) {
			printf("%d", AND[i]);
		}
	}

	void printOR(char a, char b) {
		int i, temp1[8] = {0, }, temp2[8] = {0, }, OR[8] = {0, }, *arr1, *arr2;
		//*arr1�� �������̱� ������ arr2 = make8bit(b)�� �����ϸ� ���� Ʋ������. ���� �ӽù迭�� ����� ���� �Լ� ȣ�� �� ������ �����Ѵ�.

		arr1 = make8bit(a);
		for(i=7; i>=0; i--) {
			temp1[i] = arr1[i];
		}
		arr2 = make8bit(b);
		for(i=7; i>=0; i--) {
			temp2[i] = arr1[i];
		}
		//OR����
		for(i=7; i>=0; i--) {
			OR[i] = temp1[i] | temp2[i];
		}
		//OR������ �迭 ���
		for(i=7; i>=0; i--) {
			printf("%d", OR[i]);
		}
	}

	print8bit(a);
	printf("\n");
	print8bit(b);
	printf("\n");
	printAND(a, b);
	printf("\n");
	printOR(a, b);

	return 0;
}

