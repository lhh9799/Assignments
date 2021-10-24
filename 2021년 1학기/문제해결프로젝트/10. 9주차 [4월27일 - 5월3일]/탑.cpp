#include <iostream>	//����� �Լ��� ����ϱ� ���� �������
#include <vector>	//vector Ŭ������ ����ϱ� ���� �������(�迭���� ������ : ������, ����� �Լ� ����)
#include <stack>	//stack Ŭ������ ����ϱ� ���� �������(Ư¡: ����Ʈ�� �� �� �����θ� �ڷ��� ���԰� ������ �̷����. ���Լ���)
using namespace std;//ǥ�� �̸������� �����

//Ÿ���� �ε���, ����, Ÿ���� �������� �����ϴ� ��� Ÿ���� �ε����� �����ϴ� Ŭ����
class Tower {
public:
	int index;				//Ÿ���� �ε���
	int height;				//Ÿ���� ����
	int targetTowerIndex;	//�� Ÿ���� �������� �����ϴ� ��� Ÿ���� �ε���

	Tower(int index, int height) {	//�Ű����� �ִ� ������
		this->index = index;		//�Ű������� ���� index�� �� ��ü�� index�� ����
		this->height = height;		//�Ű������� ���� height�� �� ��ü�� height�� ����
		this->targetTowerIndex = 0;	//targetTowerIndex�� 0���� ����(�⺻��)
	}

	//Ÿ���� �������� �����ϴ� ��� Ÿ���� �ε����� �����ϴ� �Լ�
	void setTargetTowerIndex(int targetTowerIndex) {
		this->targetTowerIndex = targetTowerIndex;	//�Ű������� ���� targetTowerIndex�� �� ��ü(Ÿ��)�� �۽��� �������� �����ϴ� ��� Ÿ���� �ε����� ����
	}

	//Ÿ���� �������� �����ϴ� ��� Ÿ���� �ε����� �����ϴ� �Լ�
	int getTargetTowerIndex() {
		return this->targetTowerIndex;				//�� ��ü�� targetTowerIndex ����
	}
};

//�� Ÿ���� �۽��ϴ� ���������� �����ϴ� Ÿ������ �����ϴ� �Լ�
void findTargetTowers(vector<Tower> &towers) {		//towers���͸� ���������� �޾� ���������� ���� ���� �����ϰ� ��
	stack<Tower> stk;	//���� �ٸ� Ÿ���� ��ȣ�� ������ ���ɼ��� �ִ� Ÿ������ �����ϴ� ����

	//�ð����⵵ O(n)
	for(int i=0; i<towers.size(); i++) {	//towers ������ ������ �� ��ŭ �ݺ��Ͽ�
		Tower &t = towers[i];				//�� Ÿ�� t�� ���� ���ʷ� ���
		int targetTowerIndex = 0;			//Ÿ�� t�� ��ȣ�� �����ϴ� Ÿ���� �ε����� 0���� ����(�ʱⰪ null)

		//Ÿ�� t�� ���̰� stk ������ ���� �� ����(t���پտ� �ִ� Ÿ��)�� ���̺��� ũ�ٸ�
		while(stk.empty() == false && stk.top().height < t.height) {	//������ ����ִ��� Ȯ���� �� pop() ȣ��(������ ������� �� pop() ȣ�� �� ��Ÿ�� ���� �߻� ����)
			stk.pop();
		}

		//t�� ���̸� �ʰ��ϴ� ���̸� ���� Ÿ���� �����ִٸ�(�տ��� t���� ���� Ÿ������ ���ÿ��� ���������Ƿ� ������ ���� 0�ʰ��� ���)
		if(stk.size() > 0) {
			targetTowerIndex = stk.top().index;	//targetTowerIndex�� �� ����
		}
		t.setTargetTowerIndex(targetTowerIndex);//t�� �������� �����ϴ� ��� Ÿ���� �ε����� targetTowerIndex�� ����

		//t�� �������� ���������Ƿ� �ٸ� Ÿ���� ��ȣ�� ������ �� ����. ���� ������ ���� t�� stk ���ÿ� ����
		stk.push(t);
	}
}

int main() {
	int n;		//ž�� ��
	cin >> n;	//ž�� �� �Է¹���

	vector<Tower> towers;	//Tower�� �ν��Ͻ����� ������ ����
	for(int i=0; i<n; i++) {//n(ž�� ��)�� �ݺ��Ͽ�
		int hi;				//ž�� ����
		cin >> hi;			//ž�� ���� �Է¹���
		towers.push_back(Tower(i+1, hi));	//Tower�� �ν��Ͻ� ����(�ε���: i+1(�ε����� 1���� ����. ������ ��ȣ�� �����ϴ� ž�� �������� ������ 0�̱� ����), ����: hi)�� towers������ �� �ڿ� �߰�
	}

	//�� Ÿ���� �۽��ϴ� ���������� �����ϴ� Ÿ������ �����ϴ� �Լ� ȣ��
	findTargetTowers(towers);

	for(int i=0; i<n; i++) {//n(ž�� ��)�� �ݺ��Ͽ�
		if(i>0) {			//0�� ���Ұ� �ƴ϶��
			cout << " ";	//����(" ")�� ���
		}
		cout << towers[i].getTargetTowerIndex();	//�� Tower�� �ν��Ͻ����� ���� ž�� �ε��� ��ȣ ���
	}

	return 0;	//�����Լ��� ���������� ����
}
