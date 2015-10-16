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
#define len(x)                                      ((uint32_t)(x).size())
#define esort(x)                                    (sort((x).begin(), (x).end()))
#define ersort(x)                                   (sort((x).rbegin(), (x).rend()))
#define name(x)                                     (#x)
#define uint                                        uint32_t
#define int                                         int32_t
#define ulong                                       uint64_t
#define long                                        int64_t
using namespace std;

int main() {
    #ifndef __lucy__
        ios::sync_with_stdio(0);cin.tie(0);
    #endif
    cout << fixed << setprecision(6);
    uint testcases;
    cin >> testcases;
    for(uint test = 1; test <= testcases; ++test) {
        string expression;
        cin >> expression;
        uint n = expression.size();
        vector<vector<ulong> > tabmax(n + 1, vector<ulong>(n + 1));
        for (uint y = 0; y < n; y += 2)
            tabmax[1][y] = expression[y] - '0';
        for (uint x = 3; x < n + 1; x += 2) {
            for (uint y = 0; y < n - x + 1; y += 2) {
                for (uint z = 1; z < x; z += 2) {
                    if (expression[y + z] == '+')
                        tabmax[x][y] = max(tabmax[x][y], tabmax[z][y] + tabmax[x - z - 1][y + z + 1]);
                    else
                        tabmax[x][y] = max(tabmax[x][y], tabmax[z][y] * tabmax[x - z - 1][y + z + 1]);
                }
            }
        }
        vector<vector<ulong> > tabmin(n + 1, vector<ulong>(n + 1, ui64max));
        for (uint y = 0; y < n; y += 2)
            tabmin[1][y] = expression[y] - '0';
        for (uint x = 3; x < n + 1; x += 2) {
            for (uint y = 0; y < n - x + 1; y += 2) {
                for (uint z = 1; z < x; z += 2) {
                    if (expression[y + z] == '+')
                        tabmin[x][y] = min(tabmin[x][y], tabmin[z][y] + tabmin[x - z - 1][y + z + 1]);
                    else
                        tabmin[x][y] = min(tabmin[x][y], tabmin[z][y] * tabmin[x - z - 1][y + z + 1]);
                }
            }
        }
        cout << tabmax[n][0] << ' ' << tabmin[n][0] << endl;
    }
    return 0;
}

