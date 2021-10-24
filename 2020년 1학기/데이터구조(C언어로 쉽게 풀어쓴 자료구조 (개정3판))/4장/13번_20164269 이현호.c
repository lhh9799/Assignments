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

//피크 함수
element peek(StackType *s) {
	if(is_empty(s)) { 
		fprintf(stderr, "스택 공백 에러\n");
		exit(1);
	}
	else return s->data[s->top];
}

//키보드로 받은 문자열 배열을 스택에 복사하는 함 수 
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
	int i, j=0, flag=0, n=strlen(in); 		//안쓰는 코드 삭제 바람 
	init_stack(&s2); //스택 s2 초기화 
	
	s1 = setstack(in);						//사용자로부터 입력받은 값을 인자로 스택 s1 생성 

	for(i=0; i<n; i++)						//중복 비교용 배열 cmp 초기화 
		cmp[i] = '\0'; 
	
	while(!is_empty(&s1)) {					//s1 배열이 모두 비워질 때 까지 
		open_ch = pop(&s1);					//s1에서 원소 1개 pop 
		for(i=0; i<n; i++) {				//루프를 돌며 cmp 배열과 비교 
			if(open_ch == cmp[i])			//일치하는 값 발견시 flag 값 증가 
				flag++;
		}
		if(flag==0) {						//cmp배열에서 s1의 원소와 일치하는 값을 찾지 못한 경우(즉flag==0) 
			push(&s2, open_ch);				//최종 출력용 스택s2에 해당 원소 저장 
			cmp[j++] = open_ch;				//비교용 배열 cmp에도 추가 
		}
		flag=0; //flag 초기화 
	}
	
	while(!is_empty(&s2)) {					//출력용 스택 s2가 모두 비워질 때 까지 
		printf("%c", pop(&s2));
	}
}


main(void) {
	printf("정수를 입력하시오 : ");
	char *p = (char *)malloc(100);
	scanf("%s", p);
	check_matching(p);
}
	
