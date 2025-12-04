data = []
with open("/home/bprevost/Competitive-Programming/Advent of Code/1.in") as f:
    for line in f.readlines():
        data.append([c for c in line.strip()])

visited = set()

def dfs(i, j, c):
    if i*len(data[0]) + j in visited: return 0, 0
    visited.add(i*len(data[0]) + j)

    a = 1
    p = 0
    if i-1 >= 0 and data[i-1][j] == c:
        da, dp = dfs(i-1, j, c)
    else:
        da, dp = 0, -1
        k = j
        while True:
            if k >= len(data[0]) or data[i][k] != c or (i-1>=0 and data[i-1][k] == c): break
            dp += 1
            k += 1
        k = j
        while True:
            if k < 0 or data[i][k] != c or (i-1>=0 and data[i-1][k] == c): break
            dp += 1
            k -= 1
        if dp > 0:
            dp = 1/dp

    a += da
    p += dp
    if i+1 < len(data) and data[i+1][j] == c:
        da, dp = dfs(i+1, j, c)
    else:
        da, dp = 0, -1
        k = j
        while True:
            if k >= len(data[0]) or data[i][k] != c or (i+1<len(data) and data[i+1][k] == c): break
            dp += 1
            k += 1
        k = j
        while True:
            if k < 0 or data[i][k] != c or (i+1<len(data) and data[i+1][k] == c): break
            dp += 1
            k -= 1
        if dp > 0:
            dp = 1/dp
    a += da
    p += dp
    if j-1 >= 0 and data[i][j-1] == c:
        da, dp = dfs(i, j-1, c)
    else:
        da, dp = 0, -1
        k = i
        while True:
            if k >= len(data) or data[k][j] != c or (j-1>=0 and data[k][j-1] == c): break
            dp += 1
            k += 1
        k = i
        while True:
            if k < 0 or data[k][j] != c or (j-1>=0 and data[k][j-1] == c): break
            dp += 1
            k -= 1
        if dp > 0:
            dp = 1/dp
    a += da
    p += dp
    if j+1 < len(data[0]) and data[i][j+1] == c:
        da, dp = dfs(i, j+1, c)
    else:
        da, dp = 0, -1
        k = i
        while True:
            if k >= len(data) or data[k][j] != c or (j+1<len(data[0]) and data[k][j+1] == c): break
            dp += 1
            k += 1
        k = i
        while True:
            if k < 0 or data[k][j] != c or (j+1<len(data[0]) and data[k][j+1] == c): break
            dp += 1
            k -= 1
        if dp > 0:
            dp = 1/dp
    a += da
    p += dp
    # print(i, j, c, a, p)
    return a, p

ans = 0
for i in range(len(data)):
    for j in range(len(data[0])):
        if i*len(data[0]) + j in visited: continue
        a, p = dfs(i, j, data[i][j])
        # print("\t", i, j, data[i][j], a, p)
        ans += a*round(p)
print(ans)