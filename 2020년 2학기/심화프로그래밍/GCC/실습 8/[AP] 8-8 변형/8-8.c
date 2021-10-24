#include <stdio.h>

enum option {Recursive, Nonrecursive};

enum option select_option() {
	int choice;
	
	do{
		scanf("%d", &choice);
	} while(choice < 0 || choice > 1);
	
	return choice;
}

int factorial(int num, enum option option) {
	int rt = 1;
	
	if(option == 0) {
		if(num == 1)
			return 1;
		return num * factorial(num-1, option);
	}
	else {
		do{
			rt *= num;
		} while(--num > 0);
	}
	return rt;
}

int main() {
	int num;
	enum option choice;
	
	scanf("%d", &num);
	
	choice = select_option();
	printf("%d", factorial(num, choice));
	
	return 0;
}
