#include <cstdio>	//C언어의 stdio.h와 같음 C의 입출력 함수를 포함하는 헤더파일
#include <cmath>	//sqrt함수를 포함하는 헤더파일
#include <climits>	//INT_MAX의 값이 정의되어 있는 헤더파일
#include <iostream>	//C++ 스트림을 포함한 헤더파일
using namespace std;//표준 이름공간을 사용함

//천체의 x좌표, y좌표와 천체사이의 유클리드 거리를 구하는 함수를 가진 클래스
class Point2D {
private :
	int x;	//x좌표를 저장할 변수
	int y;	//y좌표를 저장할 변수

public :
	Point2D(int x=0, int y=0) {									//매개변수 있는 생성자. 생성자가 없는 경우 기본값으로 x에 0, y에 0을 저장한다.
		this -> x = x;
		this -> y = y;
	}

	int getSquaredDistaneTo(const Point2D &target) const {		//유클리드 거리를 계산하는 함수
		//target을 참조변수로 받아 함수를 호출한 인스턴스의 x, y 좌표와의 유클리드 거리를 계산한 후 리턴. dx와 dy는 제곱할 것이기 때문에 이후 제곱하기 때문에 절댓값은 취하지 않았다.
		int dx = this -> x - target.x;							//x좌표 거리의 차
		int dy = this -> y - target.y;							//y좌표 거리의 차

		return dx*dx + dy*dy;									//유클리드 거리 리턴
	}

	double getDistanceTo(const Point2D &target) const {			//거리(sqrt(유클리드 거리))를 계산하는 함수
		double sqd = (double) this->getSquaredDistaneTo(target);//클래스에 정의되어 있는 getSquaredDistanceTo 함수를 호출해 유클리드 거리를 계산한 후 sqd에 저장

		return sqrt(sqd);										//계산된 sqrt(유클리드 거리)에 제곱근을 취해 리턴
	}
};

int main() {
	int n;							//하늘에 떠 있는 천체의 수(2이상 1000이하의 자연수)
	Point2D *points;				//Point2D형 인스턴스들의 배열을 가리키는 포인터 변수

	scanf("%d", &n);				//하늘에 떠 있는 천체의 수 입력받음
	points = new Point2D[n];		//하늘에 떠 있는 천체의 정보를 저장할 배열을 천체의 수 만큼 동적으로 할당

	for(int i=0; i<n; i++) {		//n(하늘에 떠 있는 천체의 수)번 반복하여
		int x, y;					//정수형 변수 x, y를 선언
		scanf("%d %d", &x, &y);		//x, y에 좌표를 입력받음

		points[i] = Point2D(x, y);	//x, y정보를 인자로 Point2D의 생성자를 호출하여 객체 생성 및 points변수에 저장
	}

	int min_sqd = INT_MAX;			//min_sqd(천체의 거리의 최솟값)를 INT_MAX(int 형식 변수의 최대값(2147483647))으로 초기화함
	int min_cnt = 0;				//가장 가까운 두 천체의 거리만큼 떨어진 천체 쌍의 수

	//아래 2중 for문은 i가 계속 증가하면서 자신보다 작은 범위의 j와 비교한다. 이렇게 하면 자기 자신과 비교하지 않고 천체를 중복해서 비교하지 않는다.(연산량 1/2로 감소)
	for(int i=0; i<n; i++) {
		for(int j=0; j<i; j++) {
			int sqd = points[i].getSquaredDistaneTo(points[j]);//points[j]를 인자로 Point2D 클래스에 정의되어 있는 유클리드 거리를 계산하는 함수를 호출하여 리턴값을 sqd에 저장
			if(sqd < min_sqd) {			//리턴된 값이 최소거리보다 작다면
				min_sqd = sqd;			//최소거리를 갱신
				min_cnt = 1;			//최소거리만큼 떨어진 천체 쌍의 수 갱신
			}
			else if(sqd == min_sqd) {	//리턴된 값이 최소거리와 같다면
				min_cnt++;				//최소거리만큼 떨어진 천체 쌍의 수 갱신
			}
		}
	}

	double distance = sqrt(min_sqd);	//min_sqd(유클리드 거리)에 제곱근을 취해 가장 가까운 두 천체의 거리를 계산
	printf("%.1f\n", distance);			//가장 가까운 두 천체의 거리를 소수점 첫 번재 자리까지 출력
	printf("%d\n", min_cnt);			//그 거리만큼 떨어진 천체 쌍의 수를 출력

	delete []points;					//동적할당한 배열의 메모리 해제
	points = nullptr;					//배열을 가리키는 포인터에 저장된 주소값 삭제

	return 0;							//메인함수를 정상적으로 끝냄
}

