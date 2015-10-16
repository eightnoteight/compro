#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define MAX_DIGITS 10011

#define KARAT_CUTOFF 4

void            karatsuba(int *a, int *b, int *ret, int d);
void            gradeSchool(int *a, int *b, int *ret, int d);
void            doCarry(int *a, int d);
void            getNum(int *a, int *d_a);
void            printNum(int *a, int d);

int
main() {
    int a[MAX_DIGITS]; // first multiplicand
    int b[MAX_DIGITS]; // second multiplicand
    int r[10 * MAX_DIGITS]; // result goes here
    int d_a; // length of a
    int d_b; // length of b
    int d; // maximum length
    int i; // counter
    int tests;
    scanf("%d", &tests);
    getchar();
    while(tests--)
    {
        getNum(a, &d_a);
        getNum(b, &d_b);

        if(d_a < 0 || d_b < 0) {
            printf("0\n");
            exit(0);
            return 0;
        }
        i = (d_a > d_b) ? d_a : d_b;
        for(d = 1; d < i; d *= 2);
        for(i = d_a; i < d; i++) a[i] = 0;
        for(i = d_b; i < d; i++) b[i] = 0;

        karatsuba(a, b, r, d); // compute product w/o regard to carry
        doCarry(r, 2 * d); // now do any carrying
        printNum(r,2 * d);
        printf("\n");
    }
}

void
karatsuba(int *a, int *b, int *ret, int d) {
    int             i;
    int             *ar = &a[0]; // low-order half of a
    int             *al = &a[d/2]; // high-order half of a
    int             *br = &b[0]; // low-order half of b
    int             *bl = &b[d/2]; // high-order half of b
    int             *asum = &ret[d * 5]; // sum of a's halves
    int             *bsum = &ret[d * 5 + d/2]; // sum of b's halves
    int             *x1 = &ret[d * 0]; // ar*br's location
    int             *x2 = &ret[d * 1]; // al*bl's location
    int             *x3 = &ret[d * 2]; // asum*bsum's location

    // when d is small, we're better off just reverting to
    // grade-school multiplication, since it's faster at this point.
    if(d <= KARAT_CUTOFF) {
        gradeSchool(a, b, ret, d);
        return;
    }

    // compute asum and bsum
    for(i = 0; i < d / 2; i++) {
        asum[i] = al[i] + ar[i];
        bsum[i] = bl[i] + br[i];
    }

    // do recursive calls (I have to be careful about the order,
    // since the scratch space for the recursion on x1 includes
    // the space used for x2 and x3)
    karatsuba(ar, br, x1, d/2);
    karatsuba(al, bl, x2, d/2);
    karatsuba(asum, bsum, x3, d/2);

    // combine recursive steps
    for(i = 0; i < d; i++) x3[i] = x3[i] - x1[i] - x2[i];
    for(i = 0; i < d; i++) ret[i + d/2] += x3[i];
}

void
gradeSchool(int *a, int *b, int *ret, int d) {
    int             i, j;

    for(i = 0; i < 2 * d; i++) ret[i] = 0;
    for(i = 0; i < d; i++) {
        for(j = 0; j < d; j++) ret[i + j] += a[i] * b[j];
    }
}

void
doCarry(int *a, int d) {
    int             c;
    int             i;

    c = 0;
    for(i = 0; i < d; i++) {
        a[i] += c;
        if(a[i] < 0) {
            c = -(-(a[i] + 1) / 10 + 1);
        } else {
            c = a[i] / 10;
        }
        a[i] -= c * 10;
    }
    if(c != 0) fprintf(stderr, "Overflow %d\n", c);
}

void
getNum(int *a, int *d_a) {
    int             c;
    int             i;

    *d_a = 0;
    while(true) {
        c = getchar();
        if(c == '\n' || c == EOF || c == ' ') break;
        a[*d_a] = c - '0';
        ++(*d_a);
    }
    for(i = 0; i * 2 < *d_a - 1; i++) {
        c = a[i], a[i] = a[*d_a - i - 1], a[*d_a - i - 1] = c;
    }
}

void
printNum(int *a, int d) {
    int i;
    for(i = d - 1; i > 0; i--) if(a[i] != 0) break;
    for(; i >= 0; i--) printf("%d", a[i]);
}