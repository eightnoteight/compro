from random import randint, shuffle

def main():
    n = randint(1, 10**5)
    arr = list(range(n))
    loc = [0]*n
    for i, x in enumerate(arr):
        loc[x] = i
    shuffle(arr)
    m = randint(1, 10**5)
    print(n, m)
    for _ in range(m):
        while True:
            x, y = randint(0, n - 1), randint(0, n - 1)
            if x != y:
                break
        if loc[x] < loc[y]:
            print(x, y)
        else:
            print(y, x)

main()

