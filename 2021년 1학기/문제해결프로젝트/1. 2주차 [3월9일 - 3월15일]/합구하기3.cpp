#include <cstdio>
#include <iostream>
using namespace std;

int getRangeSumFromOne(int i) {
	/*
	자연수 1부터 n까지의 합을 S로 놓으면
		S = 1 + 2 + 3 + … + (n - 2) + (n - 1) + n
	+	S = n + (n - 1) + (n - 2) + …+ 3 + 2 + 1
	------------------------------------------------------
		2S = (n+1) + (n+1) + (n+1) + …+ (n+1) = (n+1) * n
	
	∴S = n * (n + 1) / 2
	*/
	return i * (1+i) / 2;
}

long long getAnswer(int N) {
	long long total = 0;
	
	for(int i=1; i<=N; i++)	//1이상인 자연수들의 합을 구해야 하므로 i의 초기값은 1, N이하의 모든 자연수의 합을 구하기 위해 i는 N보다 작거나 같을 때까지 
		total += getRangeSumFromOne(i);
	
	return total;
}

int main() {
	int n;
	
	scanf("%d", &n);
	
	long long answer = getAnswer(n);
	
	printf("%lld\n", answer);
	
	return 0;
}
