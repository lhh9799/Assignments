#include <stdio.h>
#include <stdlib.h>
#include <string.h> //strlen 함수를 사용하기 위한 헤더 파일
#define MAX_QUEUE_SIZE 50

typedef char element;
typedef struct { //큐 타입 
	element data[MAX_QUEUE_SIZE];
	int front, rear;
} DequeType;

//오류함수
void error(char *message) {
	fprintf(stderr, "%s\n", message);
	exit(1);
}

//초기화
void init_deque(DequeType *q) {
	q->front = q->rear = 0;
}

//공백 상태 검출 함수
int is_empty(DequeType *q) {
	return (q->front == q->rear);
}

//포화 상태 검출 함수
int is_full(DequeType *q) {
return ((q->rear +1 ) % MAX_QUEUE_SIZE == q->front);
}

//원형큐 출력 함수
void deque_print(DequeType *q) {
	printf("DEQUE(front=%d rear=%d) = ", q->front, q->rear);
	if(!is_empty(q)) {
		int i = q->front;
		do {
			i = (i+1) % (MAX_QUEUE_SIZE);
			printf("%c | ", q->data[i]);
			if(i==q->rear)
				break;
		} while(i != q->front);
	}
	//printf("\n");
}

//삽입함수
void add_rear(DequeType *q, element item) {
	if(is_full(q))
		error("큐가 포화상태입니다");
	q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
	q->data[q->rear] = item;
}

//삭제함수 
element delete_front(DequeType *q) {
	if(is_empty(q))
		error("큐가 공백상태입니다");
		q->front = (q->front + 1) % MAX_QUEUE_SIZE;
		return q->data[q->front];
}

//삭제함수
element get_front(DequeType *q) {
	if(is_empty(q))
		error("큐가 공백상태입니다");
	return q->data[(q->front + 1) % MAX_QUEUE_SIZE];
}

void add_front(DequeType *q, element val) {
	if(is_full(q))
		error("큐가 포화상태입니다");
		q->data[q->front] = val;
		q->front = (q->front - 1 + MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE;
}

element delete_rear(DequeType *q) {
	int prev = q->rear;
	if(is_empty(q))
		error("큐가 공백상태입니다");
	q->rear = (q->rear - 1 + MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE;
	return q->data[prev];
}

element get_rear(DequeType *q) {
	if(is_empty(q))
		error("큐가 공백상태입니다");
	return q->data[q->rear];
}

void clear_buffer() { //버퍼를 비우는 함수 
	while(getchar() != '\n');
}

int main(void) {
	DequeType queue;																	//회문검사 큐 
	char s[16];																			//회문검사 할 단어를 저장할 문자열 배열
	int result=0, count = 0;															//result : 회문 판별 변수; count : 불필요한 문자(ex '.' ' ')를 제거한 문자들의 수를 계산하기 위한 변수 
	
	init_deque(&queue);																	//회문검사 큐 초기화 
	
	while(1) {
		printf("회문검사할 단어를 입력하세요(최대 길이 15자/입력종료 : !) >> "); 
		scanf("%[^\n]", s);																//%['문자'] : '문자'가 나오기 전까지 모든 입력을 받음; 공백문자도 입력받기 위한 장치 
		clear_buffer();																	//buffer를 비워서 무한루프 방지 
		
		if(s[0] == '!' && strlen(s) == 1)												//0번 인덱스의 값이 '!'이고 입력된 문자열의 길이가 1인 경우 종료 
			exit(0);
			
		else if(strlen(s) > 15) {														//배열의 최대 크기를 초과한 경우 
			clear_buffer();
			printf("최대 문자열 크기를 초과하였습니다. 다시 입력하세요.\n"); 
		}
		
		else {																			//회문검사 시작 
			printf("입력한 단어 : %s\n", &s); 
			
			for(int i=0; i<strlen(s); i++) {											//입력한 문자의 수 만큼 루프 
				if(s[i] >= 'a' && s[i] <= 'z') {										//소문자인 경우 별도 과정을 거치지 않고 큐에 저장 
					add_rear(&queue, s[i]);
					count++;
				}
				else if(s[i] >= 'A' && s[i] <= 'Z') {									//대문자인 경우 
					s[i] += ('a' - 'A');												//소문자로 변환 
					add_rear(&queue, s[i]);												//큐에 추가 
					count++; 
				}
			}
			
			deque_print(&queue);														//불필요한 문자를 제거한 문자열이 저장된 큐 출력 
			
			for(int i=0; i<count/2; i++) {												//글자의 수가 홀수인 경우 가운데 단어는 비교할 필요가 없기 때문에 나머지는 고려하지 않음 
				if(delete_front(&queue) != delete_rear(&queue))							//큐의 앞과 뒤에서 원소 1개를 꺼내어 서로 비교 
					result++;															//회문이 아닌 경우 result의 값 변조 
			}
			if(result==0) 																//result의 값이 0 즉 회문인 경우
				printf("은(는) 회문입니다.\n\n", &s);
			else																		//result의 값이 0이 아닌 즉 회문이 아닌 경우 
				printf("은(는) 회문이 아닙니다.\n\n", &s);
			//아래 문장은 while 루프를 위한 초기화
			init_deque(&queue);															//큐 초기화 
			count = 0;																	//count 변수 초기화 
			result = 0;																	//result 변수 초기화 
		}
	}
	return 0;
}
