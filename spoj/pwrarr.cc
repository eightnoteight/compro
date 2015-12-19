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
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (uint i = 0; i < n; ++i) {
            cin >> arr[i];
        }
        sort(arr.begin(), arr.end());
        ulong s = 0, psum = 0;
        for (uint i = 0, j = 0; i < n; i = j) {
            for (j = i; j < n && arr[i] == arr[j]; ++j) ;
            s += j - i;
            psum += s*(j - i);
        }
        cout << psum << endl;
    }
    return 0;
}
