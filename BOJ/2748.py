#이 문제 까지는 DP가 아니어도 할 수 있ㅇ르 것 같아서 기존에 풀었던 코드를 참고해서 풀어봄
#참고: 2747번

global n

def su(front, back):
    global n
    n -= 1
    if n == 0:
        return back
    return su(back, front + back)

def main():
    front = int(0)
    back = int(1)
    global n
    n = int(input())
    print(su(front, back))

if __name__ == "__main__":
    main()
