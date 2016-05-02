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

template<class intType>
inline intType mod_app(intType x, intType m) {
    return (x % m + m) % m;
}

template<class intType>
intType pow_mod(intType x, intType a, intType mod) {
    intType y = 1;
    while(a != 0) {
        if (a % 2 == 1)
            y = (y * x) % mod;
        x = (x * x) % mod;
        a /= 2;
    }
    return y;
}

class rangehash {
private:
    vector<ulong> harr;
    const ulong mul = 10007ull;
    const ulong mod = 1000000007ull;
public:
    rangehash(vector<ulong>& arr) {
        harr.resize(arr.size() + 1);
        auto it = harr.begin();
        *(it++) = 0;
        for (ulong x: arr) {
            *(it++) = mod_app(harr.back() * mul + x, mod);
        }
    }

    uint range(uint lo, uint hi) {
        return mod_app(harr[hi] - mod_app(harr[lo] * pow_mod(mul, hi - lo, mod), mod), mod);
    }
};

class fastrangehash {
private:
    vector<uint> harr;
    const uint mul = 101;
public:
    fastrangehash(vector<uint>& arr) {
        harr.resize(arr.size() + 1);
        auto it = harr.begin();
        *(it++) = 0;
        for (uint x: arr) {
            *(it++) = harr.back() * mul + x;
        }
    }

    uint pow_mod(uint x, uint a) {
        uint y = 1;
        while(a != 0) {
            if (a % 2 == 1)
                y *=  x;
            x *= x;
            a <<= 1;
        }
        return y;
    }

    uint range(uint lo, uint hi) {
        return harr[hi] - harr[lo] * pow_mod(mul, hi - lo, mod);
    }
};

int main(int argc, char const *argv[]) {
    #ifndef __mr__
        ios::sync_with_stdio(0);cin.tie(0);
    #endif
    // code
    return 0;
}
