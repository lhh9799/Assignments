//��� �����ϱ�
#include <cmath>	//pow�Լ��� ����ϱ� ���� �������
#include <ctime>	//�ڵ� ����ð� ������ ���� �������
#include <iostream>	//����� �Լ��� ����ϱ� ���� �������
using namespace std;//ǥ�� �̸������� �����

const int gear_count = 4;	//��Ϲ����� ���� const ����� ����(���� ������ �� ����)
const int direction = 8;	//� �� N�� �ִ��� const ����� ����(���� ������ �� ����)

//����ڰ� �Է��� ȸ����ų ��Ϲ����� ������ ������ Ŭ����
class Trigger {
public:
	int trigger;	//ȸ����ų ��Ϲ����� ��ȣ
	int clockwise;	//ȸ������
};

//decision�� clockwise �迭�� �ʱ�ȭ �ϴ� �Լ�
void array_clear(int* array) {
	for (int i = 0; i < gear_count; i++) {
		array[i] = 0;
	}
}

//��ϸ� ȸ����Ű�� �Լ�
void rotate(int gear[][direction], int* decision, int* clockwise) {
	int temp[direction];							//���� ������ �ӽ� �迭

	for (int i = 0; i < gear_count; i++) {
		if (decision[i] == 1) {			//decision�� ���� 1�̾�� ȸ����Ŵ
			for (int j = 0; j < direction; j++) {	//�ӽ� �迭�� �� ����
				temp[j] = gear[i][j];
			}
			if (clockwise[i] == 1) {				//�ð����
				for (int j = 0; j < direction; j++) {
					gear[i][(j + 1) % 8] = temp[j];	//j��° ���� j+1��° ���� ����. 7�� �����͸� 8�� �ε����� ������ �� �����Ƿ� mod8������ ���� �� ����
				}
			}
			else if (clockwise[i] == -1) {			//�ݽð� ����
				for (int j = 0; j < direction; j++) {
					gear[i][(j + 7) % 8] = temp[j];	//j��° ���� j-1��° ���� ����. 0�� �����͸� -1�� �ε����� ������ �� �����Ƿ� j+7(=j-1+8)�� �ε����� mod8������ ���� �� ����
				}
			}
		}
	}
}

int main() {
	string buf[gear_count];						//����ڿ��� �Է¹��� ��Ϲ����� ���¸� ������ �ӽ� ���ڿ� �迭
	int gear[gear_count][direction];			//��Ϲ����� ���¸� ������ ������ �迭
	int* decision;								//��ϸ� ȸ����ų�� ������ �����ϴ� �迭
	int* clockwise;								//ȸ�������� �����ϴ� �迭
	int K, temp_clockwise, score = 0;			//K: ȸ����ų Ƚ��, temp_clockwise: ȸ������ �ӽú���, score: ���� ����(0���� �ʱ�ȭ)

	for (int i = 0; i < gear_count; i++) {		//���� ��Ϲ��� ���� �Է¹���
		cin >> buf[i];
	}

	cin >> K;									//ȸ����ų Ƚ�� �Է¹���
	Trigger* trigger = new Trigger[K];			//ȸ����ų ��Ϲ����� ������ �����ϴ� �迭�� �������� �Ҵ�

	for (int i = 0; i < K; i++) {
		cin >> trigger[i].trigger >> trigger[i].clockwise;	//ù ��° ���� : ȸ����Ų ��Ϲ����� ��ȣ, �� ��° ���� : ȸ������
	}

	clock_t start = clock();					//���� �ð� ����

	decision = new int[K];						//��ϸ� ȸ����ų�� ������ �����ϴ� �迭�� �������� �Ҵ�
	clockwise = new int[K];						//ȸ�������� �����ϴ� �迭�� �������� �Ҵ�

	for (int i = 0; i < gear_count; i++) {
		decision[i] = 0;	//���� �迭 �ʱ�ȭ
		clockwise[i] = 0;	//���� �迭 �ʱ�ȭ
	}

	//���ڿ��� �Է¹��� ��Ϲ����� ���¸� ���������� ��ȯ
	for (int i = 0; i < gear_count; i++) {
		string temp = buf[i];

		for (int j = 0; j < direction; j++) {
			gear[i][j] = temp[j] - '0';			//���������� �ٲٱ� ���� '0'�� �ƽ�Ű�ڵ� ���� ��
		}
	}

	for (int i = 0; i < K; i++) {
		temp_clockwise = trigger[i].clockwise;							//���� ó�� ȸ���ϴ�(����ڰ� ȸ����Ų) ��Ϲ����� ȸ�������� ����
		array_clear(decision);											//ȸ���� ���� 1�� ���� �����ϱ� ������ �̸� �迭�� �ʱ�ȭ��
		array_clear(clockwise);											//�����Ⱚ ����(���� �ʾƵ� ��)
		decision[trigger[i].trigger - 1] = 1;							//���� ó�� ȸ���ϴ�(����ڰ� ȸ����Ų) ��Ϲ����� ������ ȸ���ϱ� ������ 1�� ����
		clockwise[trigger[i].trigger - 1] = trigger[i].clockwise;		//���� ó�� ȸ���ϴ�(����ڰ� ȸ����Ų) ��Ϲ����� ȸ������ ����
		switch (trigger[i].trigger - 1) {								//����ڰ� �Է��� ��Ϲ�ȣ�� �迭�� �ε����� �����ֱ� ����
		case 0:	//1�� ���
			for (int j = 0; j < gear_count - 1; j++) {					//�� 3�� �ݺ�
				if (gear[j][2] != gear[j + 1][6]) {						//���� �ٸ���
					decision[j + 1] = 1;								//1�� ������
					clockwise[j + 1] = temp_clockwise * pow(-1, j+1);	//-1�� 1��, 3���̸� ������ 2���̸� ������
				}
				else													//���� ������ ���� ��ϴ� ȸ������ �����Ƿ�
					break;												//�ݺ��� Ż��
			}
			break;														//�Ʒ��� �ִ� case������ ������� �ʵ��� ����
		case 1:	//2�� ���
			for (int j = 1; j < gear_count - 1; j++) {					//�� 2�� �ݺ�
				if (gear[j][2] != gear[j + 1][6]) {						//���� �ٸ���
					decision[j + 1] = 1;								//1�� ������
					clockwise[j + 1] = temp_clockwise * pow(-1, j);		//-1�� 1��, 3���̸� ������ 2���̸� ������
				}
				else													//���� ������ ���� ��ϴ� ȸ������ �����Ƿ�
					break;												//�ݺ��� Ż��
			}
			if (gear[0][2] != gear[1][6]) {								//1�� ��Ͽ� ���� �ٸ��ٸ�
				decision[0] = 1;										//1�� ������
				clockwise[0] = -1 * temp_clockwise;						//2����Ͽ� �ٸ� �������� ȸ��
			}
			break;														//�Ʒ��� �ִ� case������ ������� �ʵ��� ����
		case 2:	//3�� ���
			for (int j = 2; j > 0; j--) {								//�� 2�� �ݺ�
				if (gear[j][6] != gear[j - 1][2]) {						//���� �ٸ���
					decision[j - 1] = 1;								//1�� ������
					clockwise[j - 1] = temp_clockwise * pow(-1, j - 1);	//-1�� 1��, 3���̸� ������ 2���̸� ������
				}
				else													//���� ������ ���� ��ϴ� ȸ������ �����Ƿ�
					break;												//�ݺ��� Ż��
			}
			if (gear[3][6] != gear[2][2]) {								//4�� ��Ͽ� ���� �ٸ��ٸ�
				decision[3] = 1;										//1�� ������
				clockwise[3] = -1 * temp_clockwise;						//3����Ͽ� �ٸ� �������� ȸ��
			}
			break;														//�Ʒ��� �ִ� case������ ������� �ʵ��� ����
		case 3:	//4�� ���
			for (int j = gear_count - 1; j > 0; j--) {					//�� 3�� �ݺ�
				if (gear[j][6] != gear[j - 1][2]) {						//���� �ٸ���
					decision[j - 1] = 1;
					clockwise[j - 1] = temp_clockwise * pow(-1, j);		//-1�� 1��, 3���̸� ������ 2���̸� ������
				}
				else													//���� ������ ���� ��ϴ� ȸ������ �����Ƿ�
					break;												//�ݺ��� Ż��
			}
			break;														//�Ʒ��� �ִ� case������ ������� �ʵ��� ����
		}
		rotate(gear, decision, clockwise);								//decision ���ڷ� ȣ���Ͽ� ������ ȸ�� ��Ŵ
	}

	/*
	 *<������� ��Ģ>
	 *1�� ��Ϲ����� 12�� ������ N���̸� 0��, S���̸� 1�� / 2�� ��Ϲ����� 12�� ������ N���̸� 0��, S���̸� 2��
	 *3�� ��Ϲ����� 12�� ������ N���̸� 0��, S���̸� 4�� / 4�� ��Ϲ����� 12�� ������ N���̸� 0��, S���̸� 8��
	 *=> �Ϲ�ȭ: 2^(n-1)��
	 */

	for (int i = 0; i < gear_count; i++) {	//gear_count(��Ϲ����� ����)�� �ݺ��Ͽ�
		if (gear[i][0] == 1) {				//12�� ������ S��(���� 1)�̶��
			score += pow(2, i);				//���� score�� 2^(���� ��Ϲ����� ��ȣ)�� ����
		}
	}

	cout << score << endl;					//�� ��Ϲ����� ������ �� ���

	delete[]trigger;		//�����Ҵ��� �迭�� �޸� ����
	delete[] decision;		//�����Ҵ��� �迭�� �޸� ����
	delete[] clockwise;		//�����Ҵ��� �迭�� �޸� ����
	trigger = nullptr;		//�迭�� ����Ű�� �����Ϳ� ����� �ּҰ� ����
	decision = nullptr;		//�迭�� ����Ű�� �����Ϳ� ����� �ּҰ� ����
	clockwise = nullptr;	//�迭�� ����Ű�� �����Ϳ� ����� �ּҰ� ����

	clock_t end = clock();	//�ڵ尡 ���� �ð� ����
	cout << "����ð�: " << (double)(end - start) / CLOCKS_PER_SEC << "��" << endl;	//����ð�(����: ��) ���

	return 0;				//�����Լ��� ���������� ����
}

