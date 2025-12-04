M = []
with open("/home/bprevost/Competitive-Programming/Advent of Code/1.in") as f:
    row = 0 
    posByChar = {}
    for line in f.readlines():
        col = -1
        for c in line.strip():
            col += 1
            if c == '.': continue
            if c not in posByChar: posByChar[c] = []
            posByChar[c].append((row, col))
        row += 1

    ans = set()
    for c in posByChar:
        for i in range(len(posByChar[c])):
            for j in range(i+1, len(posByChar[c])):
                k = 0
                while True:
                    ra = posByChar[c][i][0] + k*(posByChar[c][i][0] - posByChar[c][j][0])
                    ca = posByChar[c][i][1] + k*(posByChar[c][i][1] - posByChar[c][j][1])
                    if ca < 0 or ca > col or ra < 0 or ra >= row:
                        break
                    ans.add(ra*row + ca)
                    k += 1

                k = 0
                while True:
                    ra = posByChar[c][j][0] + k*(posByChar[c][j][0] - posByChar[c][i][0])
                    ca = posByChar[c][j][1] + k*(posByChar[c][j][1] - posByChar[c][i][1])
                    if ca < 0 or ca > col or ra < 0 or ra >= row:
                        break
                    ans.add(ra*row + ca)
                    k += 1

    print(len(ans))