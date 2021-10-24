#include <cstdio>	//C����� stdio.h�� ���� C�� ����� �Լ��� ������ �������
#include <vector>	//vector Ŭ������ ����ϱ� ���� �������(�迭���� ������ : ������, ����� �Լ� ����)
using namespace std;//ǥ�� �̸������� �����

//���޵��� ���� ���� ��ȣ�� ã�� �Լ�, ���� ��ȣ�� ���޵Ǿ����� �˾Ƴ��� �Լ�, ���޵� ���� ��ȣ�� ���� ���θ� �����ϴ� �Լ��� ���ǵ� Ŭ����
class TicketTable {
public:
	vector<bool> used;						//���� ��ȣ�� ���� ���θ� �����ϴ� used ���� ����
	int length;								//used ������ ����

	TicketTable(int length) {				//length�� �Ű������� �޴� ������
		this->length = length;				//�Ű������� ���� length�� ������� length�� ����
		this->used.assign(length, false);	//���� ���͸� ����� false���� length�� ������ ���ͷ� �ʱ�ȭ
	}

	int findEmptyIndexByUserId(int userId) {//ȸ����ȣ�� ���޵��� ���� ���� ��ȣ�� ã�� �Լ�
		int index = userId % length;		//ȸ����ȣ (mod ���ǹ�ȣ�� ��) ���� index�� ����

		while(this->isEmpty(index) == true) {//used ������ index ���� ���� true�� ���� �ݺ�(��� ������ ��� isEmpty�Լ��� false�� ������) (�Լ� ���� �߸���)
			index = (index + 1) % length;	//while�� ���� ������ true�� ���� �ݺ��ϱ� ������ ���ݵ��� ���� ���� ��ȣ�� ã���� ����(index�� ���� ������Ų �� length�� ���� ���������� ������ �ٽ� ��) �ݺ�
		}

		return index;						//���޵��� ���� ���� ��ȣ�� ����
	}

	bool isEmpty(int ticketIndex) {			//ticketIndex(���� ��ȣ)�� ���޵Ǿ����� �����ϴ� �Լ�
		return this->used[ticketIndex];		//used ������ ticketIndex���� ���� ����
	}

	void setUsed(int index, bool status) {	//���� ��ȣ�� ���� ���θ� �����ϴ� �Լ�
		this->used[index] = status;			//used ������ index���� status�� ����
	}
};

//���� ��ȣ�� �����ϴ� ���͸� �����ϴ� �Լ�
vector<int> getTicketNumbers(int n, int m, const vector<int> &ids) {
	vector<int> tickets;					//���� ��ȣ�� ������ ������ ���� tickets ����
	TicketTable table = TicketTable(n);		//TicketTable�� �ν��Ͻ� table ����

	for(int i=0; i<m; i++) {				//m(ȸ���� ��)�� �ݺ��Ͽ�
		int userId = ids[i];				//i��° ȸ����ȣ�� userId�� ����
		int ticketIndex = table.findEmptyIndexByUserId(userId);	//ȸ����ȣ�� ���ڷ� ����ִ� index�� ã�� ticketIndex�� ����
		tickets.push_back(ticketIndex);		//ticketIndex�� tickets ������ �� �ڿ� �߰�
		table.setUsed(ticketIndex, true);	//ticketIndex�� ���� ���� ��ȣ�� ����
	}

	return tickets;							//tickets ���� ����
}

int main() {
	int n, m;					//n : ������ ��, m : ȸ���� ��
	scanf("%d %d", &n, &m);		//������ ��, ȸ���� �� �Է¹���

	vector<int> ids(m);			//0���� �ʱ�ȭ��, m���� ������ �����ϴ� ���� ids ����
	for(int i=0; i<m; i++) {	//m(ȸ���� ��)�� �ݺ��Ͽ�
		scanf("%d", &ids[i]);	//ȸ����ȣ �Է¹���
	}

	vector<int> tickets = getTicketNumbers(n, m, ids);	//ȸ����ȣ�� ���ڷ� �Ѱ� ���� ��ȣ�� tickets ���Ϳ� ����
	for(int i=0; i<tickets.size(); i++) {				//tickets ������ ������ �� ��ŭ �ݺ��Ͽ�
		printf("%d\n", tickets[i]);						//���� ��ȣ ���
	}
}
