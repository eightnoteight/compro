def kmp(text, pattern):
    pn = len(pattern)
    pattern = list(pattern)

    shifts = [1] * (pn + 1)
    shift = 1
    for pos in range(pn):
        while shift <= pos and pattern[pos] != pattern[pos-shift]:
            shift += shifts[pos-shift]
        shifts[pos+1] = shift
    startPos = 0
    matchLen = 0
    pos = []
    for c in text:
        while matchLen == pn or \
              matchLen >= 0 and pattern[matchLen] != c:
            startPos += shifts[matchLen]
            matchLen -= shifts[matchLen]
        matchLen += 1
        if matchLen == pn:
            pos.append(startPos)
    return pos

def main():
    text = raw_input().strip()
    pattern = raw_input().strip()
    tn, pn = len(text), len(pattern)
    ans = 0
    for x in kmp(text, pattern):
        ans += tn - pn + 1 - x
        print tn - pn + 1 - x
    print ans


main()

