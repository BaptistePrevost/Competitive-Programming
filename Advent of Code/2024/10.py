trails = []
with open("/home/bprevost/Competitive-Programming/Advent of Code/1.in") as f:
    for line in f.readlines():
        trails.append([int(c) for c in line.strip()])

def dfs(i, j, prev):
    if i<0 or j<0 or i>=len(trails) or j>=len(trails[0]): return 0
    if trails[i][j] != prev+1: return 0
    if prev == 8: return 1
    prev += 1
    return dfs(i+1, j, prev) + dfs(i, j+1, prev) + dfs(i-1, j, prev) + dfs(i, j-1, prev)

ans = 0
for i in range(len(trails)):
    for j in range(len(trails[0])):
        if trails[i][j] > 0: continue
        ans += dfs(i, j, -1)

print(ans)