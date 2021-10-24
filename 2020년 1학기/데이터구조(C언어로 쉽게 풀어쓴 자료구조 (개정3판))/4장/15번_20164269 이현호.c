#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAZE_SIZE 6
#define MAX_STACK_SIZE 100

typedef struct {
	short r;
	short c;
} element;

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

//피크함수
element peek(StackType *s) {
	if(is_empty(s)) {
		fprintf(stderr, "스택 공백 에러\n");
		exit(1);
	}
	else return s->data[s->top];
}

element here = {1,0}, entry = {1,0};

char maze[MAZE_SIZE][MAZE_SIZE] = {
	{'1', '1', '1', '1', '1', '1'},
	{'e', '0', '1', '0', '0', '1'},
	{'1', '0', '0', '0', '1', '1'},
	{'1', '0', '1', '0', '1', '1'},
	{'1', '0', '1', '0', '0', 'x'},
	{'1', '1', '1', '1', '1', '1'},
};
//위치를 스택에 삽입
void push_loc(StackType *s, int r, int c) {
	if(r<0 || c<0) return; 
	if(maze[r][c] != '1' && maze[r][c] != '.') {
		element tmp;
		tmp.r = r;
		tmp.c = c;
		push(s, tmp);
	}
}

//미로를 화면에 출력한다.
void maze_print(char maze[MAZE_SIZE][MAZE_SIZE]) {
	int r, c;
	printf("\n");
	for(r=0; r<MAZE_SIZE; r++); {
		for(c=0; c<MAZE_SIZE; c++) {
			printf("%c", maze[r][c]);
		}
		printf("\n");
	}
}

int main(void) {
	int r, c, flag=0;
	StackType s, s1;
	element k;												//이후 경로스택 s1에서 pop한 원소를 출력하기 위한 변수 
	
	init_stack(&s);
	init_stack(&s1);										//경로스택 s1초기화 
	here = entry;
	push(&s1, entry);										//입구 위치를 경로스택 s1에 추가 
	while(maze[here.r][here.c] != 'x') {
		r = here.r;
		c = here.c;
		maze[r][c] = '.';
		//maze_print(maze);									//교재엔 있으나 필요없어서 주석
		push_loc(&s, r-1, c);
		push_loc(&s, r+1, c);
		push_loc(&s, r, c-1);
		push_loc(&s, r, c+1);
		
		if(is_empty(&s)) {									//미로탐색에 실패한 경우 flag값 변경 
			printf("실패\n");
			flag=1;
			return;
		}
		else {
			here = pop(&s);
			push(&s1, here);								//스택 s에서 pop할때 마다 경로스택 s1에 추가 
		}
	}
		printf("성공\n");
		
		if(flag == 0) {										//미로탐색에 성공한 경우 flag값이 변경되지 않기 때문에 실행 
			while(!is_empty(&s1)) {							//경로스택 s1의 원소가 남아있는 동안 반복 
				k=pop(&s1);
				printf("(%d,%d)", k.r, k.c);
			}
		}
		return 0;
}
