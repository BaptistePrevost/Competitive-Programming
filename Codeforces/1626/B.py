import sys
inp = sys.stdin.readline

for _ in range(int(inp())):
    n = inp().strip()
    index=0
    for i in range(len(n)-2, -1, -1):
        if int(n[i])+int(n[i+1])>9:
            index=i
            break

    insert = int(n[i])+int(n[i+1])
    n = n[:i] + str(insert) + n[i+2:]
    print(n)