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
//조잡해 보일수 있으리라 생각합니다. 문제의 출력 부분에 마지막 노드 출력 후 "-> "화살표가 출력되지 않는 것을 보고 제 나름대로 책에 있던 함수를 수정하였습니다. 
void print_list(ListNode *head) {
	int count1=0, count2=0;
	for(ListNode *p = head; p!=NULL; p=p->link)									//노드의 수가 몇개인지 계산 
		count1++;
	for(ListNode *p = head; p!=NULL; p=p->link) {								//노드를 화면에 출력 
		printf("%d", p->data);
		count2++;																//화면에 출력한 노드의 수 카운트 
		if(count2<count1)														//총 노드의 수 보다 화면에 출력된 노드의 수가 작을때에만 화살표 출력 
			printf("->");
	}
}

int main(void) {
	ListNode *head = NULL;
	int num_of_nodes, data;
	
	printf("노드의 개수 : ");
	scanf("%d", &num_of_nodes);
	
	for(int i=0; i<num_of_nodes; i++) {
		printf("노드 #%d 데이터 : ", i+1);
		scanf("%d", &data);
		head = insert_last(head, data);
	}
	printf("생성된 연결 리스트: "); 
	print_list(head);
	return 0;
}
