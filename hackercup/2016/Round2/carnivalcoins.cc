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

uint ncr(uint n, uint r) {

}

int main(int argc, char const *argv[]) {
    #ifndef __mr__
        ios::sync_with_stdio(0);cin.tie(0);
    #endif
    uint testcases;
    cin >> testcases;
    while(testcases--) {
        uint n, k;
        double p;
        cin >> n >> k >> p;
        vector<double> arr(n + 1);
        for (int i = k; i <= n; ++i) {
            for (int j = i - k; j >= 0; --j) {
                for (int l = k; l <= i - j; ++l) {
                    arr[i] += ncr(i - j, l)*pow(p, k) + arr[j];
                }
            }
        }
        cout << arr[n] << endl;
    }
    return 0;
}
