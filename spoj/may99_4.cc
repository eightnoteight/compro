#include <bits/stdc++.h>
#ifdef __lucy__
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

int64_t invmod(int64_t a, int64_t b) {
    int64_t b0 = b, t, q;
    int64_t x0 = 0, x1 = 1;
    if (b == 1)
        return 1;
    while (a > 1) {
        q = a / b;
        t = b; b = a % b; a = t;
        t = x0; x0 = x1 - q*x0; x1 = t;
    }
    if (x1 < 0)
        x1 += b0;
    return x1;
}

int main() {
    int32_t n, r;
    cin >> n >> r;
    if (r > n) {
        cout << -1 << endl;
    }
    else {
        int32_t ways = 1;
        for (int32_t x = 1; x <= n - 1; ++x)
            ways = (1ll * ways * x) % 10000007;
        for (int32_t x = 1; x <= n - r; ++x)
            ways = (1ll * ways * invmod(x, 10000007)) % 10000007;
        for (int32_t x = 1; x <= r - 1; ++x)
            ways = (1ll * ways * invmod(x, 10000007)) % 10000007;
        cout << ways << endl;
    }
    return 0;
}
