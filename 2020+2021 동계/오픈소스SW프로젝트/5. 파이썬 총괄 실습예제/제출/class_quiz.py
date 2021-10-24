# quiz> 주어진 코드를 활용하여 직방의 부동산정보 제공 프로그램을 작성하시오.

# (출력예제)
# 총 3대의 매물이 있습니다.
# 지산동 원룸 월세 500/30 2010년
# 학동 아파트 매매 3억 2007년
# 서석동 주택 전세 2억 2005년

# [코드]
class House:
    #매물 초기화
    def __init__(self, location, house_type, deal_type, price, completion_year):
        self.location = location
        self.house_type = house_type
        self.deal_type = deal_type
        self.price = price
        self.completion_year = completion_year
    
    #매물 정보 표시
    def show_detail(self):
        
        print("{0} {1} {2} {3} {4}" .format(self.location, self.house_type, self.deal_type, self.price, self.completion_year))

#객체생성 및 출력
House1 = House("지산동", "원룸", "월세", "500/30", "2010년")
House2 = House("학동", "아파트", "매매", "3억", "2007년")
House3 = House("서석동", "주택", "전세", "2억", "2005년")

House_list = [House1, House2, House3]
print("총 {}대의 매물이 있습니다." .format(len(House_list)))
for member in House_list :
    member.show_detail()