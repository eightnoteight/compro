from subprocess import Popen, PIPE
from sys import stdout

def main():
    try:
        while True:
            s, tmp = Popen(['factor'], stdin=PIPE, stdout=PIPE, stderr=PIPE).communicate(raw_input())
            stdout.write('1')
            stdout.write(s[s.find(':') + 1:].replace(' ', ' x '))
    except EOFError:
        pass


main()
