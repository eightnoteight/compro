#include <bits/stdc++.h>
#ifdef __mr__
    #include "prettyprint.hpp"
#else
    #define endl                    '\n'
#endif
#define len(x)                      (uint)(x).size()
#define int                         int32_t
#define uint                        uint32_t
#define ulong                       uint64_t
#define long                        int64_t
#define t_max(x)                    numeric_limits<x>::max()
#define t_min(x)                    numeric_limits<x>::min()
using namespace std;
const ulong mod = 1000000007ul;

int mykmp_count(vector<pair<int, int>>& haystack, vector<pair<int, int>>& needle) {
    vector<int> cmpInd = failurefunc(needle);
    int curInd = 0;
    for (int i = 0; i < len(haystack); ) {
        if (haystack[i] == needle[curInd]) {
            ++curInd;
            ++i;
        }
        else {
            if (curInd == len(needle)) {
                needleCount += 1;
            }
            curInd = failurefunc[curInd];
        }
    }
}

int main(int argc, char const *argv[]) {
    #ifndef __mr__
        ios::sync_with_stdio(0);cin.tie(0);
    #endif
    cin >> n >> m;
    vector<pair<int, int>> haystack(n);
    vector<pair<int, int>> needle(n);
    for (int i = 0; i < n; ++i) {
        char lici[100];
        cin >> lici;
        int k = strlen(lici);
        haystack[i].second = lici[k - 1];
        lici[k - 2] = 0;
        haystack[i].first = atoi(lici)
    }
    for (int i = 0; i < m; ++i) {
        char lici[100];
        cin >> lici;
        int k = strlen(lici);
        needle[i].second = lici[k - 1];
        lici[k - 2] = 0;
        needle[i].first = atoi(lici)
    }
    cout << mykmp_count(haystack, needle) << endl;

    return 0;
}
