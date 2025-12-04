def solve():
    n, k = map(int, input().split())
    A = list(map(int, input().split()))

    cnt = {}
    for a in A:
        if a not in cnt: cnt[a] = 0
        cnt[a] += 1
    
    for a in cnt:
        if cnt[a]%k:
            print(0)
            return
        cnt[a] = cnt[a] // k
    
    ans = 0
    left, right = 0, 0
    cumulatedCnt = {}
    overflowValue = -1
    while left < n:
        while overflowValue == -1 and right <= n:
            if right < n:
                if A[right] not in cumulatedCnt:
                    cumulatedCnt[A[right]] = 0
                cumulatedCnt[A[right]] += 1
                if cumulatedCnt[A[right]] > cnt[A[right]]:
                    overflowValue = A[right]
            right += 1
        ans += right-left-1
        cumulatedCnt[A[left]] -= 1
        if A[left] == overflowValue:
            overflowValue = -1
        left += 1
    print(ans)

t = int(input())
for _ in range(t):
    solve()