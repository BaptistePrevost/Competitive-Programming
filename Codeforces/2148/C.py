def solve():
    n, m = map(int, input().split())
    ans = 0
    curA, curB = 0, 0
    for i in range(n):
        a, b = map(int, input().split())
        ans += a-curA
        if (a-curA)%2 == (curB==b): ans -= 1
        curA, curB = a, b
    ans += m-curA
    print(ans)

t = int(input())
for _ in range(t):
    solve()