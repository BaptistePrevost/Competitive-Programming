primes = [2, 3, 5, 6, 7, 10, 11, 12, 13, 14, 15, 17, 18, 19, 20, 21, 22, 23, 24, 26, 28, 29, 30, 31, 33, 34, 35]

def solve():
    n = int(input())
    ans = 40
    for a in map(int, input().split()):
        for p in primes:
            if a%p: ans = min(ans, p)
    print(ans)

t = int(input())
for _ in range(t):
    solve()