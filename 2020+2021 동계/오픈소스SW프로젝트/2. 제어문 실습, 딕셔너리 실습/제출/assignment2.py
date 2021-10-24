# P1 1. 어느 식당의 메뉴와 가격은 돈가스 5,000원, 생선가스 5,500원, 우동 2,500원, 초밥 세트 9,000원이다.
# 이 메뉴들을 빈 dictonary를 생성한 후, 딕셔너리 자료구조를 이용하여 저장해보고 각각의 메뉴와 가격을 순차적으로 출력하는 프로그램을 작성하여 보자.
price = dict()
price['돈가스'] = 5000
price['생선가스'] = 5500
price['우동'] = 2500
price['초밥 세트'] = 9000
print("==========================================MENU==========================================")
temp = list(price.items())
print(temp)

# P2 2. 어느 커피숍에는 메뉴가 4가지 있다.
# "아메리카노, 카페라떼, 그린티라떼, 모카라떼" 각 메뉴의 가격은 2,000원, 2500원, 3,000원, 3,500원이다.
# 이 목록을 dictionary로 작성해보고 아메리카노와 바닐라 라떼가 있는지 없는지 확인해보자.
price = {'아메리카노' : 2000, '카페라떼' : 2500, '그린티라떼' : 3000, '모카라떼' : 3500}
print("==========================================MENU==========================================")
print(list(price.keys()))
menu = input("메뉴 주문>> ")
if menu in price:
    print("주문한 ", menu, "의 가격은 ", price[menu], "입니다." ,sep="")
else :
    print("주문한 메뉴는 판매하지 않습니다.")

# P3 3. 동물이름을 한글로 입력받아, 해당되는 영어단어로 알려주는 프로그램을 만들어 보자(동물영어사전 프로그램).
animal = {'강아지' : 'dog', '코끼리' : 'elephant'}
name = input("동물이름>> ")
if name in animal :
    print(name, "는 영어로 ", animal[name], "입니다." ,sep="")
else :
    print("등록되지 않은 언어입니다.")

# P4 1. 주소록에 친구를 등록하고, 친구를 이름으로 검색한 후 연락처를 출력하는 프로그램을 작성하시오.
# 실행결과를 참고하여 문제를 해결하시오.
contact = {'홍길동' : '010-1111-1234', '김유신' : '010-2222-1234', '강감찬' : '010-3333-1234', '이순신' : '010-4444-1234', '김좌진' : '010-5555-1234'}
flag = True
while flag :
    name = input("search_name : ")
    if name in contact.keys() :
        print(contact.get(name))
    else :
        print("Not Found\n프로그램 종료")
        flag = False

# P5 2. 현대인들은 축약어를 많이 사용한다.
# 예를 들어서 "B4(Before)" "TX(Thanks)" "BBL(Be Back Later)" "BCNU(Be Seeing You)" "HAND(Have A Nice Day)"와 같은 축약어들이 있다.
# 축약어를 풀어서 일반적인 문장으로 변환하는 프로그램을 작성하여 보자.
abbr = {'B4' : 'Before', 'TX' : 'Thanks', 'BBL' : 'Be Back Later', 'BCNU' : 'Be Seeing You', 'HAND' : 'Have A Nice Day'}
sentence = input("번역할 문장을 입력하시오: ")
senList = sentence.split()
i = 0
while i < len(senList) :
    if senList[i] in abbr.keys() :
        senList[i] = abbr.get(senList[i])
        print(senList[i], " ", sep="", end="")
    else :
        print(senList[i], " ", sep="", end="")
    i += 1

# P6 3. 재고품 관리를 하려고 한다.
# 비품이 떨어지지 않도록 비품을 3개 이상으로 유지한다고 할 때, 각각 사야할 비품과 가격, 총 비용을 계산해 출력하여라.
stock = {'믹스' : [6000,2], '종이컵' : [15000,3], '커피스틱' : [3000,1]}
price = 0
Subtotal = 0
for item in stock.keys() :
    if stock.get(item)[1] >= 3 :
        continue
    else :
        qty = 3 - int (stock.get(item)[1])
        price = qty * stock.get(item)[0]
        Subtotal += price
        print("{} : {}개 부족" .format(item, qty))
        print("{}를 구입하는 데 필요한 금액은 {}원 입니다." .format(item, price))
else :
    print("부족한 비품을 사는데 필요한 총비용 : ", Subtotal, sep="")