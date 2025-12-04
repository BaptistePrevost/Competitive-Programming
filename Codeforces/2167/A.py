def solve():
    a,b,c,d = map(int, input().split())
    print("YES" if a == b and b == c and c == d else "NO")

t = int(input())
for _ in range(t):
    solve()