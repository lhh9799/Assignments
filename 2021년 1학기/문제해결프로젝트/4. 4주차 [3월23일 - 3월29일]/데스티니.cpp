#include <cstdio>	//C����� stdio.h�� ���� C�� ����� �Լ��� �����ϴ� �������
#include <cmath>	//sqrt�Լ��� �����ϴ� �������
#include <climits>	//INT_MAX�� ���� ���ǵǾ� �ִ� �������
#include <iostream>	//C++ ��Ʈ���� ������ �������
using namespace std;//ǥ�� �̸������� �����

//õü�� x��ǥ, y��ǥ�� õü������ ��Ŭ���� �Ÿ��� ���ϴ� �Լ��� ���� Ŭ����
class Point2D {
private :
	int x;	//x��ǥ�� ������ ����
	int y;	//y��ǥ�� ������ ����

public :
	Point2D(int x=0, int y=0) {									//�Ű����� �ִ� ������. �����ڰ� ���� ��� �⺻������ x�� 0, y�� 0�� �����Ѵ�.
		this -> x = x;
		this -> y = y;
	}

	int getSquaredDistaneTo(const Point2D &target) const {		//��Ŭ���� �Ÿ��� ����ϴ� �Լ�
		//target�� ���������� �޾� �Լ��� ȣ���� �ν��Ͻ��� x, y ��ǥ���� ��Ŭ���� �Ÿ��� ����� �� ����. dx�� dy�� ������ ���̱� ������ ���� �����ϱ� ������ ������ ������ �ʾҴ�.
		int dx = this -> x - target.x;							//x��ǥ �Ÿ��� ��
		int dy = this -> y - target.y;							//y��ǥ �Ÿ��� ��

		return dx*dx + dy*dy;									//��Ŭ���� �Ÿ� ����
	}

	double getDistanceTo(const Point2D &target) const {			//�Ÿ�(sqrt(��Ŭ���� �Ÿ�))�� ����ϴ� �Լ�
		double sqd = (double) this->getSquaredDistaneTo(target);//Ŭ������ ���ǵǾ� �ִ� getSquaredDistanceTo �Լ��� ȣ���� ��Ŭ���� �Ÿ��� ����� �� sqd�� ����

		return sqrt(sqd);										//���� sqrt(��Ŭ���� �Ÿ�)�� �������� ���� ����
	}
};

int main() {
	int n;							//�ϴÿ� �� �ִ� õü�� ��(2�̻� 1000������ �ڿ���)
	Point2D *points;				//Point2D�� �ν��Ͻ����� �迭�� ����Ű�� ������ ����

	scanf("%d", &n);				//�ϴÿ� �� �ִ� õü�� �� �Է¹���
	points = new Point2D[n];		//�ϴÿ� �� �ִ� õü�� ������ ������ �迭�� õü�� �� ��ŭ �������� �Ҵ�

	for(int i=0; i<n; i++) {		//n(�ϴÿ� �� �ִ� õü�� ��)�� �ݺ��Ͽ�
		int x, y;					//������ ���� x, y�� ����
		scanf("%d %d", &x, &y);		//x, y�� ��ǥ�� �Է¹���

		points[i] = Point2D(x, y);	//x, y������ ���ڷ� Point2D�� �����ڸ� ȣ���Ͽ� ��ü ���� �� points������ ����
	}

	int min_sqd = INT_MAX;			//min_sqd(õü�� �Ÿ��� �ּڰ�)�� INT_MAX(int ���� ������ �ִ밪(2147483647))���� �ʱ�ȭ��
	int min_cnt = 0;				//���� ����� �� õü�� �Ÿ���ŭ ������ õü ���� ��

	//�Ʒ� 2�� for���� i�� ��� �����ϸ鼭 �ڽź��� ���� ������ j�� ���Ѵ�. �̷��� �ϸ� �ڱ� �ڽŰ� ������ �ʰ� õü�� �ߺ��ؼ� ������ �ʴ´�.(���귮 1/2�� ����)
	for(int i=0; i<n; i++) {
		for(int j=0; j<i; j++) {
			int sqd = points[i].getSquaredDistaneTo(points[j]);//points[j]�� ���ڷ� Point2D Ŭ������ ���ǵǾ� �ִ� ��Ŭ���� �Ÿ��� ����ϴ� �Լ��� ȣ���Ͽ� ���ϰ��� sqd�� ����
			if(sqd < min_sqd) {			//���ϵ� ���� �ּҰŸ����� �۴ٸ�
				min_sqd = sqd;			//�ּҰŸ��� ����
				min_cnt = 1;			//�ּҰŸ���ŭ ������ õü ���� �� ����
			}
			else if(sqd == min_sqd) {	//���ϵ� ���� �ּҰŸ��� ���ٸ�
				min_cnt++;				//�ּҰŸ���ŭ ������ õü ���� �� ����
			}
		}
	}

	double distance = sqrt(min_sqd);	//min_sqd(��Ŭ���� �Ÿ�)�� �������� ���� ���� ����� �� õü�� �Ÿ��� ���
	printf("%.1f\n", distance);			//���� ����� �� õü�� �Ÿ��� �Ҽ��� ù ���� �ڸ����� ���
	printf("%d\n", min_cnt);			//�� �Ÿ���ŭ ������ õü ���� ���� ���

	delete []points;					//�����Ҵ��� �迭�� �޸� ����
	points = nullptr;					//�迭�� ����Ű�� �����Ϳ� ����� �ּҰ� ����

	return 0;							//�����Լ��� ���������� ����
}

