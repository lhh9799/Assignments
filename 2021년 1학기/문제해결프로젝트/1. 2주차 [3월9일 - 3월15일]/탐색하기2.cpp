#include <stdio.h>
#include <string>
#include <iostream>
using namespace std;

void printIndexes(string school[], int n) {
	int first = -1;	//�������� ������ -1 
	int last = -1;	//�������� ������ -1 
	
	for(int i = 0; i<n; i++) {		//n(�ָ��̰� ���� ������ ó�� �������� ��)�� �ݺ��Ͽ� 
		if(school[i] == "AJOU") {	//�迭���� "AJOU"�� ��ġ�ϴ� �б����� ã�� ��� 
			if(first != -1)			//first ������ �̹� ������ ��� 
				last = i;			//last ������ ���� 
			else					//first ������ ���������� ���� ���("AJOU"�� ó�� ã�� ���) 
				first = last = i;	//first�� last ���� ��� ���� 
		}
	}
	
	if(first != -1) {				//-1�� �ƴ� ��� index���� 1���� �����ϵ��� ����� ���� 1�� ���� 
		first++;
		last++;
	}
	
	printf("%d %d\n", first, last);
}

int main() {
	int n;			//�ָ��̰� ���� ������ ó�� �������� ��
	char buff[11];	//�б����� �Է¹��� ������ �迭 
	string *school;	//�б����� ������ ���ڿ� �迭�� ������ ���� 
	
	scanf("%d", &n);
	school = new string[n];		//�迭�� ������ �� ��ŭ �迭�� �����Ҵ�
	
	for(int i = 0; i<n; i++) {	//n(�ָ��̰� ���� ������ ó�� �������� ��)�� �ݺ��Ͽ� 
		scanf("%s", buff);		//char�� �迭 buff������ ���� 
		school[i] = buff;		//buf������ ���� school�迭�� ���� 
	}
	
	printIndexes(school, n);
	
	delete []school;			//�����Ҵ��� �迭�� �޸� ����
	school = nullptr;			//�迭�� ����ġ�� �����Ϳ� ����� �ּҰ� ���� 
	
	return 0;
}
