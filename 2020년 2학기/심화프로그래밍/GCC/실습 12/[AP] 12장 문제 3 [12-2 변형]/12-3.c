
struct student {
	char name[20];
	int kor, eng, math;
	double average;
};

int main() {
	int n, i;
	
	scanf("%d", &n);
	struct student std[n];
	
	for(i=0; i<n; i++) {
		scanf("%s %d %d %d", std[i].name, &std[i].kor, &std[i].eng, &std[i].math);
		std[i].average = (std[i].kor + std[i].eng + std[i].math) / 3.0;
	}
	
	for(i=0; i<n; i++) {
		printf("%s, %.2lf\n", std[i].name, std[i].average);
	}
	
	return 0;
}
