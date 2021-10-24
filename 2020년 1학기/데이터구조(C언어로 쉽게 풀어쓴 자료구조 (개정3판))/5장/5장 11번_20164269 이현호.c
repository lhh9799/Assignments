#include <stdio.h>
#include <stdlib.h>
#include <string.h> //strlen �Լ��� ����ϱ� ���� ��� ����
#define MAX_QUEUE_SIZE 50

typedef char element;
typedef struct { //ť Ÿ�� 
	element data[MAX_QUEUE_SIZE];
	int front, rear;
} DequeType;

//�����Լ�
void error(char *message) {
	fprintf(stderr, "%s\n", message);
	exit(1);
}

//�ʱ�ȭ
void init_deque(DequeType *q) {
	q->front = q->rear = 0;
}

//���� ���� ���� �Լ�
int is_empty(DequeType *q) {
	return (q->front == q->rear);
}

//��ȭ ���� ���� �Լ�
int is_full(DequeType *q) {
return ((q->rear +1 ) % MAX_QUEUE_SIZE == q->front);
}

//����ť ��� �Լ�
void deque_print(DequeType *q) {
	printf("DEQUE(front=%d rear=%d) = ", q->front, q->rear);
	if(!is_empty(q)) {
		int i = q->front;
		do {
			i = (i+1) % (MAX_QUEUE_SIZE);
			printf("%c | ", q->data[i]);
			if(i==q->rear)
				break;
		} while(i != q->front);
	}
	//printf("\n");
}

//�����Լ�
void add_rear(DequeType *q, element item) {
	if(is_full(q))
		error("ť�� ��ȭ�����Դϴ�");
	q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
	q->data[q->rear] = item;
}

//�����Լ� 
element delete_front(DequeType *q) {
	if(is_empty(q))
		error("ť�� ��������Դϴ�");
		q->front = (q->front + 1) % MAX_QUEUE_SIZE;
		return q->data[q->front];
}

//�����Լ�
element get_front(DequeType *q) {
	if(is_empty(q))
		error("ť�� ��������Դϴ�");
	return q->data[(q->front + 1) % MAX_QUEUE_SIZE];
}

void add_front(DequeType *q, element val) {
	if(is_full(q))
		error("ť�� ��ȭ�����Դϴ�");
		q->data[q->front] = val;
		q->front = (q->front - 1 + MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE;
}

element delete_rear(DequeType *q) {
	int prev = q->rear;
	if(is_empty(q))
		error("ť�� ��������Դϴ�");
	q->rear = (q->rear - 1 + MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE;
	return q->data[prev];
}

element get_rear(DequeType *q) {
	if(is_empty(q))
		error("ť�� ��������Դϴ�");
	return q->data[q->rear];
}

void clear_buffer() { //���۸� ���� �Լ� 
	while(getchar() != '\n');
}

int main(void) {
	DequeType queue;																	//ȸ���˻� ť 
	char s[16];																			//ȸ���˻� �� �ܾ ������ ���ڿ� �迭
	int result=0, count = 0;															//result : ȸ�� �Ǻ� ����; count : ���ʿ��� ����(ex '.' ' ')�� ������ ���ڵ��� ���� ����ϱ� ���� ���� 
	
	init_deque(&queue);																	//ȸ���˻� ť �ʱ�ȭ 
	
	while(1) {
		printf("ȸ���˻��� �ܾ �Է��ϼ���(�ִ� ���� 15��/�Է����� : !) >> "); 
		scanf("%[^\n]", s);																//%['����'] : '����'�� ������ ������ ��� �Է��� ����; ���鹮�ڵ� �Է¹ޱ� ���� ��ġ 
		clear_buffer();																	//buffer�� ����� ���ѷ��� ���� 
		
		if(s[0] == '!' && strlen(s) == 1)												//0�� �ε����� ���� '!'�̰� �Էµ� ���ڿ��� ���̰� 1�� ��� ���� 
			exit(0);
			
		else if(strlen(s) > 15) {														//�迭�� �ִ� ũ�⸦ �ʰ��� ��� 
			clear_buffer();
			printf("�ִ� ���ڿ� ũ�⸦ �ʰ��Ͽ����ϴ�. �ٽ� �Է��ϼ���.\n"); 
		}
		
		else {																			//ȸ���˻� ���� 
			printf("�Է��� �ܾ� : %s\n", &s); 
			
			for(int i=0; i<strlen(s); i++) {											//�Է��� ������ �� ��ŭ ���� 
				if(s[i] >= 'a' && s[i] <= 'z') {										//�ҹ����� ��� ���� ������ ��ġ�� �ʰ� ť�� ���� 
					add_rear(&queue, s[i]);
					count++;
				}
				else if(s[i] >= 'A' && s[i] <= 'Z') {									//�빮���� ��� 
					s[i] += ('a' - 'A');												//�ҹ��ڷ� ��ȯ 
					add_rear(&queue, s[i]);												//ť�� �߰� 
					count++; 
				}
			}
			
			deque_print(&queue);														//���ʿ��� ���ڸ� ������ ���ڿ��� ����� ť ��� 
			
			for(int i=0; i<count/2; i++) {												//������ ���� Ȧ���� ��� ��� �ܾ�� ���� �ʿ䰡 ���� ������ �������� ������� ���� 
				if(delete_front(&queue) != delete_rear(&queue))							//ť�� �հ� �ڿ��� ���� 1���� ������ ���� �� 
					result++;															//ȸ���� �ƴ� ��� result�� �� ���� 
			}
			if(result==0) 																//result�� ���� 0 �� ȸ���� ���
				printf("��(��) ȸ���Դϴ�.\n\n", &s);
			else																		//result�� ���� 0�� �ƴ� �� ȸ���� �ƴ� ��� 
				printf("��(��) ȸ���� �ƴմϴ�.\n\n", &s);
			//�Ʒ� ������ while ������ ���� �ʱ�ȭ
			init_deque(&queue);															//ť �ʱ�ȭ 
			count = 0;																	//count ���� �ʱ�ȭ 
			result = 0;																	//result ���� �ʱ�ȭ 
		}
	}
	return 0;
}
