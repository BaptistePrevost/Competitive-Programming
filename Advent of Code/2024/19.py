stripes = []

mem = {}
def dfs(pattern):
    if not pattern:
        return 1
    if pattern not in mem:
        ret = 0
        for stripe in stripes:
            ret += pattern[:len(stripe)] == stripe and dfs(pattern[len(stripe):])
        mem[pattern] = ret
    return mem[pattern]


with open("/home/bprevost/Competitive-Programming/Advent of Code/1.in") as f:
    line = f.readline().strip()
    stripes = [stripe.strip() for stripe in line.split(',')]
    line = f.readline()
    print(stripes)
    ans = 0
    while True:
        pattern = f.readline().strip()
        if not pattern:
            break
        ans += dfs(pattern)
        
    print(ans)