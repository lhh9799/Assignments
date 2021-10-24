Quiz 1 > 조대 후문에 항상 줄서서 먹는 맛집이 있습니다. 
대기 고객 관리를 효율적으로 하고자, 자동 대기 예약신청 시스템을 제작하였습니다.
시스템 코드를 확인하고 적절한 예외처리 구문을 넣으시오.

조건 1 : 1보다 작거나 숫자가 아닌 입력값이 들어올 때는 ValueError 로 처리
         출력 메시지 : "잘못된 값을 입력하였습니다."
조건 2 : 대기 손님이 예약 가능한 총 예약좌석은 10좌석으로 한정
         잔여 좌석이 0이 되면 Exception 에러를 발생시키고, 프로그램 종료
         출력 메시지 : "만석이 되어 더이상 예약을 받지 않습니다."

[코드]
remain_seat = 10
waiting = 1 #식당은 현재 만석 대기번호 1부터 시작
while(True):
    print("[남은 예약가능 좌석 : {0}]".format(remain_seat))
    order = int(input("몇 명 예약하시겠습니까?"))
    if order > remain_seat: #남은 예약 가능좌석보다 예약인원이 많을 때
        print("좌석이 부족합니다.")
    else:
        print("[대기번호 {0}] : {1} 좌석 예약이 완료되었습니다.".format(waiting,order))
        waiting += 1
        remain_seat -= order

