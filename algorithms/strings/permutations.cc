#include <bits/stdc++.h>
#ifdef __mr__
    #include "prettyprint.hpp"
#else
    #define endl                        '\n'
#endif
#define len(x)                          (uint)(x).size()
#define int                             int32_t
#define uint                            uint32_t
#define ulong                           uint64_t
#define long                            int64_t
#define t_max(x)                        numeric_limits<x>::max()
#define t_min(x)                        numeric_limits<x>::min()
using namespace std;
const ulong mod = 1000000007ul;

vector<uint> countarr(string& sarr) {
    vector<uint> v(256);
    for (char ch: sarr)
        v[ch]++;
    return move(v);
}

void permutations(string& sarr, uint x, vector<string>& perms) {
    if (x == len(sarr)) {
        perms.push_back(sarr);
        return;
    }
    static vector<uint> counter = countarr(sarr);
    for (uint i = 0; i < 256; ++i) {
        if (counter[i]) {
            counter[i]--;
            sarr[x] = i;
            permutations(sarr, x + 1, perms);
            counter[i]++;
        }
    }
}

int main(int argc, char const *argv[]) {
    #ifndef __mr__
        ios::sync_with_stdio(0);cin.tie(0);
    #endif
    string sarr = "012345";
    vector<string> perms;
    permutations(sarr, 0, perms);
    cout << perms << endl;
    cout << len(perms) << endl;
    return 0;
}
