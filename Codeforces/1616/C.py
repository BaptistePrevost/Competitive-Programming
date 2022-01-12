for _ in range(int(input())):
    n = int(input())
    a=list(map(int,input().split()))
    if n==1 or n==2:
        print(0)
    else:
        best = 0
        for i in range(n):
            c = {}
            for j in range(n):
                if i!=j:
                    if (a[i]-a[j])/(i-j) in c:
                        c[(a[i]-a[j])/(i-j)]+=1
                    else:
                        c[(a[i]-a[j])/(i-j)] = 1
            best = max(best, max(c.values()))
        print(n-1-best)