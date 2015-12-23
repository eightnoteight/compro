#include <bits/stdc++.h>
#ifdef __mr__
    #include "prettyprint.hpp"
#else
    #define endl                                               '\n'
#endif
#define uint                                                    unsigned int
#define ulong                                                   unsigned long long
#define len(x)                                                  (x).size()
using namespace std;
const ulong mod = 1000000007ul;

void buildsufarr(const string txt, vector<uint>& sufarr) {
    int n = len(txt);
    typedef array<int, 3> suf;
    vector<suf> suffixes(n);
    vector<int> indices(n);
    int prevrank;
    for (int i = 0; i < n - 1; ++i)
        suffixes[i] = {i, txt[i], txt[i + 1]};
    suffixes[n - 1] = {n - 1, txt[n - 1], -1};
    for (int k = 2; k < 2*n; k <<= 1) {
        stable_sort(suffixes.begin(), suffixes.end(), [](const suf& x, const suf& y) {
            return x[1] == y[1] ? x[2] < y[2] : x[1] < y[1];
        });
        prevrank = suffixes[0][1];
        suffixes[0][1] = 0;
        for (int i = 1; i < n; ++i) {
            if (suffixes[i][1] == prevrank && suffixes[i][2] == suffixes[i - 1][2]) {
                suffixes[i][1] = suffixes[i - 1][1];
            }
            else {
                prevrank = suffixes[i][1];
                suffixes[i][1] = suffixes[i - 1][1] + 1;
            }
        }
        for (int i = 0; i < n; ++i)
            indices[suffixes[i][0]] = i;
        for (int i = 0; i < n; ++i)
            suffixes[i][2] = (suffixes[i][0] + k < n) ? suffixes[indices[suffixes[i][0] + k]][1] : -1;
    }
    sufarr.resize(n);
    for (int i = 0; i < n; ++i)
        sufarr[i] = suffixes[i][0];
}

int main(int argc, char const *argv[]) {
    #ifndef __mr__
        ios::sync_with_stdio(0);cin.tie(0);
    #endif
    vector<uint> sufarr;
    buildsufarr(string("mississippi"), sufarr);
    cout << sufarr << endl;
    return 0;
}
