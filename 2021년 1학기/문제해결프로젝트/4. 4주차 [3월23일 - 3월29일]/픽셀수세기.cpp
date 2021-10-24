#include <cstdio>	//C����� stdio.h�� ���� C�� ����� �Լ��� ������ �������
#include <iostream>	//C++ ��Ʈ���� ������ �������
using namespace std;//ǥ�� �̸������� �����

//x,y ��ǥ�� �� �ȿ� �ִ��� �˻��ϴ� �Լ�
bool isInside(long long x, long long y, long long R) {
	long long sqd = x*x + y*y;	//���� �����Ŀ��� r^2�� �ش��ϴ� ���� sqd�� ����

	if(sqd < R*R)				//sqd�� R^2���� ���� -> x,y ��ǥ�� ���� ���ο� ���� -> true ����
		return true;
	return false;				//�ܺο� ������ false ����
}

//���� �������� �ȼ� ���� �Է¹ް� �׽�Ʈ ���̽��� ��ȣ�� ���� ���ԵǴ� �ȼ��� ���� ����ϴ� �Լ�
void testcase(int caseIndex) {
	long long R;		//����ϰ��� �ϴ� ���� �������� �ȼ� ��
	long long count=0;	//���� �� �ȿ� ���ԵǴ� �ȼ��� ��

	scanf("%lld", &R);	//long long�� ���� �����ڴ� %lld��
	long long y = R;	//���� �ݺ������� ����Ƚ���� ���̱� ���� y�� R���� ������

	for(long long x=0; x<=R; x++) {	//���� 4����Ͽ� x=0�� ������ �����ϸ� ��
		for(; y>=0; y--) {			//y=R�� ������ �����ϸ� ��(y=R�� �ʱ�ȭ �ϸ� ���ʿ��� ���귮 ������(������ �� �ۿ� ����))
			if(isInside(x, y, R)) {	//(x,y)��ǥ�� �� �ȿ� ���ٸ� y+1���� count������ ���� �� ���� for���� Ż���ϰ� �ٱ��� for���� ������(�� ���� y���� �翬�� �� �ȿ� ���ԵǱ� ����)
				count += y + 1;		//�������� ���� �ȼ������� 1�� ����
				break;
			}
		}
	}

	printf("#%d\n", caseIndex);		//�׽�Ʈ ���̽��� ��ȣ�� ���
	printf("%lld\n", count * 4);	//��и��� 4���̹Ƿ� *4�� ���� �����
}

int main() {
	int caseSize;			//�׽�Ʈ���̽��� ��
	scanf("%d", &caseSize);	//�׽�Ʈ���̽��� �� �Է¹���

	for(int caseIndex=1; caseIndex <= caseSize; caseIndex+=1) {	//caseSize(�׽�Ʈ ���̽��� ��)�� �ݺ�. ����� #1���� �����ϱ� ���� �ʱⰪ�� 1, ������ caseSize ���Ϸ� ����
		testcase(caseIndex);									//���̽� �ε����� ���ڷ� testcase �Լ� ����
	}

	return 0;				//�����Լ��� ���������� ����
}
