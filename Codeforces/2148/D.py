import math

def solve():
    n = int(input())
    A = list(map(int, input().split()))
    
    evens = [a for a in A if a%2==0]
    odds = sorted([a for a in A if a%2==1], reverse=True)

    if len(odds) == 0:
        print(0)
        return

    ans = sum(evens) + sum(odds[:math.ceil(len(odds)/2)])
    print(ans)

t = int(input())
for _ in range(t):
    solve()