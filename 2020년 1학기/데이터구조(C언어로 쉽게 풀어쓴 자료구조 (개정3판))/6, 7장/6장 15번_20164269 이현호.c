#include <stdio.h>
#include <stdlib.h>
#include <time.h>																//난수 생성함수의 인자 time()함수 사용을 위한 헤더파일 

typedef int element;
typedef struct ListNode {														//노드 타입
	element data; 
	struct ListNode *link;
} ListNode;

typedef struct result {															//최대갑과 최솟값을 가려내는 함수에서 사용할 리턴 데이터 타입 
	int max, min;
} result;

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
ListNode* insert_last(ListNode *head, int value) {
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

void print_list(ListNode *head) {
	for(ListNode *p = head; p!=NULL; p=p->link)
		printf("%d->", p->data);
	printf("NULL \n");
}

result find_max_and_min(ListNode *head, int num_of_nodes) {					//최댓값과 최솟값을 찾는 함수 
	ListNode *p=head;
	int max, min;
	result rs;
	
	max = p->data; min = p->data;											//첫 번째 노드의 원소를 최댓값과 최솟값에 저장한다 
	for(p = head; p!=NULL; p=p->link) {
		if(p->data > max)
			max = p->data;
		if(p->data < min)
			min = p->data;
	}
	rs.max = max; rs.min = min;												//이 함수에서 찾아낸 최댓값과 최솟값을 출력용 구조체 rs에 저장한다 
	
	return rs;
}

//테스트 프로그램
int main(void) {
	ListNode *head = NULL;
	int num_of_nodes;
	result rs;
	srand(time(NULL)); 
	
	printf("노드의 개수 : ");
	scanf("%d", &num_of_nodes);
	
	for(int i=0; i<num_of_nodes; i++)
		head = insert_last(head, rand()%100+1);								//1부터 100까지의 난수 생성 후 헤드에 삽입 
		
	print_list(head);
	rs = find_max_and_min(head, num_of_nodes);								//최댓값과 최솟값 찾는 함수 
	printf("최댓값 : %d, 최솟값 : %d", rs.max, rs.min);
	return 0;
}
