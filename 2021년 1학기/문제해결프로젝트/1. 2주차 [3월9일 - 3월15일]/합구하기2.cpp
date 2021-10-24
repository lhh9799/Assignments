#include <stdio.h>
#include <iostream>
using namespace std;

void solve(int data[], int n, int p, int q) {
	int count = 0, sum = 0;	//sum : 놀이기구의 탑승 제한 체중을 넘지 않는 동아리 회원들의 체중의 합, count : 놀이기구의 탑승 제한 체중을 넘지 않는 동아리 회원들의 수 
	
	for(int i=0; i<n; i++) {
		if(data[i] <= p) {	//동아리 회원의 체중이 놀이기구의 탑승 제한 체중을 넘지 않는다면
			sum += data[i];	//기존 몸무게의 합에 합산 
			count++;		//회원의 수 갱신
		}
	}
	
	printf("%d %d\n", count, sum);	//놀이기구 체중 제한에 걸리지 않은 회원의 수와 그들이 몸무게의 총합을 공백으로 구분하여 출력 
	
	if(sum <= q)	//탑승 제한 체중을 넘지 않는 동아리 회원들의 체중의 합이 놀이기구의 최대 하중을 넘지 않는다면 
		printf("YES");
	else			//최대 하중을 넘는다면 
		printf("NO");
}

int main() {
	int n, p, q;	//n : 동아리 회원의 수, p : 놀이기구의 탑승 제한 체중, q : 놀이기구의 최대 하중 
	int *data;		//동아리 회원의 체중을 저장할 정수형 배열의 포인터 변수 
	
	scanf("%d %d %d", &n, &p, &q);
	data = new int[n];			//동아리 회원의 수 만큼 배열을 동적으로 할당 
	
	for(int i=0; i<n; i++) {	//n(동아리 회원의 수)번 반복하여 
		scanf("%d", &data[i]);	//동아리 회원의 체중을 입력 받음
	}
	
	solve(data, n, p, q);		//결과를 계산하는 함수
	
	delete []data;	//동적할당한 배열의 메모리 해제 
	data = nullptr;	//배열을 가리치는 포인터에 저장된 주소값 삭제 
	
	return 0;
}
