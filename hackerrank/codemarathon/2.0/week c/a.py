def main():
    chars = [
        ' ',
        '',
        'abc',
        'def',
        'ghi',
        'jkl',
        'mno',
        'pqrs',
        'tuv',
        'wxyz'
    ]
    s = map(int, raw_input())
    out = []
    for x, y in zip(s[0::2], s[1::2]):
        out.append(chars[x][y - 1])
    print ''.join(out)

main()
