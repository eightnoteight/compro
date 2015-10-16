#include <bits/stdc++.h>
#ifdef __lucy__
    #include "prettyprint.hpp"
#endif
#define endl                                        ('\n')
#define i32max                                      (0x7fffffff)
#define i32min                                      (-0x7fffffff-1)
#define i64max                                      (0x7fffffffffffffff)
#define i64min                                      (-0x7fffffffffffffff-1)
#define ui32max                                     (0xffffffffu)
#define ui64max                                     (0xffffffffffffffffu)
#define bitcounti32                                 __builtin_popcount
#define bitcounti64                                 __builtin_popcountll
#define len(x)                                      ((int64_t)(x).size())
#define esort(x)                                    (sort((x).begin(), (x).end()))
#define ersort(x)                                   (sort((x).rbegin(), (x).rend()))
#define name(x)                                     (#x)
using namespace std;

int main() {
    #ifndef __lucy__
        ios::sync_with_stdio(0);cin.tie(0);
    #endif
    int64_t n, q;
    cin >> n;
    int64_t a[n][n];
    int64_t b[n][n];
    for (int64_t x = 0; x < n; ++x)
        for (int64_t y = 0; y < n; ++y)
            cin >> a[x][y];
    for (int64_t x = 0; x < n; ++x)
        for (int64_t y = 0; y < n; ++y)
            cin >> b[x][y];
    int64_t absum = 0;
    int64_t acolsums[n], browsums[n];
    for (int64_t x = 0; x < n; ++x) {
        acolsums[x] = 0;
        browsums[x] = 0;
        for (int64_t y = 0; y < n; ++y) {
            acolsums[x] += a[y][x];
            browsums[x] += b[x][y];
            for (int64_t z = 0; z < n; ++z)
                absum += a[x][z] * b[z][y];
        }
    }
    cin >> q;
    for (int64_t _ = 0; _ < q; ++_) {
        char op;
        int64_t i, j;
        int64_t k;
        cin >> op >> i >> j >> k;
        if (op == 'A') {
            absum = absum - browsums[j] * a[i][j] + browsums[j] * k;
            acolsums[j] = acolsums[j] - a[i][j] + k;
            a[i][j] = k;
        }
        else {
            absum = absum - acolsums[i] * b[i][j] + acolsums[i] * k;
            browsums[i] = browsums[i] - b[i][j] + k;
            b[i][j] = k;
        }
        cout << absum << endl;
    }
    return 0;
}

