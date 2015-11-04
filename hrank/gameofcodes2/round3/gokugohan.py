from sys import stdin
from collections import defaultdict
cache = defaultdict(int)

def ways(string, stack, msg, i):
    if len(stack) + len(msg) == len(string):
        cache[msg + stack[::-1]] += 1
        return
    ways(string, stack + string[i], msg, i + 1)
    if stack:
        ways(string, stack[:-1], msg + stack[-1], i)


def main():
    string = stdin.read().split()[0]
    ways(string, '', '', 0)
    print cache[string], len(cache)

main()
