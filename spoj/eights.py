a = ['192', '442', '692', '942']
for x in xrange(int(raw_input())):
    # code...
    k = int(raw_input())-1()
    if not k/4:
        print a[k % 4]
        continue
    print "%d%s" % (k/4, a[k % 4])
