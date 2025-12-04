def solve():
    n, m, q = map(int, input().split())
    a = list(map(int, input().split()))
    b = list(map(int, input().split()))
    a.sort(reverse=True)
    b.sort(reverse=True)

    L = [(v,1) for v in a] + [(v,2) for v in b]
    L.sort(reverse=True)
    commonPrefix = [(0,0,0)]
    for i in range(len(L)):
        commonPrefix.append((commonPrefix[-1][0]+L[i][0], commonPrefix[-1][1]+(L[i][1]==1), commonPrefix[-1][2]+(L[i][1]==2)))
    aPrefix = [0]
    bPrefix = [0]
    for i in range(len(a)):
        aPrefix.append(aPrefix[-1]+a[i])
    for i in range(len(b)):
        bPrefix.append(bPrefix[-1]+b[i])
    
    for _ in range(q):
        x, y, z = map(int, input().split())

        left, right = 0, z+1
        while right-left>1:
            mid = (left+right)//2
            if commonPrefix[mid][1] <= x and commonPrefix[mid][2] <= y:
                left = mid
            else:
                right = mid

        ans = commonPrefix[left][0]
        
        z -= left
        if z > 0:
            if commonPrefix[left][1] == x:
                ans += bPrefix[commonPrefix[left][2]+z] - bPrefix[commonPrefix[left][2]]
            else:
                ans += aPrefix[commonPrefix[left][1]+z] - aPrefix[commonPrefix[left][1]]
        print(ans)

t = int(input())
for _ in range(t):
    solve()