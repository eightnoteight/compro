from math import log


# simple one to understand. complexity: O(n*log(n))
def countzeros_va(n):
    count = 0
    for x in xrange(1, n + 1):
        while x % 5 == 0:
            count += 1
            x //= 5
    return count


# better approach. complexity: O(log(n))
def countzeros_vb(n):
    count, c5 = 0, 5
    while c5 <= n:
        count += (n // c5)
        c5 *= 5
    return count


# this is same as before, its just that while loops irk me
def countzeros_vc(n):
    return sum(n // (5 ** x) for x in range(1, int(log(n, 5) + 3)))
    # adding +3 to be sure. never trust approximations.


def run_sample_tests():
    precal = {3: 0, 60: 14, 100: 24, 1024: 253, 23456: 5861, 8735373: 2183837}
    for x in precal:
        assert precal[x] == countzeros_va(x) == countzeros_vb(x) == countzeros_vc(x)

if __name__ == '__main__':
    run_sample_tests()
