def main():
    n, k = map(int, input().split())
    counter = [0] * k
    for x in map(int, input().split()):
        counter[x % k] += 1
    subsetsize = 0
    for x, y in zip(range(1, (k // 2) + 1), range(k - 1, k // 2, -1)):
        subsetsize += max(x, y)
    if k % 2 == 0:
        subsetsize += (counter[k // 2] != 0)
    subsetsize += (counter[0] != 0)
    print(subsetsize)


main()
