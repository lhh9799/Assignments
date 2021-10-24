#include <queue>	//queue Ŭ������ ����ϱ� ���� �������(���ð��� ������: ���Լ���, back ���� ���� ����)
#include <vector>	//vector Ŭ������ ����ϱ� ���� �������(�迭���� ������: ������, ����� �Լ� ����)
#include <algorithm>//sort�Լ��� ����ϱ� ���� �������
#include <ctime>	//�ڵ� ����ð� ������ ���� �������
#include <iostream>	//����� �Լ��� ����ϱ� ���� �������
using namespace std;//ǥ�� �̸������� �����

//������ ��ȣ�� ���� �ҿ� �ð��� �����ϴ� Ŭ����
class food {
public:
	int index;		//������ ��ȣ
	int time_left;	//���� ���� �ҿ� �ð�

	//index�� time_left�� �Ű������� �޴� ������
	food(int index, int time_left) {
		this->index = index;		//�Ű������� ���� index�� ������� index�� ����
		this->time_left = time_left;//�Ű������� ���� time_left�� ������� time_left�� ����
	}

	/*��� ���� �߰�(�Լ��� ���� const�� �ǹ�: �ش� �Լ����� ��������� �б⸸ ��(������� ���� �Ұ�)
	 *�� �ν��Ͻ��� time_left�� ������ index�� �������� �켱������ ����(1�� ���ĺ��� �Ա� �����ϹǷ�)
	 *time_left�� �ٸ��ٸ� time_left�� ���� �ν��Ͻ��� �켱������ ����(���� ���� �Ծ�ġ��� �ֱ� ����)
	 */
	bool operator < (const food &o) const {
		if(this->time_left == o.time_left)
			return this->index < o.index;
		return this->time_left < o.time_left;
	}
	bool operator > (const food &o) const {
		if(this->time_left == o.time_left)
			return this->index > o.index;
		return this->time_left > o.time_left;
	}
};

//���Ĺ�ȣ�� �������� �������� �����ϴ� �Լ�
bool sort_by_index (const food &a, const food &b) {
	return a.index < b.index ? true : false;
}

int main() {
	int N, *time = nullptr;			//N: ������ ����, *time: ������ �ҿ� �ð��� �����ϴ� �迭�� ����Ű�� ������ ����
	int acc = 0;					//������ ȸ���� ����Ŭ(accumulation)
	long long k;					//��� �ߴ� �ð�(1 <= k <= 2*10^13) -> long long
	long long input_time_sum = 0;	//��� �ߴ� �ð� ������ ������ �� ���� �� �ִ��� �˻��ϱ� ���� ����
	priority_queue<food, vector<food>, greater<food>> food_list;	//������ �Ծ�� �� ������ �켱���� ť(�ҿ� �ð��� ���� �ͺ���, ���ٸ� �ε����� ���� ��)
	vector<food> food_list_order_by_index;	//���Ĺ�ȣ�� �������� �������� ������ ����(���� ����ϱ� ����)

	cin >> N;					//������ ���� �Է¹���
	time = new int[N];			//������ �ҿ� �ð��� �����ϴ� �迭 �����Ҵ�

	for(int i=0; i<N; i++) {	//N(������ ��)�� �ݺ��Ͽ�
		cin >> time[i];			//���� ���� �ҿ� �ð� ����
	}

	cin >> k;					//��� �ߴ� �ð� �Է¹���

	clock_t start = clock();	//���� �ð� ����

	//k�� �Է¹ޱ� �� for������ �ν��Ͻ� ���� �� �켱���� ť �߰��� �ϸ� �� ȿ�����̰�����, ���α׷� ����ð� ������ ������ �ֱ� ������ �Ʒ� ���� for������ ó��
	for(int i=0; i<N; i++) {				//N(������ ��)�� �ݺ��Ͽ�
		food_list.push(food(i+1, time[i]));	//food�� �ν��Ͻ� ���� �� food_list ť�� �� �ڿ� �߰�(i+1 ����: ���Ĺ�ȣ�� 1������ ����)
		input_time_sum += time[i];
	}

	if(input_time_sum <= k) {		//��� �ߴ� �ð� ������ ������ �� ���� �� �ִ� ���
		cout << "-1" << endl;		//�� �����ؾ� �� ������ �����Ƿ� -1 ���
		clock_t end = clock();		//���� �ð� ����
		cout << "����ð�: " << (double)(end - start) / CLOCKS_PER_SEC << "��";	//����ð�(����: ��) ���

		return 0;					//�Լ� ����
	}

	/*
	 *�˰���: ���� k�� �ȿ� ��� ������ �� ����(�ּ� �ҿ�ð� ����) �մ� �� �ִٸ� (�ʿ� �ð�: �ּ� �ҿ�ð� * ������ ��)
	 *k -= (�ּ� �ҿ�ð� * ������ ��)�� �ŵ��� ������ ���귮�� �ٿ�������.
	 *�� �̻� k�� �ٿ������� ���� �� while������ ����������.
	 */
	while(k >= 0) {
		food f = food_list.top();				//�켱���� ť�� ���� �� ���Ҹ� food�� �ӽú��� f�� ����
		//�� ���� ������ ���ִµ� �ɸ��� �ð� ���(�켱���� ť���� ��� ���ҵ�(top�� �̹� pop�Ǿ���)�� time_left ��������� ���ŵ��� �ʾ����Ƿ� acc(������ ȸ���� ����Ŭ)��ŭ ����)
		long long  required_time = food_list.size() * (f.time_left - acc);

		if(k >= required_time) {				//k >= (�ּ� ���� �ҿ� �ð� * ������ ��) == (k�� ���� �� ���� ������ ��� �Ծ�ġ�� �� �ִٸ�)
			acc = food_list.top().time_left;	//������ ȸ���� ����Ŭ ����
			k -= required_time;					//���� �ð� ����
		}
		else									//�� ���� ������ ��� �Ծ�ġ�� �ð��� �ȵȴٸ�
			break;								//���� Ż��

		//top������ time_left�� acc ���϶�� while���� �̿��� ����(time_left�� ���� ���Ұ� ���� �� �ֱ� ����)
		while(food_list.top().time_left <= acc) {
			food_list.pop();
		}
	}

	//�켱���� ť�� ���Ҹ� ���Ϳ� ����
	while(!food_list.empty()) {
		food_list_order_by_index.push_back(food_list.top());	//������ �� �ڿ� �߰�
		food_list.pop();										//�켱���� ť top ���� ����
	}

	//���͸� ���� ��ȣ������ ����
	sort(food_list_order_by_index.begin(), food_list_order_by_index.end(), sort_by_index);

	int target = k % food_list_order_by_index.size();			//k % v.size()�� ����� �簳�� �� �Ծ�� �ϴ� ������ ������ ����� ��ȣ. ���Ĺ�ȣ�� 1������ ���������Ƿ� �߰��� 1(���� ���Ĺ�ȣ)�� ������ ����
	cout << food_list_order_by_index[target].index << endl;		//ť�� �� �� ������ index ���(����� �簳�Ǿ��� �� �����ؾ� �� ������ ��ȣ)

	delete []time;				//�����Ҵ��� �迭�� �޸� ����
	time = nullptr;				//�迭�� ����Ű�� �����Ϳ� ����� �ּҰ� ����

	clock_t end = clock();		//���� �ð� ����
	cout << "����ð�: " << (double)(end - start) / CLOCKS_PER_SEC << "��";	//����ð�(����: ��) ���

	return 0;					//�����Լ��� ���������� ����
}
