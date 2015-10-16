def main():
    nthtry = '010101'
    while True:
        print 'try: {0}'.format(nthtry)
        res = raw_input()
        if res == '6a':
            break
        a = res[:2]
        b = res[2:]
        a, b = b, a  # solve this thing


main()
