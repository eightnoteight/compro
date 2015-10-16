from sys import stdin



def main():
    inp = stdin.readlines()
    for _ in range(int(inp[0])):
        arrsum = [0]*(int(inp[2*_ + 1]) + 1)
        for i, y in enumerate(map(int, inp[2*_ + 2].split())):
            arrsum[i] = arrsum[i - 1] + y
        s = 0
        for x in range(len(arrsum) - 2, -1, -1):
            s += (x)*(arrsum[x] - arrsum[x - 1]) - arrsum[x - 1]

        print(s)

main()
