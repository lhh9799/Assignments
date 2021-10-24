#include <cctype>	//isalpha 함수를 사용하기 위한 헤더파일(A~Z: 1, a~z: 2, 그 외: 0 리턴)
#include <string>	//getline 함수를 사용하기 위한 헤더파일(공백(" ")도 입력받도록)
#include <map>		//map 클래스를 사용하기 위한 헤더파일(각 노드가 key와 value 쌍으로 이루어진 트리. 중복을 허용하지 않음. 오름차순 정렬)
#include <algorithm>//min, max 함수를 사용하기 위한 헤더파일
#include <ctime>	//코드 실행시간 측정을 위한 헤더파일
#include <iostream>	//입출력 함수를 사용하기 위한 헤더파일
using namespace std;//표준 이름공간을 사용함

int main() {
	string str1, str2, temp = "";				//str1, str2: 입력받을 문자열 / temp: 부분집합에 추가할 문자열
	map<string, int> map1, map2;				//map1, map2: str1, str2에서 유효한 문자열(순수 알파벳)을 추출해 저장하는 맵
	map<string, int> intersection, union_set;	//intersection: 교집합 맵, union_set: 합집합 맵
	int intersection_count = 0;					//부분집합의 원소의 수
	int union_count = 0;						//합집합의 원소의 수
	int answer = 65536;							//자카드 유사도(집합 A와 집합 B가 모두 공집합일 경우에는 나눗셈이 정의되지 않으니 따로 J(A, B) = 1로 정의한다.) -> 1 * 65536

	//두 문자열 입력받음
	getline(cin, str1);
	getline(cin, str2);

	clock_t start = clock();	//시작 시간 저장

	for(unsigned int i=0; i<str1.length()-1; i++) {		//str1길이 - 1까지 반복(i+1번까지 접근하기 때문)
		if(isalpha(str1[i]) && isalpha(str1[i+1])) {	//두 글자 모두 알파벳이면
			temp = tolower(str1[i]);					//첫 번째 문자를 소문자로 바꿈
			temp += tolower(str1[i+1]);					//두 번째 문자를 소문자로 바꾼뒤 문자열에 추가
			map1[temp]++;								//맵의 value 증가
		}
	}

	for(unsigned int i=0; i<str2.length()-1; i++) {		//str2길이 - 1까지 반복(i+1번까지 접근하기 때문)
		if(isalpha(str2[i]) && isalpha(str2[i+1])) {	//두 글자 모두 알파벳이면
			temp = tolower(str2[i]);					//첫 번째 문자를 소문자로 바꿈
			temp += tolower(str2[i+1]);					//두 번째 문자를 소문자로 바꾼뒤 문자열에 추가
			map2[temp]++;								//맵의 value 증가
		}
	}

	/*
	 *[교집합 찾기]
	 *중복된 값만 찾으면 되므로 어느 맵을 기준으로 비교를 해도 상관없음
	 *길이가 짧은 맵을 기준으로 비교하면 긴 맵에 원소가 남아있겠지만, 더 이상 짧은 맵에 값이 없으므로 중복될 수 없음(비교 대상 없음)
	 */
	for(auto it : map1) {											//map1의 모든 key를 가지고 순회
		int map1_count = map1.find(it.first)->second;				//map1에 있는 유효한 문자열의 개수를 map1_count에 저장

		if(map2.find(it.first) != map2.end()) {						//find함수는 키 값이 존재하지 않으면 end를 리턴함 -> find의 리턴값이 end()가 아니면
			int map2_count = map2.find(it.first)->second;			//map2애 있는 map1의 유효한 문자열의 개수를 map2_count에 저장
			int duplication_count = min(map1_count, map2_count);	//교집합이므로 "최솟값"을 duplication_count에 저장

			intersection[it.first] = duplication_count;				//두 맵 둘 다 가지고 있는 부분집합 정보 저장(문자열, 개수)
			intersection_count += duplication_count;				//교집합 원소의 수 증가(다중집합이므로 1씩이 아닌 duplication_count를 더해야 함)
		}
	}

	/*
	 *[합집합 찾기]
	 *1. map1과 map2의 값을 한곳에 모두 복사(map 컨테이너이므로 key값이 중복해서 들어가지 않음)
	 *2. map1에 해당 원소가 몇 개 존재하는지 검색
	 *3. map2에 해당 원소가 몇 개 존재하는지 검색
	 *4. 둘 중 큰 값을 합집합에 저장(key: 문자열, value: 개수)
	 */
	union_set.insert(map1.begin(), map1.end());
	union_set.insert(map2.begin(), map2.end());
	for(auto it : union_set) {								//합집합의 모든 key를 가지고 순회
		int map1_count = 0, map2_count = 0;					//최댓값을 찾아야 하므로 매번 0으로 초기화(0은 해당 원소 없음을 의미)

		//아래 두 if문 중 하나는 반드시 실행됨(union_set에 존재하는 맵은 map1, map2에서 가져왔기 때문)
		if(map1.find(it.first) != map1.end())				//find함수는 키 값이 존재하지 않으면 end를 리턴함 -> find의 리턴값이 end()가 아니면
			map1_count = map1.find(it.first)->second;		//map1에 존재하는 해당 원소의 수 map1_count에 저장

		if(map2.find(it.first) != map2.end())				//find함수는 키 값이 존재하지 않으면 end를 리턴함 -> find의 리턴값이 end()가 아니면
			map2_count = map2.find(it.first)->second;		//map2에 존재하는 해당 원소의 수 map2_count에 저장

		int duplication_count = max(map1_count, map2_count);//합집합이므로 "최댓값"을 duplication_count에 저장
		union_set[it.first] = duplication_count;			//합집합 map의 value 정정
		union_count += duplication_count;					//합집합 원소의 수 증가(다중집합이므로 1씩이 아닌 duplication_count를 더해야 함)
	}

	if(union_count != 0)	//교집합이 존재한다면 자카드 유사도를 계산
		//65536 * intersection_count(최대: 999) -> 65,470,464 -> int형으로 커버 가능
		answer = 65536 * intersection_count / union_count;	//자카드 유사도 * 65536 -> 소수점 아래 버림

	cout << answer << endl;	//연산결과 출력

	clock_t end = clock();	//종료 시간 저장
	cout << "실행시간: " << (double)(end - start) / CLOCKS_PER_SEC << "초";	//실행시간(단위: 초) 출력

	return 0;				//메인함수를 정상적으로 끝냄
}
