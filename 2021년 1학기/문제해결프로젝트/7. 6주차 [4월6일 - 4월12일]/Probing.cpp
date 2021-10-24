#include <cstdio>	//C언어의 stdio.h와 같음 C의 입출력 함수를 포함한 헤더파일
#include <vector>	//vector 클래스를 사용하기 위한 헤더파일(배열과의 차이점 : 가변형, 입출력 함수 제공)
using namespace std;//표준 이름공간을 사용함

//지급되지 않은 행운권 번호를 찾는 함수, 행운권 번호가 지급되었는지 알아내는 함수, 지급된 행운권 번호의 지급 여부를 갱신하는 함수가 정의된 클래스
class TicketTable {
public:
	vector<bool> used;						//행운권 번호의 지급 여부를 저장하는 used 벡터 선언
	int length;								//used 벡터의 길이

	TicketTable(int length) {				//length를 매개변수로 받는 생성자
		this->length = length;				//매개변수로 받은 length를 멤버변수 length에 저장
		this->used.assign(length, false);	//기존 벡터를 지우고 false값을 length개 가지는 벡터로 초기화
	}

	int findEmptyIndexByUserId(int userId) {//회원번호로 지급되지 않은 행운권 번호를 찾는 함수
		int index = userId % length;		//회원번호 (mod 행운권번호의 수) 값을 index에 저장

		while(this->isEmpty(index) == true) {//used 벡터의 index 번의 값이 true일 동안 반복(사용 가능한 경우 isEmpty함수가 false를 리턴함) (함수 설계 잘못됨)
			index = (index + 1) % length;	//while문 안의 조건이 true일 동안 반복하기 때문에 지금되지 않은 행운권 번호를 찾을때 까지(index의 값을 증가시킨 뒤 length로 나눈 나머지값을 가지고 다시 비교) 반복
		}

		return index;						//지급되지 않은 행운권 번호를 리턴
	}

	bool isEmpty(int ticketIndex) {			//ticketIndex(행운권 번호)가 지급되었는지 리턴하는 함수
		return this->used[ticketIndex];		//used 벡터의 ticketIndex값의 논리값 리턴
	}

	void setUsed(int index, bool status) {	//행운권 번호의 지급 여부를 갱신하는 함수
		this->used[index] = status;			//used 벡터의 index값을 status로 갱신
	}
};

//행운권 번호를 저장하는 벡터를 리턴하는 함수
vector<int> getTicketNumbers(int n, int m, const vector<int> &ids) {
	vector<int> tickets;					//행운권 번호를 저장할 정수형 벡터 tickets 선언
	TicketTable table = TicketTable(n);		//TicketTable형 인스턴스 table 생성

	for(int i=0; i<m; i++) {				//m(회원의 수)번 반복하여
		int userId = ids[i];				//i번째 회원번호를 userId에 저장
		int ticketIndex = table.findEmptyIndexByUserId(userId);	//회원번호를 인자로 비어있는 index를 찾아 ticketIndex에 저장
		tickets.push_back(ticketIndex);		//ticketIndex를 tickets 벡터의 맨 뒤에 추가
		table.setUsed(ticketIndex, true);	//ticketIndex를 사용된 행운권 번호로 갱신
	}

	return tickets;							//tickets 벡터 리턴
}

int main() {
	int n, m;					//n : 행운권의 수, m : 회원의 수
	scanf("%d %d", &n, &m);		//행운권의 수, 회원의 수 입력받음

	vector<int> ids(m);			//0으로 초기화된, m개의 정수를 저장하는 벡터 ids 선언
	for(int i=0; i<m; i++) {	//m(회원의 수)번 반복하여
		scanf("%d", &ids[i]);	//회원번호 입력받음
	}

	vector<int> tickets = getTicketNumbers(n, m, ids);	//회원번호를 인자로 넘겨 행운권 번호를 tickets 벡터에 저장
	for(int i=0; i<tickets.size(); i++) {				//tickets 벡터의 원소의 수 만큼 반복하여
		printf("%d\n", tickets[i]);						//행운권 번호 출력
	}
}
