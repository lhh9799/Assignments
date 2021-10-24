#include <stdio.h>

#define NUMBER 21

struct student {
	char name[NUMBER];
	int id;
	float grade;
};

int main() {
	struct student std;
	
	scanf("%[^\n] %d %f", std.name, &std.id, &std.grade);
	
	if(std.grade >= 3.5)
		printf("%d %s", std.id, std.name);
	else
		printf("failed");
	
	return 0;
}
