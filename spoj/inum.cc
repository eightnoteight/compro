#include <bits/stdc++.h>
#ifdef __mr__
    #include "prettyprint.hpp"
#endif
#define endl                        ('\n')
using namespace std;

int main() {
    ios::sync_with_stdio(0);cin.tie(0);
    int64_t n;
    cin >> n;
    vector<int64_t> arr(n);
    if (n == 1) {
        cout << "0 0\n";
        return 0;
    }
    for (int64_t& x: arr)
        cin >> x;
    sort(arr.begin(), arr.end());
    int64_t maxdiffs = 0, mindiffs = 0;
    // counting maxdiffs
    int64_t lower = 1;
    while(arr[lower] == arr[lower - 1]) lower++;
    int64_t higher = 1;
    while(arr[n - higher] == arr[n - higher - 1]) higher++;
    maxdiffs = lower*higher;
    bool flag = false;
    for (int x = 1; x < n; ++x)
        if (arr[x] == arr[x - 1]){
            flag = true;
            break;
        }
    // counting mindiffs
    if (flag) {
        int64_t counts = 1;
        for (int64_t x = 1; x < n; ++x) {
            if (arr[x] == arr[x - 1]){
                counts++;
            }
            else {
                mindiffs += (counts*(counts - 1)) / 2;
                counts = 1;
            }
        }
        mindiffs += (counts*(counts - 1)) / 2;
    }
    else {
        int64_t mindiff = arr[1] - arr[0];
        for (int64_t x = 1; x < n; ++x) {
            if (arr[x] - arr[x - 1] < mindiff) {
                mindiff = arr[x] - arr[x - 1];
                mindiffs = 1;
            }
            else if (arr[x] - arr[x - 1] == mindiff)
                mindiffs++;
        }
    }
    if (*arr.rbegin() == *arr.begin())
        cout << (n*(n - 1)) / 2 << " " << (n*(n - 1)) / 2 << endl;
    else
        cout << mindiffs << " " << maxdiffs << endl;
    return 0;
}
