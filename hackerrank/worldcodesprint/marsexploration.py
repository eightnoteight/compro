from itertools import cycle
cnt = 0
for x, y in zip(cycle('SOS'), raw_input()):
    if x != y:
        cnt += 1
print cnt
