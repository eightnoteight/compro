#include <bits/stdc++.h>
#ifdef __lucy__
    #include "prettyprint.hpp"
#endif
#define endl                                        ('\n')
using namespace std;

int main() {
    #ifndef __lucy__
        ios::sync_with_stdio(0);cin.tie(0);
    #endif
    int32_t testcases;
    cin >> testcases;
    for(int32_t test = 1; test <= testcases; ++test) {
        int32_t n;
        int64_t k;
        cin >> n >> k;
        int64_t* arr = new int64_t[n];
        for (int i = 0; i < n; ++i)
            cin >> arr[i];
        for (int i = 0; i < n && k; ++i) if (arr[i] < 0) {
            arr[i] = -arr[i];
            k--;
        }
        cout << accumulate(arr + 0, arr + n, 0) - 2**min_element(arr + 0, arr + n)*(k % 2) << endl;
        delete[] arr;
    }
    return 0;
}
