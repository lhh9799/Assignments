#include <ctime>	//코드 실행시간 측정을 위한 헤더파일
#include <algorithm>//sort함수를 사용하기 위한 헤더파일
#include <iostream>	//입출력 함수를 사용하기 위한 헤더파일
using namespace std;//표준 이름공간을 사용함

//N이 2의 몇 승인지 계산(연산의 횟수). 값에 의한 호출이기 때문에 원본 N의 값은 바뀌지 않음
int exponent(int N) {
	int count = 0;

	do {
		N /= 2;
		count++;
	} while (N > 1);

	return count;
}

int main() {
	int N;						//행렬의 행(열)의 수
	int repetition;				//필요한 작업의 횟수
	int answer;					//문제에 대한 해답(마지막에 남은 수)
	int*** matrix = nullptr;	//원본 행렬과 222-풀링을 연산한 행렬을 저장하는 배열을 가리키는 포인터 변수. matrix[0]은 원본 행렬

	cin >> N;					//행렬의 행(열)의 수 입력받음
	repetition = exponent(N);	//필요한 작업의 횟수 계산

	matrix = new int** [2];		//행렬 2개를 번갈아가며 연산하기 위해 3차원 배열의 높이를 2로 선언
	matrix[0] = new int* [N];	//원본행렬을 저장하기 위해 세로길이 N만큼 동적할당
	matrix[1] = new int* [N];	//가공행렬을 저장하기 위해 세로길이 N만큼 동적할당

	for (int i = 0; i < N; i++) {
		matrix[0][i] = new int[N];	//원본행렬을 저장하기 위해 가로길이 N만큼 동적할당
		matrix[1][i] = new int[N];	//가공행렬을 저장하기 위해 가로길이 N만큼 동적할당

		for (int j = 0; j < N; j++) {
			cin >> matrix[0][i][j];	//원본행렬 입력받음
		}
	}

	clock_t start = clock();				//시작 시간 저장

	/* 알고리즘: 기존의 행렬에서 숫자 4개씩 그룹으로 묶습니다.
	 * 추출한 4개의 숫자를 val 배열에 저장한 뒤 sort함수로 정렬한 뒤 두 번째로 큰 수 val[2]를 새로운 행렬에 저장합니다.
	 * 새로 저장할 행렬의 가로(=세로 길이)길이를 절반으로 갱신한 뒤 다시 연산합니다.
	 * 이를 repetition 횟수만큼 반복합니다.
	 */

	for (int i = 1; i <= repetition; i++) {	//222-풀링을 연산한 행렬은 1번부터 저장됨(원본행렬이 0번)
		int val[4];							//각 그룹에서 추출할 4개의 수를 저장할 배열 선언
		int group_num = (N / 2) * (N / 2);	//그룹의 수: (N의 절반)의 제곱

		for (int j = 0; j < group_num; j++) {//그룹의 수번 반복하여
			/*
			 * val[0]	val[1]
			 * val[2]	val[3]
			 * 의 형태를 띰
			 */
			val[0] = matrix[(i + 1) % 2][j / (N / 2) * 2][j % (N / 2) * 2];			//왼쪽 위
			val[1] = matrix[(i + 1) % 2][j / (N / 2) * 2][j % (N / 2) * 2 + 1];		//오른쪽 위
			val[2] = matrix[(i + 1) % 2][j / (N / 2) * 2 + 1][j % (N / 2) * 2];		//왼쪽 아래
			val[3] = matrix[(i + 1) % 2][j / (N / 2) * 2 + 1][j % (N / 2) * 2 + 1];	//오른쪽 아래

			sort(val, val + 4);	//각 그룹에서 추출한 4개의 수를 오름차순 정렬

			matrix[i%2][j / (N / 2)][j % (N / 2)] = val[2];	//두 번째로 큰 수들을 새로운 행렬에 저장
		}
		N /= 2;								//행렬의 가로 길이(=세로 길이) 갱신
		answer = matrix[i%2][0][0];			//정답 백업
	}

	cout << answer << endl;	//마지막에 남은 수 출력

	//동적할당한 3차원 배열의 메모리 해제
	for (int i=0; i <2; i++) {
		delete[] matrix[i];
	}
	delete[]matrix;			//동적할당한 배열의 메모리 해제
	matrix = nullptr;		//배열을 가리키는 포인터에 저장된 주소값 삭제

	clock_t end = clock();					//코드가 끝난 시간 저장
	cout << "실행시간: " << (double)(end - start) / CLOCKS_PER_SEC << "초";	//실행시간(단위: 초) 출력

	return 0;
}
