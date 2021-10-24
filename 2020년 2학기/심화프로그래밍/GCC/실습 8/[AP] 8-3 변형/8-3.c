#include <stdio.h>

#define swap(type, a, b) do{type t = a; a = b; b = t;} while(0)
enum which {integer, realnumber};

enum which select_type() {
		int num;
		
		do{
			scanf("%d", &num);
		} while(num < 0 || num > 1);
	return num;
}

void execute(enum which choice) {
	if(choice == 0) {
		int a, b;
		
		scanf("%d %d", &a, &b);
		if(a > b)
			swap(int, a, b);
		printf("%d %d", a, b);
	}
	else {
		float a, b;
		
		scanf("%f %f", &a, &b);
		if(a > b)
			swap(float, a, b);
		printf("%.2f %.2f", a, b);
	}
}

int main() {
	int type;
	enum which choice;
	
	choice = select_type();
	execute(choice);
	
	return 0;
}
