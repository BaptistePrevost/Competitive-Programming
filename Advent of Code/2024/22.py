data = []
with open("/home/bprevost/Competitive-Programming/Advent of Code/1.in") as f:
    for line in f.readlines():
        data.append(int(line))


cnt = {
    i: {
        j: {
            k: {
                l: [-10 for _ in range(len(data))] for l in range(-9, 10)
            } for k in range(-9, 10)
        } for j in range(-9, 10)
    } for i in range(-9, 10)
}

def f(x):
    x = ((x*64)^x)%M
    x = ((x//32)^x)%M
    x = ((x*2048)^x)%M
    return x


M = 16777216
for v, val in enumerate(data):
    vals = [val, 0, 0, 0]
    diffs = [0, 0, 0, 0]
    for _ in range(3):
        vals[0], vals[1], vals[2], vals[3] = f(vals[0]), vals[0], vals[1], vals[2]
        diffs[0], diffs[1], diffs[2], diffs[3] = vals[0]%10 - vals[1]%10, diffs[0], diffs[1], diffs[2]
    
    for _ in range(1997):
        vals[0], vals[1], vals[2], vals[3] = f(vals[0]), vals[0], vals[1], vals[2]
        diffs[0], diffs[1], diffs[2], diffs[3] = vals[0]%10 - vals[1]%10, diffs[0], diffs[1], diffs[2]
        if cnt[diffs[3]][diffs[2]][diffs[1]][diffs[0]][v] == -10:
            cnt[diffs[3]][diffs[2]][diffs[1]][diffs[0]][v] = vals[0]%10

ans = 0
for i in range(-9, 10):
    for j in range(-9, 10):
        for k in range(-9, 10):
            for l in range(-9, 10):
                ans = max(ans, sum(v if v>-10 else 0 for v in cnt[i][j][k][l]))

print(ans)