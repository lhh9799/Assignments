#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct ListNode {				//노드 타입
	element data;
	struct ListNode *link;
} ListNode;

//리스트의 항목 출력
void print_list(ListNode* head) {
	ListNode* p;
	
	if(head == NULL) return;
	p = head->link;
	do {
		printf("%d->", p->data);
		p = p->link;
	} while(p!=head);
	printf("%d->", p->data);			//마지막 노드 출력
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
	return head;						//변경된 헤드 포인터를 반환한다.
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
	return head;						//변경된 헤드 포인터를 반환한다.
}

//특정한 값을 탐색하는 함수 - 원형 연결 리스트 L에서 data를 가지고 있는 노드를 찾아서 반환한다. 
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
	
	if(p->data == data) {				//위 do-while문에서 마지막노드는 검색하지 않기 때문에 마지막 노드를 검색한다 
		flag++;
		return p;
	}
	if(flag == 0) {						//일치하는 값을 찾지 못한 경우
		return NULL;
	}
}

int main(void) {
	ListNode *head = NULL, *result;
	element data;
	
	// list = 10->20->30->40
	head = insert_last(head, 20);		//insert_last()가 반환한 헤드 포인터를 head에 대입한다.
	head = insert_last(head, 30);
	head = insert_last(head, 40);
	head = insert_first(head, 10);
	print_list(head);
	
	printf("\n탐색할 값을 입력하시오: ");
	scanf("%d", &data);
	result = search(head, data);
	if(result == NULL)
		printf("일치하는 값을 가진 노드를 찾지 못했습니다.");
	else
		printf("해당 노드의 주소 : %d", result->link);

	return 0;
}
