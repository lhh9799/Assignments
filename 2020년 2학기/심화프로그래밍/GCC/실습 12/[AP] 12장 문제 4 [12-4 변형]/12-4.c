#include <stdio.h>

typedef struct {
	char name[64];
	int height;
	float weight;
	long schols;
} Student;

void swap_Student(Student *x, Student *y) {
	Student temp = *x;
	*x = *y;
	*y = temp;
}

void sort_by_name(Student std[], int n) {
	int i, j;
	
	for(i=0; i<n; i++) {
		for(j=n-1; j>i; j--)
			if(strcmp(std[j].name, std[i].name) < 0)
				swap_Student(&std[j], &std[i]);
	}
}

void sort_by_height(Student std[], int n) {
	int i, j;
	
	for(i=0; i<n; i++) {
		for(j=n-1; j>i; j--)
			if(std[j].height > std[i].height)
				swap_Student(&std[j], &std[i]);
	}
}

void sort_by_schols(Student std[], int n) {
	int i, j;
	
	for(i=0; i<n; i++) {
		for(j=n-1; j>i; j--)
			if(std[j].schols > std[i].schols)
				swap_Student(&std[j], &std[i]);
	}
}

int main() {
	int i, num, sort_type;
	
	scanf("%d %d", &num, &sort_type);
	Student std[num];
	
	for(i=0; i<num; i++)
		scanf("%s %d %f %ld", std[i].name, &std[i].height, &std[i].weight, &std[i].schols);
	
	switch(sort_type) {
		case 0 : sort_by_name(std, num);	break;
		case 1 : sort_by_height(std, num);	break;
		case 2 : sort_by_schols(std, num);	break;
	}
	
	for(i=0; i<num; i++)
		printf("%-10s%6d%6.1f%7ld\n", std[i].name, std[i].height, std[i].weight, std[i].schols);
	
	return 0;
}
