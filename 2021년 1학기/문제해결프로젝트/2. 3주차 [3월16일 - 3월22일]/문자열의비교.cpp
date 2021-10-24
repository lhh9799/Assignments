#include <cstdio>
#include <string>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

const int MAX_LENGTH = 100000;

class MyString {
	private :
		char *characters;	//������ �迭�� ������ ������ ������ ����
		int length;			//������ �迭�� ����

	public :
		MyString(const char *str) {								//������ ������ ���ڷ� �޴� ������ �Լ�
			this->length = strnlen(str, MAX_LENGTH);			//strnlen �Լ� : ���ڿ��� �ִ��� ���ڷ� �־� ���ڿ��� ���̰� �ִ��� ������ �ִ��� ����, ���� ������ ���ڿ��� ���� ����
			this->characters = new char[this->length];			//���ڵ��� ������ ������ �迭�� ���ڿ��� ���� ��ŭ �������� �Ҵ�

			for(int i=0; i<this->length; i+=1) {				//�ν��Ͻ��� length������ŭ �ݺ��Ͽ�
				this->characters[i] = str[i];					//���� ������ �迭�� ���Ҹ� �ν��Ͻ��� ������ �迭�� ����
			}
		}

		MyString(const string &original) {						//���ڿ� ������ ���ڷ� �޴� ������ �Լ�
			this->length = original.length();					//�Է¹��� ���ڿ��� ���̸� �� �ν��Ͻ��� length������ ����
			this->characters = new char[this->length];			//���ڵ��� ������ ������ �迭�� ���ڿ��� ���� ��ŭ �������� �Ҵ�

			for(int i=0; i<this->length; i+=1) {				//�ν��Ͻ��� length������ŭ �ݺ��Ͽ�
				this->characters[i] = original[i];				//���� ���ڿ��� ���Ҹ� �ν��Ͻ��� ������ �迭�� ����
			}
		}

		~MyString() {											//�Ҹ���
			delete []characters;								//�����Ҵ��� ������ �迭�� �޸� ����
		}

		/*line 39 ~ 75 : ������ ������ */
		bool operator < (const MyString &o) const {				//������� characters�� MyString�� �ν��Ͻ� o���� ���������� �ռ��ٸ� true, �׷��� �ʴٸ� false ����
			if(this->length == o.length)						//������� characters�� MyString�� �ν��Ͻ� o�� ���̰� ���ٸ� false ����
				return false;

			//�Ʒ� ������ ������� characters�� MyString�� �ν��Ͻ� o�� ���̰� �ٸ� ��� ����
			int n = min(this->length, o.length);				//������� characters�� MyString�� �ν��Ͻ� o�� �迭�� ���� �� ���� ���� n�� ����

			for(int i=0; i<n; i++) {							//������� characters�� MyString�� �ν��Ͻ� o�� �迭�� ���� �� ���� ����ŭ �ݺ��Ͽ�
				if(this->characters[i] > o.characters[i])		//������� characters�� ���� MyString�� �ν��Ͻ� o���� ũ�ٸ�(ASCII �� a : 97, b: 98) false ����
					return false;
				else if(this->characters[i] < o.characters[i])	//������� characters�� ���� MyString�� �ν��Ͻ� o���� �۴ٸ�(ASCII �� a : 97, b: 98) true ����
					return true;
			}
		}

		bool operator > (const MyString &o) const {				//MyString�� �ν��Ͻ� o�� ������� characters�� ���������� �ռ��ٸ� true, �׷��� �ʴٸ� false ����
			if(this->length == o.length)						//������� characters�� MyString�� �ν��Ͻ� o�� ���̰� ���ٸ� false ����
				return false;

			//�Ʒ� ������ ������� characters�� MyString�� �ν��Ͻ� o���� ª�� ��� ����
			int n = min(this->length, o.length);				//������� characters�� MyString�� �ν��Ͻ� o�� �迭�� ���� �� ���� ���� n�� ����

			for(int i=0; i<n; i++) {							//������� characters�� MyString�� �ν��Ͻ� o�� �迭�� ���� �� ���� ����ŭ �ݺ��Ͽ�
				if(this->characters[i] < o.characters[i])		//������� characters�� ���� MyString�� �ν��Ͻ� o���� �۴ٸ�(ASCII �� a : 97, b: 98) false ����
					return false;
				else if(this->characters[i] > o.characters[i])	//������� characters�� ���� MyString�� �ν��Ͻ� o���� ũ�ٸ�(ASCII �� a : 97, b: 98) true ����
					return true;
			}
		}

		bool operator == (const MyString &o) const {			//MyString�� �ν��Ͻ� o�� ������� characters�� ���������� �ռ��ٸ� true, �׷��� �ʴٸ� false ����
			int n = min(this->length, o.length);				//������� characters�� MyString�� �ν��Ͻ� o�� �迭�� ���� �� ���� ���� n�� ����(�� ���� ���� ���� �� �ۿ� ����)

			for(int i=0; i<n; i++) {							//������� characters�� MyString�� �ν��Ͻ� o�� �迭�� ���� �� ���� ����ŭ �ݺ��Ͽ�
				if(this->characters[i] != o.characters[i])		//������� characters�� ���� MyString�� �ν��Ͻ� o�� ���� �ʴٸ�(ASCII �� a : 97, b: 98) false ����
					return false;
			}
			return true;
		}
};

int main() {
	string s1;
	string s2;

	cin >> s1 >> s2;											//���ڿ� 2���� �Է� ����

	MyString mys1(s1);											//���ڿ� s1�� ���ڷ� �ϴ� MyString ��ü mys1 ����
	MyString mys2(s2);											//���ڿ� s2�� ���ڷ� �ϴ� MyString ��ü mys2 ����

	if(mys1 < mys2) {											//mys1�� mys2���� ���������� �ռ��� ���ڿ��̶�� �ֿܼ� -1 ���
		printf("-1");
	}
	else if(mys1 > mys2) {										//mys2�� mys1���� ���������� �ռ��� ���ڿ��̶�� �ֿܼ� 1 ���
		printf("1");
	}
	else {														//�� ���ڿ��� ��ġ�Ѵٸ� �ֿܼ� 0 ���
		printf("0");
	}

	return 0;
}

