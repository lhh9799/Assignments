#include <iostream>
using namespace std;

#include "Div.h"

void Div::setValue(int x, int y) {
	a = x; b = y;
}

int Div::calculate() {
	if(b==0) {
		cout << "0으로 나눌 수 없다" << endl;
		return -1;
	}
	return a / b;
	}
