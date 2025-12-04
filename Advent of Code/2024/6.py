M = []
with open("/home/bprevost/Competitive-Programming/Advent of Code/1.in") as f:
    for line in f.readlines():
        M.append([c for c in line.strip()])

baseX = -1
baseY = -1
for i in range(len(M)):
    for j in range(len(M[0])):
        if M[i][j] == '^':
            baseX = i
            baseY = j
            break

diff = [(-1,0), (0, 1), (1, 0), (0, -1)]
ans = 0
for i in range(len(M)):
    for j in range(len(M[0])):
        if M[i][j] != '.': continue

        M[i][j] = '#'
        x, y = baseX, baseY
        d = 0

        visited = set()
        debug = len(M)*len(M[0])
        while debug:
            debug -= 1
            if debug < 0:
                raise Exception("WTH ?")
            h = x*len(M)*4 + y*4 + d
            if h in visited:
                ans += 1
                break
            visited.add(h)

            dx = x+diff[d][0]
            dy = y+diff[d][1]
            if dx >= 0 and dx<len(M) and dy >= 0 and dy <len(M[0]):
                if M[dx][dy] == '#':
                    d = (d+1)%4
                else:
                    x = dx
                    y = dy
            else:
                break

        
        M[i][j] = '.'

print(ans)