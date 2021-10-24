#include <stdio.h>

#define NUMBER 21

struct student {
	char name[NUMBER];
	int height;
	float weight;
	long schols;
};

int main() {
	struct student std;
	
	scanf("%s %d %f %ld", std.name, &std.height, &std.weight, &std.schols);
	printf("name = %s\n", std.name);
	printf("height = %d\n", std.height);
	printf("weight = %.2f\n", std.weight);
	printf("schols = %ld\n", std.schols);
	
	return 0;
}
