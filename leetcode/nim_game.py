
class Solution(object):
    def canWinNim(self, n):
        return n % 4 != 0


def main():
    sol = Solution()
    for _ in xrange(int(raw_input())):
        print sol.canWinNim(int(raw_input()))

if __name__ == '__main__':
    main()
