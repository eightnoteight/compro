

def main():
    out = []
    try:
        while True:
            raw_input()
            aplayer = min(map(int, raw_input().split()))
            bplayers = sorted(map(int, raw_input().split()))[:2]
            if bplayers[0] <= aplayer and bplayers[1] <= aplayer:
                out.append('N')
            else:
                out.append('Y')
    except EOFError:
        print '\n'.join(out)


main()
