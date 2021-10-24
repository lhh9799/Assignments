#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct DListNode { //���߿��� ��� Ÿ��
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
		//printf("<-| |%d| |-> ", p->data); //å�� �Լ�
		printf("%d ", p->data); 
	}
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

//���� ���� ����Ʈ �׽�Ʈ ���α׷�
int main(void) {
	int num_of_nodes;
	element data;
	
	DListNode* head = (DListNode *)malloc(sizeof(DListNode));
	init(head);

	printf("�������� ������ �Է��Ͻÿ� : "); 
	scanf("%d", &num_of_nodes);
	printf("\n");
	
	//å�� �Լ��� ����� �����ʿ� ��带 �����ϱ� ������ ���� �������� ������ ����� ���� ��µȴ�. ���� �����Լ��� ���� �ۼ��Ѵ�. 
	for(int i=1; i<num_of_nodes+1; i++) {
		printf("��� #%d�� �����͸� �Է��Ͻÿ�: ", i);
		scanf("%d", &data);
		my_dinsert(head, data);
	}
	printf("\n�����͸� �������� ���: "); 
	print_dlist(head);
	//reverse_print_dlist(head);
	free(head);
	return 0;
}
