#include <iostream>	//����� �Լ��� ����ϱ� ���� �������
#include <vector>	//vector Ŭ������ ����ϱ� ���� �������(�迭���� ������ : ������, ����� �Լ� ����)
#include <stack>	//stack Ŭ������ ����ϱ� ���� �������(Ư¡: ����Ʈ�� �� �� �����θ� �ڷ��� ���԰� ������ �̷����. ���Լ���)
#include <cmath>	//abs, max�Լ��� ����ϱ� ���� �������
using namespace std;//ǥ�� �̸������� �����

//���簢�� ��� ����� ����, ������ x��ǥ�� ���̸� �����ϴ� Ŭ����
class Histogram {
public:
	int height;		//������׷��� ����
	int leftX;		//�ε��� Ȥ�� ������׷��� ���� ���� x��ǥ
	int rightX;		//������׷��� ������ ���� x��ǥ

	Histogram() {}	//�⺻ ������. ���͸� ����� ���� ����

	Histogram(int index, int height) {	//�Ű����� �ִ� ������
		this->leftX = index;			//�Ű������� ���� index�� �� ��ü�� index�� ����
		this->rightX = this->leftX + 1;	//�� ������׷��� �ʺ� 1�̹Ƿ� rightX�� leftX + 1
		this->height = height;			//�Ű������� ���� height�� �� ��ü�� height�� ����
	}
};

//������׷� ���ο� ������ �� �ִ� ���簢���� �ִ� ���̸� �����ϴ� �Լ�
long long getLargestRectangleArea(const vector<Histogram> &histograms) {
	long long answer = 0;	//�ִ� ���簢���� ����(�ִ� 100���̹Ƿ� long long���� ����)

	//���� �������� Ȯ�� ���ɼ��� �ִ� ���簢����
	stack<Histogram> stk;

	//������ ���Ǹ� ���� ���� ���ʿ� ���� 0���� ������ ���簢�� �߰�
	stk.push(Histogram(-1, 0));

	for(int i=0; i<histograms.size()+1; i++) {	//���� ���ʿ� Histogram�� �ν��Ͻ��� �߰������Ƿ� size+1�� �ݺ�
		//���ʺ��� ������ ������׷����� ���ʷ�
		Histogram h;
		if(i<histograms.size()) {				//���� ������ ���簢���� �ƴ� ���
			h = histograms[i];					//i��° ���簢���� h
		}
		else {									//���� ������ ���簢���� ���
			//������ ���Ǹ� ���� ���� �����ʿ� ���� 0���� ������ ������׷� �߰�
			h = Histogram(histograms.size(), 0);//���� ������ ���簢���� x��ǥ, ���̴� 0�� Histrogram�� h
		}

		//h(���)�� ���̰� ������ ���簢������ �۴ٸ� �� ���� ���簢���� ���� �� �����Ƿ� �Ʒ� ������ ����(�ִ���� ã��)
		//stk������ ������ ���� 2�̸��̸� �簢���� ���� �� ����(�簢�� 1���� ����� ���� x��ǥ�� �ּ� 2�� �ʿ�)
		while(stk.size() > 1 && stk.top().height > h.height) {
			Histogram lh = stk.top();	//������ �ֻ�ܿ� �ִ� ����(h���� �����Ͽ� ���ʹ��⿡ �ִ� ���簢��)�� lh�� ����
			stk.pop();					//lh���� ���ʿ� �ִ� ���簢���� �����Ͽ� ���̸� ����ϱ� ���� ������ �ֻ�� ���Ҹ� ����

			//�� ������ ������׷�(���� Ȯ���� ��)
//			Histogram bh = stk.top();

			//���� �߰��� h�� �ٷ� ���ʱ��� Ȯ�����̾���.
//			long long width = abs(h.leftX - bh.rightX);	//bh�� ������ x��ǥ�� h�� ���� x��ǥ�� ���� width�� ����
//			long long width = abs(h.leftX - lh.leftX);	//lh�� ���� x��ǥ�� h�� ���� x��ǥ�� ���� width�� ����
			long long width = h.leftX - lh.leftX;	//lh�� ���� x��ǥ�� h�� ���� x��ǥ�� ���� width�� ����
			long long height = lh.height;				//bh���� ���� lh�� ���̸� height�� ����
			long long area = width * height;			//���簢���� ���� ���

			//�ִ밪 ����
			answer = max(answer, area);
		}

	//h�� ������ �߰��Ѵ�.
	stk.push(h);
	}

	return answer;										//���簢���� �ִ� ���� ����
}

//�Է¹��� ������׷� ���ο� ������ �� �ִ� ���簢���� �ִ� ���̸� ����ϴ� �Լ�
void process(int caseIndex) {
	int n;		//������׷��� �����ϴ� ���簢�� ��� ����� ��
	cin >> n;	//������׷��� �����ϴ� ���簢�� ��� ����� �� �Է¹���

	vector<Histogram> histograms;	//������׷��� �����ϴ� ���簢�� ��� ����� ���̸� �����ϴ� ����
	for(int i=0; i<n; i++) {		//���簢�� ��� ����� ���� �ݺ��Ͽ�
		int height;					//���簢�� ��� ����� ���� ����
		cin >> height;				//���簢�� ��� ����� ���� �Է¹���
		histograms.push_back(Histogram(i, height));//Histogram�� �ν��Ͻ� ����, ����: height)�� histograms������ �� �ڿ� �߰�
	}

	long long answer = getLargestRectangleArea(histograms);	//�ִ� ���簢���� ���̸� answer�� ����(�ִ� 100���̹Ƿ� long long���� ����)
	cout << answer << endl;	//�ִ� ���簢���� ���� ���
}

int main() {
	int caseSize;			//�׽�Ʈ ���̽��� ��
	cin >> caseSize;		//�׽�Ʈ ���̽��� ��

	for(int caseIndex=0; caseIndex<caseSize; caseIndex++) {	//caseSize(�׽�Ʈ ���̽��� ��)�� �ݺ��Ͽ�
		process(caseIndex);	//���簢���� �ִ� ���� ��� �� ���
	}

	return 0;				//�����Լ��� ���������� ����
}
