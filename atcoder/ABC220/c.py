def main():
    n = int(input())
    a = list(map(int, input().split()))
    x = int(input())
    ans = 0
    s = 0
    for item in a:
        s += item
        ans += 1
        if s > x:
            print(ans)
            return
    ans = 0
    ans += x // s * n
    rest = x % s
    s = 0
    for item in a:
        s += item
        ans += 1
        if s > rest:
            print(ans)
            return


main()
