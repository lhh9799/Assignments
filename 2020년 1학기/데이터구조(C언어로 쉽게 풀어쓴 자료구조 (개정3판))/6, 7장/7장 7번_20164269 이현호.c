#include <stdio.h>
#include <stdlib.h>
#include <time.h>															//난수 생성함수의 인자 time()함수 사용을 위한 헤더파일 

typedef int element;
typedef struct DListNode {													//이중연결 노드 타입
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
		printf("<-| |%d| |-> ", p->data);
	}
	printf("\n");
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

//이중 연결 리스트 L에서 data를 가지고 있는 노드를 찾아서 반환한다. 
DListNode* search(DListNode* L, element data) {
	DListNode* p;
	int flag=0;
	
	for(p=L->rlink; p!=L; p=p->rlink) {
		if(p->data == data) {
			flag++;
			return p;
		}
	}
	if(flag == 0)															//일치하는 값을 찾지 못한 경우
		return NULL;
}

int main(void) {
	int num_of_nodes;
	element data;
	DListNode *result;
	
	srand(time(NULL));
	
	DListNode* head = (DListNode *)malloc(sizeof(DListNode));
	init(head);
	
	printf("데이터의 개수를 입력하시오 : "); 
	scanf("%d", &num_of_nodes);
	
	for(int i=0; i<num_of_nodes; i++)
		my_dinsert(head, rand()%100+1);										//1부터 100까지의 난수 생성 후 헤드의 오른쪽 노드에 삽입
	
	printf("---노드 출력---\n");
	reverse_print_dlist(head);

	printf("\n탐색할 값을 입력하시오: ");
	scanf("%d", &data);
	
	result = search(head, data);
	if(result == NULL)
		printf("일치하는 값을 가진 노드를 찾지 못했습니다.");
	else
		printf("해당 노드의 주소 : %d", result);
	
	free(head);
	return 0;
}
