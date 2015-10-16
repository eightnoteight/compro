#include <bits/stdc++.h>
#ifdef __mr__
    #include "prettyprint.hpp"
#endif
#define endl                        ('\n')
#define i32inf                      (0x7fffffff)
#define i32_inf                     (-0x7fffffff-1)
#define i64inf                      (0x7fffffffffffffff)
#define i64_inf                     (-0x7fffffffffffffff-1)
#define ui32inf                     (0xffffffffu)
#define ui64inf                     (0xffffffffffffffffu)
#define bitcounti32                 __builtin_popcount
#define bitcounti64                 __builtin_popcountll
using namespace std;
int testcases;

template<class Function>
int32_t bsearch(int32_t lo, int32_t hi, Function check) {
    while(lo < hi) {
        int32_t mid = lo + ((hi - lo) / 2);
        if (check(mid))
            hi = mid;
        else
            lo = mid + 1;
    }
    if (!check(lo))
        throw runtime_error("bsearch: Couldn't Locate the target. program termination authorised!");
    return lo;
}

int main() {
    cin >> testcases;
    for (int test = 1; test <= testcases; ++test) {
        int32_t n, c;
        cin >> n >> c;
        vector<int32_t> stalls(n);
        for_each(stalls.begin(), stalls.end(), [](int32_t& x) {
            cin >> x;
        });
        sort(stalls.begin(), stalls.end());
        cout << bsearch(0, 1000000001, [&](int32_t x) -> bool {
            int32_t k = 0, last = -x;
            for (int32_t y: stalls) {
                if (y - last >= x) {
                    last = y;
                    k++;
                }
            }
            return k < c;
        }) - 1 << endl;
    }
    return 0;
}
