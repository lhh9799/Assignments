#include <stdio.h>
#include <string>
#include <iostream>
using namespace std;

void printIndexes(string school[], int n) {
	int first = -1;	//존재하지 않으면 -1 
	int last = -1;	//존재하지 않으면 -1 
	
	for(int i = 0; i<n; i++) {		//n(주명이가 얻은 복무지 처리 데이터의 수)번 반복하여 
		if(school[i] == "AJOU") {	//배열에서 "AJOU"와 일치하는 학교명을 찾은 경우 
			if(first != -1)			//first 변수가 이미 수정된 경우 
				last = i;			//last 변수만 수정 
			else					//first 변수가 수정된적이 없는 경우("AJOU"를 처음 찾은 경우) 
				first = last = i;	//first와 last 변수 모두 수정 
		}
	}
	
	if(first != -1) {				//-1이 아닌 경우 index값이 1부터 시작하도록 만들기 위해 1을 더함 
		first++;
		last++;
	}
	
	printf("%d %d\n", first, last);
}

int main() {
	int n;			//주명이가 얻은 복무지 처리 데이터의 수
	char buff[11];	//학교명을 입력받을 문자형 배열 
	string *school;	//학교명을 저장할 문자열 배열의 포인터 변수 
	
	scanf("%d", &n);
	school = new string[n];		//배열의 원소의 수 만큼 배열을 동적할당
	
	for(int i = 0; i<n; i++) {	//n(주명이가 얻은 복무지 처리 데이터의 수)번 반복하여 
		scanf("%s", buff);		//char형 배열 buff변수에 저장 
		school[i] = buff;		//buf변수의 값을 school배열에 저장 
	}
	
	printIndexes(school, n);
	
	delete []school;			//동적할당한 배열의 메모리 해제
	school = nullptr;			//배열을 가리치는 포인터에 저장된 주소값 삭제 
	
	return 0;
}
