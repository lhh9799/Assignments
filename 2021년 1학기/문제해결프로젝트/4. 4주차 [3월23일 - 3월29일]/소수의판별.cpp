#include <cstdio>		//C언어의 stdio.h와 같음 C의 입출력 함수를 포함한 헤더파일 
#include <iostream>		//C++ 스트림을 포함한 헤더파일 
using namespace std;	//표준 이름공간을 사용함

/*
*약수는 쌍을 이룬다. 예를 들어 169가 양의 약수 a와 b를 가지고 있다고 하면 a * b = 169이다. 
*a * b = 169이므로 a와 b의 최댓값은 sqrt(169)인 13이다. 따라서 약수를 검사할 때 sqrt(입력값)까지만 검사하면 된다. 
*/
bool isPrime(int N) {
	int aliquot_count = 1;				//아래 반복문에서는 sqrt(N)까지 검사하기 때문에 N의 약수는 세지 않는다. 따라서 1을 초기값으로 지정한다.
	
	if(N == 1)							//1은 소수가 아니다. 아래 조건문에서 걸러줄 수 없으므로 비효율적이지만 반복문을 실행하기 전에 검사한다. 
		return false;
	
	for(int i=1; i*i <= N; i++) {		//0으로 나누지 않게 하기 위해 i를 0으로 초기화해서는 안된다. i를 2로 초기화하는 것은 일부 숫자에서 조건문을 실행하지 않기때문에 1로 초기화 한다.
		if(N % i == 0) {				//N이 i로 나누어 떨어진다면(i라는 약수를 갖는다면) 
			if(++aliquot_count >= 3)	//약수의 개수를 증가시키고 그 값이 3이상인지 검사해서 참이라면 
				return false;			//false 리턴 
		}
	}
	
	return true;						//약수의 개수가 3미만인 경우 true 리턴 
}

//소수인지 아닌지 판별한 결과에 따라 "YES" 또는 "NO"를 출력하는 함수 
void testcase(int caseIndex) {
	int n;								//입력받을 수 (이후 소수인지 아닌지 판별함) 
	scanf("%d", &n);					//정수 하나를 입력받음 
	
	bool result = isPrime(n);			//result변수에 n이 소수이면 true, 아니면 false가 저장됨 
	
	printf("Case #%d\n", caseIndex);	//화면에 테스트 케이스의 번호를 출력 
	
	if(result)							//isPrime함수의 리턴값인 result의 값이 참(n이 소수)이면 "YES" 출력 
		printf("YES\n");
	else								//거짓(n이 소수가 아님)이면 "NO" 출력 
		printf("NO\n");
}

int main() {
	int caseSize;						//테스트 케이스의 수 
	scanf("%d", &caseSize);				//테스트 케이스의 수를 입력받음 
	
	for(int caseIndex = 1; caseIndex <= caseSize; caseIndex += 1) {	//caseSize(테스트 케이스의 수)번 반복. 출력을 Case #1부터 시작하기 위해 초기값을 1, 조건을 caseSize 이하로 설정 
		testcase(caseIndex);										//케이스 인덱스를 인자로 testcase 함수 실행 
	}
	
	return 0;							//메인함수를 정상적으로 끝냄
}
