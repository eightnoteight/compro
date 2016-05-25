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
int bsearch(int lo, int hi, Func check) {
    int mid;
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
    string s;
    cin >> s;
    int n = s.size();
    vector<int> red(n);
    vector<int> green(n);
    vector<int> blue(n);
    red[0] = (s[0] == 'R')? 1:0;
    green[0] = (s[0] == 'G')? 1:0;
    blue[0] = (s[0] == 'B')? 1:0;
    for (int i = 1; i < n; ++i) {
        red[i] = red[i - 1] + ((s[i] == 'R')?1:0);
        green[i] = green[i - 1] + ((s[i] == 'G')?1:0);
        blue[i] = blue[i - 1] + ((s[i] == 'B')?1:0);
    }
    int q;
    cin >> q;
    while(q--) {
        int k, x, y, z;
        cin >> k >> x >> y >> z;
        k -= 1;
        int kx, ky, kz;
        kx = bsearch(0, n, [&](int m) {
            return red[m] >= red[k] + x - (s[k] == 'R');
        });
        ky = bsearch(0, n, [&](int m) {
            return green[m] >= green[k] + y - (s[k] == 'G');
        });
        kz = bsearch(0, n, [&](int m) {
            return blue[m] >= blue[k] + z - (s[k] == 'B');
        });
        int ans = max(max(kx, ky), kz);
        if (ans == n) {
            cout << -1 << endl;
        }
        else {
            cout << ans + 1 << endl;
        }
    }
    return 0;
}
