#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct ListNode {				//��� Ÿ��
	element data;
	struct ListNode *link;
} ListNode;

//����Ʈ�� �׸� ���
void print_list(ListNode* head) {
	ListNode* p;
	
	if(head == NULL) return;
	p = head->link;
	do {
		printf("%d->", p->data);
		p = p->link;
	} while(p!=head);
	printf("%d->", p->data);			//������ ��� ���
}

ListNode* insert_first(ListNode* head, element data) {
	ListNode *node = (ListNode *)malloc(sizeof(ListNode));
	node->data = data;
	if(head==NULL) {
		head = node;
		node->link = head;
	}
	else {
		node->link = head->link;
		head->link = node;
	}
	return head;						//����� ��� �����͸� ��ȯ�Ѵ�.
}

ListNode* insert_last(ListNode* head, element data) {
	ListNode *node = (ListNode *)malloc(sizeof(ListNode));
	node->data=data;
	if(head==NULL) {
		head=node;
		node->link=head;
	}
	else {
		node->link=head->link;
		head->link=node;
		head=node;
	}
	return head;						//����� ��� �����͸� ��ȯ�Ѵ�.
}

//Ư���� ���� Ž���ϴ� �Լ� - ���� ���� ����Ʈ L���� data�� ������ �ִ� ��带 ã�Ƽ� ��ȯ�Ѵ�. 
ListNode* search(ListNode* L, element data) {
	ListNode *p = L->link;
	int flag=0;
	
	do {
		if(p->data == data) {
			flag++; 
			return p;
		}
		p = p->link;
	} while(p!=L);
	
	if(p->data == data) {				//�� do-while������ ���������� �˻����� �ʱ� ������ ������ ��带 �˻��Ѵ� 
		flag++;
		return p;
	}
	if(flag == 0) {						//��ġ�ϴ� ���� ã�� ���� ���
		return NULL;
	}
}

int main(void) {
	ListNode *head = NULL, *result;
	element data;
	
	// list = 10->20->30->40
	head = insert_last(head, 20);		//insert_last()�� ��ȯ�� ��� �����͸� head�� �����Ѵ�.
	head = insert_last(head, 30);
	head = insert_last(head, 40);
	head = insert_first(head, 10);
	print_list(head);
	
	printf("\nŽ���� ���� �Է��Ͻÿ�: ");
	scanf("%d", &data);
	result = search(head, data);
	if(result == NULL)
		printf("��ġ�ϴ� ���� ���� ��带 ã�� ���߽��ϴ�.");
	else
		printf("�ش� ����� �ּ� : %d", result->link);

	return 0;
}
