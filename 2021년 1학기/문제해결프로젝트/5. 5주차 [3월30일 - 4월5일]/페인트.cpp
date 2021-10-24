#include <cstdio>		//C언어의 stdio.h와 같음 C의 입출력 함수를 포함한 헤더파일
#include <vector>		//vector 클래스를 사용하기 위한 헤더파일(배열과의 차이점 : 가변형, 입출력 함수 제공)
using namespace std;	//표준 이름공간을 사용함

const int MAX_SEAT_NUMBER = 1000;	//좌석의 최대 수를 const 상수로 선언(값을 변경할 수 없음) 
const int MAX_COLOR_NUMBER = 100;	//색깔의 최대 수를 const 상수로 선언(값을 변경할 수 없음)

//좌석에 색칠할 가장 왼쪽, 오른쪽 좌석의 번호, 색깔의 번호를 저장하는 클래스
class Painting {
public :
	int left;	//칠할 가장 왼쪽 좌석의 번호
	int right;	//칠할 가장 오른쪽 좌석의 번호
	int color;	//칠할 색깔의 번호

	Painting() {}	//기본 생성자. 아래에 매개변수가 있는 생성자가 정의되어 있으므로 컴파일러가 기본생성자를 생성해주지 않는다. Painting 형 배열을 만들기 위해 기본 생성자 정의.

	Painting(int left, int right, int color) {	//매개변수 있는 생성자
		this->left = left;						//매개변수로 받은 left를 이 객체의 left에 저장
		this->right = right;					//매개변수로 받은 right를 이 객체의 right에 저장
		this->color = color;					//매개변수로 받은 color를 이 객체의 color에 저장
	}
};

//칠해진 색의 빈도를 계산하는 함수
void fillFrequencyTable(int data[], int n, int table[]) {
	for(int i=0; i<MAX_COLOR_NUMBER; i++) {	//MAX_COLOR_NUMBER(색깔의 최대 수)번 반복하여
		table[i] = 0;						//배열의 값을 0으로 초기화
	}

	for(int i=0; i<n; i++) {				//n(좌석의 수)번 반복하여
		table[data[i]]++;					//해당 색이 칠해진 횟수 증가
	}
}

//가장 많은 좌석이 칠해진 색의 번호, 가장 적은 좌석이 칠해진 색의 번호를 출력하는 함수
void solve(int n, int m, const Painting *paintings) {
	int *seats = new int[n];	//입력된 도색 정보를 바탕으로 seats 배열로 재구성함. 좌석의 수 만큼 동적으로 할당

	//처음에 모든 좌석은 0번 색으로 칠해져 있음
	for(int i=0; i<n; i++) {	//n(좌석의 수)번 반복하여
		seats[i] = 0;			//0번 색으로 초기화
	}

	for(int i=0; i<m; i++) {				//m(색칠을 할 방법의 수)번 반복하여
		const Painting &p = paintings[i];	//paintings[i]를 참조변수 p에 저장

		for(int j=p.left; j<=p.right; j++) {//해당 색이 칠해진 왼쪽부터 오른쪽 좌석의 번호까지 반복하여
			seats[j] = p.color;				//seats 배열의 값을 해당색으로 저장
		}
	}

	int *table = new int[MAX_COLOR_NUMBER];	//빈도를 저장할 배열을 색깔의 최대 수만큼 동적으로 할당
	fillFrequencyTable(seats, n, table);	//seats 배열과 n을 인자로 넘겨 table 배열에 빈도를 채워넣음

	int minColor = seats[0];				//가장 적게 등장한 색상을 첫 번째 색으로 초기화
	int maxColor = seats[0];				//가장 많이 등장한 색상을 첫 번째 색으로 초기화

	for(int color=0; color<MAX_COLOR_NUMBER; color++) {//MAX_COLOR_NUMBER(색깔의 최대 수)번 반복하여
		if(table[color] == 0) {				//아무 좌석에도 칠해져 있지 않은 색상인 경우
			continue;						//아래의 코드를 건너뛰고 다음 반복을 실행
		}
		if(table[minColor] > table[color]) {//color번째 색깔이 가장 적게 칠해진 색의 수보다 작다면
			minColor = color;				//최솟값 갱신
		}
		if(table[maxColor] < table[color]) {//color번째 색깔이 가장 많이 칠해진 색의 수보다 크다면
			maxColor = color;				//최댓값 갱신
		}
	}

	printf("%d\n", maxColor);
	printf("%d\n", minColor);

	delete []seats;							//동적할당한 배열의 메모리 해제
	seats = nullptr;						//배열을 가리키는 포인터에 저장된 주소값 삭제
}

int main() {
	int n, m;								//n : 좌석의 수, m : 색칠을 할 방법의 수
	scanf("%d %d", &n, &m);					//좌석의 수, 색칠을 할 방법의 수 입력받음

	Painting *paintings = new Painting[n];	//색칠 정보를 가지고 있는 Painting 클래스의 인스턴스 배열을 좌석의 수 만큼 동적으로 할당

	for(int i=0; i<m; i++) {				//m(색칠을 할 방법의 수)번 반복하여
		scanf("%d", &paintings[i].left);	//색칠할 가장 왼쪽 좌석의 번호 입력받음
		scanf("%d", &paintings[i].right);	//색칠할 가장 오른쪽 좌석의 번호 입력받음
		scanf("%d", &paintings[i].color);	//칠할 색깔의 번호 입력받음

		paintings[i].left -= 1;				//좌석의 번호는 1번부터 시작하지만 배열은 0번부터 시작하기 때문에 맞춰주기 위해 1을 감함
		paintings[i].right -= 1;			//좌석의 번호는 1번부터 시작하지만 배열은 0번부터 시작하기 때문에 맞춰주기 위해 1을 감함
	}

	solve(n, m, paintings);					//가장 많은 좌석이 칠해진 색의 번호, 가장 적은 좌석이 칠해진 색의 번호를 출력하는 solve함수 호출

	return 0;								//메인함수를 정상적으로 끝냄
}

