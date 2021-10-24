#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct ListNode {											//노드 타입
	element data; 
	struct ListNode *link;
} ListNode;

typedef struct result {												//split 함수의 리턴 데이터 타입을 구조체로 정의 
	struct ListNode *a, *b;
} result;

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

//마지막 노드뒤에 새로운 노드 삽입 
ListNode* insert_last(ListNode *head, element value) {
	ListNode *i = head;
	ListNode *p = (ListNode *)malloc(sizeof(ListNode));
	p->data = value;
	p->link = NULL;
	
	if(head == NULL)												//헤드 포인터가 NULL값이라면(즉, 노드를 처음 추가하는 경우) 
		head = p;													//헤드 포인터 변경
	
	else {
		while(i->link != NULL)										//마지막노드 탐색 
			i=i->link;
		i->link = p;												//마지막노드의 링크에 새로운 노드의 주소 저장 
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

void print_list(ListNode *head) {
	for(ListNode *p = head; p!=NULL; p=p->link)
		printf("%d->", p->data);
	printf("NULL \n");
}

result split(ListNode *head) {
	ListNode *A = NULL, *B = NULL;
	result rs;
	int num=1;														//0은 짝수도 홀수도 아니므로 1부터 시작한다
	
	for(ListNode *p = head; p!=NULL; p=p->link) {
		if(num%2 == 1)												//노드의 번호가 홀수인 경우
			A = insert_last(A, p->data);
		else														//노드의 번호가 짝수인 경우 
			B = insert_last(B, p->data);
		num++;														//split 작업을 마치면 num을 증가시킨다 
	}
	
	rs.a = A; 
	rs.b = B;
	
	return rs;
}

int main(void) {
	ListNode *C = NULL;												// head는 C의 헤드 포인터, head1은 A의 헤드 포인터, head2는 B의 헤드 포인터 
	result rs;
	
	for(int i=0; i<10; i++)
		C = insert_last(C, i);										//insert_first()가 반환된 헤드 포인터를 head에 대입한다

	//단순 연결 리스트 C 출력 
	printf("단순 연결 리스트 C : "); print_list(C);
	
	printf("---split 함수 실행---\n");
	rs = split(C);													//split한 결과값을 result형 변수 rs에 저장한다 
	
	//단순 연결 리스트 A 출력 
	printf("단순 연결 리스트 A : "); print_list(rs.a);
	//단순 연결 리스트 B 출력 
	printf("단순 연결 리스트 B : "); print_list(rs.b);
	
	return 0;
}
