#include <bits/stdc++.h>
#ifdef __mr__
    #include "prettyprint.hpp"
#else
    #define endl                                               '\n'
#endif
#define ulong                                                   unsigned long
using namespace std;
const ulong mod = 1000000007ul;

int main(int argc, char const *argv[]) {
    #ifndef __mr__
        ios::sync_with_stdio(0);cin.tie(0);
    #endif
    uint testcases, n;
    uint area[11];
    uint spot[11];
    cin >> testcases;
    for (uint _ = 0; _ < testcases; ++_) {
        cin >> n;
        for (uint i = 0; i < n; ++i) {
            cin >> area[i];
        }
        for (uint i = 0; i < n; ++i) {
            cin >> spot[i];
        }
    }
    return 0;
}
