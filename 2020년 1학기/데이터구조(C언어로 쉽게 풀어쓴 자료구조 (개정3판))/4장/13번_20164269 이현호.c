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

//��ũ �Լ�
element peek(StackType *s) {
	if(is_empty(s)) { 
		fprintf(stderr, "���� ���� ����\n");
		exit(1);
	}
	else return s->data[s->top];
}

//Ű����� ���� ���ڿ� �迭�� ���ÿ� �����ϴ� �� �� 
StackType setstack(const char *in) {
	StackType s;
	init_stack(&s);
	
	for(int i=0; i<strlen(in); i++) {
		push(&s, in[i]);
	}
	return s;
}

void check_matching(const char *in) {
	StackType s1, s2;
	char ch, open_ch, cmp[strlen(in)];
	int i, j=0, flag=0, n=strlen(in); 		//�Ⱦ��� �ڵ� ���� �ٶ� 
	init_stack(&s2); //���� s2 �ʱ�ȭ 
	
	s1 = setstack(in);						//����ڷκ��� �Է¹��� ���� ���ڷ� ���� s1 ���� 

	for(i=0; i<n; i++)						//�ߺ� �񱳿� �迭 cmp �ʱ�ȭ 
		cmp[i] = '\0'; 
	
	while(!is_empty(&s1)) {					//s1 �迭�� ��� ����� �� ���� 
		open_ch = pop(&s1);					//s1���� ���� 1�� pop 
		for(i=0; i<n; i++) {				//������ ���� cmp �迭�� �� 
			if(open_ch == cmp[i])			//��ġ�ϴ� �� �߽߰� flag �� ���� 
				flag++;
		}
		if(flag==0) {						//cmp�迭���� s1�� ���ҿ� ��ġ�ϴ� ���� ã�� ���� ���(��flag==0) 
			push(&s2, open_ch);				//���� ��¿� ����s2�� �ش� ���� ���� 
			cmp[j++] = open_ch;				//�񱳿� �迭 cmp���� �߰� 
		}
		flag=0; //flag �ʱ�ȭ 
	}
	
	while(!is_empty(&s2)) {					//��¿� ���� s2�� ��� ����� �� ���� 
		printf("%c", pop(&s2));
	}
}


main(void) {
	printf("������ �Է��Ͻÿ� : ");
	char *p = (char *)malloc(100);
	scanf("%s", p);
	check_matching(p);
}
	
