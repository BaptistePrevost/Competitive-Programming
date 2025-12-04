def util(base, power):
    if base==0:
        return 1
    else:
        return 45*base*(power//10)
    
def dumb(k):
    ans=0
    for i in range(1,100000):
        for d in str(i):
            ans+=int(d)
            k-=1
            if k==0: break
        if k==0: break
    return ans

def smart(k):
    nbDigits = 0
    base = 1
    power = 10
    while nbDigits + base*(power - power//10) < k:
        nbDigits += base*(power - power//10)
        power *= 10
        base += 1

    # sumOfDigits = 45*(base-1)*(power//100)
    # print("sumOfDigits", sumOfDigits)

    number = power//10
    k -= nbDigits
    number += (k-1)//base
    k -= base*((k-1)//base)
    # print("number", number, "k", k)

    sums = [0, 0]
    for i in range(1,10):
        sums.append(sums[-1]+i)
    power //= 10
    base -= 1
    subNumber = number-1
    sumOfDigits = 0
    while power:
        digit = subNumber//power
        # print("power", power, "base", base, "subNumber", subNumber, "digit", digit)
        sumOfDigits += digit*util(base, power) + sums[digit]*power
        # print("sumOfDigits", sumOfDigits)
        subNumber %= power
        if power>1:
            sumOfDigits += (subNumber+1)*digit
            # print("sumOfDigits", sumOfDigits)
        power //=10
        base-=1
    
    # print("number", number)
    for d in str(number)[:k]:
        sumOfDigits += int(d)
    return sumOfDigits
    # print()



for k in range(1,10000):
    if dumb(k) != smart(k):
        print(k, dumb(k), smart(k))
        break