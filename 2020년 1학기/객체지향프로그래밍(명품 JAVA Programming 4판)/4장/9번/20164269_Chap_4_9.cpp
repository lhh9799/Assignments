#include <iostream>
#include <string>
using namespace std;

class Person {
	string name;
	string tel;
public:
	Person() {name = ""; tel = "";}; //�⺻ ������: name�� tel�� ""�� ����
	string getName() {return name;}
	string getTel() {return tel;}
	void set(string name, string tel) {this->name = name; this->tel = tel;}
	//�Լ� ������ name, tel�� Ŭ���� ����� name, tel�� ����. this ���
};

class PersonManager {
	Person *p; //����� ���� ������ ���� �� ó���� ���� ��ü �迭�� ���� ������

public:
	//PersonManager() {} //�⺻ ������

	PersonManager(int n) { //������: n�� �迭�� ũ��, �� ������ ������ ����� ��
		p = new Person[n]; //Person�� �迭�� �������� �Ҵ� �ޱ�
		//�ʿ��� string ���� ���� name, tel
		string name, tel;
		cout << "�̸��� ��ȭ ��ȣ�� �Է��� �ּ���" << endl;

		for(int i=0; i<3; i++) {
			cout << "��� " << i+1 << ">> ";
			cin >> name >> tel; //�̸��� ��ȭ ��ȣ�� name, tel�� �Է� �ޱ�
			//�Է¹��� �̸��� ��ȭ��ȣ�� p[i].set(...)�� ȣ���Ͽ� p[i]�� ����
			p[i].set(name, tel);
		}
	}

	void show() {
		cout << "��� ����� �̸��� ";
		for(int i=0; i<3; i++)
			cout << p[i].getName() << " ";
	}

	void search() {
		cout << "\n��ȭ��ȣ �˻��մϴ�. �̸��� �Է��ϼ���>>";
		string searchname;
		cin >> searchname;

		for(int i=0; i<3; i++) {
			if(searchname == p[i].getName()) {
				cout << "��ȭ��ȣ�� " << p[i].getTel();
				break;
			}
		}
	}

	~PersonManager() { //�Ҹ���
		//�������� �Ҵ� ���� �迭(p)�� ��ȯ�� // ���� 4-9 ����
		delete p;
	}
};

int main() {
	// PersonManager ��ü ����: 3���� person�� ������
	PersonManager manager(3); //�� ����� �̸��� ��ȭ��ȣ �Է� ����

	manager.show();
	manager.search();
}
