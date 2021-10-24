#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct DListNode { //이중연결 노드 타입
	element data;
	struct DListNode* llink;
	struct DListNode* rlink;
} DListNode;

//이중 연결 리스트를 초기화
void init(DListNode* phead) {
	phead->llink = phead;
	phead->rlink = phead;
}

//이중 연결 리스트의 노드를 출력
void print_dlist(DListNode* phead) {
	DListNode* p; 
	for(p=phead->rlink; p!=phead; p=p->rlink) {
		//printf("<-| |%d| |-> ", p->data); //책의 함수
		printf("%d ", p->data); 
	}
}

//새로 작성한 출력 함수. 기존 함수의 역순으로 출력한다. 
void reverse_print_dlist(DListNode* phead) {
	DListNode* p;
	for(p=phead->llink; p!=phead; p=p->llink)
		printf("%d ", p->data);
	printf("\n");
}

//새로운 데이터를 노드 before의 오른쪽에 삽입한다.
void dinsert(DListNode *before, element data) {
	DListNode *newnode = (DListNode *)malloc(sizeof(DListNode));
	newnode->data=data;
	newnode->llink=before;
	newnode->rlink=before->rlink;
	before->rlink->llink = newnode;
	before->rlink=newnode;
}

//새로 작성한 삽입 함수. head의 왼쪽에 새로운 노드를 삽입한다. 
void my_dinsert(DListNode *phead, element data) {
	DListNode *newnode = (DListNode *)malloc(sizeof(DListNode));
	newnode->data = data;
	newnode->rlink = phead->rlink;
	newnode->llink = phead;
	phead->rlink->llink = newnode;
	phead->rlink = newnode;
}

//노드 removed를 삭제한다.
void ddelete(DListNode* head, DListNode* removed) {
	if(removed == head) return;
	removed->llink->rlink = removed->rlink;
	removed->rlink->llink = removed->llink;
	free(removed);
}

//이중 연결 리스트 테스트 프로그램
int main(void) {
	int num_of_nodes;
	element data;
	
	DListNode* head = (DListNode *)malloc(sizeof(DListNode));
	init(head);

	printf("데이터의 개수를 입력하시오 : "); 
	scanf("%d", &num_of_nodes);
	printf("\n");
	
	//책의 함수는 헤드의 오른쪽에 노드를 삽입하기 때문에 가장 마지막에 삽입한 노드의 값이 출력된다. 따라서 삽입함수를 새로 작성한다. 
	for(int i=1; i<num_of_nodes+1; i++) {
		printf("노드 #%d의 데이터를 입력하시오: ", i);
		scanf("%d", &data);
		my_dinsert(head, data);
	}
	printf("\n데이터를 역순으로 출력: "); 
	print_dlist(head);
	//reverse_print_dlist(head);
	free(head);
	return 0;
}
