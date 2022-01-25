MOD = 998244353 
n, a0, x, y, k, M = map(int, input().split())
a = [a0]
for _ in range(n-1):
    a.append((a[-1]*x+y)%M)


ans = 0
b = [a]
for i in range(1,k+1):
    for z in range(pow(n, i-1)):
        curr = b.pop(0)
        ans+=sum(curr)/pow(n,i)
        for j in range(n):
            b.append([curr[pick] if pick!=j else curr[pick]-(curr[pick]%i) for pick in range(n)])

print(int((ans*pow(n,k))%MOD))