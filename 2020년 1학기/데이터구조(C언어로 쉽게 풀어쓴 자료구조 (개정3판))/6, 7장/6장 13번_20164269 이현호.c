#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct ListNode {											//��� Ÿ��
	element data; 
	struct ListNode *link;
} ListNode;

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
//����ڰ� �Է��� ���� ã�� �����Ѵ�. 
ListNode* find_and_delete(ListNode *head, int value) {
	ListNode *p=head, *q=NULL, *r=NULL;
	int count=0;
	
	while(p!=NULL) {
		r=q;
		q=p;
		p=p->link;													//p�� ���ؿ� ���� 
		if(q->data == value) {										//��ġ�ϴ� ���� ã�� ��� 
			r->link=p;												//q�� ���� ����� p�� r�� �ּҸ� �����Ѵ�. 
			count++;												//��ġ�� ���� ��. �� �ڵ忡���� �ߺ��Ǵ� ���� �����Ƿ�(1���� 5�� ��) flag�� �ִ� 1�̴�. 
		}
	}
	if(count<=0)
		printf("��ġ�ϴ� ���� ã�� ���߽��ϴ�.");
	else
		printf("��ġ�ϴ� �� %d���� ���� �Ͽ����ϴ�.\n", count);
		
	return head;
}
		

void print_list(ListNode *head) {
	for(ListNode *p = head; p!=NULL; p=p->link)
		printf("%d->", p->data);
	printf("NULL \n");
}

//�׽�Ʈ ���α׷�
int main(void) {
	ListNode *head = NULL;
	int value;
	
	for(int i=0; i<5; i++) {
		head = insert_first(head, i);								//insert_first()�� ��ȯ�� ��� �����͸� head�� �����Ѵ�. 
	}
	printf("ã�Ƽ� ������ ������ �Է� (1���� 5������ ��) >> ");
	scanf("%d", &value);
	find_and_delete(head, value);
	printf("���� ���� �ܼ� ���� ����Ʈ ��� : "); 
	print_list(head);
	return 0;
}
