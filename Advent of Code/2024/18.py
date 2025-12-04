DIM = 71
bits = []
data = [['.' for y in range(DIM)] for x in range(DIM)]
with open("/home/bprevost/Competitive-Programming/Advent of Code/1.in") as f:
    for line in f.readlines():
        x, y = (int(v) for v in line.split(','))
        bits.append((x,y))
        
def hash(x, y):
    return x*DIM + y

def solve():
    visited = set()
    bfs = [(0, 0)]
    depth = 0
    while bfs:
        nxt = []
        for x, y in bfs:
            if x<0 or x>=DIM or y<0 or y>=DIM: continue
            if data[x][y] == '#': continue
            if x == DIM-1 and y == DIM-1:
                return True
            h = hash(x, y)
            if h in visited: continue
            visited.add(h)
            nxt.append((x-1, y))
            nxt.append((x+1, y))
            nxt.append((x, y-1))
            nxt.append((x, y+1))
        
        bfs = nxt
        depth += 1
    return False

left, right = -1, len(bits)
while right - left > 1:
    mid = (left + right) // 2

    for x,y in bits[:mid+1]:
        data[x][y] = '#'

    if solve(): left = mid
    else: right = mid

    for x,y in bits[:mid+1]:
        data[x][y] = '.'

print(bits[right])