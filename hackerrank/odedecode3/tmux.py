string = raw_input()
counts = [1]*(len(string) + 1)
counts[0] = 0
for c in 'tmux':
    for i, x in enumerate(string):
        counts[i + 1] = counts[i] + counts[i + 1]*(x == c)
print counts[-1]
