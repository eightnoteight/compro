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
    int n, s, curtime = 0;
    cin >> n >> s;
    vector<pair<int, int>> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i].first >> arr[i].second;
    }
    sort(arr.rbegin(), arr.rend());
    for (int i = s, j = 0; i >= 0; --i) {
        while (j < arr.size() && arr[j].first == i) {
            curtime = max({arr[j].second, s - i, curtime});
            j++;
        }
        curtime++;
    }
    cout << curtime - 1 << endl;
    return 0;
}
