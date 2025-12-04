data = {}
ands = {}
xors = {}
ors = {}
with open("/home/bprevost/Competitive-Programming/Advent of Code/1.in") as f:
    while True:
        line = f.readline().strip()
        if not line: break
    
        wire, value = line.split(':')
        wire = wire.strip()
        value = int(value)
        data[wire] = value
    while True:
        line = f.readline().strip()
        if not line: break

        lhs, rhs = line.split(' -> ')
        u, inst, v = lhs.split(' ')
        if inst == "OR":
            if u not in ors:
                ors[u] = {}
            if v not in ors[u]:
                ors[u][v] = []
            if v not in ors:
                ors[v] = {}
            if u not in ors[v]:
                ors[v][u] = []
            ors[u][v].append(rhs)
            ors[v][u].append(rhs)
        elif inst == "XOR":
            if u not in xors:
                xors[u] = {}
            if v not in xors[u]:
                xors[u][v] = []
            if v not in xors:
                xors[v] = {}
            if u not in xors[v]:
                xors[v][u] = []
            xors[u][v].append(rhs)
            xors[v][u].append(rhs)
        elif inst == "AND":
            if u not in ands:
                ands[u] = {}
            if v not in ands[u]:
                ands[u][v] = []
            if v not in ands:
                ands[v] = {}
            if u not in ands[v]:
                ands[v][u] = []
            ands[u][v].append(rhs)
            ands[v][u].append(rhs)

prv = {}
for i in range(1000):
    nxt = {}
    for u in data:
        if u in ors:
            for v in ors[u]:
                if v not in data: continue
                for w in ors[u][v]:
                    nxt[w] = data[u] | data[v]
                    prv[w] = (u, v, '|')
        if u in xors:
            for v in xors[u]:
                if v not in data: continue
                for w in xors[u][v]:
                    nxt[w] = data[u] ^ data[v]
                    prv[w] = (u, v, '^')
        if u in ands:
            for v in ands[u]:
                if v not in data: continue
                for w in ands[u][v]:
                    nxt[w] = data[u] & data[v]
                    prv[w] = (u, v, '&')
    for u in nxt:
        data[u] = nxt[u]


zs = sorted([u for u in data if u[0] == 'z'])
# ans = 0
# for z in zs[::-1]:
#     ans *= 2
#     ans += data[z]
# print(ans)

def dfs(u):
    if u not in prv:
        print(u, end='')
        return 1
    v, w, inst = prv[u]
    ret = 0
    print("[", u, "]", end='')
    print("(", end='')
    ret += dfs(v)
    print(inst, end='')
    ret += dfs(w)
    print(")", end='')
    return ret

for z in zs:
    dfs(z)
    print()