data = []
with open("/home/bprevost/Competitive-Programming/Advent of Code/1.in") as f:
    for line in f.readlines():
        data.append([c for c in line.strip()])
    
    print(data)

numKeypad = [
    ['7', '8', '9'],
    ['4', '5', '6'],
    ['1', '2', '3'],
    [None, '0', 'A']
]

numToPos = {
    '7': (0, 0),
    '8': (0, 1),
    '9': (0, 2),
    '4': (1, 0),
    '5': (1, 1),
    '6': (1, 2),
    '1': (2, 0),
    '2': (2, 1),
    '3': (2, 2),
    '0': (3, 1),
    'A': (3, 2),
}

dirKeypad = [
    [None, '^', 'A'],
    ['<', 'v', '>']
]

dirToPos = {
    '^': (0, 1),
    'A': (0, 2),
    '<': (1, 0),
    'v': (1, 1),
    '>': (1, 2)
}


def bfs(c, x, y, pad, ans):
    L = [(x,y,"")]
    found = False
    while L:
        N = []
        for x, y, path in L:
            if pad[x][y] == c:
                path += 'A'
                ans.append(path)
                found = True
                continue
            if found: continue
            if pad[x][y] == None:
                continue
            if x>0:
                N.append((x-1, y, path + '^'))
            if x<len(pad)-1:
                N.append((x+1, y, path + 'v'))
            if y>0:
                N.append((x, y-1, path + '<'))
            if y<len(pad[0])-1:
                N.append((x, y+1, path + '>'))
        L = N

transitions = {}
for start in 'A^v<>':
    transitions[start] = {}
    for end in 'A^v<>':
        ts = []
        bfs(end, dirToPos[start][0], dirToPos[start][1], dirKeypad, ts)
        transitions[start][end] = ts


mem = [{} for _ in range(26)]

def solve(seq, depth):
    if depth == 0: return len(seq)
    if seq not in mem[depth]:
        ret = 0
        prev = 'A'
        for c in seq:
            mn = 999999999999999999999
            for nxt in transitions[prev][c]:
                x = solve(nxt, depth-1)
                if x < mn:
                    mn = x
            ret += mn
            prev = c
        mem[depth][seq] = ret
    return mem[depth][seq]

ans = 0
for code in data:
    x, y = 3, 2
    totL = 0
    for c in code:
        sps = []
        bfs(c, x, y, numKeypad, sps)
        x, y = numToPos[c]

        minL = 999999999999999999999
        for sp in sps:
            l = solve(sp, 25)
            if l < minL:
                minL = l
        totL += minL

    ans += totL * int(''.join(code[:-1]))

print(ans)

