# P19 1. 다음과 같은 문자열 a:b:c:d가 있다. 문자열의 replace함수를 사용하여 a#b#c#d로 바꿔서 출력해보자.
a = "a:b:c:d"
b = a.replace(":", "#")
print(b)

# P19 2. 영어로 된 문장을 입력받아 전체를 대문자로 수정하고, 모든 공백을 제거한 후, 화면에 출력하시오.
str = input("입력 : ")
print("출력 :",str.replace(" ", "").upper())

# P20 3. 텍스트를 입력받아 입력한 내용이 몇 글자인지 알려주는 프로그램을 작성하시오.
# 알파벳 A의 개수, O의 개수를 출력하시오.
str = input("입력 : ")
print("전체 문자 개수 : ", len(str), "글자" ,sep="")
print("문자 a 개수 : ", str.count('a'))
print("문자 o 개수 : ", str.count('o'))

# P20 4. 사용자가 불필요한 공백 문자를 입력할 경우가 있으므로 그것을 처리해보자. 아래와 같이 배우고 싶은 3개의 프로그래밍 언어를 입력받는 프로그램을 만들어보자 여러 개의 항목을 쉼표 단위로 끊어서 입력받는 예제이다.
str1, str2, str3 = input("배우고 싶은 코딩 언어 3개 입력 : ").split(",")
print(str1.strip())
print(str2.strip())
print(str3.strip())

# P21 1. "20010902"형식으로 생년월일을 입력받아 현재 나이와 생일 정보를 추출하여 화면에 출력해주는 프로그램을 작성하시오.
birth = input("입력 : ")
print("출생연도 : {}년" .format(birth[0:4]))
print("생일 : {}월 {}일" .format(int (birth[4:6]), int (birth[6:])))
print("나이 : {}살" .format(2020 - int (birth[0:4] ) +1))

# P36 학생 리스트에 새 학생이 들어오면, 재정렬하여 이름순으로 번호와 출력하기
stdlist = ['이황', '이이', '원효']
print("현재학생은", stdlist)
name = input("전학 온 학생은 누구입니까? ")
stdlist.append(name)
print(stdlist)
print("번호 재정렬....")
stdlist.sort()
i = 1
for name in stdlist :
    print(i, name)
    i += 1