#include <stdio.h>
#include <stdlib.h>
#define MAX_QUEUE_SIZE 3

typedef int element;
typedef struct { //큐 타입 
	int front;
	int rear;
	element data[MAX_QUEUE_SIZE];
} QueueType;

//오류 함수
void error(char *message) {
	fprintf(stderr, "%s\n", message);
	exit(1); 
}

void init_queue(QueueType *q) {
	q->rear = -1;
	q->front = -1;
}

void queue_print(QueueType *q) {
	for(int i=0; i<MAX_QUEUE_SIZE; i++) {
		if(i <= q->front || i > q->rear)
			printf("|");
		else
			printf("%d|", q->data[i]);
		}
		printf("\n");
	}
	
int is_full(QueueType *q) {
	if(q->rear == MAX_QUEUE_SIZE -1)
		return 1;
	else
		return 0;
}

int is_empty(QueueType *q) {
	if(q->front == q->rear)
		return 1;
	else
		return 0;
}

void enqueue(QueueType *q, int item) {
	if(is_full(q)) {
		error("큐가 포화상태입니다.");
		return;
	}
	q->data[++(q->rear)] = item;
}

int dequeue(QueueType *q) {
	if(is_empty(q)) {
		error("큐가 공백상태입니다.");
		return -1;
	}
	int item = q->data[++(q->front)];
	return item;
}

int main(void) {
	int item = 0;
	QueueType q1, q2;
	char c;
	
	init_queue(&q1);
	init_queue(&q2);
	
	while(1) {
		printf("입력할 지 출력할 지 선택하세요. 1:입력 2:출력 3:종료 >> ");
		scanf(" %c", &c);															//입력버퍼에 남아있는 값 때문에 위 문장이 두번 출력됨. 따라서 공백문자 삽입 
		
		switch(c) {
		case '1': //입력 
			printf("입력할 숫자 입력 : ");
			scanf("%d", &item);
			enqueue(&q1, item);														//입력용 큐에 값을 저장 
			break;
		case '2': //출력 
			if(is_empty(&q2)) {														//출력용 큐가 비어있는 경우 
				printf("\n출력용 큐가 공백 상태입니다. 입력 큐에서 값을 복사합니다.\n"); 
				while(!is_empty(&q1))												//입력용 큐가 모두 비워질 때 까지
					enqueue(&q2, dequeue(&q1)); 
			}
			item = dequeue(&q2); printf("출력용 큐에서 dequeue한 값 : %d", item);	//출력용 큐에서 값을 하나 출력 
			printf("\t\t출력용 큐 출력 > "); queue_print(&q2);
			printf("\n");
			break;
		case '3': //종료 
			exit(0);
		}
	}
	return 0;
}
