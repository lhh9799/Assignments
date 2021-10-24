#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct ListNode {														//노드 타입
	element data; 
	struct ListNode *link;
} ListNode;

//오류 처리 함수
void error(char *message) {
	fprintf(stderr, "%s\n", message);
	exit(1);
}
ListNode* insert_first(ListNode *head, int value) {
	ListNode *p = (ListNode *)malloc(sizeof(ListNode));
	p->data = value;
	p->link = head;																//헤드 포인터의 값을 복사
	head = p;																	//헤드 포인터 변경
	return head;
}

//마지막 노드뒤에 새로운 노드 삽입 
ListNode* insert_last(ListNode *head, element value) {
	ListNode *i = head;
	ListNode *p = (ListNode *)malloc(sizeof(ListNode));
	p->data = value;
	p->link = NULL;
	
	if(head == NULL)															//헤드 포인터가 NULL값이라면(즉, 노드를 처음 추가하는 경우) 
		head = p;																//헤드 포인터 변경
	
	else {
		while(i->link != NULL)													//마지막노드 탐색 
			i=i->link;
		i->link = p;															//마지막노드의 링크에 새로운 노드의 주소 저장 
	}
	return head;
}


//노드 pre 뒤에 새로운 노드 삽입
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
//pre가 가리키는 노드의 다음 노드를 삭제한다.
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
	
	printf("노드의 개수 : ");
	scanf("%d", &num_of_nodes);
	
	for(int i=0; i<num_of_nodes; i++) {
		printf("노드 #%d 데이터 : ", i+1);
		scanf("%d", &data);
		head = insert_last(head, data);
	}
	sum=sum_of_nodes(head);
	printf("연결 리스트의 데이터 합: %d", sum);
	return 0;
}
