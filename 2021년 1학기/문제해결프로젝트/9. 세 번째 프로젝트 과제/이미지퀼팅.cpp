#include <vector>	//vector 클래스를 사용하기 위한 헤더파일(배열과의 차이점 : 가변형, 입출력 함수 제공)
#include <ctime>	//코드 실행시간 측정을 위한 헤더파일
#include <algorithm>//min_element함수를 사용하기 위한 헤더파일
#include <iostream>	//입출력 함수를 사용하기 위한 헤더파일
using namespace std;//표준 이름공간을 사용함

//이미지의 값을 입력받는 함수. 2차원 포인터를 참조변수로 받아 값을 수정 가능하게 함
void fill_array(int H, int W, int **&array) {
	array = new int *[H];		//세로 길이 H만큼 동적 할당

	for(int i=0; i<H; i++) {
		array[i] = new int [W];	//가로 길이 W만큼 동적 할당

		for(int j=0; j<W; j++) {
			cin >> array[i][j];	//값 입력 받음
		}
	}
}

//아래 방향으로 탐색해서 SSD를 계산하는 함수. SSD 벡터를 참조변수로 받아 수정 가능하게 함
void explore(int **B1, int **B2, int H, int W, int row, int col, int sum, vector <int> &SSD) {
	int diff = (B1[row][col] - B2[row][col]) * (B1[row][col] - B2[row][col]);	//1개 픽셀의 squared distance

	//마지막 열인 경우
	if(row == H-1) {
		SSD.push_back(sum + diff);
		return;
	}

	//0번 열인 경우
	if(col == 0) {
		explore(B1, B2, H, W, row+1, col, sum+diff, SSD);		//같은 열 아래 행 탐색
		if(W > 1) {												//오른쪽으로 이동할 열이 있는 경우
			explore(B1, B2, H, W, row+1, col+1, sum+diff, SSD);	//오른쪽 열 아래 행 탐색
		}
	}
	//가장 오른쪽 열이고 왼쪽으로 이동할 열이 있는 경우
	else if(col == W-1 && W > 1) {
		explore(B1, B2, H, W, row+1, col-1, sum+diff, SSD);		//왼쪽 열 아래 행 탐색
		explore(B1, B2, H, W, row+1, col, sum+diff, SSD);		//같은 열 아래 행 탐색
	}
	//가장자리 열이 아닌 경우(안쪽 열 탐색)
	else {
		explore(B1, B2, H, W, row+1, col-1, sum+diff, SSD);		//왼쪽 열 아래 행 탐색
		explore(B1, B2, H, W, row+1, col, sum+diff, SSD);		//같은 열 아래 행 탐색
		explore(B1, B2, H, W, row+1, col+1, sum+diff, SSD);		//오른쪽 열 아래 행 탐색
	}
}

int main() {
	int H, W;					//H: 높이(행의 수), W: 너비(열의 수). 두 수는 1이상 100이하의 수
	int **B1 = nullptr, **B2 = nullptr;	//B1: 왼쪽 이미지, B2: 오른쪽 이미지
	vector<int> SSD;			//SSD를 저장하는 벡터

	cin >> H >> W;				//H: 높이(행의 수), W: 너비(열의 수) 입력받음

	fill_array(H, W, B1);		//B1 입력받음
	fill_array(H, W, B2);		//B2 입력받음

	clock_t start = clock();	//시작 시간 저장

	for(int i=0; i<W; i++) {	//0번 열부터 마지막 열까지 반복하여
		explore(B1, B2, H, W, 0, i, 0, SSD);	//픽셀마다 squared distance와 SSD를 계산
	}

	//동적할당한 2차원 배열의 메모리 해제
	for(int i=0; i<H; i++) {
		delete []B1[i];	delete []B2[i];
	}
	delete []B1;	delete []B2;

	cout << *min_element(SSD.begin(), SSD.end()) << endl;	//최소 SSD 출력

	clock_t end = clock();		//종료 시간 저장
	cout << "실행시간: " << (double)(end - start) / CLOCKS_PER_SEC << "초";	//실행시간(단위: 초) 출력

	return 0;					//메인함수를 정상적으로 끝냄
}
