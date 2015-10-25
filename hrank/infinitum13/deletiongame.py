from sys import stdin

def main():
    nextint = iter(map(int, stdin.read().split())).next
    for _ in xrange(nextint()):
        n, k = nextint(), nextint()
        tots = ((n * (n + 1)) // 2)
        if tots % 2 == 0:
            print ['NO', 'YES'][
                k % 2 == 0 and -tots <= k <= tots
            ]
        else:
            print ['NO', 'YES'][
                k % 2 == 1 and -tots <= k <= tots
            ]
main()
