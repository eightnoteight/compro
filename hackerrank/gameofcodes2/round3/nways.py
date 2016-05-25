from sys import stdin

def main():
    arr = [1, 1, 2, 4]
    for _ in xrange(4, 10000001):
        arr.append((arr[-1] + arr[-2] + arr[-3]) % 1000000007)
    nextint = iter(stdin.read().split()).next
    for _ in xrange(int(nextint())):
        print arr[int(nextint())]
main()
