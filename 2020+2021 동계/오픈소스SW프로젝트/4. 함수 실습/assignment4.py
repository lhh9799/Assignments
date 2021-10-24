#ex01
def hello(world) :
    print("Hello", world)
hello("python")

#ex02
def hello_return(world) :
    value="hello " + str(world)
    return value
str1 = hello_return("python")
print(str1)

#ex03
def func_mul1(x) :
    a1 = x * 2
    a2 = x * 4
    a3 = x * 6
    return a1, a2, a3
a1, a2, a3 = func_mul1(3)
print(a1, a2, a3)
print(type(a1))

#튜플리턴
def func_mul2(x) :
    a1 = x * 2
    a2 = x * 4
    a3 = x * 6
    return (a1, a2, a3)
tup = func_mul2(4)
print(tup, type(tup), list(tup))

#리스트 리턴
def func_mul3(x) :
    a1 = x * 2
    a2 = x * 4
    a3 = x * 6
    return [a1, a2, a3]
lis = func_mul3(5)
a, b, c = func_mul3(6)
print(a, b, c)
print(lis, type(lis), set(lis))

#딕셔너리 리턴
def func_mul4(x) :
    a1 = x * 2
    a2 = x * 4
    a3 = x * 6
    return {'first' : a1, 'second' : a2, 'third' : a3}

dic = func_mul4(1)
print(type(dic), dic)
print(dic.get('a2'))
print(list(dic.items()))
print(dic.keys(), dic.values())

a, b, c = dic
print(a)
print(dic.get(b))

#ex04
# *args, **kwargs의 이해
def args_func(*args) : #가변길이의 튜플입력
    for i, v in enumerate(args) :
        print(i, v)
#args_func('kim')
args_func('kim', 'park', 'lee', 'an')

print()
print()
print()

# **kwargs #가변길이의 딕셔너리 입력
def kwarg_func(**kwargs) :
    for k, v in kwargs.items() :
        print(k, v)

kwarg_func(name1 = 'kim', name2 = 'park', name = 'lee')
kwarg_func(name1 = 'kim')

print()
print()
print()

#전체 혼합
def exam(arg1, arg2, *args, **kwargs) :
    print(arg1, arg2, args, kwargs)

exam(10, 20, 'park', 'kim', age1 = 33, age2 = 23, age3 = 26)
exam(10, 20)

#ex05 중첩함수
def nested_func(num) :
    def func_in_func(num) :
        print('>>>', num)
    print("In func")
    func_in_func(num + 100)

nested_func(1)

#ex06 hint
def func_mul5(x:int)->list :
    a1 = x * 2
    a2 = x * 4
    a3 = x * 6
    return [a1, a2, a3]
print(func_mul5(5))

def tot_len(word:str, num:list)->int :
    return len(word) * num
print('hint exam : ', tot_len("python is useful", 10))

#람다식 예제
#메모리 절약, 코드 간결
#일반 함수는 객체 생성 -> 메모리(리소스) 할당
#람다는 즉시 실행 -> 메모리 초기화

def func_ex1(num) :
    return num*10

#def func_ex2(num) : return num * 10

#lambda x : x * 10

def mul_10(num:int)->int :
    return num * 10

mul_func = mul_10
print(mul_func)
print(type(mul_func))
print(mul_func(5))

#람다 함수
lambda_mul_10 = lambda x : x * 10
print('>>>', lambda_mul_10(10))

def func_final(x, y, func) :
    print(x * y * func(10))
func_final(10, 10, lambda_mul_10)
print()
print()
print(func_final(10, 10, lambda x : x * 1000))