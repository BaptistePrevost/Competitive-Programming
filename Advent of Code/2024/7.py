ans = 0

with open("/home/bprevost/Competitive-Programming/Advent of Code/1.in") as f:
    for line in f.readlines():
        lhs, rhs = line.strip().split(':')
        target = int(lhs)
        L = [int(v) for v in rhs.split()]

        def rec(pos, tmp):
            if pos == len(L):
                return tmp == target
            return rec(pos+1, tmp+L[pos]) or rec(pos+1, tmp*L[pos]) or rec(pos+1, int(str(tmp) + str(L[pos])))

        if rec(1, L[0]):
            ans += target

print(ans)