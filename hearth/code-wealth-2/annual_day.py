from sys import stdin

def main():
    nextint = iter(map(int, stdin.read().split())).next
    for _ in xrange(nextint()):
        n, k = nextint(), nextint()
        print sum(sorted([bin(nextint()).count('1') for _ in xrange(n)], reverse=True)[:k])
        
main()
