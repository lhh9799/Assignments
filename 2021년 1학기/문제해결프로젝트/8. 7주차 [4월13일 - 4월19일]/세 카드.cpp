#include <stdio.h>	//표준입출력 라이브러리
#include <vector>	//vector 클래스를 사용하기 위한 헤더파일(배열과의 차이점 : 가변형, 입출력 함수 제공)
#include <algorithm>//탐색, 정렬, 셈, 수정 등 여러 함수를 포함하는 헤더파일
using namespace std;//표준 이름공간을 사용함

//입력받은 카드 중 당첨번호를 벡터에 저장하여 리턴하는 함수 
vector<int> getPossibleTargets(int n, int m, int *cards, int *targets) {
	vector<int> possibleTargets;	//만들 수 있는 당첨 번호들

	sort(cards, cards+n);			//입력받은 카드를 오름차순으로 정렬

	for(int i=0; i<m; i++) {		//m(검사할 후보 당첨번호의 수)번 반복하여 당첨번호와 일치하는지 비교
		int k = targets[i];			//i번째 당첨번호를 가져와 k에 저장
		bool possible = false;		//기본값을 false로 지정

		for(int j=0; j<n; j++) {	//n(카드의 수)번 반복하여
			int x = cards[j];		//첫 번째 카드 선택(j번째 카드를 x에 저장)

			for(int p=0; p<=j; p++) {	//p(j이하까지의 범위)번 반복하여(중복을 허용하므로 j'이하'임)
				int y = cards[p];		//두 번째 카드 선택(p번째 카드를 y에 저장)
				int z = k - (x + y);	//첫 번째와 두 번째 카드를 이미 선택했으므로 당첨이 되는데 필요한 세 번째 카드의 숫자인 z를 계산

				//이진탐색하여 비교 횟수를 줄임
				if(binary_search(cards, cards+n, z) == true) {	//세 번째 카드인 z를 찾았다면(당첨이 가능하므로)
					possible = true;	//possible변수를 true로 설정하고
					break;				//당첨 가능하므로 x에 대한 y와 z 쌍을 찾을 필요가 없음. 루프에서 탈출
				}
			}
			if(possible) {				//당첨 가능하면
				break;					//루프를 탈출하여 첫 번째 카드를 다시 뽑도록 함
			}
		}
		if(possible) {						//당첨 가능하면
			possibleTargets.push_back(k);	//당첨번호를 possibleTargets 벡터의 맨 뒤에 추가
		}
	}
	sort(possibleTargets.begin(), possibleTargets.end());	//당첨번호들을 오름차순으로 정렬
	return possibleTargets;				//possibleTargets 벡터 리턴
}

int main() {
	int n;	//카드의 수
	int m;	//검사할 후보 당첨번호의 수

	scanf("%d %d", &n, &m);		//카드의 수, 검사할 후보 당첨번호의 수 입력받음

	int *cards = new int[n];	//카드를 저장할 배열을 카드의 수 만큼 동적으로 할당
	int *targets = new int[m];	//당첨번호를 저장할 배열을 당첨번호의 수 만큼 동적으로 할당

	//각 카드 정보를 입력받는다
	for(int i=0; i<n; i++) {
		scanf("%d", &cards[i]);
	}

	//각 후보 당첨번호를 입력받는다
	for(int i=0; i<m; i++) {
		scanf("%d", &targets[i]);
	}

	vector<int> answers = getPossibleTargets(n, m, cards, targets);	//입력받은 후보 당첨 번호 중 당첨된 번호들을 answers 벡터에 저장

	if(answers.size() == 0) {	//벡터의 크기가 0이라면 즉 당첨번호가 없다면
		printf("NO");			//"NO"를 출력
	}
	else {						//당첨번호가 있다면
		for(int i=0; i<answers.size(); i++) {	//answers 벡터의 원소의 수 만큼 반복하여
			if(i>0) {							//0번 원소가 아니라면
				printf(" ");					//공백(" ")을 출력
			}
			printf("%d", answers[i]);			//중복 없는 시리얼 번호 출력
		}
	}

	delete[] cards;			//동적할당한 배열의 메모리 해제
	delete[] targets;		//동적할당한 배열의 메모리 해제
	cards = nullptr;		//배열을 가리키는 포인터에 저장된 주소값 삭제
	targets = nullptr;		//배열을 가리키는 포인터에 저장된 주소값 삭제

	return 0;				//메인함수를 정상적으로 끝냄
}
