from sys import stdin

def main():
    arr = [0, 23, 37, 53, 73, 313, 317, 373, 797, 3137, 3797, 739397]
    n = int(stdin.read().split()[0])
    print sum([x for x in arr if x < n])

main()

