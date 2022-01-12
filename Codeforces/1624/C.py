import math

for _ in range(int(input())):
    n = int(input())
    a = list(map(int, input().split()))
    a.sort()
    a = a[::-1]
    used = (n+1)*[False]
    impossible=False
    for b in a:
        while b > n:
            b//=2
        while used[b]:
            b//=2
        if b:
            used[b]=True
        else:
            impossible=True
            break

    if impossible:
        print("NO")
    else:
        print("YES")