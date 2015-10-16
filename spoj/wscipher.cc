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

int main() {
    ios::sync_with_stdio(0);cin.tie(0);
    for ( ; ; ) {
        int32_t k1, k2, k3;
        string brownfox, superfox;
        cin >> k1 >> k2 >> k3;
        if (k1 == 0 && k2 == 0 && k3 == 0)
            break;
        cin >> brownfox;
        superfox = brownfox;
        // copy(brownfox.begin(), brownfox.end(), superfox.begin());
        // cout << "superfox: " << superfox << endl;
        vector<int32_t> G1, G2, G3;
        for (int32_t y = 0, x = brownfox[0]; y < brownfox.size(); x = brownfox[++y]) {
            if (x == '_')
                x = 'z' + 1;
            if (x >= 'a' && x <= 'i')
                G1.push_back(y);
            else if (x >= 'j' && x <= 'r')
                G2.push_back(y);
            else if (x >= 's' && x <= 'z' + 1)
                G3.push_back(y);
        }
        // cout << G1 << endl << G2 << endl << G3 << endl;
        // k1 %= G1.size(); k2 %= G2.size(); k3 %= G3.size();
        for (size_t x = 0; x < G1.size(); ++x)
            superfox[G1[(x + k1) % G1.size()]] = brownfox[G1[x]];
        for (size_t x = 0; x < G2.size(); ++x)
            superfox[G2[(x + k2) % G2.size()]] = brownfox[G2[x]];
        for (size_t x = 0; x < G3.size(); ++x)
            superfox[G3[(x + k3) % G3.size()]] = brownfox[G3[x]];
        // cout << brownfox << endl;
        cout << superfox << endl;
    }
    return 0;
}
