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
// const ulong mod = 1000000007ul;

template<intType>
inline intType mod_app(intType x, intType m) {
    return (x % m + m) % m;
}

class RabinKarp
{
vector<ulong> harr;
const ulong mul = 10007;
const ulong mod = 1000000007;
public:
    RabinKarp(vector<ulong>& arr) {
        harr.emplace_back(0);
        for (ulong x: arr) {
            harr.emplace_back(mod_app(harr.back() * mul + x, mod));
        }
    }

    uint rangehash(uint lo, uint hi) {
        return mod_app(harr[hi] - mod_app(harr[lo] * pow_mod(mul, hi - lo, mod), mod), mod);
    }
};

int main(int argc, char const *argv[]) {
    #ifndef __mr__
        ios::sync_with_stdio(0);cin.tie(0);
    #endif
        cin >> n >> m;
    vector<pair<int, int>> text(n);
    vector<pair<int, int>> patt(n);
    for (int i = 0; i < n; ++i) {
        char lici[100];
        cin >> lici;
        int k = strlen(lici);
        text[i].second = lici[k - 1];
        lici[k - 2] = 0;
        text[i].first = atoi(lici)
    }
    for (int i = 0; i < m; ++i) {
        char lici[100];
        cin >> lici;
        int k = strlen(lici);
        patt[i].second = lici[k - 1];
        lici[k - 2] = 0;
        patt[i].first = atoi(lici)
    }

    return 0;
}
