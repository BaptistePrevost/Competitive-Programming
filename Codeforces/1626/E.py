'''
    Author : Baptiste Prévost

    Idea :
        - Only need to perform DFS once from an arbitrary root, and store the parent of each node, and the number of black nodes in its subtree
        - Then iterate over the arcs x->y. Keep if iff y is black, or if the subtree of y without x->y has at least 2 black nodes.
        - Revert the arcs, and perform bfs multirooted with black nodes
        - TLE in PyPy3, I'm rewriting this in c++
'''

import sys
inp = sys.stdin.readline

def solve():
    n = int(inp())
    c = list(map(int, inp().split()))
    vert = [[] for _ in range(n)]
    par = [-1 for _ in range(n)]
    count = [0 for _ in range(n)]
    for _ in range(n-1):
        u, v = map(int, inp().split())
        vert[u-1].append(v-1)
        vert[v-1].append(u-1)

    def dfs(x: int, origin: int):
        par[x]=origin
        for y in vert[x]:
            if y != origin:
                dfs(y,x)
                count[x] += count[y]
        count[x] += c[x]
    dfs(0, -1)

    vert = [[j for j in vert[i] if (i==par[j] and (c[i] or count[0]-count[j] > 1)) or (i!=par[j] and (c[i] or count[i] > 1))] for i in range(n)]

    bfs = [i for i in range(n) if c[i]]
    while bfs:
        current = bfs.pop(0)
        c[current]=1
        bfs += [son for son in vert[current] if not c[son]]

    print(" ".join(map(str, c)))

def main():
    solve()

if __name__ == '__main__':
	main()