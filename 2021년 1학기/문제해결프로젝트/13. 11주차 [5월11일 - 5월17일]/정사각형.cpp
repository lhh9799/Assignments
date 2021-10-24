#include <iostream>	//입출력 함수를 사용하기 위한 헤더파일
#include <iomanip>	//setprecision함수를 사용하기 위한 헤더파일(부동 소수점의 유효자리 설정)
#include <vector>	//vector 클래스를 사용하기 위한 헤더파일(배열과의 차이점: 가변형, 입출력 함수 제공)
#include <cmath>	//max함수를 사용하기 위한 헤더파일
#include <set>		//set 클래스를 사용하기 위한 헤더파일(중복을 허용하지 않는 컨테이너. 균형 이진트리로 구현)
using namespace std;//표준 이름공간을 사용함

//점의 x좌표, y좌표, 인덱스 번호를 저장하고 제곱거리와 실수거리 계산, 우선순위가 정의되어 있는 클래스
class Point2D {
public:
	int x;		//점의 x좌표
	int y;		//점의 y좌표
	int index;	//점의 번호

	Point2D(int index, int x, int y) {	//index, x, y를 매개변수로 받는 생성자
		this->index = index;			//매개변수로 받은 index를 멤버변수 index에 저장
		this->x = x;					//매개변수로 받은 x를 멤버변수 x에 저장
		this->y = y;					//매개변수로 받은 y를 멤버변수 y에 저장
	}

	Point2D(int x, int y) {				//x, y를 매개변수로 받는 생성자
		this->index = 1;				//멤버변수 index의 값을 1로 설정
		this->x = x;					//매개변수로 받은 x를 멤버변수 x에 저장
		this->y = y;					//매개변수로 받은 y를 멤버변수 y에 저장
	}

	//두 좌표간의 제곱거리를 리턴하는 함수
	long long getSquaredDistanceTo(Point2D target) {
		long long dx = abs(this->x - target.x);
		long long dy = abs(this->y - target.y);

		return dx * dx + dy * dy;
	}

	//두 좌표간의 실수 거리를 리턴하는 함수
	double getDistanceTo(Point2D target) {
		long long sqd = this->getSquaredDistanceTo(target);

		return sqrt(sqd);
	}

	//각 좌표의 우선순위를 비교하기 위한 비교 연산자
	bool operator < (const Point2D& other) const {
		//x좌표가 다르다면 x좌표를 기준으로 비교
		if(this->x != other.x) {
			return this->x < other.x;
		}

		//x좌표가 같다면 y좌표를 기준으로 비교
		return this->y < other.y;
	}
};

//점 4개로 만들 수 있는 정사각형들 중 가장 큰 넓이를 리턴하는 함수
long long getMaximumSquareArea(int n, const vector<Point2D>& points) {
	long long answer = 0;		//정사각형의 넓이 중 최대값을 저장하는 변수

	//모든 점을 Set에 저장
	set<Point2D> pSet;			//default: less(오름차순), datatype이 class이므로 대소관계 정의 필요
	for(int i=0; i<n; i++) {	//n(좌표의 수)번 반복하여
		pSet.insert(points[i]);	//set컨테이너에 저장(중복 제거)
	}

	//임의의 a와 b 두 점을 잡음
	for(int i=0; i<n; i++) {		//n(좌표의 수)번 반복하여
		Point2D pa = points[i];		//Point2D형 변수 pa에 points 배열의 i번째 인스턴스(Point2D의 인스턴스) 저장 -> 첫 번째 좌표 선택
		for(int j=0; j<n; j++) {	//n(좌표의 수)번 반복하여
			Point2D pb = points[j];	//Point2D형 변수 pb에 points 배열의 j번째 인스턴스(Point2D의 인스턴스) 저장 -> 두 번째 좌표 선택

			if(i==j) continue;		//같은 점 제외(아래 코드를 실행하지 않음)

			//선분 pa-pb가 정사각형의 한 변이라고 하면 두 점의 거리(선분의 길이)의 제곱은 정사각형의 넓이가 된다.
			long long area = pa.getSquaredDistanceTo(pb);	//pa-pb를 선분으로 갖는 정사각형의 넓이를 area에 저장

			//이미 구한 사각형보다 넓이가 작을 수 밖에 없다면 건너뜀
			if(area < answer)
				continue;

			/*
			 * 		 i	  j
			 *      ___.____
			 *   j  |		| i
			 *      .       .점 pb
			 *   i  |       | j
			 *      |_____.__
			 * 		  j 점pa i
			 *
			 *파티고라스의 정리를 생각해 보면 편하다.
			 *정점 2개를 알고 있다면 정사각형을 2개 그릴 수 있다.(왼쪽 아래, 오른쪽 위)
			 *여기서는 왼쪽 아래로만 그린다.(오른쪽 위는 다른 정점 2개를 그릴 때 해결한다.)
			 *고정된 좌표 pa와 pb를 통해 그릴 수 있는 정사각형의 좌표를 그려본다.
			 */
			int dx = pb.x - pa.x;	//위 그림에서 i값
			int dy = pb.y - pa.y;	//위 그림에서 j값

			//위에서 구한 dx와 dy값을 이용해 점 pd와 pc의 좌표 계산
			Point2D pd(pa.x - dy, pa.y + dx);
			Point2D pc(pb.x - dy, pb.y + dx);

			//앞서 계산한 pd와 pc가 pSet에 존재한다면
			if(pSet.count(pc) > 0 && pSet.count(pd) > 0) {	//O(log2N)
				answer = max(answer, area);	//최대 정사각형의 넓이 갱신
			}
		}
	}

	return answer;	//점 4개로 만들 수 있는 정사각형들 중 가장 큰 넓이를 리턴하는 함수
}

void process(int caseIndex) {
	int n;		//좌표의 수 선언
	cin >> n;	//좌표의 수 입력받음

	vector<Point2D> points;	//점의 좌표를 저장하는 벡터

	for(int i=0; i<n; i++) {	//n(좌표의 수)번 반복하여
		int x, y;				//점의 x, y좌표 변수 선언
		cin >> x >> y;			//점의 x, y좌표 입력받음
		points.push_back(Point2D(i, x, y));	//Point2D형 인스턴스를 생성하여 points 벡터의 맨 뒤에 추가
	}

	long long answer = getMaximumSquareArea(n, points);	//점 4개로 만들 수 있는 정사각형들 중 가장 큰 넓이를 계산하여 answer에 저장

	//fixed: 소수점을 고정시켜 표현(fixed가 없는 경우 정수부와 소수부의 자릿수를 합하여 자릿수 출력), setprecision: 2자리까지 표현
	cout << fixed << setprecision(2) << answer << endl;	//점 4개로 만들 수 있는 정사각형들 중 가장 큰 넓이를 소수점 아래 2자리까지 출력
}

int main() {
	int caseSize;			//테스트 케이스의 수
	cin >> caseSize;		//테스트 케이스의 수 입력받음

	for(int caseIndex = 0; caseIndex < caseSize; caseIndex++) {	//caseSize(테스트 케이스의 수)번 반복하여
		process(caseIndex);	//점 4개로 만들 수 있는 정사각형들 중 가장 큰 넓이를 계산하여 소수점 아래 2자리까지 출력하는 함수 호출
	}

	return 0;				//메인함수를 정상적으로 끝냄
}
