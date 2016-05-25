#include <bits/stdc++.h>
#ifdef __mr__
    #include "prettyprint.hpp"
#else
    #define endl                                               '\n'
#endif
#define uint                                                    unsigned int
#define ulong                                                   unsigned long long
using namespace std;
const ulong mod = 1000000007ul;

int main(int argc, char const *argv[]) {
    #ifndef __mr__
        ios::sync_with_stdio(0);cin.tie(0);
    #endif
    uint n, tmp;
    cin >> n;
    vector<tuple<uint, uint, uint>> source(n*n);
    vector<tuple<uint, uint, uint>> target(n*n);
    for (uint i = 0; i < n; ++i) {
        for (uint j = 0; j < n; ++j) {
            cin >> tmp;
            source[i*n + j] = make_tuple(tmp, i, j);
        }
    }
    for (uint i = 0; i < n; ++i) {
        for (uint j = 0; j < n; ++j) {
            cin >> tmp;
            target[i*n + j] = make_tuple(tmp, i, j);
        }
    }
    uint deltax = 0, deltay = 0;
    sort(source.begin(), source.end());
    sort(target.begin(), target.end());
    auto sit = source.begin(), tit = target.begin();
    int in = n;
    while (sit != source.end() && tit != target.end()) {
        if (get<0>(*sit) != get<0>(*tit))
            break;
        deltax = (deltax + (((((int)get<1>(*sit) - (int)get<1>(*tit)) % in) + in) % in)) % in;
        deltay = (deltay + (((((int)get<2>(*sit) - (int)get<2>(*tit)) % in) + in) % in)) % in;
        sit++; tit++;
    }
    deltax %= n;
    deltay %= n;
    if (sit != source.end() || tit != target.end() || deltax != 0 || deltay != 0)
        cout << "NO" << endl;
    else
        cout << "YES" << endl;
    return 0;
}
