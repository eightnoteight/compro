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
    long long int n, ai, bi;
    cin >> n;
    vector<long long int> arr(1000001), cum(1000002), dp(1000002);
    for (long long int i = 0; i < n; ++i) {
        cin >> ai >> bi;
        arr[ai] = bi;
        cum[ai] = 1;
    }
    partial_sum(cum.begin(), cum.end(), cum.begin());
    dp[0] = 0;
    for (long long int i = 1; i < 1000001; ++i) {
        if (arr[i] == 0)
            dp[i] = cum[i] - ((i - arr[i] - 1 < 0) ? 0 : cum[i - arr[i] - 1])  + ((i - arr[i] - 1 < 0) ? 0 : dp[i - arr[i] - 1]);
        else
            dp[i] = cum[i] - ((i - arr[i] - 1 < 0) ? 0 : cum[i - arr[i] - 1])  + ((i - arr[i] - 1 < 0) ? 0 : dp[i - arr[i] - 1]) - 1;
    }
    long long int ans = n;
    for (long long int i = 0; i < 1000001; ++i) {
        ans = min(dp[i] + cum.back() - cum[i], ans);
    }
    cout << ans << endl;

    return 0;
}
