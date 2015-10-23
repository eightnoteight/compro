def survivor(x):
    if x == 1:
        return 0
    if x % 2 == 0:
        return 2*survivor(x // 2)
    else:
        s = x // 2 + 1
        a = (survivor(s) - 1) % s
        return 2*a

def main():
    for _ in xrange(int(raw_input())):
        x = int(raw_input())
        print survivor(x) + 1

main()
