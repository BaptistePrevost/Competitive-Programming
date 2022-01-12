for _ in range(int(input())):
    n, k = map(int, input().split())
    s = input()
    d = {}
    for i in range(n):
        if s[i] not in d:
            d[s[i]]=1
        else:
            d[s[i]]+=1
    pairs=0
    ones=0
    for e in d:
        pairs+=d[e]//2
        ones+=d[e]%2
    ans=2*(pairs//k)
    ones+=2*(pairs%k)
    if (pairs//k>0 and ones>=n-pairs%k) or (ones>=k):
        ans+=1
    print(ans)
