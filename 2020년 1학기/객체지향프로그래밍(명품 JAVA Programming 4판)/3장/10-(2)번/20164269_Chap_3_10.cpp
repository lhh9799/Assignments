#include <iostream>
using namespace std;

#include "Add.h"
#include "Sub.h"
#include "Mul.h"
#include "Div.h"

int main() {
	Add a; Sub s; Mul m; Div d;

	while(true) {
		//화면에 프롬프트를 출력하고 키보드로 두 정수와 연산자를 입력 받는다.
		cout <<"두 정수와 연산자를 입력하세요>>";
		int x, y;
		char c;
		cin >> x >> y >> c;
		switch(c) {
			case '+' : a.setValue(x, y);
				cout << a.calculate();
				break;
			case '-' : s.setValue(x, y);
				cout << s.calculate();
				break;
			case '*' : m.setValue(x, y);
				cout << m.calculate();
				break;
			case '/' : d.setValue(x, y);
				cout << d.calculate();
				break;
		}
		cout << endl;
	}
}
