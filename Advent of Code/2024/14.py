X = 101
Y = 103
# X = 11
# Y = 7
q1, q2, q3, q4 = 0, 0, 0, 0

data = [[0 for j in range(Y)] for i in range(X)]

class Bot:
    xP, yP, xS, yS = 0, 0, 0, 0

    def __init__(this, xP, yP, xS, yS):
        this.xP = xP
        this.yP = yP
        this.xS = xS
        this.yS = yS

bots = []

with open("/home/bprevost/Competitive-Programming/Advent of Code/1.in") as f:
    while True:
        line = f.readline()
        if not line: break
        pos, speed = line.strip().split(' ')
        pos = pos.split('=')[1]
        speed = speed.split('=')[1]
        xP, yP = (int(c) for c in pos.split(','))
        xS, yS = (int(c) for c in speed.split(','))
        
        bots.append(Bot(xP, yP, xS, yS))
        data[xP][yP] += 1

for i in range(1, 50000):
    for bot in bots:
        data[bot.xP][bot.yP] -= 1
        bot.xP = (bot.xP + bot.xS) % X
        bot.yP = (bot.yP + bot.yS) % Y
        data[bot.xP][bot.yP] += 1

    for bot in bots:
        if bot.xP == 0 or bot.xP == X-1 or bot.yP == 0 or bot.yP == Y-1: continue
        if data[bot.xP-1][bot.yP-1] > 0 and data[bot.xP][bot.yP-1] > 0 \
            and data[bot.xP+1][bot.yP-1] > 0 and data[bot.xP+1][bot.yP] > 0 and data[bot.xP+1][bot.yP+1] > 0 \
            and data[bot.xP][bot.yP+1] > 0 and data[bot.xP-1][bot.yP+1] > 0 and data[bot.xP-1][bot.yP] > 0 \
            and data[bot.xP-1][bot.yP-1] > 0:
            for y in range(Y):
                for x in range(X):
                    print('*' if data[x][y] > 0 else ' ', end='')
                print()
            print("\n\n\n\n\n")
            print(i)
            break


        
