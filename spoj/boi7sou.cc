#include <bits/stdc++.h>
#ifdef __mr__
    #include "prettyprint.hpp"
#endif
#define endl                        ('\n')
using namespace std;

int main() {
    ios::sync_with_stdio(0);cin.tie(0);
    int32_t n, m, c;
    cin >> n >> m >> c;
    vector<int32_t> arr(n);
    for (int32_t& x: arr)
        cin >> x;
    map<int32_t, int32_t> table;
    for (int32_t x = 0; x < m - 1; ++x)
        table[arr[x]]++;
    bool silence = false;
    for (int32_t x = m - 1, y = 0; x < n; ++x, ++y) {
        table[arr[x]]++;
        if (table.rbegin()->first - table.begin()->first <= c && (silence = true))
            cout << y + 1 << endl;
        table[arr[y]]--;
        if (table[arr[y]] == 0)
            table.erase(arr[y]);
    }
    if (!silence)
        cout << "NONE" << endl;
    return 0;
}
