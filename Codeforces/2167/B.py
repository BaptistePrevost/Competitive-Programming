def solve():
    n = int(input())
    s, t = map(str, input().split())
    cS = {}
    for c in s:
        if c not in cS: cS[c] = 0
        cS[c] += 1
    for c in t:
        if c not in cS:
            return False
        if cS[c] == 0:
            return False
        cS[c] -= 1
    return True

t = int(input())
for _ in range(t):
    print("YES" if solve() else "NO")