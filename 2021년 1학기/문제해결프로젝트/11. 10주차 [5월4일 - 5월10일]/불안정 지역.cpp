#include <iostream>	//����� �Լ��� ����ϱ� ���� �������
#include <queue>	//queue Ŭ������ ����ϱ� ���� �������(���ð��� ������: ���Լ���, back ���� ���� ����)
#include <vector>	//vector Ŭ������ ����ϱ� ���� �������(�迭���� ������: ������, ����� �Լ� ����)
using namespace std;//ǥ�� �̸������� �����

//������ ��ȣ, �ҵ� ������ �����ϴ� Ŭ����
class City {
public:
	int index;	//������ �ε���
	int income;	//�ش� ������ �ҵ�

	City(int index, int income) {	//index, income�� �Ű������� �޴� ������
		this->index = index;		//�Ű������� ���� index�� ������� index�� ����
		this->income = income;		//�Ű������� ���� income�� ������� income�� ����
	}

	//��� ���� �߰�(�Լ��� ���� const�� �ǹ�: �ش� �Լ����� ��������� �б⸸ ��(������� ���� �Ұ�)
	bool operator < (const City &o) const {	//������� income�� �Ű������� ���� o�� income���� ������ '<'������ ���ϰ� true
		return this->income < o.income;
	}
	bool operator > (const City &o) const {	//������� income�� �Ű������� ���� o�� income���� ũ�� '>'������ ���ϰ� true
		return this->income > o.income;
	}
};

//���� ū �ҵ����� �����ϴ� �Լ�
int getMaximumRangeDifference(int n, int k, const vector<City> &cities) {
	int answer = 0;	//���� ū �ҵ��� ������ 0���� �ʱ�ȭ

	/*			[���̵��]
	 * 1. �켱���� ť 2�� �غ�(��������, ��������)
	 * 2. k-1���� ���ø� �켱���� ť 2���� ����
	 * 3. k��° ���ø� �켱���� ť 2���� ����
	 * 4. top�� �ε����� i-k+1�� (�� �̻� �׷�(k���� ����)�� ������ �ʴ� ����)���� �۴ٸ� pop�� (�� �̻� �׷쿡 ������ �ʴ��� top���� �Ʒ��� �ִ� ���Ҷ�� �״�� �����ְ� �ȴ�. while���̹Ƿ� ���߿� �߰� �� ����ؼ� pop�ϹǷ� ������.)
	 * 5. �� ť�� top������ ���� ���Ͽ� max�� ����
	 * 6. i�� n-1�� �� ������ 3~5�� �ݺ�
	 */

	//�ҵ��� ���� ���� ���ú��� pop�Ǵ� �켱���� ť
	priority_queue<City, vector<City>, greater<City>> rangeMinimum;

	//�ҵ��� ���� ���� ���ú��� pop�Ǵ� �켱���� ť
	priority_queue<City> rangeMaximum;


	for(int i=0; i<k-1; i++) {			//k-2���� ���Ҹ�
		rangeMaximum.push(cities[i]);	//�������� �켱���� ť�� �߰�
		rangeMinimum.push(cities[i]);	//�������� �켱���� ť�� �߰�
	}
	for(int i=k-1; i<n; i++) {			//������ ����(k-1��°)��
		rangeMaximum.push(cities[i]);	//�������� �켱���� ť�� �߰�
		rangeMinimum.push(cities[i]);	//�������� �켱���� ť�� �߰�
		while(rangeMaximum.top().index < i - k + 1) rangeMaximum.pop();	//�������� ť�� top�� ���Ұ� �׷쿡 ���ϴ� ���Ұ� ���ö� ���� pop
		while(rangeMinimum.top().index < i - k + 1) rangeMinimum.pop();	//�������� ť�� top�� ���Ұ� �׷쿡 ���ϴ� ���Ұ� ���ö� ���� pop
		answer = max(answer, rangeMaximum.top().income - rangeMinimum.top().income);	//�� ť�� top������ ���� ���Ͽ� max�� ����
	}

	return answer;	//���� ū �ҵ��� ����
}

//������ K���� ���÷� �̷���� ������ �� ���� ū �ҵ����� ������ ������ �ҵ����� ����ϴ� �Լ�
void process(int caseIndex) {
	int n, k;				//n: ������ ��, k: �� ���� ������ �����ϴ� ������ ������ ��
	cin >> n >> k;			//������ ��, �� ���� ������ �����ϴ� ������ ������ �� �Է¹���
	vector<City> cities;	//������ ������ �����ϴ� ����

	for(int i=0; i<n; i++) {	//n(������ ��)�� �ݺ��Ͽ�
		int income;				//�ҵ� ����
		cin >> income;			//�ҵ� �Է¹���
		cities.push_back(City(i, income));	//City�� �ν��Ͻ��� �����Ͽ� cities ������ �� �ڿ� �߰�
	}

	int answer = getMaximumRangeDifference(n, k, cities);	//������ K���� ���÷� �̷���� ������ �� ���� ū �ҵ����� ������ ������ �ҵ����� answer�� ����

	cout << answer << endl;	//���� ū �ҵ��� ���
}

int main() {
	int caseSize;			//�׽�Ʈ ���̽��� ��
	cin >> caseSize;		//�׽�Ʈ ���̽��� �� �Է¹���

	for(int caseIndex=0; caseIndex<caseSize; caseIndex++) {	//caseSize(�׽�Ʈ ���̽��� ��)�� �ݺ��Ͽ�
		process(caseIndex);	//������ K���� ���÷� �̷���� ������ �� ���� ū �ҵ����� ������ ������ �ҵ��� ���
	}

	return 0;				//�����Լ��� ���������� ����
}
