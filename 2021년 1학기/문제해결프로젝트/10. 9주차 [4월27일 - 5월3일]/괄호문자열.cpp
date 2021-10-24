#include <iostream>	//����� �Լ��� ����ϱ� ���� �������
#include <string>	//string Ŭ������ length �Լ��� ����ϱ� ���� �������
#include <stack>	//stack Ŭ������ ����ϱ� ���� �������(Ư¡: ����Ʈ�� �� �� �����θ� �ڷ��� ���԰� ������ �̷����. ���Լ���)
using namespace std;//ǥ�� �̸������� �����

//��ȣ�� ���ڿ��� �Է¹޾� �ùٸ� ��ȣ ���ڿ����� �ƴ����� �����ϴ� �Լ�
bool process() {
	string bracket;		//�Է¹��� ��ȣ ���ڿ��� �����ϴ� ���ڿ� ����
	stack<char> verify;	//�Է¹��� ��ȣ ���ڿ��� ������ ����

	cin >> bracket;		//��ȣ ���ڿ� �Է¹���

	for(int i=0; i<bracket.length(); i++) {	//��ȣ ���ڿ��� ���� ��ŭ �ݺ��Ͽ�
		if(bracket[i] == '(')				//i��° ���ڰ� '('���
			verify.push(bracket[i]);		//���ÿ� �߰�
		else if(bracket[i] == ')') {		//i��° ���ڰ� ')'���
			if(!verify.empty())				//������ ����ִ��� Ȯ���� ��(������� �ʴٸ� �Ʒ� �ڵ� ����)
				verify.pop();				//���� �� ���� ����
			else							//������ ������� �ʴٸ�(�ݴ� ��ȣ�� ������ ���̹Ƿ�)
				return false;				//false ����
		}
	}
	if(verify.size() > 0)					//�� �ݺ����� �� ������ �ڿ� verify ���ÿ� ���Ұ� �����ִٸ� ��ȣ���� ���� �ʴ� ���̹Ƿ�
		return false;						//false ����

	return true;							//������ ���Ұ� �������� �ʴ� ����̹Ƿ� true ����
}

int main() {
	int caseSize;							//�׽�Ʈ ���̽��� ��
	cin >> caseSize;						//�׽�Ʈ ���̽��� ���� �Է¹���

	for(int caseIndex=0; caseIndex<caseSize; caseIndex++) {	//caseSize(�׽�Ʈ ���̽��� ��)�� �ݺ��Ͽ�
		if(process())						//process�Լ��� ���ϰ��� true�̸�
			cout << "YES" << endl;			//"YES" ���
		else								//process�Լ��� ���ϰ��� false�̸�
			cout << "NO" << endl;			//"NO" ���
	}

	return 0;								//�����Լ��� ���������� ����
}
