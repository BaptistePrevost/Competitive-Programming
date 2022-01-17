import sys
inp = sys.stdin.readline

def getCost(a: int):
    # print("cost of ", a)
    return (a * (a+1))//2

for _ in range(int(inp())):
    n = int(inp())
    k = list(map(int, inp().split()))
    h = list(map(int, inp().split()))

    ans=0
    segEnd = len(k)-1
    segMax = len(k)-1
    for i in range(len(k)-2, -1, -1):
        # print("here i", i)
        if h[segMax] <= k[segMax] - k[i]:
            # print("end seg")
            ans+=getCost(h[segMax]+(k[segEnd]-k[segMax]))
            segEnd=i
            segMax=i
        else:
            if h[i]+k[segMax]-k[i]>h[segMax]:
                # print("max seg")
                segMax=i


    ans+=getCost(h[segMax]+(k[segEnd]-k[segMax]))

    print(ans)