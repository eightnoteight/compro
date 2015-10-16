# i have wasted some decades in this problem


def main():

    def count(n):
        if n <= 1:
            return n
        s = bin(n)[2:]
        if '0' not in s:
            return len(s)*(2**(len(s) - 1))
        ans = 0

        for i, x in enumerate(s):
            if x is '1':
                ans += int((s[0: i] + s[i + 1: len(s)]), 2) + 1
            else:
                ans += count(2**(len(s) - 2))
        return ans

    for x in xrange(int(raw_input())):
        n = int(raw_input())
        print count(n)
        #print count_cake(n) + count_cream(n - 2**int(log(n)))

main()
