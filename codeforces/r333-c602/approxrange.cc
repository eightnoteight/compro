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
    #ifndef __mr__
        ios::sync_with_stdio(0);cin.tie(0);
    #endif
    int n;
    cin >> n;
    vector<int> arr(n);
    cin >> arr[0];
    for (int i = 1; i < n; ++i) {
        cin >> arr[i];
        arr[i - 1] = arr[i] - arr[i - 1];
    }
    arr[n - 1] = 1;
    int lastch = 1, lastpos = -1, maxdiff = 0, start = 0;
    for (int i = 0; i < n; ++i) {
        maxdiff = max(i - start + 1, maxdiff);
        if (lastch == arr[i]) {
            start = lastpos + 1;
        }
        if (arr[i] != 0) {
            lastch = arr[i];
            lastpos = i;
        }
    }
    cout << maxdiff << endl;
    return 0;
}
