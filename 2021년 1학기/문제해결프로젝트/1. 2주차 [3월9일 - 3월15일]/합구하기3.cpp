#include <cstdio>
#include <iostream>
using namespace std;

int getRangeSumFromOne(int i) {
	/*
	�ڿ��� 1���� n������ ���� S�� ������
		S = 1 + 2 + 3 + �� + (n - 2) + (n - 1) + n
	+	S = n + (n - 1) + (n - 2) + ��+ 3 + 2 + 1
	------------------------------------------------------
		2S = (n+1) + (n+1) + (n+1) + ��+ (n+1) = (n+1) * n
	
	��S = n * (n + 1) / 2
	*/
	return i * (1+i) / 2;
}

long long getAnswer(int N) {
	long long total = 0;
	
	for(int i=1; i<=N; i++)	//1�̻��� �ڿ������� ���� ���ؾ� �ϹǷ� i�� �ʱⰪ�� 1, N������ ��� �ڿ����� ���� ���ϱ� ���� i�� N���� �۰ų� ���� ������ 
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
