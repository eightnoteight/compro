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

int main(int argc, char const *argv[]) {
    #ifndef __mr__
        ios::sync_with_stdio(0);cin.tie(0);
    #endif
    int n, m;
    cin >> n >> m;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    vector<pair<int, int>> opstack;
    for (int i = 0; i < m; ++i) {
        int ti, ri;
        cin >> ti >> ri;
        ri--;
        while (opstack.size() && opstack.back().second <= ri) {
            opstack.pop_back();
        }
        opstack.push_back(make_pair(ti, ri));
    }
    vector<int> answer(n);
    for (int i = n - 1; i > opstack[0].second; --i) {
        answer[i] = arr[i];
    }
    map<pair<int, int>, int> mima;
    for (int i = 0; i <= opstack[0].second; ++i) {
        mima[make_pair(arr[i], i)] = 0;
    }
    reverse(opstack.begin(), opstack.end());
    int curti;
    for (int j = opstack.back().second; j >= 0; --j) {
        if (j == opstack.back().second) {
            auto op = opstack.back();
            curti = op.first;
            opstack.pop_back();
        }
        if (curti == 1) {
            auto it = --mima.end();
            answer[j] = it->first.first;
            mima.erase(it);
        }
        else {
            auto it = mima.begin();
            answer[j] = it->first.first;
            mima.erase(it);
        }
    }
    for (int i = 0; i < n; ++i) {
        cout << answer[i] << ' ';
    }
    cout << endl;
    return 0;
}
