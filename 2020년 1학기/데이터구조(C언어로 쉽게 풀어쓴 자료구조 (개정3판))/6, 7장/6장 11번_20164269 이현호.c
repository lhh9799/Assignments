#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct ListNode {														//��� Ÿ��
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
	p->link = head;																//��� �������� ���� ����
	head = p;																	//��� ������ ����
	return head;
}

//������ ���ڿ� ���ο� ��� ���� 
ListNode* insert_last(ListNode *head, element value) {
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

int sum_of_nodes(ListNode *head) {
	int sum=0;
	
	for(ListNode *p = head; p!=NULL; p=p->link)
		sum+=p->data;
		
	return sum;
}
		

void print_list(ListNode *head) {
	for(ListNode *p = head; p!=NULL; p=p->link)
		printf("%d->", p->data);
	printf("NULL \n");
}

int main(void) {
	ListNode *head = NULL;
	int num_of_nodes, data, sum;
	
	printf("����� ���� : ");
	scanf("%d", &num_of_nodes);
	
	for(int i=0; i<num_of_nodes; i++) {
		printf("��� #%d ������ : ", i+1);
		scanf("%d", &data);
		head = insert_last(head, data);
	}
	sum=sum_of_nodes(head);
	printf("���� ����Ʈ�� ������ ��: %d", sum);
	return 0;
}
