#include <ctime>		//코드 실행시간 측정을 위한 헤더파일
#include <iostream>		//입출력 함수를 사용하기 위한 헤더파일
using namespace std;	//표준 이름공간을 사용함

//매개변수로 받은 수의 자릿수를 세는 함수
int countCipher(unsigned int num) {
	int cipher = 0;		//자릿수 변수

	do {
		num /= 10;		//일의자리 수를 버림. 여기서 사용하는 num변수는 함수가 호출될 때 복사된 값이므로 원본값이 손상되지 않음
		cipher++;		//자릿수 변수 증가
	} while(num>0);		//한 자릿수가 될 때까지 나눔

	return cipher;		//자릿수 리턴
}

int main() {
	unsigned int A, B, B_copy, count = 0;	//A: 바꿀 수, B: 목표로 하는 수, B_copy: B의 사본(B의 변조를 막기 위함), count: A를 B로 바꾸는데 필요한 연산의 최소 횟수
											//1 < A < B < 10^9 이므로 int(-2,147,483,648 ~ 2,147,483,647)의 범위보다 큰 unsigned int(0 ~ 4,294,967,295) 사용
	cin >> A >> B;							//A와 B입력 받음
	clock_t start = clock();				//시작 시간 저장
	B_copy = B;								//B_copy에 B 대입(B의 변조 막기 위함)

/*A를 B로 바꾸는 것은 어렵습니다. 따라서 역으로 B를 A로 가공하는 것을 시도하고 불가능한 경우 -1, 가능한 경우 필요한 연산의 최솟값에 1을 더한 값을 출력할 것입니다.
* 아래 루프에서 B의 일의자리 수가 1인 경우 10으로 나눈 몫만을 B에 저장합니다.
* B의 일의자리 수가 짝수면 2로 나눕니다.
* B의 일의자리 수가 1이 아닌 홀수면 A를 가공하여 만들 수 없으므로 콘솔에 "-1"을 출력한 뒤 루프를 빠져나갑니다.
* B가 한 자릿수이면서 A와 같지 않은 경우 가공에 실패한 것이므로 콘솔에 "-1"을 출력한 뒤 루프를 빠져나갑니다.
*/

	while(B_copy >= A) {					//B_copy가 A 이상일 동안 반복
		if(B_copy % 10 == 1) {				//일의자리가 1인 경우
			B_copy /= 10;					//일의자리를 버림
			count++;						//연산횟수 1 증가
		}
		else if(B_copy % 2 == 0) {			//일의자리가 0 또는 짝수인 경우
			B_copy /= 2;					//B를 2로 나눔
			count++;						//연산횟수 1 증가
		}
		else if(B_copy % 10 == 3 || B_copy % 10 == 5 || B_copy % 10 == 7 || B_copy % 10 == 9) {	//일의자리가 1이 아닌 홀수인 경우 -1 리턴(가공 불가능함)
			cout << "-1" << endl;			//콘솔에 "-1" 출력
			break;							//루프를 빠져나감
		}

		if(B_copy == A) {					//A를 가공해 B를 만들 수 있는 경우
			cout << count+1 << endl;		//A를 B로 바꾸는데 필요한 연산의 최솟값에 1을 더한 값을 출력
			break;							//루프를 빠져나감
		}
		else if((countCipher(B_copy) == countCipher(A)) && (B_copy % A != 0)) {	//B가 한 자릿수이면서 A로 나누어 떨어지지 않는 경우(A 가공 실패한 경우)
			cout << "-1" << endl;			//콘솔에 "-1" 출력
			break;							//루프를 빠져나감
		}
	}

	clock_t end = clock();					//코드가 끝난 시간 저장
	cout << "실행시간: " << (double) (end - start) / CLOCKS_PER_SEC << "초" << endl;	//실행시간(단위: 초) 출력

	return 0;								//메인함수를 정상적으로 끝냄
}

