def solve():
    x, n = map(int, input().split())
    print(x if n%2 else 0)

t = int(input())
for _ in range(t):
    solve()