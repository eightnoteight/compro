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
map<tuple<int32_t, int32_t, int32_t>, int32_t> cache;
map<tuple<int32_t, int32_t, int32_t>, int32_t> cache2;

int32_t dumbmode(vector<int32_t>& arr, int32_t i, int32_t j, bool turn) {
    // cout << turn << " " << i << ":" << j << endl;
    if (cache2.find(make_tuple(i, j, turn)) != cache2.end())
        return cache2[make_tuple(i, j, turn)];
    if (i <= j) {
        if (turn)
            cache2[make_tuple(i, j, turn)] = max(dumbmode(arr, i + 1, j, !turn), dumbmode(arr, i, j - 1, !turn));
        else
            cache2[make_tuple(i, j, turn)] = max(arr[i] + dumbmode(arr, i + 1, j, !turn), arr[j] + dumbmode(arr, i, j - 1, !turn));
        return cache2[make_tuple(i, j, turn)];
    }
    return 0;
}

int32_t smartmode(vector<int32_t>& arr, int32_t i, int32_t j, bool turn) {
    // cout << turn << " " << i << ":" << j << endl;
    if (cache.find(make_tuple(i, j, turn)) != cache.end())
        return cache[make_tuple(i, j, turn)];
    if (i <= j) {
        if (turn)
            cache[make_tuple(i, j, turn)] = min(smartmode(arr, i + 1, j, !turn), smartmode(arr, i, j - 1, !turn));
        else
            cache[make_tuple(i, j, turn)] = max(arr[i] + smartmode(arr, i + 1, j, !turn), arr[j] + smartmode(arr, i, j - 1, !turn));
        return cache[make_tuple(i, j, turn)];
    }
    return 0;
}

int main() {
    #ifndef __mr__
        ios::sync_with_stdio(0);cin.tie(0);
    #endif
    cin >> testcases;
    for (int test = 1; test <= testcases; ++test) {
        cache.clear();
        cache2.clear();
        int32_t n;
        cin >> n;
        vector<int32_t> arr(n);
        for (int32_t& x: arr)
            cin >> x;
        cout << dumbmode(arr, 0, n - 1, false) << ' ' << smartmode(arr, 0, n - 1, false) << endl;
    }
    return 0;
}
