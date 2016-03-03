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
#define uset                        unordered_set
#define umap                        unordered_map
using namespace std;
const ulong mod = 1000000007ul;

int main(int argc, char const *argv[]) {
    #ifndef __mr__
        ios::sync_with_stdio(0);cin.tie(0);
    #endif
    long n;
    cin >> n;
    vector<long> arr(n);
    for (long i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    umap<long, int> arrcounts;
    for(uint i = 0; i < n; ++i) {
        arrcounts[arr[i]]++;
    }
    vector<long> series(n);
    long mlen = count(arr.begin(), arr.end(), 0);
    if (mlen == 1)
        mlen = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i == j)
                continue;
            long len = 2;
            series[0] = arr[i];
            series[1] = arr[j];
            arrcounts[arr[i]]--;
            arrcounts[arr[j]]--;
            if (arr[i] == 0 && arr[j] == 0)
                continue;
            for (long x = arr[i], y = arr[j]; ; series[len++] = y) {
                auto zit = arrcounts.find(x + y);
                if (zit == arrcounts.end() or arrcounts[zit->first] == 0)
                    break;
                arrcounts[zit->first]--;
                x = y;
                y = zit->first;
            }
            for (int i = 0; i < len; ++i)
                arrcounts[series[i]]++;
            mlen = max(len, mlen);
        }
    }
    cout << mlen << endl;
    return 0;
}
