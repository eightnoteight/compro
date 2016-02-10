from itertools import groupby

def main():
    strokes = input().strip()
    ops = [
        ' 0', '.?!1', 'ABC2', 'DEF3', 'GHI4',
        'JKL5', 'MNO6', 'PQRS7', 'TUV8', 'WXYZ9',
    ]
    stack = []
    for ch, it in groupby(strokes):
        if ch == '*':
            stack = stack[:-len(list(it))]
        elif ch != '#':
            stack.append(ops[int(ch)][(len(list(it)) - 1) % len(ops[int(ch)])])
    print(''.join(stack))


main()
