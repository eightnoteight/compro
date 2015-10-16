t = int(raw_input())
for x in xrange(t):
    # code...
    n = int(raw_input())
    numbers = []
    minimum = 11
    for y in xrange(n):
        # code...
        numbers.append(raw_input())
    numbers.sort()
    answer = 'YES'
    for x in xrange(n-1):
        if numbers[x] == numbers[x+1][:len(numbers[x])]:
            answer = 'NO'
            break
    print answer
