/* ��¥�� ���� �Ǵ� �������� ���� */
#include <stdio.h>

/*--- y���� �����ΰ�? ---*/
int is_leap(int y) {
	return y%4 == 0 && y%100 != 0 || y%400 == 0;
}

/*--- y�� m���� �ϼ� ---*/
int days_of_month(int y, int m) {
	int mdays[][12] = {
		{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},	/*���*/
		{31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},	/*����*/
	};
	return mdays[is_leap(y)][m-1];
}

/*--- *y�� *m�� *d���� ���� ��¥�� ���� ---*/
void decrement_date(int *y, int *m, int *d) {
	if(*d > 1)
		--*d;
	else {
		if(--*m < 1) {
			--*y;
			*m = 12;
		}
		*d = days_of_month(*y, *m);
	}
}

/*--- *y�� *m�� *d���� ������ ��¥�� ���� ---*/
void increment_date(int *y, int *m, int *d) {
	if(*d < days_of_month(*y, *m))
		++*d;
	else {
		if(++*m > 12) {
			++*y;
			*m = 1; 
		}
	*d = 1;
	}
}

int main(void) {
	int i, n;
	int y, m, d;
	
//	puts("��¥�� �Է����ּ���.");
	scanf("%d %d %d %d", &y, &m, &d, &n);
//	printf("�� : ");	scanf("%d", &y);
//	printf("�� : ");	scanf("%d", &m);
//	printf("�� : ");	scanf("%d", &d);
	
//	printf("��ĥ �ڷ� �ұ�� : ");	scanf("%d", &n);
//	for(i=0; i<n; i++)
//		decrement_date(&y, &m, &d);
//	
//	printf("%d�� %d�� %d���� �Ǿ����ϴ�.\n", y, m, d);
//	
//	printf("��ĥ ������ �ұ�� : ");	scanf("%d", &n);
//	for(i=0; i<n; i++)
//		increment_date(&y, &m, &d);
//	
//	printf("%d�� %d�� %d���� �Ǿ����ϴ�.\n", y, m, d);
	if(n >= 0) {
		for(i=0; i<n; i++)
			increment_date(&y, &m, &d);
	}
	else {
		for(i=0; i<-n; i++)
			decrement_date(&y, &m, &d);
	}
	printf("%d %d %d", y, m, d);
	
	return 0;
}
