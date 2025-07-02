# 큰수연산을 직접 구현해보기도 해야하는데, 하기 귀찮다.
# 파이썬 sys 모듈도 사용해보고싶긴 한데, 하기 귀찮다.
# 나중에는 꼭 해보자!
# 아니면 내일이라도!!
# 일단 정답인듯?

N = int(input())
result = 1

while (N):
    result *= N
    N -= 1

print(result)
