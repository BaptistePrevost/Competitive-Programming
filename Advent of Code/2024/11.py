data = []
with open("/home/bprevost/Competitive-Programming/Advent of Code/1.in") as f:
    for line in f.readlines():
        data.append([int(c) for c in line.strip().split()])

mem = {}
D = 75
def solve(n, d):
    if d == D:
        return 1
    if n not in mem:
        mem[n] = {}
    if d not in mem[n]:
        if n == 0:
            mem[n][d] = solve(1, d+1)
        else:
            s = str(n)
            if len(s)%2 == 0:
                mem[n][d] = solve(int(s[:len(s)//2]), d+1) + solve(int(s[len(s)//2:]), d+1)
            else:
                mem[n][d] = solve(n*2024, d+1)

    return mem[n][d]

ans = 0
for n in data[0]:
    ans += solve(n, 0)
print(ans)