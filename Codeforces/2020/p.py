def isPerfectSquare(n: int) -> bool:
    return pow(n,  0.5)*pow(n, 0.5) == n

if __name__ == "__main__":
    n = 854258780613619262
    print(isPerfectSquare(n))