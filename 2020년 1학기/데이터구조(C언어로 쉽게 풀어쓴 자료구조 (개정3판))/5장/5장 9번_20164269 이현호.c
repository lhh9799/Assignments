#include <stdio.h>
#include <stdlib.h>
#define MAX_QUEUE_SIZE 3

typedef int element;
typedef struct { //ť Ÿ�� 
	int front;
	int rear;
	element data[MAX_QUEUE_SIZE];
} QueueType;

//���� �Լ�
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
		error("ť�� ��ȭ�����Դϴ�.");
		return;
	}
	q->data[++(q->rear)] = item;
}

int dequeue(QueueType *q) {
	if(is_empty(q)) {
		error("ť�� ��������Դϴ�.");
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
		printf("�Է��� �� ����� �� �����ϼ���. 1:�Է� 2:��� 3:���� >> ");
		scanf(" %c", &c);															//�Է¹��ۿ� �����ִ� �� ������ �� ������ �ι� ��µ�. ���� ���鹮�� ���� 
		
		switch(c) {
		case '1': //�Է� 
			printf("�Է��� ���� �Է� : ");
			scanf("%d", &item);
			enqueue(&q1, item);														//�Է¿� ť�� ���� ���� 
			break;
		case '2': //��� 
			if(is_empty(&q2)) {														//��¿� ť�� ����ִ� ��� 
				printf("\n��¿� ť�� ���� �����Դϴ�. �Է� ť���� ���� �����մϴ�.\n"); 
				while(!is_empty(&q1))												//�Է¿� ť�� ��� ����� �� ����
					enqueue(&q2, dequeue(&q1)); 
			}
			item = dequeue(&q2); printf("��¿� ť���� dequeue�� �� : %d", item);	//��¿� ť���� ���� �ϳ� ��� 
			printf("\t\t��¿� ť ��� > "); queue_print(&q2);
			printf("\n");
			break;
		case '3': //���� 
			exit(0);
		}
	}
	return 0;
}
