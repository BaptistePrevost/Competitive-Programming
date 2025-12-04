def solve():
    n = int(input())
    A = []
    for _ in range(n):
        A.append(list(map(int, input().split())))
    A = sorted(A, key=lambda a: a[0])
    i = 0
    startJ = 0
    while startJ < n:
        while startJ < n and A[startJ][0] <= i:
            startJ += 1
        minJ = -1
        minV = 99999999
        minS = 99999999
        for j in range(startJ, n):
            if A[j][i+1] < minV or (A[j][i+1] == minV and A[j][0] < minS):
                minV = A[j][i+1]
                minJ = j
                minS = A[j][0]
        while i < A[minJ][0]:
            print(A[minJ][i+1], end=' ')
            i+=1
    print()

t = int(input())
for _ in range(t):
    solve()