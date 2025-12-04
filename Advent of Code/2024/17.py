twos = [1]
for i in range(1, 8):
    twos.append(twos[-1]*2)

class Computer:
    A, B, C = 0, 0, 0
    ptr = 0
    data = []
    instructions = []
    output = []

    def __init__(self):
        self.instructions = [self.adv, self.bxl, self.bst, self.jnz, self.bxc, self.out, self.bdv, self.cdv]
        self.reset()

    def reset(self):
        self.A = self.B = self.C = self.ptr = 0
        self.output = []

    def combo(self, i):
        if i<4: return i
        elif i==4: return self.A
        elif i==5: return self.B
        elif i==6: return self.C
        else:
            raise Exception

    def adv(self, i):
        self.A = self.A//twos[self.combo(i)]
        self.ptr += 2

    def bxl(self, i):
        self.B = self.B^i
        self.ptr += 2

    def bst(self, i):
        self.B = self.combo(i) % 8
        self.ptr += 2

    def jnz(self, i):
        if self.A == 0: self.ptr += 2
        else: self.ptr = i

    def bxc(self, i):
        self.B = self.B^self.C
        self.ptr += 2

    def out(self, i):
        self.output.append(self.combo(i) % 8)
        # print(self.combo(i) % 8, end=',')
        self.ptr += 2

    def bdv(self, i):
        self.B = self.A//twos[self.combo(i)]
        self.ptr += 2

    def cdv(self, i):
        self.C = self.A//twos[self.combo(i)]
        self.ptr += 2

    def run(self):
        while self.ptr < len(self.data)-1:
            self.instructions[self.data[self.ptr]](self.data[self.ptr+1])


computer = Computer()

with open("/home/bprevost/Competitive-Programming/Advent of Code/1.in") as f:
    line = f.readline()
    computer.A = int(line.split(':')[1].strip())
    line = f.readline()
    computer.B = int(line.split(':')[1].strip())
    line = f.readline()
    computer.C = int(line.split(':')[1].strip())
    
    line = f.readline()
    line = f.readline().strip()
    for c in line.split(": ")[1].split(','):
        computer.data.append(int(c))


def dfs(ans, depth):
    ans *= 8
    for A in range(8):
        computer.reset()
        computer.A = ans + A
        computer.run()
        if computer.output[0] == computer.data[-1-depth]:
            if depth == 15:
                print(ans + A)
            else:
                dfs(ans + A, depth+1)
                
dfs(0,0)
