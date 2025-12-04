data = []
with open("/home/bprevost/Competitive-Programming/Advent of Code/1.in") as f:
    while True:
        line = f.readline().strip()
        if not line:
            break
        data.append([c for c in line])

    data2 = []
    for i in range(len(data)):
        row = []
        for j in range(len(data[0])):
            if data[i][j] == '@':
                row.append('@')
                row.append('.')
            elif data[i][j] == '.':
                row.append('.')
                row.append('.')
            elif data[i][j] == '#':
                row.append('#')
                row.append('#')
            elif data[i][j] == 'O':
                row.append('[')
                row.append(']')
        data2.append(row)
    data = data2


    for i in range(len(data)):
        row = []
        for j in range(len(data[0])):
            if data[i][j] == '@':
                x, y = i, j

    while True:
        line = f.readline()
        if not line: break
        for c in line:
            # print("Apply ", c)
            if c == '^':
                if data[x-1][y] == '#': continue
                if data[x-1][y] == '.':
                    data[x][y] = '.'
                    data[x-1][y] = '@'
                    x -= 1
                else:
                    if data[x-1][y] == '[':
                        steps = [[(x-1,y)]]
                    else:
                        steps = [[(x-1,y-1)]]
                        
                    valid = True
                    while steps[-1] and valid:
                        nxt = []
                        for bx, by in steps[-1]:
                            if data[bx-1][by] == '#' or data[bx-1][by+1] == '#':
                                valid = False
                                break
                            # print(data[bx-1][by], data[bx-1][by+1])
                            if data[bx-1][by] == '[':
                                nxt.append((bx-1, by))
                            if data[bx-1][by] == ']':
                                nxt.append((bx-1,by-1))
                            if data[bx-1][by+1] == '[':
                                nxt.append((bx-1,by+1))
                        steps.append(nxt)
                    
                    if valid:
                        for step in steps[::-1]:
                            for bx, by in step:
                                data[bx-1][by] = '['
                                data[bx-1][by+1] = ']'
                                data[bx][by] = '.'
                                data[bx][by+1] = '.'
                        data[x][y] = '.'
                        x -= 1
                        data[x][y] = '@'


            elif c == 'v':
                if data[x+1][y] == '#': continue
                if data[x+1][y] == '.':
                    data[x][y] = '.'
                    data[x+1][y] = '@'
                    x += 1
                else:
                    if data[x+1][y] == '[':
                        steps = [[(x+1,y)]]
                    else:
                        steps = [[(x+1,y-1)]]

                    valid = True
                    while steps[-1] and valid:
                        nxt = []
                        for bx, by in steps[-1]:
                            if data[bx+1][by] == '#' or data[bx+1][by+1] == '#':
                                valid = False
                                break
                            if data[bx+1][by] == '[':
                                nxt.append((bx+1, by))
                            elif data[bx+1][by] == ']':
                                nxt.append((bx+1,by-1))
                            if data[bx+1][by+1] == '[':
                                nxt.append((bx+1,by+1))
                        steps.append(nxt)
                    
                    if valid:
                        for step in steps[::-1]:
                            for bx, by in step:
                                data[bx+1][by] = '['
                                data[bx+1][by+1] = ']'
                                data[bx][by] = '.'
                                data[bx][by+1] = '.'
                        data[x][y] = '.'
                        x += 1
                        data[x][y] = '@'

            elif c == '<':
                if data[x][y-1] == '#': continue
                if data[x][y-1] == '.':
                    data[x][y] = '.'
                    data[x][y-1] = '@'
                    y -= 1
                else:
                    z, t = x, y-1
                    while data[z][t] == ']': t-=2
                    if data[z][t] == '.':
                        while t<y-1:
                            data[z][t] = '['
                            data[z][t+1] = ']'
                            t += 2
                        data[x][y] = '.'
                        y -= 1
                        data[x][y] = '@'

            elif c == '>':
                if data[x][y+1] == '#': continue
                if data[x][y+1] == '.':
                    data[x][y] = '.'
                    data[x][y+1] = '@'
                    y += 1
                else:
                    z, t = x, y+1
                    while data[z][t] == '[': t+=2
                    if data[z][t] == '.':
                        while t>y+1:
                            data[z][t] = ']'
                            data[z][t-1] = '['
                            t -= 2
                        data[x][y] = '.'
                        y += 1
                        data[x][y] = '@'

            # for i in range(len(data)):
            #     for j in range(len(data[0])):
            #         print(data[i][j], end='')
            #     print()

    ans = 0
    for i in range(len(data)):
        for j in range(len(data[0])):
            if data[i][j] == '[':
                ans += 100*i + j

    print(ans)