#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct ListNode {											//노드 타입
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
	p->link = head;													//헤드 포인터의 값을 복사
	head = p;														//헤드 포인터 변경
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
//사용자가 입력한 값을 찾고 삭제한다. 
ListNode* find_and_delete(ListNode *head, int value) {
	ListNode *p=head, *q=NULL, *r=NULL;
	int count=0;
	
	while(p!=NULL) {
		r=q;
		q=p;
		p=p->link;													//p는 항해용 변수 
		if(q->data == value) {										//일치하는 값을 찾은 경우 
			r->link=p;												//q의 다음 노드인 p에 r의 주소를 저장한다. 
			count++;												//일치한 값의 수. 이 코드에서는 중복되는 값이 없으므로(1부터 5의 수) flag는 최대 1이다. 
		}
	}
	if(count<=0)
		printf("일치하는 값을 찾지 못했습니다.");
	else
		printf("일치하는 값 %d개를 삭제 하였습니다.\n", count);
		
	return head;
}
		

void print_list(ListNode *head) {
	for(ListNode *p = head; p!=NULL; p=p->link)
		printf("%d->", p->data);
	printf("NULL \n");
}

//테스트 프로그램
int main(void) {
	ListNode *head = NULL;
	int value;
	
	for(int i=0; i<5; i++) {
		head = insert_first(head, i);								//insert_first()가 반환된 헤드 포인터를 head에 대입한다. 
	}
	printf("찾아서 삭제할 데이터 입력 (1부터 5까지의 수) >> ");
	scanf("%d", &value);
	find_and_delete(head, value);
	printf("삭제 이후 단순 연결 리스트 출력 : "); 
	print_list(head);
	return 0;
}
