# 주소록 제작

# 연락처 클래스
class Contact:
    def __init__(self,id_num, name, phone_num, email):
        pass
    # 개인 연락처 출력
    def prt_info(self):
        pass

# 연락처 정보 입력
def add_cont(c_list):
    id_num=input("Id(00#) : ")
    name = input("Name : ")
    phone_num = input("Phone Number : ")
    email = input("email : ")
    print()
    #### Contact의 인스턴스 생성 
    print('saved.')
    print()
    
    c_list.append(cont)                 # 인스턴스 반환
    #### 입력받은 고객정보 파일로 저장(리스트를 파일로 저장하는 함수 사용)하는 코드 작성
    #### ---> with 사용하지 않고 작성할 것!
    

# 메뉴 출력
def prt_menu():
    print("1. Add")
    print("2. Info")
    print("3. Delete")
    print("4. Exit")
    print()
    
    menu = input("Select Menu Number : ")         # 메뉴 넘버 입력
    print()
    return int(menu)


# 이름으로 조회 된 연락처 삭제
def del_cont(c_list):
    rm_id = input("Id : ")        # 삭제 할 id 입력
    print()

    if len(c_list) > 0:
        # enumerate : 인덱스 생성
        for i, cont in enumerate(c_list):
            if str(cont.id_num).strip() == rm_id.strip():
                print('"{}" deleted.'.format(cont.name))
                print()
                del c_list[i]                # 해당 리스트 삭제
                break
        else:                               # 삭제 할 데이터 없을 경우
            print('No files to delete.')
            print()
    else:                                   # 연락처 리스트가 비어 있을 경우
        print('No files to delete.')
        print()


# 저장 된 모든 연락처 정보 출력
def prt_cont(c_list):
    
    if len(c_list) > 0:             # 연락처 리스트가 비어 있지 않은 경우
        
        for i in c_list:              # 리스트 형태로 된 인스턴스 정보 출력
            i.prt_info()
    else:                           # 연락처가 비어 있을 경우
        print('Contact is empty.')
        print()


# 프로그램 시작
def main():
    c_list=[]
    while True:
        # 실행 메뉴 번호 저장
        menu = prt_menu()
        if menu == 1:  # 추가
            add_cont(c_list)
        elif menu == 2:  # 출력
            prt_cont(c_list)
        elif menu == 3:  # 삭제
            del_cont(c_list)
        else:
            print("종료")
            break


if __name__ == "__main__":
    # 프로그램 시작
    main()
