#include <bits/stdc++.h>
#ifdef __lucy__
    #include "prettyprint.hpp"
#endif
#define endl                                        ('\n')
#define i32max                                      (0x7fffffff)
#define i32min                                      (-0x7fffffff-1)
#define i64max                                      (0x7fffffffffffffff)
#define i64min                                      (-0x7fffffffffffffff-1)
#define ui32max                                     (0xffffffffu)
#define ui64max                                     (0xffffffffffffffffu)
#define bitcounti32                                 __builtin_popcount
#define bitcounti64                                 __builtin_popcountll
#define len(x)                                      ((int64_t)(x).size())
#define esort(x)                                    (sort((x).begin(), (x).end()))
#define ersort(x)                                   (sort((x).rbegin(), (x).rend()))
#define name(x)                                     (#x)
using namespace std;

template<class Function>
int32_t bsearch(int32_t lo, int32_t hi, Function check) {
    while(lo < hi) {
        int32_t mid = lo + ((hi - lo) / 2);
        if (check(mid))
            hi = mid;
        else
            lo = mid + 1;
    }
    return lo;
}

int main() {
    #ifndef __lucy__
        ios::sync_with_stdio(0);cin.tie(0);
    #endif
    int64_t n;
    int64_t m;
    cin >> n >> m;
    int64_t *heights = new int64_t[n];
    int64_t *sums = new int64_t[n];
    for (int x = 0; x < n; ++x)
        cin >> heights[x];
    sort(heights, heights + n);
    partial_sum(heights, heights + n, sums);
    cout << bsearch(0, 1000000010, [&heights, &n, &m, &sums](int64_t h)->bool {
        int32_t dist = bsearch(0, n, [&h, &heights](int64_t i)->bool {
            return h < heights[i];
        });
        if (dist == 0)
            return m > sums[n - 1] - (int64_t)n*h;
        else
            return m > sums[n - 1] - sums[dist - 1] - (int64_t)(n - dist)*h;
    }) - 1 << endl;
    return 0;
}

