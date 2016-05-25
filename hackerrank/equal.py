from sys import stdin

#problem link: https://www.hackerrank.com/challenges/equal

def main():
    nextint = iter(map(int, stdin.read().split())).next
    for _ in xrange(nextint()):
        n = nextint()
        arr = [nextint() for _ in xrange(n)]
        m = [min(arr)]
        for x in xrange(1, 5):
            m.append(m[-1] - 1)
        count = [0, 0, 0, 0, 0]
        for x in arr:
            for z in xrange(5):
                count[z] += ((x - m[z]) // 5) + (((x - m[z]) % 5) // 2) + (((x - m[z]) % 5) % 2)
        print min(count)

main()

