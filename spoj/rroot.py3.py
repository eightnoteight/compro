from sys import stdin

def main():
    stdin.readline()
    for s in map(int, stdin):
        print("%.6f" % (1.0 - ((2**0.5)/(3*(s**0.5)))))

main()
