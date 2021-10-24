#include <iostream>	//입출력 함수를 사용하기 위한 헤더파일
#include <string>	//string 클래스의 length 함수를 사용하기 위한 헤더파일
#include <stack>	//stack 클래스를 사용하기 위한 헤더파일(특징: 리스트의 한 쪽 끝으로만 자료의 삽입과 삭제가 이루어짐. 후입선출)
using namespace std;//표준 이름공간을 사용함

//괄호를 문자열로 입력받아 올바른 괄호 문자열인지 아닌지를 리턴하는 함수
bool process() {
	string bracket;		//입력받을 괄호 문자열을 저장하는 문자열 변수
	stack<char> verify;	//입력받은 괄호 문자열을 저장할 스택

	cin >> bracket;		//괄호 문자열 입력받음

	for(int i=0; i<bracket.length(); i++) {	//괄호 문자열의 길이 만큼 반복하여
		if(bracket[i] == '(')				//i번째 문자가 '('라면
			verify.push(bracket[i]);		//스택에 추가
		else if(bracket[i] == ')') {		//i번째 문자가 ')'라면
			if(!verify.empty())				//스택이 비어있는지 확인한 뒤(비어있지 않다면 아래 코드 수행)
				verify.pop();				//가장 위 원소 삭제
			else							//스택이 비어있지 않다면(닫는 괄호가 부족한 것이므로)
				return false;				//false 리턴
		}
	}
	if(verify.size() > 0)					//위 반복문을 다 실행한 뒤에 verify 스택에 원소가 남아있다면 괄호쌍이 맞지 않는 것이므로
		return false;						//false 리턴

	return true;							//스택의 원소가 남아있지 않는 경우이므로 true 리턴
}

int main() {
	int caseSize;							//테스트 케이스의 수
	cin >> caseSize;						//테스트 케이스의 수를 입력받음

	for(int caseIndex=0; caseIndex<caseSize; caseIndex++) {	//caseSize(테스트 케이스의 수)번 반복하여
		if(process())						//process함수의 리턴값이 true이면
			cout << "YES" << endl;			//"YES" 출력
		else								//process함수의 리턴값이 false이면
			cout << "NO" << endl;			//"NO" 출력
	}

	return 0;								//메인함수를 정상적으로 끝냄
}
