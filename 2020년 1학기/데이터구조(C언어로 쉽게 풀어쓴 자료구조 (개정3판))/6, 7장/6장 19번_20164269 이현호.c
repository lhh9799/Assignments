#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct ListNode {											//��� Ÿ��
	element data; 
	struct ListNode *link;
} ListNode;

typedef struct result {												//split �Լ��� ���� ������ Ÿ���� ����ü�� ���� 
	struct ListNode *a, *b;
} result;

//���� ó�� �Լ�
void error(char *message) {
	fprintf(stderr, "%s\n", message);
	exit(1);
}
ListNode* insert_first(ListNode *head, int value) {
	ListNode *p = (ListNode *)malloc(sizeof(ListNode));
	p->data = value;
	p->link = head;													//��� �������� ���� ����
	head = p;														//��� ������ ����
	return head;
}

//������ ���ڿ� ���ο� ��� ���� 
ListNode* insert_last(ListNode *head, element value) {
	ListNode *i = head;
	ListNode *p = (ListNode *)malloc(sizeof(ListNode));
	p->data = value;
	p->link = NULL;
	
	if(head == NULL)												//��� �����Ͱ� NULL���̶��(��, ��带 ó�� �߰��ϴ� ���) 
		head = p;													//��� ������ ����
	
	else {
		while(i->link != NULL)										//��������� Ž�� 
			i=i->link;
		i->link = p;												//����������� ��ũ�� ���ο� ����� �ּ� ���� 
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

result split(ListNode *head) {
	ListNode *A = NULL, *B = NULL;
	result rs;
	int num=1;														//0�� ¦���� Ȧ���� �ƴϹǷ� 1���� �����Ѵ�
	
	for(ListNode *p = head; p!=NULL; p=p->link) {
		if(num%2 == 1)												//����� ��ȣ�� Ȧ���� ���
			A = insert_last(A, p->data);
		else														//����� ��ȣ�� ¦���� ��� 
			B = insert_last(B, p->data);
		num++;														//split �۾��� ��ġ�� num�� ������Ų�� 
	}
	
	rs.a = A; 
	rs.b = B;
	
	return rs;
}

int main(void) {
	ListNode *C = NULL;												// head�� C�� ��� ������, head1�� A�� ��� ������, head2�� B�� ��� ������ 
	result rs;
	
	for(int i=0; i<10; i++)
		C = insert_last(C, i);										//insert_first()�� ��ȯ�� ��� �����͸� head�� �����Ѵ�

	//�ܼ� ���� ����Ʈ C ��� 
	printf("�ܼ� ���� ����Ʈ C : "); print_list(C);
	
	printf("---split �Լ� ����---\n");
	rs = split(C);													//split�� ������� result�� ���� rs�� �����Ѵ� 
	
	//�ܼ� ���� ����Ʈ A ��� 
	printf("�ܼ� ���� ����Ʈ A : "); print_list(rs.a);
	//�ܼ� ���� ����Ʈ B ��� 
	printf("�ܼ� ���� ����Ʈ B : "); print_list(rs.b);
	
	return 0;
}
