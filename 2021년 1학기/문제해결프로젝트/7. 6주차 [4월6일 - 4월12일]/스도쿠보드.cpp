#include <cstdio>		//C언어의 stdio.h와 같음 C의 입출력 함수를 포함한 헤더파일
using namespace std;	//표준 이름공간을 사용함

const int MAX_ROW = 9;	//행의 최댓값인 9를 const 상수로 선언(값을 변경할 수 없음)
const int MAX_COL = 9;	//열의 최댓값인 9를 const 상수로 선언(값을 변경할 수 없음)

//열 번호, 행 번호, 그룹 번호, 칸의 번호를 계산하는 메소드가 정의된 클래스
class SudokuBoard {
public:
	//칸의 번호로 행의 번호를 계산하는 메소드
	int getRowByIndex(int index) {
		/*각 행은 1씩 증가하며 9개의 수로 이루어져 있다. 따라서 9로 나눈 몫을 가공하면 행 번호를 알 수 있다.
		 *단, 첫 수가 1부터 시작하기 때문에 이대로 나누면 마지막 열에 있는 수들은 원래의 행보다 +1된 값을 갖기 때문에
		 *첫 수인 1을 먼저 뺀 뒤 9로 나눈다. 마지막으로 결과값에 1을 더하여 시작 행의 번호를 1로 만들어 준다.
		 */
		return (index-1) / 9 + 1;		//행 번호 리턴
	}

	//칸의 번호로 열의 번호를 계산하는 메소드
	int getColByIndex(int index) {
		/*첫 번째 행에 있는 수만을 가지고 예를 들었을 때 1번은 1열, 6번은 6열에 있다는 것을 알 수 있다.
		 *그리고 그 아래에 있는 수들은 9씩 증가한 수들이므로 모듈러 연산을 통해 덜어낼 수 있다.
		 *따라서 index에 mod9 연산을 취하면 되는데 마지막 열은 0을 나머지로 가지기 때문에 먼저 1을 뺀 다음 mod9를 취한다.
		 *마지막으로 결과값에 1을 더하여 시작 열의 번호를 1로 만들어 준다.
		 */
		return (index - 1) % 9 + 1;		//열 번호 리턴
	}

	//칸의 번호로 그룹 번호를 계산하는 메소드
	int getGroupByIndex(int index) {
		int r = getRowByIndex(index);	//행의 번호를 r에 저장
		int c = getColByIndex(index);	//열의 번호를 c에 저장

		return getGroupByPosition(r, c);//그룹의 번호 리턴
	}

	//칸의 위치(행, 열)로 그룹 번호를 계산하는 메소드
	int getGroupByPosition(int row, int column) {
		/*이 함수에서는 행 번호를 기준으로 1~3번 행은 1, 4~6번 행은 2, 7~9번 행은 3을 left 값으로 갖는다.
		 *열 번호를 가공하여 offset값을 계산한다. 1~3번 열은 0, 4~6번 열은 1, 7~9번 열은 2를 갖는다.
		 *가장 왼쪽 그룹의 값에 offset을 더하여 최종 그룹의 번호를 계산하여 리턴한다.
		 */
		int left = ((row - 1) / 3) * 3 + 1;	//가장 왼쪽 그룹의 번호를 계산
		int offset = ((column - 1) / 3);	//왼쪽에서 떨어진 값 만큼 offset 값을 계산

		return left + offset;				//그룹의 번호 리턴
	}

	//칸의 위치(행, 열)로 칸의 번호를 계산하는 메소드
	int getIndexByPosition(int row, int column) {
		/*행의 번호가 1이면 최솟값 1, 최댓값 9를 갖는다.
		 *스도쿠보드 그림을 통해 *n행의 가장 왼쪽(최솟값)은 (row - 1) * 9임을 알 수 있다.
		 *따라서 열 번호로 가장 왼쪽의 값을 구하고 (행번호-1)을 더하여 해당 칸에 위치한 번호를 알 수 잇다.
		 *가장 왼쪽의 수는 1부터 시작하므로 마지막에 1을 더한다.
		 */
//		return (row - 1) * 9 + (column - 1) % 9 + 1;
		return (row - 1) * 9 + (column - 1) + 1;	//(column-1)은 0~8사이의 값만을 가지므로 모듈러 연산이 필요없다.
	}
};

void process(int caseIndex) {
	int index;				//열 번호, 행 번호, 그룹 번호를 알고 싶은 숫자
	scanf("%d", &index);	//열 번호, 행 번호, 그룹 번호를 알고 싶은 숫자를 입력받음

	SudokuBoard board = SudokuBoard();	//SudokuBoard형 인스턴스 board 생성

	//칸의 번호로 행, 열, 그룹 번호를 계산한다
	int row = board.getRowByIndex(index);
	int col = board.getColByIndex(index);
	int group = board.getGroupByIndex(index);

	printf("Case #%d:\n", caseIndex);		//테스트 케이스의 번호를 출력
	printf("%d %d %d\n", row, col, group);	//열 번호, 행 번호, 그룹 번호를 출력
}

int main() {
	int caseSize;				//테스트 케이스의 수
	scanf("%d", &caseSize);		//테스트 케이스의 수를 입력받음

	for(int caseIndex=1; caseIndex<=caseSize; caseIndex++) {	//caseSize(테스트 케이스의 수)번 반복. 출력을 Case #1부터 시작하기 위해 초기값을 1, 조건을 caseSize 이하로 설정
		process(caseIndex);										//caseIndex를 인자로 process 함수 실행
	}

	return 0;					//메인함수를 정상적으로 끝냄
}

