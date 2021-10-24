#include <iostream>		//입출력 함수를 사용하기 위한 헤더파일
#include <ctime>		//코드 실행시간 측정을 위한 헤더파일
#include <cstring>		//memset 함수를 사용하기 위한 헤더파일
using namespace std;	//표준 이름공간을 사용함

/*
*전남이의 총 점수를 리턴하는 함수
*알고리즘 : 전남이는 한 번에 한 명의 친구를 상대한다. 한 명의 친구와 게임이 끝나면 다음 친구를 상대한다. 즉 안쪽 루프는 R번 반복되고 바깥쪽 루프는 N번 반복된다.
*/
int scoring(char chonnam_card[], string friend_card[], int N, int R)  {	//chonnam_card : 전남이가 낸 모양을 저장하는 문자형 배열, friend_card : 친구가 낸 모양을 저장하는 문자열 배열, N : 친구의 수, R : 라운드 수
	int total_score = 0;												//전남이의 최종 점수

	for(int i=0; i<N; i++) {
		for(int j=0; j<R; j++) {
			if(chonnam_card[j] == friend_card[i][j])					//전남이와 친구가 낸 모양이 같음 -> 비김 -> 1점
				total_score += 1;
			else if(chonnam_card[j] == 'S' && friend_card[i][j] == 'P')	//전남 : 가위, 친구 : 보 -> 승 -> 2점
				total_score += 2;
			else if(chonnam_card[j] == 'S' && friend_card[i][j] == 'R')	//전남 : 가위, 친구 : 주먹 -> 패 -> 0점
				total_score += 0;
			else if(chonnam_card[j] == 'P' && friend_card[i][j] == 'S')	//전남 : 보, 친구 : 가위 -> 패 -> 0점
				total_score += 0;
			else if(chonnam_card[j] == 'P' && friend_card[i][j] == 'R')	//전남 : 보, 친구 : 주먹 -> 승 -> 2점
				total_score += 2;
			else if(chonnam_card[j] == 'R' && friend_card[i][j] == 'S')	//전남 : 주먹, 친구 : 가위 -> 승 -> 2점
				total_score += 2;
			else if(chonnam_card[j] == 'R' && friend_card[i][j] == 'P')	//전남 : 주먹, 친구 : 보 -> 패 -> 0점
				total_score += 0;
		}
	}

	return total_score;													//최종 점수 리턴
}

/*
*전남이가 얻을 수 있는 최고 점수를 리턴하는 함수
*알고리즘 : 전남이가 낼 수 있는 모양의 경우의 수를 배열에 저장한다. 매 라운드마다 전남이가 낼 수 있는 모양들과 이미 친구들이 낸 모양들을 비교해 어떤 모양을 냈을 때 가장 높은 점수를 받는지 계산한 후, 얻을 수 있는 최고 점수에 합한다.
*
*---예시---
*	[1라운드]		[2라운드]		[3라운드]		[4라운드]
*친구 1: SSPP		SSPP		SSPP		SSPP
*친구 2: RSRP		RSRP		RSRP		RSRP
*친구 3: PSPR		PSPR		PSPR		PSPR
*전남:   ?		 ?			  ?			   ?
*
*1라운드 ?에 {가위, 보, 주먹}를 직접 대입하여 가장 높은 점수를 받는 패를 계산한 후 얻을 수 있는 최고 점수에 합한다.
*모든 라운드를 위와 같은 방법으로 반복한다.
*이는 3중 for 문으로 구현할 수 있다. 가장 안쪽 반복문은 전남이가 낼 수 있는 모양의 수인 3번. 가운데에 있는 반복문은 친구의 수인 N번. 가장 바깥쪽에 있는 반복문은 R번 반복하면 된다.
*/
int best_scoring(string friend_card[], int N, int R) {							//friend_card : 친구가 낸 모양을 저장하는 문자열 배열, N : 친구의 수, R : 라운드 수
	int best_score = 0;															//전남이가 얻을 수 있는 최고 점수
	int temp_score[3];															//전남이가 각각 '가위', '보', '주먹'을 내서 얻은 점수를 저장하는 배열
	char possible_card[3] = {'S', 'P', 'R'};									//전남이가 낼 수 있는 모양의 경우의 수를 배열에 저장해서 재사용 가능하도록 함

	for(int i=0; i<R; i++) {													//총 R라운드 까지 있으므로 전남이가 내야 할 모양의 수를 R개 구해야 함
		memset(temp_score, 0, sizeof(temp_score));								//해당 배열은 이후 반복문에서 다시 사용되므로 배열을 0으로 초기화함

		for(int j=0; j<N; j++) {												//친구의 수만큼 반복
			for(int k=0; k<3; k++) {											//전남이가 낼 수 있는 모양이 3가지(가위, 바위, 보) 이므로 3번 반복
				if(possible_card[k] == friend_card[j][i])						//전남이와 친구가 낸 모양이 같음 -> 비김 -> 1점
					temp_score[k] += 1;
				else if(possible_card[k] == 'S' && friend_card[j][i] == 'P')	//전남 : 가위, 친구 : 보 -> 승 -> 2점
					temp_score[k] += 2;
				else if(possible_card[k] == 'S' && friend_card[j][i] == 'R')	//전남 : 가위, 친구 : 주먹 -> 패 -> 0점
					temp_score[k] += 0;
				else if(possible_card[k] == 'P' && friend_card[j][i] == 'S')	//전남 : 보, 친구 : 가위 -> 패 -> 0점
					temp_score[k] += 0;
				else if(possible_card[k] == 'P' && friend_card[j][i] == 'R')	//전남 : 보, 친구 : 주먹 -> 승 -> 2점
					temp_score[k] += 2;
				else if(possible_card[k] == 'R' && friend_card[j][i] == 'S')	//전남 : 주먹, 친구 : 가위 -> 승 -> 2점
					temp_score[k] += 2;
				else if(possible_card[k] == 'R' && friend_card[j][i] == 'P')	//전남 : 주먹, 친구 : 보 -> 패 -> 0점
					temp_score[k] += 0;
			}
		}
		//최고점 계산
		if(temp_score[0] >= temp_score[1] && temp_score[0] >= temp_score[2])		//전남이가 "가위"를 내야 가장 높은 점수를 받을 수 있는 경우 해당 라운드에서 가위를 내서 받은 점수를 최고 점수에 합한다.
			best_score += temp_score[0];
		else if(temp_score[1] >= temp_score[0] && temp_score[1] >= temp_score[2])	//전남이가 "보"를 내야 가장 높은 점수를 받을 수 있는 경우 해당 라운드에서 보를 내서 받은 점수를 최고 점수에 합한다.
			best_score += temp_score[1];
		else if(temp_score[2] >= temp_score[0] && temp_score[2] >= temp_score[1])	//전남이가 "주먹"을 내야 가장 높은 점수를 받을 수 있는 경우 해당 라운드에서 주먹을 내서 받은 점수를 최고 점수에 합한다.
			best_score += temp_score[2];
	}

	return best_score;																//전남이가 받을 수 있는 최고 점수를 리턴
}

int main() {
	int R, N;					//R : 라운드 수, N : 친구의 수
	char *chonnam_card;			//전남이의 패를 저장할 문자형 배열의 포인터 변수
	string *friend_card;		//친구의 패를 저장할 문자열 배열의 포인터 변수

	cin >> R;					//라운드 수를 입력받음
	chonnam_card = new char[R];	//전남이가 각 라운드에 낸 모양을 저장할 배열을 라운드 수 만큼 동적으로 할당

	for(int i=0; i<R; i++)		//R(라운드 수)번 반복하여
		cin >> chonnam_card[i];	//전남이가 각 라운드에 낸 모양을 입력받음

	cin >> N;					//친구의 수 입력받음
	friend_card = new string[N];//친구들이 낸 모양을 저장할 배열을 친구의 수 만큼 동적으로 할당

	for(int i=0; i<N; i++) 		//N(친구의 수)번 반복하여
		cin >> friend_card[i];	//친구들이 낸 모양을 문자열 배열에 입력받음

	clock_t start = clock();	//시작 시간 저장

	cout << scoring(chonnam_card, friend_card, N, R) << endl;	//전남이의 총 점수를 출력
	cout << best_scoring(friend_card, N, R) << endl;			//전남이가 얻을 수 있는 최고 점수를 출력
	cout << endl;												//실행시간(단위: 초) 출력

	delete []chonnam_card;	//동적할당한 배열의 메모리 해제
	delete []friend_card;	//동적할당한 배열의 메모리 해제
	chonnam_card = nullptr;	//배열을 가리치는 포인터에 저장된 주소값 삭제
	friend_card = nullptr;	//배열을 가리치는 포인터에 저장된 주소값 삭제

	clock_t end = clock();	//코드가 끝난 시간 저장

	cout << "실행시간: " << (double) (end - start) / CLOCKS_PER_SEC << "초" << endl;	//실행시간(단위: 초) 출력

	return 0;				//메인함수를 정상적으로 끝냄
}
