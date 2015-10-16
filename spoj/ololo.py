from sys import stdin, stdout
stdin.readline()
stdout.write(str(eval(stdin.read().replace('\n', '^') + '0')))

