def main():
    sieve = [0]*110011
    sieve[0] = sieve[1] = 1
    for x in range(2, 110011):
        if sieve[x] == 0:
            sieve[x*x: 110011: x] = [1]*len(range(x*x, 110011, x))
    n = int(input())
    for k in range(n + 1, 110011):
        if sieve[k] == 0:
            print(k - n, ['Alex', 'Stella'][(k - n) % 2])
            break
main()
