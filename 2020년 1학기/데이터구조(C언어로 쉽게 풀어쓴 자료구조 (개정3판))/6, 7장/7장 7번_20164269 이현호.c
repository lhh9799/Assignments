#include <stdio.h>
#include <stdlib.h>
#include <time.h>															//���� �����Լ��� ���� time()�Լ� ����� ���� ������� 

typedef int element;
typedef struct DListNode {													//���߿��� ��� Ÿ��
	element data;
	struct DListNode* llink;
	struct DListNode* rlink;
} DListNode;

//���� ���� ����Ʈ�� �ʱ�ȭ
void init(DListNode* phead) {
	phead->llink = phead;
	phead->rlink = phead;
}

//���� ���� ����Ʈ�� ��带 ���
void print_dlist(DListNode* phead) {
	DListNode* p; 
	for(p=phead->rlink; p!=phead; p=p->rlink) {
		printf("<-| |%d| |-> ", p->data);
	}
	printf("\n");
}

//���� �ۼ��� ��� �Լ�. ���� �Լ��� �������� ����Ѵ�. 
void reverse_print_dlist(DListNode* phead) {
	DListNode* p;
	for(p=phead->llink; p!=phead; p=p->llink)
		printf("%d ", p->data);
	printf("\n");
}

//���ο� �����͸� ��� before�� �����ʿ� �����Ѵ�.
void dinsert(DListNode *before, element data) {
	DListNode *newnode = (DListNode *)malloc(sizeof(DListNode));
	newnode->data=data;
	newnode->llink=before;
	newnode->rlink=before->rlink;
	before->rlink->llink = newnode;
	before->rlink=newnode;
}

//���� �ۼ��� ���� �Լ�. head�� ���ʿ� ���ο� ��带 �����Ѵ�. 
void my_dinsert(DListNode *phead, element data) {
	DListNode *newnode = (DListNode *)malloc(sizeof(DListNode));
	newnode->data = data;
	newnode->rlink = phead->rlink;
	newnode->llink = phead;
	phead->rlink->llink = newnode;
	phead->rlink = newnode;
}

//��� removed�� �����Ѵ�.
void ddelete(DListNode* head, DListNode* removed) {
	if(removed == head) return;
	removed->llink->rlink = removed->rlink;
	removed->rlink->llink = removed->llink;
	free(removed);
}

//���� ���� ����Ʈ L���� data�� ������ �ִ� ��带 ã�Ƽ� ��ȯ�Ѵ�. 
DListNode* search(DListNode* L, element data) {
	DListNode* p;
	int flag=0;
	
	for(p=L->rlink; p!=L; p=p->rlink) {
		if(p->data == data) {
			flag++;
			return p;
		}
	}
	if(flag == 0)															//��ġ�ϴ� ���� ã�� ���� ���
		return NULL;
}

int main(void) {
	int num_of_nodes;
	element data;
	DListNode *result;
	
	srand(time(NULL));
	
	DListNode* head = (DListNode *)malloc(sizeof(DListNode));
	init(head);
	
	printf("�������� ������ �Է��Ͻÿ� : "); 
	scanf("%d", &num_of_nodes);
	
	for(int i=0; i<num_of_nodes; i++)
		my_dinsert(head, rand()%100+1);										//1���� 100������ ���� ���� �� ����� ������ ��忡 ����
	
	printf("---��� ���---\n");
	reverse_print_dlist(head);

	printf("\nŽ���� ���� �Է��Ͻÿ�: ");
	scanf("%d", &data);
	
	result = search(head, data);
	if(result == NULL)
		printf("��ġ�ϴ� ���� ���� ��带 ã�� ���߽��ϴ�.");
	else
		printf("�ش� ����� �ּ� : %d", result);
	
	free(head);
	return 0;
}
