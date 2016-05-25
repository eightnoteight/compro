from itertools import combinations

def main():
    n, k = map(int, input().split())
    arr = map(int, input().split())
    print(sum([((x + y) % k == 0) for x, y in combinations(arr, 2)]))

main()
