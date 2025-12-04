def solve():
    n, m = map(int, input().split())
    x = 20
    p = 1
    cnt = {1:0}
    for _ in range(x):
        p*=3
        cnt[p]=0

    k = 0
    c = 0
    while n > 0:
        while p > n:
            p //= 3
            x -= 1
        n-=p
        c += 3*p + x*(p//3)
        k+=1
        cnt[p]+=1
    
    if k>m:
        c=-1
    else:
        p=1
        for _ in range(20): p*=3
        while p>1:
            s = cnt[p]
            if k<=m: s=min(s,(m-k)//2)
            cnt[p]-=s
            k+=2*s
            p//=3
            c -= s*p
            cnt[p]+=3*s
    print(c)


t = int(input())
for _ in range(t):
    solve()