#include <iostream>	//입출력 함수를 사용하기 위한 헤더파일
#include <set>		//set 클래스를 사용하기 위한 헤더파일(중복을 허용하지 않는 컨테이너. 균형 이진트리로 구현)
using namespace std;//표준 이름공간을 사용함

int main() {
	int N;		//주어질 정수들의 총 개수
	cin >> N;	//주어질 정수들의 총 개수 입력받음

	set<int> s;	//등장한 정수들을 저장하는 set 컨테이너

	for(int i=0; i<N; i++) {	//n(정수들의 수)번 반복하여
		int X;		//중복 여부를 검사할 정수 선언
		cin >> X;	//중복 여부를 검사할 정수 입력받음

		//이미 앞서 등장한 적 있는 숫자의 경우
		if(s.count(X) > 0) {				//찾는 수가 있다면, s.count(x) = 1 즉 (s.count > 0) == true
			cout << "DUPLICATED" << endl;	//한 줄에 "DUPLICATED" 출력
		}
		//처음 등장한 숫자의 경우
		else {
			s.insert(X);			//set에 X를 등록
			cout << "OK" << endl;	//한 줄에 "OK" 출력
		}
	}
	return 0;
}
