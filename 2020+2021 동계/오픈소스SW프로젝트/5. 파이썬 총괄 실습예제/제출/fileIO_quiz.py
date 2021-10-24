# Quiz 2> 현재 수강하고 있는 과목은 매주 1회 작성해야 하는 레포트가 있습니다. 
# 레포트는 항상 아래와 같은 형태로 출력되어야 합니다.

# - X주차 report
# 학과 : 
# 이름 : 
# 학번 : 
# coding 내용 : 


# 1주차부터 8주차까지의 보고서 파일을 만드는 프로그램을 작성하시오.

# 조건 : 파일명은 '1주차.txt','2주차.txt','3주차.txt',...와 같이 만듭니다.
# hint 1: n주차 파일이름 작성-> str(i)+"주차.txt"이용
# hint 2: 파일생성에 for문 이용
# 다음 코드를 이용하여 완성하기
# with open(str(i)+"주차.txt","w",encoding='utf8') as report_file:

for i in range(1, 9, 1) :
       with open(str(i) + "주차.txt", "w", encoding='utf8') as report_file :
              print(" - {}주차 report" .format(i), file = report_file)
              print("이름 : ", file = report_file)
              print("학번 : ", file = report_file)
              print("coding 내용 : ", file = report_file)

# ========================================================================================
# Quiz 3> clc에 업로드된 score.txt파일은 "수학:40\n, 영어:50\n.."형태로 내용이 입력되어 있다.
# 이 텍스트 파일을 받아서, 평균점수를 계산하시오.
# hint : 리스트로 불러와서 딕셔너리 형태로 변형 후 계산
#        문자열함수 split을 이용하여 과목, 점수를 key와 value로 구분할 것!
# 다음 코드 완성하기!
with open("./test_fio/score.txt", "r",encoding="utf8") as score_file :
       score_dict={}
       lines = score_file.readlines()
       for line in lines :
              subject, score = line.split(":")
              score_dict[subject] = int (score)
       print("평균 : {:6.3f}" .format(sum(score_dict.values()) / len(score_dict)))