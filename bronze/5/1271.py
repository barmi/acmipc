# std in으로 2개의 정수를 입력받아서, 정수나눗셈 몫과 나머지를 출력한다.

a, b = map(int, input().split())
print(a//b)
print(a%b)