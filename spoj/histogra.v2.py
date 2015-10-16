from sys import stdin


def main():
    def maxarea(arr, length):
        stack = []
        i = 0
        max_area = float('-inf')
        while i < length:
            if len(stack) == 0 or arr[stack[-1]] <= arr[i]:
                stack.append(i)
                i += 1
            else:
                top = stack.pop()
                if stack:
                    area_with_top = arr[top] * (i - stack[-1] - 1)
                else:
                    area_with_top = arr[top] * i
                max_area = max(max_area, area_with_top)
        while stack:
            top = stack.pop()
            if stack:
                area_with_top = arr[top] * (i - stack[-1] - 1)
            else:
                area_with_top = arr[top] * i
            max_area = max(max_area, area_with_top)


        return max_area

    inp = stdin.readlines()
    inp.pop()
    for x in inp:
        l = map(int, x.split())
        length = l.pop(0)
        print maxarea(l, length)

main()
