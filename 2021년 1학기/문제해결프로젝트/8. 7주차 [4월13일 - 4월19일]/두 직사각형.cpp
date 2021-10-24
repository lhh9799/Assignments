#include <iostream>	//입출력 함수를 사용하기 위한 헤더파일
#include <cstdio>	//C언어의 stdio.h와 같음 C의 입출력 함수를 포함하는 헤더파일
using namespace std;//표준 이름공간을 사용함

//두 직사각형이 교차하는 영역의 넓이를 리턴하는 함수
int get_area(int la, int ra, int ta, int ba, int lb, int rb, int tb, int bb) {
	int l, r, t, b;		//두 직사각형이 교차하는 영역으로 만든 직사각형의 x,y좌표

	l = max(la, lb);	//직사각형 a의 왼쪽 x좌표와 와 b의 왼쪽 x좌표 중 더 큰 값을 l에 저장
	r = min(ra, rb);	//직사각형 a의 오른쪽 x좌표와 와 b의 오른쪽 x좌표 중 더 작은 값을 r에 저장
	t = min(ta, tb);	//직사각형 a의 위 y좌표와 b의 위 y좌표 중 더 작은 값을 t에 저장
	b = max(ba, bb);	//직사각형 a의 아래 y좌표와 b의 아래 y좌표 중 더 큰 값을 b에 저장

	//두 직사각형이 교차하는 영역으로 직사각형을 만들었다고 했을 때
	if(l<=r && b<=t)	//왼쪽 x좌표가 오른쪽 x좌표보다 작고 아래 y좌표가 위 y좌표보다 작으면
		return ((r-l) * (t-b));	//교차하는 영역의 넓이를 리턴

	return 0;	//두 직사각형이 교차하는 영역이 없으므로 0을 리턴
}

//두 직사각형의 좌푤르 입력받고 교차하는 영역의 넓일ㄹ 출력하는 함수
void test_case() {
	int ax, ay, bx, by;	//점 A, B의 x,y좌표
	int px, py, qx, qy;	//점 P, Q의 x,y좌표

	scanf("%d %d %d %d", &ax, &ay, &bx, &by);	//점 A, B의 x,y좌표 입력받음
	scanf("%d %d %d %d", &px, &py, &qx, &qy);	//점 P, Q의 x,y좌표 입력받음

	int la, ra, ba, ta;	//직사각형 a
	la = min(ax, bx);	//점 A와 B의 x좌표 중 작은 값을 la에 저장
	ra = max(ax, bx);	//점 A와 B의 x좌표 중 큰 값을 ra에 저장
	ta = max(ay, by);	//점 A와 B의 y좌표 중 큰 값을 ta에 저장
	ba = min(ay, by);	//점 A와 B의 y좌표 중 작은 값을 ba에 저장

	int lb, rb, bb, tb;	//직사각형 b
	lb = min(px, qx);	//점 P와 Q의 x좌표 중 작은 값을 lb에 저장
	rb = max(px, qx);	//점 P와 Q의 x좌표 중 큰 값을 rb에 저장
	tb = max(py, qy);	//점 P와 Q의 y좌표 중 큰 값을 tb에 저장
	bb = min(py, qy);	//점 P와 Q의 y좌표 중 작은 값을 bb에 저장

	int answer = get_area(la, ra, ta, ba, lb, rb, tb, bb);	//직사각형 a와 b의 좌표를 인자로 넘겨 넓이 계산 후 answer에 저장

	printf("%d\n", answer);	//두 직사각형이 교차하는 영역의 넓이를 출력
}

int main() {
	int t;		//테스트 케이스의 수

	scanf("%d", &t);			//테스트 케이스의 수 입력받음

	for(int i=0; i<t; i++) {	//t(테스트 케이스의 수)번 반복하여
		test_case();			//두 직사각형이 교차하는 영역의 넓이 출력
	}

	return 0;	//메인함수를 정상적으로 끝냄
}
