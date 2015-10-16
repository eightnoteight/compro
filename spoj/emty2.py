for tests in range(int(input())):
    s = input()
    stack = []
    for x in range(len(s)):
        stack.append(s[x])
        if stack[-3:] == ['1', '0', '0']:
            stack.pop()
            stack.pop()
            stack.pop()
    if stack:
        print('Case', str(tests + 1)+':', 'no')
    else:
        print('Case', str(tests + 1)+':', 'yes')
