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
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<int> neg, pos;
        bool zeros = false;
        int ones = 0;
        for (int i = 0; i < n; ++i){
            int ivar1;
            cin >> ivar1;
            if (ivar1 < 0)
                neg.push_back(ivar1);
            else if (ivar1 > 1)
                pos.push_back(ivar1);
            else if (ivar1 == 1)
                ones += 1;
            else
                zeros = true;
        }
        sort(neg.begin(), neg.end());
        sort(pos.rbegin(), pos.rend());
        long answer = 0;
        for (int i = 0; i + 1 < neg.size(); i += 2) {
            answer += neg[i] * neg[i + 1];
        }
        for (int i = 0; i + 1 < pos.size(); i += 2){
            answer += pos[i] * pos[i + 1];
        }
        if (neg.size() % 2 == 1 && !zeros)
            answer += neg.back();
        if (pos.size() % 2 == 1)
            answer += pos.back();
        cout << answer + ones << endl;
    }
    return 0;
}
