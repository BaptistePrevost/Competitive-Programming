pow2 = [1]
while pow2[-1]<200000:
    pow2.append(pow2[-1]*2)

def getCost(k: int):
    for i in range(len(pow2)):
        if pow2[i]>=k:
            return pow2[i]-k

for _ in range(int(input())):
    n = int(input())
    a = sorted(list(map(int, input().split())))

    first = {}
    for i in range(len(a)):
        if a[i] not in first:
            first[a[i]]=i
    
    ans = 200005
    for i in range(len(a)):
        x = a[i]
        if i!=0 and a[i]==a[i-1]:
            continue
        mid=0
        while i+mid<n:
            y = a[i+mid]
            j = first[y]
            bounds = (i, j-i, n-j)
            ans = min(sum(map(getCost, bounds)), ans)
            if not mid:
                mid=1
            else:
                mid*=2

    print(ans)