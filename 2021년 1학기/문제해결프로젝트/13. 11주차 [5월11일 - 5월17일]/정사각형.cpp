#include <iostream>	//����� �Լ��� ����ϱ� ���� �������
#include <iomanip>	//setprecision�Լ��� ����ϱ� ���� �������(�ε� �Ҽ����� ��ȿ�ڸ� ����)
#include <vector>	//vector Ŭ������ ����ϱ� ���� �������(�迭���� ������: ������, ����� �Լ� ����)
#include <cmath>	//max�Լ��� ����ϱ� ���� �������
#include <set>		//set Ŭ������ ����ϱ� ���� �������(�ߺ��� ������� �ʴ� �����̳�. ���� ����Ʈ���� ����)
using namespace std;//ǥ�� �̸������� �����

//���� x��ǥ, y��ǥ, �ε��� ��ȣ�� �����ϰ� �����Ÿ��� �Ǽ��Ÿ� ���, �켱������ ���ǵǾ� �ִ� Ŭ����
class Point2D {
public:
	int x;		//���� x��ǥ
	int y;		//���� y��ǥ
	int index;	//���� ��ȣ

	Point2D(int index, int x, int y) {	//index, x, y�� �Ű������� �޴� ������
		this->index = index;			//�Ű������� ���� index�� ������� index�� ����
		this->x = x;					//�Ű������� ���� x�� ������� x�� ����
		this->y = y;					//�Ű������� ���� y�� ������� y�� ����
	}

	Point2D(int x, int y) {				//x, y�� �Ű������� �޴� ������
		this->index = 1;				//������� index�� ���� 1�� ����
		this->x = x;					//�Ű������� ���� x�� ������� x�� ����
		this->y = y;					//�Ű������� ���� y�� ������� y�� ����
	}

	//�� ��ǥ���� �����Ÿ��� �����ϴ� �Լ�
	long long getSquaredDistanceTo(Point2D target) {
		long long dx = abs(this->x - target.x);
		long long dy = abs(this->y - target.y);

		return dx * dx + dy * dy;
	}

	//�� ��ǥ���� �Ǽ� �Ÿ��� �����ϴ� �Լ�
	double getDistanceTo(Point2D target) {
		long long sqd = this->getSquaredDistanceTo(target);

		return sqrt(sqd);
	}

	//�� ��ǥ�� �켱������ ���ϱ� ���� �� ������
	bool operator < (const Point2D& other) const {
		//x��ǥ�� �ٸ��ٸ� x��ǥ�� �������� ��
		if(this->x != other.x) {
			return this->x < other.x;
		}

		//x��ǥ�� ���ٸ� y��ǥ�� �������� ��
		return this->y < other.y;
	}
};

//�� 4���� ���� �� �ִ� ���簢���� �� ���� ū ���̸� �����ϴ� �Լ�
long long getMaximumSquareArea(int n, const vector<Point2D>& points) {
	long long answer = 0;		//���簢���� ���� �� �ִ밪�� �����ϴ� ����

	//��� ���� Set�� ����
	set<Point2D> pSet;			//default: less(��������), datatype�� class�̹Ƿ� ��Ұ��� ���� �ʿ�
	for(int i=0; i<n; i++) {	//n(��ǥ�� ��)�� �ݺ��Ͽ�
		pSet.insert(points[i]);	//set�����̳ʿ� ����(�ߺ� ����)
	}

	//������ a�� b �� ���� ����
	for(int i=0; i<n; i++) {		//n(��ǥ�� ��)�� �ݺ��Ͽ�
		Point2D pa = points[i];		//Point2D�� ���� pa�� points �迭�� i��° �ν��Ͻ�(Point2D�� �ν��Ͻ�) ���� -> ù ��° ��ǥ ����
		for(int j=0; j<n; j++) {	//n(��ǥ�� ��)�� �ݺ��Ͽ�
			Point2D pb = points[j];	//Point2D�� ���� pb�� points �迭�� j��° �ν��Ͻ�(Point2D�� �ν��Ͻ�) ���� -> �� ��° ��ǥ ����

			if(i==j) continue;		//���� �� ����(�Ʒ� �ڵ带 �������� ����)

			//���� pa-pb�� ���簢���� �� ���̶�� �ϸ� �� ���� �Ÿ�(������ ����)�� ������ ���簢���� ���̰� �ȴ�.
			long long area = pa.getSquaredDistanceTo(pb);	//pa-pb�� �������� ���� ���簢���� ���̸� area�� ����

			//�̹� ���� �簢������ ���̰� ���� �� �ۿ� ���ٸ� �ǳʶ�
			if(area < answer)
				continue;

			/*
			 * 		 i	  j
			 *      ___.____
			 *   j  |		| i
			 *      .       .�� pb
			 *   i  |       | j
			 *      |_____.__
			 * 		  j ��pa i
			 *
			 *��Ƽ����� ������ ������ ���� ���ϴ�.
			 *���� 2���� �˰� �ִٸ� ���簢���� 2�� �׸� �� �ִ�.(���� �Ʒ�, ������ ��)
			 *���⼭�� ���� �Ʒ��θ� �׸���.(������ ���� �ٸ� ���� 2���� �׸� �� �ذ��Ѵ�.)
			 *������ ��ǥ pa�� pb�� ���� �׸� �� �ִ� ���簢���� ��ǥ�� �׷�����.
			 */
			int dx = pb.x - pa.x;	//�� �׸����� i��
			int dy = pb.y - pa.y;	//�� �׸����� j��

			//������ ���� dx�� dy���� �̿��� �� pd�� pc�� ��ǥ ���
			Point2D pd(pa.x - dy, pa.y + dx);
			Point2D pc(pb.x - dy, pb.y + dx);

			//�ռ� ����� pd�� pc�� pSet�� �����Ѵٸ�
			if(pSet.count(pc) > 0 && pSet.count(pd) > 0) {	//O(log2N)
				answer = max(answer, area);	//�ִ� ���簢���� ���� ����
			}
		}
	}

	return answer;	//�� 4���� ���� �� �ִ� ���簢���� �� ���� ū ���̸� �����ϴ� �Լ�
}

void process(int caseIndex) {
	int n;		//��ǥ�� �� ����
	cin >> n;	//��ǥ�� �� �Է¹���

	vector<Point2D> points;	//���� ��ǥ�� �����ϴ� ����

	for(int i=0; i<n; i++) {	//n(��ǥ�� ��)�� �ݺ��Ͽ�
		int x, y;				//���� x, y��ǥ ���� ����
		cin >> x >> y;			//���� x, y��ǥ �Է¹���
		points.push_back(Point2D(i, x, y));	//Point2D�� �ν��Ͻ��� �����Ͽ� points ������ �� �ڿ� �߰�
	}

	long long answer = getMaximumSquareArea(n, points);	//�� 4���� ���� �� �ִ� ���簢���� �� ���� ū ���̸� ����Ͽ� answer�� ����

	//fixed: �Ҽ����� �������� ǥ��(fixed�� ���� ��� �����ο� �Ҽ����� �ڸ����� ���Ͽ� �ڸ��� ���), setprecision: 2�ڸ����� ǥ��
	cout << fixed << setprecision(2) << answer << endl;	//�� 4���� ���� �� �ִ� ���簢���� �� ���� ū ���̸� �Ҽ��� �Ʒ� 2�ڸ����� ���
}

int main() {
	int caseSize;			//�׽�Ʈ ���̽��� ��
	cin >> caseSize;		//�׽�Ʈ ���̽��� �� �Է¹���

	for(int caseIndex = 0; caseIndex < caseSize; caseIndex++) {	//caseSize(�׽�Ʈ ���̽��� ��)�� �ݺ��Ͽ�
		process(caseIndex);	//�� 4���� ���� �� �ִ� ���簢���� �� ���� ū ���̸� ����Ͽ� �Ҽ��� �Ʒ� 2�ڸ����� ����ϴ� �Լ� ȣ��
	}

	return 0;				//�����Լ��� ���������� ����
}
