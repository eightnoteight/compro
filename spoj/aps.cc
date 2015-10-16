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

int main() {
    ios::sync_with_stdio(0);cin.tie(0);
    vector<int64_t> lfac(10000001), aps(10000001);
    for (int i = 2; i*i < 10000001; i++)
        if (!lfac[i])
            for (int j = i*i; j < 10000001; j += i)
                if (!lfac[j])
                    lfac[j] = i;
    for (int i = 2; i < 10000001; i++)
        if (!lfac[i])
            lfac[i] = i;
    for (int i = 2; i < 10000001; i++)
        aps[i] = aps[i - 1] + lfac[i];

    cin >> testcases;
    for (int test = 1; test <= testcases; ++test) {
        int n;
        cin >> n;
        cout << aps[n] << endl;
    }
    return 0;
}
