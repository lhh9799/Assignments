#include <cstdio>
#include <string>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

const int MAX_LENGTH = 100000;

class MyString {
	private :
		char *characters;	//문자형 배열을 저장할 문자형 포인터 변수
		int length;			//문자형 배열의 길이

	public :
		MyString(const char *str) {								//문자형 변수를 인자로 받는 생성자 함수
			this->length = strnlen(str, MAX_LENGTH);			//strnlen 함수 : 문자열과 최댓값을 인자로 넣어 문자열의 길이가 최댓값을 넘으면 최댓값을 리턴, 넘지 않으면 문자열의 길이 리턴
			this->characters = new char[this->length];			//문자들을 저장할 문자형 배열을 문자열의 길이 만큼 동적으로 할당

			for(int i=0; i<this->length; i+=1) {				//인스턴스의 length변수만큼 반복하여
				this->characters[i] = str[i];					//원본 문자형 배열의 원소를 인스턴스의 문자형 배열에 저장
			}
		}

		MyString(const string &original) {						//문자열 변수를 인자로 받는 생성자 함수
			this->length = original.length();					//입력받은 문자열의 길이를 이 인스턴스의 length변수에 저장
			this->characters = new char[this->length];			//문자들을 저장할 문자형 배열을 문자열의 길이 만큼 동적으로 할당

			for(int i=0; i<this->length; i+=1) {				//인스턴스의 length변수만큼 반복하여
				this->characters[i] = original[i];				//원본 문자열의 원소를 인스턴스의 문자형 배열에 저장
			}
		}

		~MyString() {											//소멸자
			delete []characters;								//동적할당한 문자형 배열의 메모리 해제
		}

		/*line 39 ~ 75 : 연산자 재정의 */
		bool operator < (const MyString &o) const {				//멤버변수 characters가 MyString형 인스턴스 o보다 사전순으로 앞선다면 true, 그렇지 않다면 false 리턴
			if(this->length == o.length)						//멤버변수 characters와 MyString형 인스턴스 o의 길이가 같다면 false 리턴
				return false;

			//아래 라인은 멤버변수 characters와 MyString형 인스턴스 o의 길이가 다른 경우 실행
			int n = min(this->length, o.length);				//멤버변수 characters와 MyString형 인스턴스 o의 배열의 길이 중 작은 값을 n에 저장

			for(int i=0; i<n; i++) {							//멤버변수 characters와 MyString형 인스턴스 o의 배열의 길이 중 작은 값만큼 반복하여
				if(this->characters[i] > o.characters[i])		//멤버변수 characters의 값이 MyString형 인스턴스 o보다 크다면(ASCII 예 a : 97, b: 98) false 리턴
					return false;
				else if(this->characters[i] < o.characters[i])	//멤버변수 characters의 값이 MyString형 인스턴스 o보다 작다면(ASCII 예 a : 97, b: 98) true 리턴
					return true;
			}
		}

		bool operator > (const MyString &o) const {				//MyString형 인스턴스 o가 멤버변수 characters가 사전순으로 앞선다면 true, 그렇지 않다면 false 리턴
			if(this->length == o.length)						//멤버변수 characters와 MyString형 인스턴스 o의 길이가 같다면 false 리턴
				return false;

			//아래 라인은 멤버변수 characters가 MyString형 인스턴스 o보다 짧은 경우 실행
			int n = min(this->length, o.length);				//멤버변수 characters와 MyString형 인스턴스 o의 배열의 길이 중 작은 값을 n에 저장

			for(int i=0; i<n; i++) {							//멤버변수 characters와 MyString형 인스턴스 o의 배열의 길이 중 작은 값만큼 반복하여
				if(this->characters[i] < o.characters[i])		//멤버변수 characters의 값이 MyString형 인스턴스 o보다 작다면(ASCII 예 a : 97, b: 98) false 리턴
					return false;
				else if(this->characters[i] > o.characters[i])	//멤버변수 characters의 값이 MyString형 인스턴스 o보다 크다면(ASCII 예 a : 97, b: 98) true 리턴
					return true;
			}
		}

		bool operator == (const MyString &o) const {			//MyString형 인스턴스 o가 멤버변수 characters가 사전순으로 앞선다면 true, 그렇지 않다면 false 리턴
			int n = min(this->length, o.length);				//멤버변수 characters와 MyString형 인스턴스 o의 배열의 길이 중 작은 값을 n에 저장(두 값은 서로 같을 수 밖에 없다)

			for(int i=0; i<n; i++) {							//멤버변수 characters와 MyString형 인스턴스 o의 배열의 길이 중 작은 값만큼 반복하여
				if(this->characters[i] != o.characters[i])		//멤버변수 characters의 값이 MyString형 인스턴스 o와 같지 않다면(ASCII 예 a : 97, b: 98) false 리턴
					return false;
			}
			return true;
		}
};

int main() {
	string s1;
	string s2;

	cin >> s1 >> s2;											//문자열 2개를 입력 받음

	MyString mys1(s1);											//문자열 s1을 인자로 하는 MyString 객체 mys1 생성
	MyString mys2(s2);											//문자열 s2을 인자로 하는 MyString 객체 mys2 생성

	if(mys1 < mys2) {											//mys1이 mys2보다 사전순으로 앞서는 문자열이라면 콘솔에 -1 출력
		printf("-1");
	}
	else if(mys1 > mys2) {										//mys2이 mys1보다 사전순으로 앞서는 문자열이라면 콘솔에 1 출력
		printf("1");
	}
	else {														//두 문자열이 일치한다면 콘솔에 0 출력
		printf("0");
	}

	return 0;
}

