for _ in range(int(input())):
    n = int(input())
    a = list(set(map(int, input().split())))
    a.sort()
    a = a[::-1]
    m = a[0]
    ans = 0
    offset = 0
    for b in a:
        ans += m-b-offset
        offset +=m-b-offset
    print(ans)