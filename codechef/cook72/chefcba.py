from itertools import permutations

def main():
    for a, b, c, d in permutations(map(int, raw_input().split())):
        if a * b == c * d:
            print 'Possible'
            break
    else:
        print 'Impossible'

main()
