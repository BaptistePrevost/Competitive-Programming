for _ in range(int(input())):
    n = int(input())
    a = list(map(int, input().split()))
    x = int(input())
    a = [c-x for c in a]

    begin=True
    unchosen = 0
    sum = 0
    for i in range(n):
        if begin:
            sum = a[i]
            begin=False
        else:
            sum+=a[i]
            if sum < 0:
                begin=True
                unchosen+=1
            else:
                sum=min(sum, a[i])

    print(n-unchosen)