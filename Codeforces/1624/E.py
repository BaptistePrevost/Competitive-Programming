mem = {}
s=""
for _ in range(int(input())):
    input() #empty line
    n, m = map(int, input().split())
    known = []
    for _ in range(n):
        known.append(input())
    
    s = input().strip()
    mem.clear()
    
    for i in range(n):
        for j in range(m-1):
            mem[known[i][j:j+2]] = [j+1, j+2, i+1]
        for j in range(m-2):
            mem[known[i][j:j+3]] = [j+1, j+3, i+1]

    path = (m+1)*[0]
    dp = (m+1)*[False]
    dp[0] = True
    for i in range(2, m+1):
        if dp[i-2] and s[i-2:i] in mem:
            path[i] = mem[s[i-2:i]]
            dp[i]=True
        elif dp[i-3] and s[i-3:i] in mem:
            path[i] = mem[s[i-3:i]]
            dp[i] = True
    if dp[m]:
        index = m
        ans = []
        while index>=2:
            # print("index", index)
            ans.append(path[index])
            index -= path[index][1] - path[index][0] + 1

        print(len(ans))
        for a in ans[::-1]:
            print(f'{a[0]} {a[1]} {a[2]}')
    else:
        print(-1)