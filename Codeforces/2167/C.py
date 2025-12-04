def solve():
    n = int(input())
    A = list(map(str, input().split()))
    odd, even = 0, 0
    for a in A:
        if int(a)%2: odd+=1
        else: even+=1
    if odd==0 or even==0:
        print(' '.join(A))
    else:
        print(' '.join(sorted(A)))

t = int(input())
for _ in range(t):
    solve()