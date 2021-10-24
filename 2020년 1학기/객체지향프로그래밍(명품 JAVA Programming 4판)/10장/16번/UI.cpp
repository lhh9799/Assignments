#include <iostream>
#include "UI.h"
using namespace std;

int UI::printGetInt(string msg) {	//msg ���ڿ� ��� �� ���� �� �ϳ� �о� ����
	cout << msg;					//���ڿ� msg ���
	int value;						//������ ������ ���� �ϳ��� ����
	cin >> value;	//Ű���忡�� ���� �� �ϳ� �о� ������ ����
	return value;	//���� �� ����
}

void UI::println(string msg) {
	cout << msg << endl;	//���ڿ� msg�� �ٹٲٱ⸦ ���
}

void UI::print(string msg) {
	cout << msg;			//���ڿ� msg ���
}
//���� �޴� ���� ����ϰ� ���� �޴� �� �Է� �޾� ����
int UI::getMainMenu() {
	return printGetInt("����:0, ��κ���:1, �ڵ�����:2, ����̵�:3, ��λ���:4, ��κ���:5 >> ");
}
//������ ���� ���� ����ϰ� ���� �� �Է� �޾� ����
void UI::getWidthHeight(int &width, int &height) {
	cout << "X��� Y������ �̵��� ����(���� �ΰ� �Է�)? >> ";
	cin >> width >> height;
}
