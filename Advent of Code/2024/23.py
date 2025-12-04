data = []
edges = []
adj = {}
with open("/home/bprevost/Competitive-Programming/Advent of Code/1.in") as f:
    for line in f.readlines():
        u, v = line.strip().split('-')
        if u not in adj: adj[u] = set()
        if v not in adj: adj[v] = set()
        adj[u].add(v)
        adj[v].add(u)

verticesByDegree = [set() for _ in range(len(adj)+1)]
for u in adj:
    verticesByDegree[len(adj[u])].add(u)


mx = 0
ans = None
for u in adj:
    clique = set([u])
    for v in adj[u]:
        valid = True
        for w in clique:
            if v not in adj[w]:
                valid = False
                break
        if valid:
            clique.add(v)
    if len(clique) > mx:
        mx = len(clique)
        ans = ','.join(sorted([w for w in clique]))
print(ans)