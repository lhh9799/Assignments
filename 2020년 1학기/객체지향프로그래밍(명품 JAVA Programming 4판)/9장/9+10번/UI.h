#ifndef UI_H_
#define UI_H_

#include <string>
using namespace std;

class UI {
public:
	static void println(string msg);	//msg ���ڿ� �� �� �ٲٱ� ���
	static void print(string msg);		//msg ���ڿ� ���
	static int printGetInt(string msg);	//msg ���ڿ� ��� �� ���� �ϳ� �о� ����
	static int getMainMenu();			//���� �޴� ���� ����ϰ� ���� �޴� �� �Է� �޾� ����
	//����ڷκ��� x, y������ �̵��� �� width�� height���� �Է� ����
	static void getWidthHeight(int &width, int &height);//���� �� �� �Է� ����
};

#endif /* UI_H_ */
