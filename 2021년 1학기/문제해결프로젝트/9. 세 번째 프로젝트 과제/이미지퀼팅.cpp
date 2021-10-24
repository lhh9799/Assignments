#include <vector>	//vector Ŭ������ ����ϱ� ���� �������(�迭���� ������ : ������, ����� �Լ� ����)
#include <ctime>	//�ڵ� ����ð� ������ ���� �������
#include <algorithm>//min_element�Լ��� ����ϱ� ���� �������
#include <iostream>	//����� �Լ��� ����ϱ� ���� �������
using namespace std;//ǥ�� �̸������� �����

//�̹����� ���� �Է¹޴� �Լ�. 2���� �����͸� ���������� �޾� ���� ���� �����ϰ� ��
void fill_array(int H, int W, int **&array) {
	array = new int *[H];		//���� ���� H��ŭ ���� �Ҵ�

	for(int i=0; i<H; i++) {
		array[i] = new int [W];	//���� ���� W��ŭ ���� �Ҵ�

		for(int j=0; j<W; j++) {
			cin >> array[i][j];	//�� �Է� ����
		}
	}
}

//�Ʒ� �������� Ž���ؼ� SSD�� ����ϴ� �Լ�. SSD ���͸� ���������� �޾� ���� �����ϰ� ��
void explore(int **B1, int **B2, int H, int W, int row, int col, int sum, vector <int> &SSD) {
	int diff = (B1[row][col] - B2[row][col]) * (B1[row][col] - B2[row][col]);	//1�� �ȼ��� squared distance

	//������ ���� ���
	if(row == H-1) {
		SSD.push_back(sum + diff);
		return;
	}

	//0�� ���� ���
	if(col == 0) {
		explore(B1, B2, H, W, row+1, col, sum+diff, SSD);		//���� �� �Ʒ� �� Ž��
		if(W > 1) {												//���������� �̵��� ���� �ִ� ���
			explore(B1, B2, H, W, row+1, col+1, sum+diff, SSD);	//������ �� �Ʒ� �� Ž��
		}
	}
	//���� ������ ���̰� �������� �̵��� ���� �ִ� ���
	else if(col == W-1 && W > 1) {
		explore(B1, B2, H, W, row+1, col-1, sum+diff, SSD);		//���� �� �Ʒ� �� Ž��
		explore(B1, B2, H, W, row+1, col, sum+diff, SSD);		//���� �� �Ʒ� �� Ž��
	}
	//�����ڸ� ���� �ƴ� ���(���� �� Ž��)
	else {
		explore(B1, B2, H, W, row+1, col-1, sum+diff, SSD);		//���� �� �Ʒ� �� Ž��
		explore(B1, B2, H, W, row+1, col, sum+diff, SSD);		//���� �� �Ʒ� �� Ž��
		explore(B1, B2, H, W, row+1, col+1, sum+diff, SSD);		//������ �� �Ʒ� �� Ž��
	}
}

int main() {
	int H, W;					//H: ����(���� ��), W: �ʺ�(���� ��). �� ���� 1�̻� 100������ ��
	int **B1 = nullptr, **B2 = nullptr;	//B1: ���� �̹���, B2: ������ �̹���
	vector<int> SSD;			//SSD�� �����ϴ� ����

	cin >> H >> W;				//H: ����(���� ��), W: �ʺ�(���� ��) �Է¹���

	fill_array(H, W, B1);		//B1 �Է¹���
	fill_array(H, W, B2);		//B2 �Է¹���

	clock_t start = clock();	//���� �ð� ����

	for(int i=0; i<W; i++) {	//0�� ������ ������ ������ �ݺ��Ͽ�
		explore(B1, B2, H, W, 0, i, 0, SSD);	//�ȼ����� squared distance�� SSD�� ���
	}

	//�����Ҵ��� 2���� �迭�� �޸� ����
	for(int i=0; i<H; i++) {
		delete []B1[i];	delete []B2[i];
	}
	delete []B1;	delete []B2;

	cout << *min_element(SSD.begin(), SSD.end()) << endl;	//�ּ� SSD ���

	clock_t end = clock();		//���� �ð� ����
	cout << "����ð�: " << (double)(end - start) / CLOCKS_PER_SEC << "��";	//����ð�(����: ��) ���

	return 0;					//�����Լ��� ���������� ����
}
