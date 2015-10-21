#include <bits/stdc++.h>
#ifdef __mr__
    #include "prettyprint.hpp"
#endif
#ifndef __mr__
    #define endl                                               '\n'
#endif
using namespace std;

template<class Function>
unsigned long bsearch(unsigned long lo, unsigned long hi, Function check) {
    while(lo < hi) {
        unsigned long mid = lo + (hi - lo) / 2;
        if (check(mid))
            hi = mid;
        else
            lo = mid + 1;
    }
    return lo;
}

int main(int argc, char const *argv[]) {
    vector<int> arr = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int val = -1;
    cout << bsearch(0, 10, [&arr, &val](unsigned long x) {
        return arr[x] >= val;
    }) << endl;
    return 0;
}
