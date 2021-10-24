#include <cstdio>	//C언어의 stdio.h와 같음 C의 입출력 함수를 포함한 헤더파일
#include <vector>	//vector 클래스를 사용하기 위한 헤더파일(배열과의 차이점 : 가변형, 입출력 함수 제공)
using namespace std;//표준 이름공간을 사용함

const int MAX_N = 1000000;		//어떤 수 N의 최댓값을 const 상수로 선언(값을 변경할 수 없음)
vector<int> FIBONACCI_TABLE;	//피보나치 수열을 저장할 벡터 FIBONACCI_TABLE 선언

//미리 피보나치 수열을 계산해 벡터에 저장하는 함수
vector<int> makeFibonacciTable(int n) {
	const int MOD = 100000000;	//마지막 8자리 수를 추출하기 위한 장치

	vector<int> ret(n+1);		//벡터 ret의 크기를 MAX_N + 1로 지정(크기를 1000000로 지정하면 999999번 인덱스까지만 생성되기 때문)
	ret[1] = 0;					//피보나치 수열의 1번째 숫자는 0
	ret[2] = 1;					//피보나치 수열의 2번째 숫자는 1

	for(int i=3; i<=n; i++) {			//1번과 2번은 연산할 필요가 없으므로 i는 3부터 시작. n번재 수까지 계산해야 하므로 n이하 일 때까지 반복
		ret[i] = ret[i-1] + ret[i-2];	//두 번째항 뒤의 모든 항은 바로 앞 두 항의 합인 수열임
		ret[i] %= MOD;					//피보나치 수의 마지막 8자리 숫자만을 저장하기 위해 MOD(100000000)로 나눈 나머지를 저장
	}

	return ret;							//바로 앞 두 항의 수를 더한 뒤 8자리만 추출한 수를 리턴
}

//n번째 피보나치 수를 리턴하는 함수
int getFibo(int n) {
	int answer = FIBONACCI_TABLE[n];	//계산되어있는 피보나치 수열 벡터에서 n번째 수를 answer에 저장

	return answer;						//n번째 피보나치 수(answer) 리턴
}

int main() {
	FIBONACCI_TABLE = makeFibonacciTable(MAX_N);				//MAX_N번째까지의 피보나치 수열을 벡터 FIBONACCI_TABLE에 저장

	int caseSize;					//테스트 케이스의 수(1이상 10만 이하)
	scanf("%d", &caseSize);			//테스트 케이스의 수 입력받음

	for(int caseIndex=1; caseIndex<=caseSize; caseIndex++) {	//caseSize(테스트 케이스의 수)번 반복. 출력을 1번부터 하기 때문에 조건을 caseSize 이하로 설정
		int n;						//확인하고자 하는 수(n번째 수)
		scanf("%d", &n);			//n번째 수 입력받음

		int answer = getFibo(n);	//n번째 수를 answer에 저장
		printf("%d\n", answer);		//n번째 수 출력
	}

	FIBONACCI_TABLE.clear();		//벡터 FIBONACCI_TABLE의 모든 원소 삭제

	return 0;						//메인함수를 정상적으로 끝냄
}
