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
    cin >> testcases;
    for (int test = 1; test <= testcases; ++test) {
        double x, y, z;
        cin >> x >> y >> z;
        double t1 = ((z*(x + sqrt(x*x + y*y + 2*y*z))) / (2*z + y));
        double t2 = ((z*(x - sqrt(x*x + y*y + 2*y*z))) / (2*z + y));
        if (t1 == (int64_t)t1)
            cout << (int64_t)t1 << endl;
        else if (t2 >= 0 && t2 == (int64_t)t2)
            cout << (int64_t)t2 << endl;
        else
            cout << "Not this time." << endl;
    }
    return 0;
}
