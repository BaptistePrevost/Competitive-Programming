def solve():
    n = int(input())
    a = str(input())
    m = int(input())
    b = str(input())
    s = str(input())

    i = 0
    for c in s:
        if c == 'D':
            a+=b[i]
        else:
            a = b[i]+a
        i+=1
    print(a)

t = int(input())
for _ in range(t):
    solve()