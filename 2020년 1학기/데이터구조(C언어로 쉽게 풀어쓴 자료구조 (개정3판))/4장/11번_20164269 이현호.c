#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_STACK_SIZE 100

typedef int element;
typedef struct {
	element data[MAX_STACK_SIZE];
	int top;
} StackType;

//���� �ʱ�ȭ �Լ� 
void init_stack(StackType *s) {
	s->top = -1;
}

//���� ���� ���� �Լ�
int is_empty(StackType *s) {
	return (s->top == -1);
}

//��ȭ ���� ���� �Լ� 
int is_full(StackType *s) {
	return (s->top == (MAX_STACK_SIZE -1));
}

//�����Լ� 
void push(StackType *s, element item) {
	if(is_full(s)) {
		fprintf(stderr, "���� ��ȭ ����\n");
		return;
	}
	else s->data[++(s->top)] = item;

}

//�����Լ�
element pop(StackType *s) {
	if(is_empty(s)) {
		fprintf(stderr, "���� ���� ����\n");
		exit(1);
	}
	else return s->data[(s->top)--];
}

//��ũ �Լ� - ���� �ʿ����� Ȯ�� �ٶ� 
element peek(StackType *s) {
	if(is_empty(s)) { 
		fprintf(stderr, "���� ���� ����\n");
		exit(1);
	}
	else return s->data[s->top];
}

int check_matching(const char *in) {
	StackType s;
	char ch, open_ch;
	int i, n = strlen(in), count = 0;
	init_stack(&s);
	
	for(i=0; i<n; i++) {
		ch = in[i]; //ch = ���� ����
		switch (ch) {
		case '(':								//'(' ���� ����� count�� �������� ���ÿ� ���� 
			push(&s, ++count);
			printf("%d ", count);
			break;
		case ')':								//')' ���� ����� ������ ���ڸ� ������ ��� 
			printf("%d ", pop(&s));
			break;
		}
	}
}				

main(void) {
	printf("���� : ");
	char *p = (char *)malloc(12);
	scanf("%s", p);
	check_matching(p);
}
	
