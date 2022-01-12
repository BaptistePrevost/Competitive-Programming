for _ in range(int(input())):
    n = int(input())
    s = str(input()).strip()
    k = 1
    if len(s) > 1 and s[0] != s[1]:
        current = s[0]
        for c in s[1:]:
            if c <= current:
                k += 1
                current = c
            else:
                break

    print(s[:k] + s[:k][::-1])