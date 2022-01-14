'''
    Author : Baptiste Prévost

    Idea :
        - We iterate over the bits of a mask, asserting whether we should keep the edges or not
        - I had trouble to beat TLE, and looked at "* r57shell" (https://codeforces.com/contest/1624/submission/142312509) code.
        - The best idea is an UnionFind algorithm. I also copied his setup for IO
'''


import sys
inp = sys.stdin.readline

def solve():
    inp()
    n, m = map(int, inp().split())
    edges= [tuple(map(int, inp().split())) for _ in range(m)]
    mask=0

    def getClass(x):
        if parent[x]==x:
            return x
        parent[x] = getClass(parent[x])
        return parent[x]

    for i in range(29,-1,-1):
        temp=mask|(1<<i)
        parent=list(range(n+1))
        classCount = n-1
        for a,b,w in edges:
            if not w&temp:
                a=getClass(a)
                b=getClass(b)
                if a != b:
                    parent[b] = a
                    classCount-=1

        if not classCount:
            mask=temp
    print(((1<<30) - 1) - mask)

def main():
    for _ in range(int(inp())):
        solve()

if __name__ == '__main__':
	main()