def solve():
    n = int(input())
    p = 10
    ans = []
    for _ in range(19):
        if n%(p+1) == 0:
            ans.append(n//(p+1))
        p*=10
    print(len(ans))
    if ans:
        for x in ans[::-1]: print(x, end=' ')
        print()

t = int(input())
for _ in range(t):
    solve()