import sys
import math
inp = sys.stdin.readline

pow2 = [1]
for _ in range(16):
    pow2.append(pow2[-1]*2)

def getCost(i: int):
    index = 0
    while pow2[index]<i:
        index+=1
    return pow2[index]-i

for _ in range(int(inp())):
    n = int(inp())
    a = list(map(int, inp().split()))
    a.append(-1)
    a.append(-2)
    a.append(200005)
    a.append(200006)
    a.sort()
    w = list(set(a))
    w.sort()

    count={}
    for z in a:
        if not z in count:
            count[z]=1
        else:
            count[z]+=1
    count[-2]=0
    count[-1]=0
    count[200005]=0
    count[200006]=0

    x=0
    xCount = count[w[x]]
    best = 200005
    if(len(w)>1):
        while x < len(w)-1:
            y=len(w)-1
            yCount = count[w[y]]
            while y>x and y > 0:
                # print("x", w[x], "y", w[y])
                # print("xCount", xCount, "yCount", yCount)
                temp = getCost(xCount) + getCost(yCount) + getCost(n-xCount-yCount)
                if temp<best:
                    # print("best here")
                    best = temp
                y-=1
                yCount+=count[w[y]]
            x+=1
            xCount += count[w[x-1]]
    else:
        best = getCost(w[0])+2
    print(best)
    