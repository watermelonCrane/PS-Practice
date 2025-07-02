#성공
def main():
    n, m = input().split()
    n = int(n)
    m = int(m)

    print("%d\n%d" % (n // m, n % m))

if __name__ == "__main__":
    main()