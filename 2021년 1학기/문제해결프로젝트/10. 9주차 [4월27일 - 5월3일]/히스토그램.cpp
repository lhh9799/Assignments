#include <iostream>	//입출력 함수를 사용하기 위한 헤더파일
#include <vector>	//vector 클래스를 사용하기 위한 헤더파일(배열과의 차이점 : 가변형, 입출력 함수 제공)
#include <stack>	//stack 클래스를 사용하기 위한 헤더파일(특징: 리스트의 한 쪽 끝으로만 자료의 삽입과 삭제가 이루어짐. 후입선출)
#include <cmath>	//abs, max함수를 사용하기 위한 헤더파일
using namespace std;//표준 이름공간을 사용함

//직사각형 모양 기둥의 왼쪽, 오른쪽 x좌표와 높이를 저장하는 클래스
class Histogram {
public:
	int height;		//히스토그램의 높이
	int leftX;		//인덱스 혹은 히스토그램의 왼쪽 변의 x좌표
	int rightX;		//히스토그램의 오른쪽 변의 x좌표

	Histogram() {}	//기본 생성자. 벡터를 만들기 위해 선언

	Histogram(int index, int height) {	//매개변수 있는 생성자
		this->leftX = index;			//매개변수로 받은 index를 이 객체의 index에 저장
		this->rightX = this->leftX + 1;	//각 히스토그램은 너비가 1이므로 rightX는 leftX + 1
		this->height = height;			//매개변수로 받은 height를 이 객체의 height에 저장
	}
};

//히스토그램 내부에 존재할 수 있는 직사각형의 최대 넓이를 리턴하는 함수
long long getLargestRectangleArea(const vector<Histogram> &histograms) {
	long long answer = 0;	//최대 직사각형의 넓이(최대 100억이므로 long long으로 선언)

	//현재 우측으로 확장 가능성이 있는 직사각형들
	stack<Histogram> stk;

	//구현상 편의를 위해 가장 왼쪽에 높이 0까지 가상의 직사각형 추가
	stk.push(Histogram(-1, 0));

	for(int i=0; i<histograms.size()+1; i++) {	//가장 왼쪽에 Histogram형 인스턴스를 추가했으므로 size+1번 반복
		//왼쪽부터 오른쪽 히스토그램까지 차례로
		Histogram h;
		if(i<histograms.size()) {				//가장 오른쪽 직사각형이 아닌 경우
			h = histograms[i];					//i번째 직사각형이 h
		}
		else {									//가장 오른쪽 직사각형인 경우
			//구현상 편의를 위해 가장 오른쪽에 높이 0까지 가상의 히스토그램 추가
			h = Histogram(histograms.size(), 0);//가장 오른쪽 직사각형의 x좌표, 높이는 0인 Histrogram이 h
		}

		//h(헤더)의 높이가 기존의 직사각형보다 작다면 더 넓은 직사각형을 만들 수 없으므로 아래 루프를 실행(최대넓이 찾기)
		//stk스택의 원소의 수가 2미만이면 사각형을 만들 수 없음(사각형 1개를 만들기 위한 x좌표는 최소 2개 필요)
		while(stk.size() > 1 && stk.top().height > h.height) {
			Histogram lh = stk.top();	//스택의 최상단에 있는 원소(h에서 시작하여 왼쪽방향에 있는 직사각형)을 lh에 저장
			stk.pop();					//lh보다 왼쪽에 있는 직사각형을 포함하여 넓이를 계산하기 위해 스택의 최상단 원소를 제거

			//그 이전의 히스토그램(왼쪽 확장의 끝)
//			Histogram bh = stk.top();

			//현재 추가된 h의 바로 왼쪽까지 확장중이었다.
//			long long width = abs(h.leftX - bh.rightX);	//bh의 오른쪽 x좌표와 h의 왼쪽 x좌표의 차를 width에 저장
//			long long width = abs(h.leftX - lh.leftX);	//lh의 왼쪽 x좌표와 h의 왼쪽 x좌표의 차를 width에 저장
			long long width = h.leftX - lh.leftX;	//lh의 왼쪽 x좌표와 h의 왼쪽 x좌표의 차를 width에 저장
			long long height = lh.height;				//bh보다 낮은 lh의 높이를 height에 저장
			long long area = width * height;			//직사각형의 넓이 계산

			//최대값 갱신
			answer = max(answer, area);
		}

	//h를 새로이 추가한다.
	stk.push(h);
	}

	return answer;										//직사각형의 최대 넓이 리턴
}

//입력받은 히스토그램 내부에 존재할 수 있는 직사각형의 최대 넓이를 출력하는 함수
void process(int caseIndex) {
	int n;		//히스토그램을 구성하는 직사각형 모양 기둥의 수
	cin >> n;	//히스토그램을 구성하는 직사각형 모양 기둥의 수 입력받음

	vector<Histogram> histograms;	//히스토그램을 구성하는 직사각형 모양 기둥의 높이를 저장하는 벡터
	for(int i=0; i<n; i++) {		//직사각형 모양 기둥의 수번 반복하여
		int height;					//직사각형 모양 기둥의 높이 선언
		cin >> height;				//직사각형 모양 기둥의 높이 입력받음
		histograms.push_back(Histogram(i, height));//Histogram형 인스턴스 생성, 높이: height)후 histograms벡터의 맨 뒤에 추가
	}

	long long answer = getLargestRectangleArea(histograms);	//최대 직사각형의 넓이를 answer에 저장(최대 100억이므로 long long으로 선언)
	cout << answer << endl;	//최대 직사각형의 넓이 출력
}

int main() {
	int caseSize;			//테스트 케이스의 수
	cin >> caseSize;		//테스트 케이스의 수

	for(int caseIndex=0; caseIndex<caseSize; caseIndex++) {	//caseSize(테스트 케이스의 수)번 반복하여
		process(caseIndex);	//직사각형의 최대 넓이 계산 및 출력
	}

	return 0;				//메인함수를 정상적으로 끝냄
}
