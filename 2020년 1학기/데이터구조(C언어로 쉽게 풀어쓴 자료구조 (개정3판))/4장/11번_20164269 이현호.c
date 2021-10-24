#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_STACK_SIZE 100

typedef int element;
typedef struct {
	element data[MAX_STACK_SIZE];
	int top;
} StackType;

//스택 초기화 함수 
void init_stack(StackType *s) {
	s->top = -1;
}

//공백 상태 검출 함수
int is_empty(StackType *s) {
	return (s->top == -1);
}

//포화 상태 검출 함수 
int is_full(StackType *s) {
	return (s->top == (MAX_STACK_SIZE -1));
}

//삽입함수 
void push(StackType *s, element item) {
	if(is_full(s)) {
		fprintf(stderr, "스택 포화 에러\n");
		return;
	}
	else s->data[++(s->top)] = item;

}

//삭제함수
element pop(StackType *s) {
	if(is_empty(s)) {
		fprintf(stderr, "스택 공백 에러\n");
		exit(1);
	}
	else return s->data[(s->top)--];
}

//피크 함수 - 추후 필요한지 확인 바람 
element peek(StackType *s) {
	if(is_empty(s)) { 
		fprintf(stderr, "스택 공백 에러\n");
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
		ch = in[i]; //ch = 다음 문자
		switch (ch) {
		case '(':								//'(' 문자 등장시 count를 증가시켜 스택에 저장 
			push(&s, ++count);
			printf("%d ", count);
			break;
		case ')':								//')' 문자 등장시 스택의 숫자를 빼내어 출력 
			printf("%d ", pop(&s));
			break;
		}
	}
}				

main(void) {
	printf("수식 : ");
	char *p = (char *)malloc(12);
	scanf("%s", p);
	check_matching(p);
}
	
