for _ in range(int(input())):
    a,b,c = list(map(int, input().split()))
    
    m = (2*b-c)//a
    if m>0 and b-m*a==c-b:
        print('YES')
        continue
    m = (c+a)//(2*b)
    if m>0 and m*b-a==c-m*b:
        print('YES')
        continue
    m= (2*b-a)//c
    if m>0 and b-a==m*c-b:
        print('YES')
        continue
    print('NO')