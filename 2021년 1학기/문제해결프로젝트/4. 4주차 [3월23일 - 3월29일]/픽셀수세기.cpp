#include <cstdio>	//C언어의 stdio.h와 같음 C의 입출력 함수를 포함한 헤더파일
#include <iostream>	//C++ 스트림을 포함한 헤더파일
using namespace std;//표준 이름공간을 사용함

//x,y 좌표가 원 안에 있는지 검사하는 함수
bool isInside(long long x, long long y, long long R) {
	long long sqd = x*x + y*y;	//원의 방정식에서 r^2에 해당하는 값을 sqd에 저장

	if(sqd < R*R)				//sqd가 R^2보다 작음 -> x,y 좌표가 원의 내부에 있음 -> true 리턴
		return true;
	return false;				//외부에 있으면 false 리턴
}

//원의 반지름의 픽셀 수를 입력받고 테스트 케이스의 번호와 원에 포함되는 픽셀의 수를 출력하는 함수
void testcase(int caseIndex) {
	long long R;		//계산하고자 하는 원의 반지름의 픽셀 수
	long long count=0;	//실제 원 안에 포함되는 픽셀의 수

	scanf("%lld", &R);	//long long의 서식 지정자는 %lld임
	long long y = R;	//이후 반복문에서 연산횟수를 줄이기 위해 y에 R값을 저장함

	for(long long x=0; x<=R; x++) {	//원을 4등분하여 x=0인 값부터 증가하며 비교
		for(; y>=0; y--) {			//y=R인 값부터 감소하며 비교(y=R로 초기화 하면 불필요한 연산량 많아짐(어차피 원 밖에 있음))
			if(isInside(x, y, R)) {	//(x,y)좌표가 원 안에 들어간다면 y+1값을 count변수에 더한 뒤 안쪽 for문을 탈출하고 바깥쪽 for문을 진행함(더 작은 y값은 당연히 원 안에 포함되기 때문)
				count += y + 1;		//완전하지 않은 픽셀때문에 1을 더함
				break;
			}
		}
	}

	printf("#%d\n", caseIndex);		//테스트 케이스의 번호를 출력
	printf("%lld\n", count * 4);	//사분면이 4개이므로 *4한 값을 출력함
}

int main() {
	int caseSize;			//테스트케이스의 수
	scanf("%d", &caseSize);	//테스트케이스의 수 입력받음

	for(int caseIndex=1; caseIndex <= caseSize; caseIndex+=1) {	//caseSize(테스트 케이스의 수)번 반복. 출력을 #1부터 시작하기 위해 초기값을 1, 조건을 caseSize 이하로 설정
		testcase(caseIndex);									//케이스 인덱스를 인자로 testcase 함수 실행
	}

	return 0;				//메인함수를 정상적으로 끝냄
}
