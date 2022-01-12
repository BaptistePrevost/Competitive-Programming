for _ in range(int(input())):
    n = int(input())
    a = input()
    res = {}
    for i in a.split():
        if int(i) in res:
            res[-int(i)] = True
        else:
            res[int(i)] = True
    print(len(res))