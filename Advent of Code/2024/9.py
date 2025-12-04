with open("/home/bprevost/Competitive-Programming/Advent of Code/1.in") as f:
    disk = [int(c) for c in f.readline().strip()]
    data = []
    id = 0
    pos = 0
    blocks = []
    spaces = []
    for i in range(0, len(disk)-1, 2):
        blocks.append((pos, disk[i]))
        for k in range(disk[i]):
            data.append(id)
            pos += 1
        spaces.append((pos, disk[i+1]))
        for k in range(disk[i+1]):
            data.append(-1)
            pos += 1
        id += 1
    if len(disk) % 2:
        blocks.append((pos, disk[len(disk)-1]))
        for k in range(disk[len(disk)-1]):
            data.append(id)
            pos += 1

    # for d in data:
    #     print(d if d > -1 else '.', end='')
    # print()

    for (pos, sz) in blocks[::-1]:
        for j, (qos, tz) in enumerate(spaces):
            if qos > pos: break
            if tz > sz:
                for k in range(qos, qos+sz):
                    data[k] = data[pos + k - qos]
                    data[pos + k - qos] = -1
                spaces[j] = (qos+sz, tz-sz)
                break
            elif tz == sz:
                for k in range(qos, qos+sz):
                    data[k] = data[pos + k - qos]
                    data[pos + k - qos] = -1
                spaces.pop(j)
                break
        if data[pos] == -1:
            continue

    # for d in data:
    #     print(d if d > -1 else '.', end='')
    # print()
    
    pos = 0
    ans = 0
    for i, d in enumerate(data):
        if d > -1: ans += d*i
    print(ans)