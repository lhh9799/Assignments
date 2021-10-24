#include <stdio.h>
#include <stdlib.h>
#include <time.h>																//���� �����Լ��� ���� time()�Լ� ����� ���� ������� 

typedef int element;
typedef struct ListNode {														//��� Ÿ��
	element data; 
	struct ListNode *link;
} ListNode;

typedef struct result {															//�ִ방�� �ּڰ��� �������� �Լ����� ����� ���� ������ Ÿ�� 
	int max, min;
} result;

//���� ó�� �Լ�
void error(char *message) {
	fprintf(stderr, "%s\n", message);
	exit(1);
}
ListNode* insert_first(ListNode *head, int value) {
	ListNode *p = (ListNode *)malloc(sizeof(ListNode));
	p->data = value;
	p->link = head;																//��� �������� ���� ����
	head = p;																	//��� ������ ����
	return head;
}

//������ ���ڿ� ���ο� ��� ���� 
ListNode* insert_last(ListNode *head, int value) {
	ListNode *i = head;
	ListNode *p = (ListNode *)malloc(sizeof(ListNode));
	p->data = value;
	p->link = NULL;
	
	if(head == NULL)															//��� �����Ͱ� NULL���̶��(��, ��带 ó�� �߰��ϴ� ���) 
		head = p;																//��� ������ ����
	
	else {
		while(i->link != NULL)													//��������� Ž�� 
			i=i->link;
		i->link = p;															//����������� ��ũ�� ���ο� ����� �ּ� ���� 
	}
	return head;
}

//��� pre �ڿ� ���ο� ��� ����
ListNode* insert(ListNode *head, ListNode *pre, element value) {
	ListNode *p = (ListNode *)malloc(sizeof(ListNode));
	p->data = value;
	p->link = pre->link;
	pre->link = p;
	return head;
}

ListNode* delete_first(ListNode *head) {
	ListNode *removed;
	if(head == NULL) return NULL;
	removed = head;
	head = removed->link;
	free(removed);
	return head;
}
//pre�� ����Ű�� ����� ���� ��带 �����Ѵ�.
ListNode* delete(ListNode *head, ListNode *pre) {
	ListNode *removed;
	removed = pre->link;
	pre->link = removed->link;
	free(removed);
	return head;
}

void print_list(ListNode *head) {
	for(ListNode *p = head; p!=NULL; p=p->link)
		printf("%d->", p->data);
	printf("NULL \n");
}

result find_max_and_min(ListNode *head, int num_of_nodes) {					//�ִ񰪰� �ּڰ��� ã�� �Լ� 
	ListNode *p=head;
	int max, min;
	result rs;
	
	max = p->data; min = p->data;											//ù ��° ����� ���Ҹ� �ִ񰪰� �ּڰ��� �����Ѵ� 
	for(p = head; p!=NULL; p=p->link) {
		if(p->data > max)
			max = p->data;
		if(p->data < min)
			min = p->data;
	}
	rs.max = max; rs.min = min;												//�� �Լ����� ã�Ƴ� �ִ񰪰� �ּڰ��� ��¿� ����ü rs�� �����Ѵ� 
	
	return rs;
}

//�׽�Ʈ ���α׷�
int main(void) {
	ListNode *head = NULL;
	int num_of_nodes;
	result rs;
	srand(time(NULL)); 
	
	printf("����� ���� : ");
	scanf("%d", &num_of_nodes);
	
	for(int i=0; i<num_of_nodes; i++)
		head = insert_last(head, rand()%100+1);								//1���� 100������ ���� ���� �� ��忡 ���� 
		
	print_list(head);
	rs = find_max_and_min(head, num_of_nodes);								//�ִ񰪰� �ּڰ� ã�� �Լ� 
	printf("�ִ� : %d, �ּڰ� : %d", rs.max, rs.min);
	return 0;
}
