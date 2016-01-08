#include <bits/stdc++.h>
#ifdef __mr__
    #include "prettyprint.hpp"
#else
    #define endl                '\n'
#endif
#define len(x)                  (uint)(x).size()
#define int                     int32_t
#define uint                    uint32_t
#define ulong                   uint64_t
#define long                    int64_t
#define t_max(x)                numeric_limits<x>::max()
#define t_min(x)                numeric_limits<x>::min()
using namespace std;
const ulong mod = 1000000007ul;

template<class Function>
uint bsearch(uint lo, uint hi, Function check) {
    while (lo < hi) {
        uint mid = lo + ((hi - lo) / 2);
        if (check(mid))
            hi = mid;
        else
            lo = mid + 1;
    }
    return lo;
}

uint longest_increasing_subsequece(vector<uint> arr) {
    vector<uint> lis(len(arr), t_max(uint));
    lis[0] = arr[0];
    uint lis_length = 1;
    for (uint i = 1; i < len(arr); ++i) {
        uint k = bsearch(0, len(lis), [&](uint x) -> bool {
            return lis[x] >= arr[i];
        });
        if (arr[i] < lis[k])
            lis[k] = arr[i];
        if (k >= lis_length)
            lis_length = k + 1;
    }
    return len(lis) - count(lis.begin(), lis.end(), t_max(uint));
}

int main(int argc, char const *argv[]) {
    #ifndef __mr__
        ios::sync_with_stdio(0);cin.tie(0);
    #endif
    uint n;
    cin >> n;
    vector<uint> arr(n);
    for (uint i = 0; i < n; ++i)
        cin >> arr[i];
    cout << longest_increasing_subsequece(arr) << endl;
    return 0;
}
