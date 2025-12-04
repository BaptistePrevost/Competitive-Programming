data = []
with open("/home/bprevost/Competitive-Programming/Advent of Code/1.in") as f:
    for line in f.readlines():
        data.append([c for c in line.strip()])


for x in range(len(data)):
    for y in range(len(data[0])):
        if data[x][y] == 'E':
            xE, yE = x, y
        elif data[x][y] == 'S':
            xS, yS = x, y

print(xS, yS, xE, yE)
        
def display():
    for x in range(len(data)):
        for y in range(len(data[0])):
            print(data[x][y], end='')
        print()
    print()

def hash(x, y):
    return x*len(data[0]) + y


M = len(data)*len(data[0])
dp = [[((-1, -1), M) for y in range(len(data[0]))] for x in range(len(data))] #Shortest path

def solve():
    for x in range(len(data)):
        for y in range(len(data[0])):
            dp[x][y] = ((-1, -1), M)
    dp[xE][yE] = ((-1, -1), 0)
    L = [(xE, yE)]
    while L:
        L2 = []
        for x, y in L:
            if dp[x][y][1] > 9324: continue
            if x-1>=0:
                if data[x-1][y] != '#' and dp[x][y][1]+1 < dp[x-1][y][1]:
                    dp[x-1][y] = ((x,y), dp[x][y][1]+1)
                    L2.append((x-1,y))
            if x+1<len(data):
                if data[x+1][y] != '#' and dp[x][y][1]+1 < dp[x+1][y][1]:
                    dp[x+1][y] = ((x,y), dp[x][y][1]+1)
                    L2.append((x+1,y))
            if y-1>=0:
                if data[x][y-1] != '#' and dp[x][y][1]+1 < dp[x][y-1][1]:
                    dp[x][y-1] = ((x,y), dp[x][y][1]+1)
                    L2.append((x,y-1))
            if y+1<len(data[0]):
                if data[x][y+1] != '#' and dp[x][y][1]+1 < dp[x][y+1][1]:
                    dp[x][y+1] = ((x,y), dp[x][y][1]+1)
                    L2.append((x,y+1))

        L = L2

solve()
print(dp[xS][yS])

CHEAT = 20
cnt = {}
for x in range(len(data)):
    for y in range(len(data[0])):
        if data[x][y] == '#': continue
        for x2 in range(max(x-CHEAT, 0), min(x+CHEAT+1, len(data))):
            for y2 in range(max(y-CHEAT, 0), min(y+CHEAT+1, len(data[0]))):
                if abs(x-x2) + abs(y-y2) > CHEAT: continue
                if data[x2][y2] == '#': continue
                if dp[x][y][1] < dp[x2][y2][1]:
                    gain = dp[x2][y2][1] - dp[x][y][1] - abs(x-x2) - abs(y-y2)
                    if gain not in cnt:
                        cnt[gain] = 0
                    cnt[gain] += 1

ans = 0
for c in cnt:
    print(c, cnt[c])
    if c >= 100:
        ans += cnt[c]
print(ans)
