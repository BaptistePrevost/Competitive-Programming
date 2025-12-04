keyValues = []
lockValues = []
with open("/home/bprevost/Competitive-Programming/Advent of Code/1.in") as f:
    while True:
        pattern = [[c for c in f.readline().strip()] for _ in range(7)]

        isKey = True
        if sum(c=='#' for c in pattern[0]) == 5: isKey = False

        if isKey:
            values = [0 for _ in range(5)]
            for j in range(5):
                val = 0
                for i in range(5,-1,-1):
                    if pattern[i][j] == '.': break
                    val+=1
                values[j] = val

            keyValues.append(values)
        else:
            values = [0 for _ in range(5)]
            for j in range(5):
                val = 0
                for i in range(1,7):
                    if pattern[i][j] == '.': break
                    val+=1
                values[j] = val

            lockValues.append(values)
                
        line = f.readline()
        if not line: break


sortedLockIndices = []
for i in range(5):
    sortedLockIndices.append(
        sorted(
            [l for l in range(len(lockValues))], key=lambda l: lockValues[l][i]
        )
    )

ans = 0
for keyValue in keyValues:
    for lockValue in lockValues:
        valid = True
        for i in range(5):
            if lockValue[i] + keyValue[i] > 5:
                valid = False
                break
        if valid: ans += 1
print(ans)