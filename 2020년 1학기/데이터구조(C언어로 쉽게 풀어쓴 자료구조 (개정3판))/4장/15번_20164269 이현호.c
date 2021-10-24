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

//��ũ�Լ�
element peek(StackType *s) {
	if(is_empty(s)) {
		fprintf(stderr, "���� ���� ����\n");
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
//��ġ�� ���ÿ� ����
void push_loc(StackType *s, int r, int c) {
	if(r<0 || c<0) return; 
	if(maze[r][c] != '1' && maze[r][c] != '.') {
		element tmp;
		tmp.r = r;
		tmp.c = c;
		push(s, tmp);
	}
}

//�̷θ� ȭ�鿡 ����Ѵ�.
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
	element k;												//���� ��ν��� s1���� pop�� ���Ҹ� ����ϱ� ���� ���� 
	
	init_stack(&s);
	init_stack(&s1);										//��ν��� s1�ʱ�ȭ 
	here = entry;
	push(&s1, entry);										//�Ա� ��ġ�� ��ν��� s1�� �߰� 
	while(maze[here.r][here.c] != 'x') {
		r = here.r;
		c = here.c;
		maze[r][c] = '.';
		//maze_print(maze);									//���翣 ������ �ʿ��� �ּ�
		push_loc(&s, r-1, c);
		push_loc(&s, r+1, c);
		push_loc(&s, r, c-1);
		push_loc(&s, r, c+1);
		
		if(is_empty(&s)) {									//�̷�Ž���� ������ ��� flag�� ���� 
			printf("����\n");
			flag=1;
			return;
		}
		else {
			here = pop(&s);
			push(&s1, here);								//���� s���� pop�Ҷ� ���� ��ν��� s1�� �߰� 
		}
	}
		printf("����\n");
		
		if(flag == 0) {										//�̷�Ž���� ������ ��� flag���� ������� �ʱ� ������ ���� 
			while(!is_empty(&s1)) {							//��ν��� s1�� ���Ұ� �����ִ� ���� �ݺ� 
				k=pop(&s1);
				printf("(%d,%d)", k.r, k.c);
			}
		}
		return 0;
}
