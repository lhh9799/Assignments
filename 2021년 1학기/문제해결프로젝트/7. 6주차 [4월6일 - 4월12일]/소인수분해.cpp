#include <cstdio>	//C언어의 stdio.h와 같음 C의 입출력 함수를 포함한 헤더파일
#include <vector>	//vector 클래스를 사용하기 위한 헤더파일(배열과의 차이점 : 가변형, 입출력 함수 제공)
using namespace std;//표준 이름공간을 사용함

//n의 약수들을 계산하여 벡터에 저장한 뒤 리턴하는 함수
vector<int> factorize(int n) {
	vector<int> factors;				//약수들을 저장할 벡터

	/*약수는 쌍을 이룬다. 예를 들어 169가 양의 약수 a와 b를 가지고 있다고 하면 a * b = 169이다.
	a * b = 169이므로 쌍을 이루는 수 중 작은 수가 가질 수 있는 최댓값은 sqrt(169)인 13이다. 따라서 약수를 검사할 때 sqrt(입력값)까지만 검사하고 쌍을 이루어 약수를 추가하면 연산횟수를 줄일 수 있다*/
	for(int div=2; div*div<=n; div+=1) {
		while(n % div == 0) {			//n이 div로 나누어 떨어진다면 div가 n의 약수라는 의미이므로
			factors.push_back(div);		//factors 벡터의 맨 뒤에 추가
			n /= div;					//피제수를 갱신
		}
	}
	if(n>1) {							//위 for문에서 마지막 루프를 실행한 뒤 div가 sqrt(n)보다 커서 n을 추가하지 못하는 경우가 있다. 28 -> 14 -> 7이 예이다.
		factors.push_back(n);			//따라서 n이 1보다 크다면 그 수를 약수를 저장하는 factors 벡터의 맨 뒤에 추가한다
	}

	return factors;						//약수 벡터 리턴
}

//테스트케이스의 번호와 약수를 저장한 벡터를 출력하는 함수
void process(int caseIndex) {
	int n;								//소인수 분해할 수
	scanf("%d", &n);					//소인수 분해할 수를 입력받음

	vector<int> factors = factorize(n);	//n의 약수들을 계산하여 factors 벡터에 저장

	printf("#%d:\n", caseIndex);		//테스트케이스의 번호를 출력
	for(int i=0; i<factors.size(); i++) {//factors 벡터의 원소의 수 만큼 반복하여
		if(i>0) {						//출력하는 원소가 첫 번째 원소가 아닌 경우
			printf(" ");				//앞에 공백(" ")을 출력
		}
		printf("%d", factors[i]);		//약수 출력
	}
	printf("\n");						//new line
}

int main() {
	int caseSize;			//테스트 케이스의 수
	scanf("%d", &caseSize);	//테스트 케이스의 수를 입력받음

	for(int caseIndex=1; caseIndex<=caseSize; caseIndex++) {	//caseSize(테스트 케이스의 수)번 반복. 출력을 Case #1부터 시작하기 위해 초기값을 1, 조건을 caseSize 이하로 설정
		process(caseIndex);	//caseIndex를 인자로 process 함수 실행
	}

	return 0;				//메인함수를 정상적으로 끝냄
}
