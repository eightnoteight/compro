#include <bits/stdc++.h>
#ifdef __mr__
    #include "prettyprint.hpp"
#else
    #define endl                                               '\n'
#endif
#define int                                                     int32_t
#define uint                                                    uint32_t
#define ulong                                                   uint64_t
#define long                                                    int64_t
using namespace std;
const ulong mod = 1000000007ul;

int main(int argc, char const *argv[]) {
    #ifndef __mr__
        ios::sync_with_stdio(0);cin.tie(0);
    #endif
    string a, b;
    cin >> a >> b;
    vector<ulong> cumb;
    cumb.push_back(0);
    for (uint i = 0; i < b.size(); ++i)
        cumb.push_back(cumb.back() + b[i] - '0');
    ulong hamsum = 0;
    for (uint i = 0; i < a.size(); ++i) {
        if (a[i] == '0')
            hamsum += cumb[b.size() - a.size() + 1 + i] - cumb[i];
        else
            hamsum += b.size() - a.size() + 1 - (cumb[b.size() - a.size() + 1 + i] - cumb[i]);
    }
    cout << hamsum << endl;
    return 0;
}
