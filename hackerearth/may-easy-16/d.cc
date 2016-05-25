#include <bits/stdc++.h>
#ifdef __mr__
    #include "prettyprint.hpp"
#else
    #define endl                    '\n'
#endif
#define len(x)                      (uint)(x).size()
#define int                         int32_t
#define uint                        uint32_t
#define ulong                       uint64_t
#define long                        int64_t
#define t_max(x)                    numeric_limits<x>::max()
#define t_min(x)                    numeric_limits<x>::min()
using namespace std;
const ulong mod = 1000000007ul;


template<class Func>
long bsearch(long lo, long hi, Func check) {
    // cout << lo << " " << hi << " xxx" << endl;
    long mid;
    while(lo < hi) {
        mid = lo + ((hi - lo) / 2);
        if (check(mid))
            hi = mid;
        else
            lo = mid + 1;
    }
    return lo;
}



int main(int argc, char const *argv[]) {
    #ifndef __mr__
        ios::sync_with_stdio(0);cin.tie(0);
    #endif

    long n, k;
    cin >> n >> k;
    vector<long> arra(n), arrb(n);
    for (int i = 0; i < n; ++i)
        cin >> arra[i];
    for (int i = 0; i < n; ++i)
        cin >> arrb[i];
    // for(int i = 0; i < n; ++i) {
    //     cout << arra[i] << ' ';
    // }
    // cout << endl;
    cout << bsearch(0l, 2000000002l, [&arra, &arrb, &k, &n](long x) {
        long cost = 0;
        for(int i = 0; i < n; ++i) {
            cost += max(arra[i] * x - arrb[i], (long)0);
        }
        cout << (cost > k) << " " << x << " " << cost << " " << k << endl;
        return cost > k;
    }) - 1 << endl;
    return 0;
}
