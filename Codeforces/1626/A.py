import sys
inp = sys.stdin.readline


for _ in range(int(inp())):
    count = {}
    for letter in inp().strip():
        if letter in count:
            count[letter]+=1
        else:
            count[letter] = 1
    for letter in count:
        for i in range(count[letter]):
            print(letter, end='')
    print()