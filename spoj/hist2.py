from math import factorial

def main():
    def max_perimeter(histogram):
        histogram.sort()
        if len(histogram) == 2:
            return 2*histogram[-1] + 2*2
        return 2*histogram[-1] + 2*histogram[-2] - 2*histogram[0] + 2*len(histogram)

    while int(raw_input()) != 0:
        histogram = map(int, raw_input().split())
        print max_perimeter(histogram), 2*(len(histogram) - 2)*factorial(len(histogram) - 2) or 1


main()
