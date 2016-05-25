from sys import stdin
from collections import defaultdict


def main():
    tokens = iter(stdin.read().split())
    counter = defaultdict(int)
    for _ in range(int(next(tokens))):
        counter[next(tokens)[0]] += 1
    print(sum([(v + 9) // 10 for v in counter.values()]))

main()
