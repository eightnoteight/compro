from sys import stdin

def main():
    next = iter(stdin.read().split()).__next__
    for _ in range(int(next())):
        next()
        even_error, odd_error = 0, 0
        for i, x in enumerate(next()):
            if i % 2:
                odd_error += (x != 'B')
            else:
                even_error += (x != 'B')
        print(min(even_error, odd_error))

main()


