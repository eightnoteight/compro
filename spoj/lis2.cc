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

uint longest_increasing_subsequece(vector<pair<int, int>> arr) {
    vector<pair<int, int>> lis(len(arr), make_pair(t_max(int), t_max(int)));
    lis[0] = arr[0];
    uint lis_length = 1;
    for (uint i = 1; i < len(arr); ++i) {
        uint k = bsearch(0, len(lis), [&](uint x) -> bool {
            return lis[x].first >= arr[i].first || lis[x].second >= arr[i].second;
        });
        if (arr[i].first <= lis[k].first && arr[i].second <= lis[k].second)
            lis[k] = arr[i];
        if (k >= lis_length)
            lis_length = k + 1;
        cout << "i = " << i << "; k = " << k << "; arr[i] = " << arr[i] << "; lis[k] = " << lis[k] << endl;
    }
    return lis_length;
}

int main(int argc, char const *argv[]) {
    #ifndef __mr__
        ios::sync_with_stdio(0);cin.tie(0);
    #endif
    uint n;
    cin >> n;
    vector<pair<int, int>> arr(n);
    for (uint i = 0; i < n; ++i)
        cin >> arr[i].first >> arr[i].second;
    cout << arr << endl;
    cout << longest_increasing_subsequece(arr) << endl;
    return 0;
}
