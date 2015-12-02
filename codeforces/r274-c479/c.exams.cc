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
    vector<pair<int, int>> arr(n);
    for (int i = 0; i < n; ++i)
        cin >> arr[i].first >> arr[i].second;
    sort(arr.begin(), arr.end());
    pair<bool, bool> lastb = make_pair(true, true);
    for (int i = 1; i < n; ++i) {
        pair<bool, bool> newb = make_pair(false, false);;
        if (arr[i].first >= arr[i - 1].first && lastb.first)
            newb.first = true;
        if (arr[i].first >= arr[i - 1].second && lastb.second)
            newb.first = true;
        if (arr[i].second >= arr[i - 1].first && lastb.first)
            newb.second = true;
        if (arr[i].second >= arr[i - 1].second && lastb.second)
            newb.second = true;
        lastb = newb;
    }
    if (lastb.first && lastb.second)
        cout << min(arr.back().first, arr.back().second) << endl;
    else if (lastb.first)
        cout << arr.back().first << endl;
    else if (lastb.second)
        cout << arr.back().second << endl;
    else
        assert(false);
    return 0;
}
