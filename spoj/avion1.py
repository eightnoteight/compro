


def main():
    a = True
    for x in xrange(5):
        if 'FBI' in raw_input():
            a = False
            print x + 1,
    if a:
        print 'HE GOT AWAY!'
main()
