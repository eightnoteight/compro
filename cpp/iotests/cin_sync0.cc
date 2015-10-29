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
    ios::sync_with_stdio(0);cin.tie(0);
    ulong* arr = new ulong[10000001];
    uint k = 0;
    for (uint x = 0; x < 10000001; ++x) {
        cin >> arr[x];
        k += __builtin_popcountll(arr[x]);
    }
    return 0;
}
