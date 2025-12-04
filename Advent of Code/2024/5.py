cmp = {}
ans1 = 0
ans2 = 0
with open("/home/bprevost/Competitive-Programming/Advent of Code/1.in") as f:
    while True:
        line = f.readline().strip()
        if not line: break
        (x, y) = (int(v) for v in line.split('|'))
        if x not in cmp:
            cmp[x] = {}
        if y not in cmp:
            cmp[y] = {}
        cmp[x][y] = -1
        cmp[y][x] = 1

    while True:
        line = f.readline().strip()
        if not line: break

        d = {}
        i = 0
        L = [int(v) for v in line.split(',')]
        for x in L:
            d[x] = i
            i += 1

        valid = True
        for i in range(len(L)-1):
            if cmp[L[i]][L[i+1]] == 1:
                valid = False
                break
        if valid:
            ans1 += L[len(L)//2]
        else:
            from functools import cmp_to_key
            compare = lambda x, y: cmp[x][y]
            L = sorted(L, key=cmp_to_key(compare))
            print(L)
            ans2 += L[len(L)//2]
            
print(ans1)
print(ans2)