from sys import stdin
input = stdin.readline

n = int(input().rstrip())
a = list(map(int, input().rstrip().split()))

cum = 1
over = False
for x in a:
    if x == 0:
        cum = 0
        break

if cum == 0:
    print(0)
else:
    for x in a:
        cum *= x
        if (cum > 1e18):
            over = True
            break
    print(-1) if over else print(cum)
