from sys import stdin

def main():
    mod = 100003
    facts = [1]
    for x in xrange(1, mod):
        facts.append((facts[-1]*x) % mod)
    nextint = iter(map(int, stdin.read().split())).next
    for _ in xrange(nextint()):
        n = nextint()
        print ((facts[n + 1] if n + 1 < mod else 0) - 1) % mod

main()
