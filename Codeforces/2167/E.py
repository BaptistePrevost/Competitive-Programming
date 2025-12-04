def solve():
    n, k, x = map(int, input().split())
    A = list(map(int, input().split()))

    A = sorted(A)
    gaps = [(-A[0]-1, A[0])]
    for i in range(len(A)-1):
        gaps.append((A[i], A[i+1]))
    gaps.append((A[-1], x+x-A[-1]+1))

    lbd = lambda gap: gap[1]-gap[0]-1
    sortedGaps = sorted((gap for gap in gaps), key=lbd, reverse=True)

    current = lbd(sortedGaps[0])
    if current%2:
        current = (current+1)//2
    else:
        current //= 2
    ans = []
    while k > 0 and current > 0 and current >= lbd(sortedGaps[-1]):
        i = 0
        while i < len(sortedGaps):
            gap = sortedGaps[i]
            size = lbd(gap)
            if size%2:
                if (size+1)//2 < current: break
                if (size+1)//2 == current:
                    k-=1
                    ans.append(gap[0]+current)
                else:
                    if k > 0 and gap[0] >= 0:
                        k-=1
                        ans.append(gap[0]+current)
                    if k > 0 and gap[1] <= x:
                        k-=1
                        ans.append(gap[1]-current)
            else:
                if size//2 < current: break
                if k > 0 and gap[0] >= 0:
                    k-=1
                    ans.append(gap[0]+current)
                if k > 0 and gap[1] <= x:
                    k-=1
                    ans.append(gap[1]-current)
            i += 1
        current -= 1

    ans += A[:k]
    print(' '.join(str(a) for a in ans))


t = int(input())
for _ in range(t):
    solve()