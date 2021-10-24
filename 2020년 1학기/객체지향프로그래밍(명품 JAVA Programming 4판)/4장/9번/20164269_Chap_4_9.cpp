#include <iostream>
#include <string>
using namespace std;

class Person {
	string name;
	string tel;
public:
	Person() {name = ""; tel = "";}; //기본 생성자: name과 tel을 ""로 설정
	string getName() {return name;}
	string getTel() {return tel;}
	void set(string name, string tel) {this->name = name; this->tel = tel;}
	//함수 인자인 name, tel을 클래스 멤버인 name, tel에 저장. this 사용
};

class PersonManager {
	Person *p; //사람에 대한 정보를 저장 및 처리를 위한 객체 배열에 대한 포인터

public:
	//PersonManager() {} //기본 생성자

	PersonManager(int n) { //생성자: n은 배열의 크기, 즉 정보를 저장할 사람의 수
		p = new Person[n]; //Person의 배열을 동적으로 할당 받기
		//필요한 string 변수 선언 name, tel
		string name, tel;
		cout << "이름과 전화 번호를 입력해 주세요" << endl;

		for(int i=0; i<3; i++) {
			cout << "사람 " << i+1 << ">> ";
			cin >> name >> tel; //이름과 전화 번호를 name, tel에 입력 받기
			//입력받은 이름과 전화번호를 p[i].set(...)을 호출하여 p[i]에 저장
			p[i].set(name, tel);
		}
	}

	void show() {
		cout << "모든 사람의 이름은 ";
		for(int i=0; i<3; i++)
			cout << p[i].getName() << " ";
	}

	void search() {
		cout << "\n전화번호 검색합니다. 이름을 입력하세요>>";
		string searchname;
		cin >> searchname;

		for(int i=0; i<3; i++) {
			if(searchname == p[i].getName()) {
				cout << "전화번호는 " << p[i].getTel();
				break;
			}
		}
	}

	~PersonManager() { //소멸자
		//동적으로 할당 받은 배열(p)을 반환함 // 예제 4-9 참조
		delete p;
	}
};

int main() {
	// PersonManager 객체 선언: 3명의 person을 관리함
	PersonManager manager(3); //세 사람의 이름과 전화번호 입력 받음

	manager.show();
	manager.search();
}
