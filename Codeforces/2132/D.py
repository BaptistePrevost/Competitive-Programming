def util(base, power):
    if base==0:
        return 1
    else:
        return 45*base*(power//10)

def solve():
    k = int(input())

    nbDigits = 0
    base = 1
    power = 10
    while nbDigits + base*(power - power//10) < k:
        nbDigits += base*(power - power//10)
        power *= 10
        base += 1

    number = power//10
    k -= nbDigits
    number += (k-1)//base
    k -= base*((k-1)//base)

    sums = [0, 0]
    for i in range(1,10):
        sums.append(sums[-1]+i)
    power //= 10
    base -= 1
    subNumber = number-1
    sumOfDigits = 0
    while power:
        digit = subNumber//power
        sumOfDigits += digit*util(base, power) + sums[digit]*power
        subNumber %= power
        if power>1:
            sumOfDigits += (subNumber+1)*digit
        power //=10
        base-=1
    
    for d in str(number)[:k]:
        sumOfDigits += int(d)
    print(sumOfDigits)



t = int(input())
for _ in range(t):
    solve()