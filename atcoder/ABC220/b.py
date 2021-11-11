def main():
    k = int(input())
    a, b = input().split()
    a_decimal, b_decimal = 0, 0
    for i, c in enumerate(reversed(a)):
        a_decimal += int(c) * k ** i
    for i, c in enumerate(reversed(b)):
        b_decimal += int(c) * k ** i
    print(a_decimal * b_decimal)


main()
