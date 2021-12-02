import sys

def fact(n: int):
    if n==1:
        return 1
    return n*fact(n-1)

data = sys.stdin.readlines()
for n in data[1:]:
    print(fact(int(n)))