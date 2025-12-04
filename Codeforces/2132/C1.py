def solve():
    n, m = map(int, input().split())
    x = 20
    p = 1
    for _ in range(x): p*=3

    k = 0
    c = 0
    while n > 0:
        while p > n:
            p //= 3
            x -= 1
        n-=p
        c += 3*p + x*(p//3)
        k+=1
    print(c)


t = int(input())
for _ in range(t):
    solve()