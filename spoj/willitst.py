n = int(raw_input())
stack = []
while n > 1:
    if n in stack:
        break
    stack.append(n)
    if n % 2:
        n = (3 * n) + 3
    else:
        n //= 2

if n > 1:
    print('NIE')
else:
    print('TAK')
