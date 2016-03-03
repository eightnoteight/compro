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


int main(int argc, char const *argv[]) {
    #ifndef __mr__
        ios::sync_with_stdio(0);cin.tie(0);
    #endif
    cin >> n;
    vector<ulong> arr;
    for (uint i = 0; i < n; ++i) {
        ulong r, h;
        cin >> r >> h;
        arr.push_back(r*r*h);
    }
    vector<ulong> arr_copy(arr.begin(), arr.end());
    sort(arr.begin(), arr.end());
    for (uint i = 0; i < n; ++i) {
        nums[arr[i]] = min(i, )
    }
    return 0;
}
