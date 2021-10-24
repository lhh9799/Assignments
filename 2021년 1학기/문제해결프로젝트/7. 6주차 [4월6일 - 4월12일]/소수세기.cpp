#include <cstdio>	//C언어의 stdio.h와 같음 C의 입출력 함수를 포함한 헤더파일
#include <vector>	//vector 클래스를 사용하기 위한 헤더파일(배열과의 차이점 : 가변형, 입출력 함수 제공)
using namespace std;//표준 이름공간을 사용함

//소수인지 아닌지를 판별하는 함수, 에라토스테네스의 체 알고리즘을 구현한 함수가 정의된 클래스
class Sieve {
public:
	int maximumValue;		//체의 최댓값
	vector<bool> isPrime;	//소수인지 아닌지를 저장하는 isPrime 벡터 선언

	//maximumValue를 매개변수로 받는 생성자
	Sieve(int maximumValue) {
		this->maximumValue = maximumValue;				//매개변수로 받은 maximumValue를 멤버변수 maximumValue에 저장
		this->isPrime.assign(maximumValue + 1, false);	//기존 벡터를 지우고 false값을 (maximumValue + 1)개 가지는 벡터로 초기화(크기를 maximumValue로 지정하면 maximumValue-1번 인덱스까지만 생성되기 때문)
		this->fillSieve();								//에라토스테네스의 체 알고리즘을 구현한 멤버함수 실행
	}

	//소수인지 아닌지를 리턴하는 함수
	bool isPrimeNumber(int num) const {	//함수명 뒤의 const의 의미: 해당 함수에서 멤버변수를 읽기만 함
		return this->isPrime[num];		//소수인지 아닌지를 저장하는 isPrime벡터의 index 번의 값을 리턴
	}

	//에라토스테네스의 체 알고리즘을 구현하는 함수
	bool fillSieve() {
		isPrime.assign(this->maximumValue, true);	//기존 벡터를 지우고 true값을 maximumValue개 가지는 벡터로 초기화
		isPrime[0] = isPrime[1] = false;			//0과 1은 소수가 아니므로(소수의 정의) false값을 저장

		for(int num=2; num<=maximumValue; num++) {	//0과 1은 계산할 필요가 없으므로 2부터 시작. 최댓값인 maximumValue까지 반복
			if(isPrime[num] == false) {				//num이 소수가 아니라면
				continue;							//다시 소수인지 판별할 필요가 없으므로 아래 for문을 건너뜀
			}
			//위 if문에서 num이 소수가 아닌 경우는 걸러짐 => num은 소수 => num의 배수들을 다시 걸러내야 함
			//num * num 미만의 수들은 이전 반복문에서 이미 걸러졌음
			//따라서 num * num부터 maximumValue 까지 mul을 num만큼 증가시키며 소수 검사를 실행한다
			for(long long mul = (long long) num * num; mul <= maximumValue; mul+=num) {	//mul을 num * num으로 초기화함. num(maximumValue)은 1000000 이하의 수이므로 mul의 최댓값은 1000000000000(1조)임
																						//따라서 mul은 약 21억까지 표현 가능한 int가 아닌 약 922경까지 표현 가능한 long long 으로 선언해야 함
				int index = (int)mul;				//mul <= maximumValue 제한때문에 mul은 int의 범위를 넘어서지 않았다. 위에서 long long으로 선언한 이유는 num*num을 저장할 때 일시적으로 int의 범위를 벗어날 수 있었기 때문
													//mul을 int로 명시적 캐스팅하여 int형 index에 저장
				isPrime[index] = false;				//index는 '소수가 아님'으로 갱신
			}
		}
	}
};

//from 이상 to 이하인 수 중 소수인 수를 벡터에 저장해 리턴하는 함수
vector<int> getAllPrimeNumbers(int from, int to, const Sieve &sieve) {
	vector<int> primes;					//소수를 저장할 벡터 primes 선언

	for(int num=from; num<=to; num++) {	//사용자가 입력한 L과 R사이를 순회하며
		if(sieve.isPrimeNumber(num)) {	//num이 소수라면
			primes.push_back(num);		//primes벡터의 맨 뒤에 num을 삽입
		}
	}

	return primes;						//소수들을 저장한 벡터를 리턴
}

void process(int caseIndex, const Sieve &sieve) {
	int L, R;							//소수의 개수를 셀 범위. L: 시작값, R: 끝값
	scanf("%d %d", &L, &R);				//시작값, 끝값을 입력받음

	vector<int> allPrimeNumbers = getAllPrimeNumbers(L, R, sieve);	//L 이상 R 이하인 수 중 소수인 수를 allPrimeNumbers 벡터에 저장

	printf("Case #%d:\n", caseIndex);	//테스트케이스의 번호를 출력
	printf("%d\n", (int)allPrimeNumbers.size());	//L 이상 R 이하인 수 중 소수인 수의 개수를 출력
}

int main() {
	const int MAX_VALUE = 1000000;	//R의 최댓값인 1000000을 const 상수로 선언(값을 변경할 수 없음)
	Sieve sieve = Sieve(MAX_VALUE);	//MAX_VALUE를 인자로 Sieve형 인스턴스 sieve 생성

	int caseSize;					//테스트 케이스의 수
	scanf("%d", &caseSize);			//테스트 케이스의 수를 입력받음

	for(int caseIndex=1; caseIndex<=caseSize; caseIndex++) {	//caseSize(테스트 케이스의 수)번 반복. 출력을 Case #1부터 시작하기 위해 초기값을 1, 조건을 caseSize 이하로 설정
		process(caseIndex, sieve);	//caseIndex를 인자로 process 함수 실행
	}

	return 0;						//메인함수를 정상적으로 끝냄
}
