def solve(rl, cl, op):
    k = rl - cl - op
    for x, y in zip(xrange(k + 1), xrange(k, -1, -1)):



def main():
    n, m = map(int, raw_input().split())
    s = raw_input().strip()
    cl, op = 0, 0
    stack = []
    for ch in s:
        if ch == ')' and stack and stack[-1] == '(':
            stack.pop()
        else:
            stack.append(ch)
    cl, op = stack.count(')'), stack.count('(')
    remlen = n - m
    if remlen < cl + op:
        print 0
    elif remlen == cl + op:
        print 1
    else:
        print solve(remlen, cl, op)

