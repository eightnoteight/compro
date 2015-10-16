#include <bits/stdc++.h>
#ifdef __mr__
    #include "prettyprint.hpp"
#endif
#define endl                        ('\n')
using namespace std;
int testcases;

inline unsigned int tnum(unsigned long long int n) {
    unsigned long long int nth = 0, p2x = 1;
    unsigned int p3x = 1, sigx = 0, sum = 0;
    while (n) {
        if (n % 2) {
            sum += (nth + 1)*p3x + sigx*(p2x / 2);
            nth += p2x;
        }
        sigx += p3x;
        p2x *= 2;
        p3x *= 3;
        n /= 2;
    }
    return sum;
}


int main() {
    scanf("%d", &testcases);
    while(testcases--) {
        unsigned long long int l, r;
        scanf("%llu%llu", &l, &r);
        printf("%u\n", tnum(r) - tnum(l - 1));
    }
    return 0;
}
