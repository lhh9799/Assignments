#include <cstdio>		//C����� stdio.h�� ���� C�� ����� �Լ��� ������ �������
#include <vector>		//vector Ŭ������ ����ϱ� ���� �������(�迭���� ������ : ������, ����� �Լ� ����)
using namespace std;	//ǥ�� �̸������� �����

const int MAX_SEAT_NUMBER = 1000;	//�¼��� �ִ� ���� const ����� ����(���� ������ �� ����) 
const int MAX_COLOR_NUMBER = 100;	//������ �ִ� ���� const ����� ����(���� ������ �� ����)

//�¼��� ��ĥ�� ���� ����, ������ �¼��� ��ȣ, ������ ��ȣ�� �����ϴ� Ŭ����
class Painting {
public :
	int left;	//ĥ�� ���� ���� �¼��� ��ȣ
	int right;	//ĥ�� ���� ������ �¼��� ��ȣ
	int color;	//ĥ�� ������ ��ȣ

	Painting() {}	//�⺻ ������. �Ʒ��� �Ű������� �ִ� �����ڰ� ���ǵǾ� �����Ƿ� �����Ϸ��� �⺻�����ڸ� ���������� �ʴ´�. Painting �� �迭�� ����� ���� �⺻ ������ ����.

	Painting(int left, int right, int color) {	//�Ű����� �ִ� ������
		this->left = left;						//�Ű������� ���� left�� �� ��ü�� left�� ����
		this->right = right;					//�Ű������� ���� right�� �� ��ü�� right�� ����
		this->color = color;					//�Ű������� ���� color�� �� ��ü�� color�� ����
	}
};

//ĥ���� ���� �󵵸� ����ϴ� �Լ�
void fillFrequencyTable(int data[], int n, int table[]) {
	for(int i=0; i<MAX_COLOR_NUMBER; i++) {	//MAX_COLOR_NUMBER(������ �ִ� ��)�� �ݺ��Ͽ�
		table[i] = 0;						//�迭�� ���� 0���� �ʱ�ȭ
	}

	for(int i=0; i<n; i++) {				//n(�¼��� ��)�� �ݺ��Ͽ�
		table[data[i]]++;					//�ش� ���� ĥ���� Ƚ�� ����
	}
}

//���� ���� �¼��� ĥ���� ���� ��ȣ, ���� ���� �¼��� ĥ���� ���� ��ȣ�� ����ϴ� �Լ�
void solve(int n, int m, const Painting *paintings) {
	int *seats = new int[n];	//�Էµ� ���� ������ �������� seats �迭�� �籸����. �¼��� �� ��ŭ �������� �Ҵ�

	//ó���� ��� �¼��� 0�� ������ ĥ���� ����
	for(int i=0; i<n; i++) {	//n(�¼��� ��)�� �ݺ��Ͽ�
		seats[i] = 0;			//0�� ������ �ʱ�ȭ
	}

	for(int i=0; i<m; i++) {				//m(��ĥ�� �� ����� ��)�� �ݺ��Ͽ�
		const Painting &p = paintings[i];	//paintings[i]�� �������� p�� ����

		for(int j=p.left; j<=p.right; j++) {//�ش� ���� ĥ���� ���ʺ��� ������ �¼��� ��ȣ���� �ݺ��Ͽ�
			seats[j] = p.color;				//seats �迭�� ���� �ش������ ����
		}
	}

	int *table = new int[MAX_COLOR_NUMBER];	//�󵵸� ������ �迭�� ������ �ִ� ����ŭ �������� �Ҵ�
	fillFrequencyTable(seats, n, table);	//seats �迭�� n�� ���ڷ� �Ѱ� table �迭�� �󵵸� ä������

	int minColor = seats[0];				//���� ���� ������ ������ ù ��° ������ �ʱ�ȭ
	int maxColor = seats[0];				//���� ���� ������ ������ ù ��° ������ �ʱ�ȭ

	for(int color=0; color<MAX_COLOR_NUMBER; color++) {//MAX_COLOR_NUMBER(������ �ִ� ��)�� �ݺ��Ͽ�
		if(table[color] == 0) {				//�ƹ� �¼����� ĥ���� ���� ���� ������ ���
			continue;						//�Ʒ��� �ڵ带 �ǳʶٰ� ���� �ݺ��� ����
		}
		if(table[minColor] > table[color]) {//color��° ������ ���� ���� ĥ���� ���� ������ �۴ٸ�
			minColor = color;				//�ּڰ� ����
		}
		if(table[maxColor] < table[color]) {//color��° ������ ���� ���� ĥ���� ���� ������ ũ�ٸ�
			maxColor = color;				//�ִ� ����
		}
	}

	printf("%d\n", maxColor);
	printf("%d\n", minColor);

	delete []seats;							//�����Ҵ��� �迭�� �޸� ����
	seats = nullptr;						//�迭�� ����Ű�� �����Ϳ� ����� �ּҰ� ����
}

int main() {
	int n, m;								//n : �¼��� ��, m : ��ĥ�� �� ����� ��
	scanf("%d %d", &n, &m);					//�¼��� ��, ��ĥ�� �� ����� �� �Է¹���

	Painting *paintings = new Painting[n];	//��ĥ ������ ������ �ִ� Painting Ŭ������ �ν��Ͻ� �迭�� �¼��� �� ��ŭ �������� �Ҵ�

	for(int i=0; i<m; i++) {				//m(��ĥ�� �� ����� ��)�� �ݺ��Ͽ�
		scanf("%d", &paintings[i].left);	//��ĥ�� ���� ���� �¼��� ��ȣ �Է¹���
		scanf("%d", &paintings[i].right);	//��ĥ�� ���� ������ �¼��� ��ȣ �Է¹���
		scanf("%d", &paintings[i].color);	//ĥ�� ������ ��ȣ �Է¹���

		paintings[i].left -= 1;				//�¼��� ��ȣ�� 1������ ���������� �迭�� 0������ �����ϱ� ������ �����ֱ� ���� 1�� ����
		paintings[i].right -= 1;			//�¼��� ��ȣ�� 1������ ���������� �迭�� 0������ �����ϱ� ������ �����ֱ� ���� 1�� ����
	}

	solve(n, m, paintings);					//���� ���� �¼��� ĥ���� ���� ��ȣ, ���� ���� �¼��� ĥ���� ���� ��ȣ�� ����ϴ� solve�Լ� ȣ��

	return 0;								//�����Լ��� ���������� ����
}

