#include <bits/stdc++.h>
#ifdef __mr__
    #include "prettyprint.hpp"
#endif
#define endl                        ('\n')
#define i32inf                      (0x7fffffff)
#define i32_inf                     (-0x7fffffff-1)
#define i64inf                      (0x7fffffffffffffff)
#define i64_inf                     (-0x7fffffffffffffff-1)
#define ui32inf                     (0xffffffffu)
#define ui64inf                     (0xffffffffffffffffu)
#define bitcounti32                 __builtin_popcount
#define bitcounti64                 __builtin_popcountll
#define umap unordered_map
using namespace std;
int testcases;

int main() {
    ios::sync_with_stdio(0);cin.tie(0);
    cin >> testcases;
    for (int test = 1; test <= testcases; ++test) {
        int32_t e, n;
        cin >> e >> n;
        map<pair<int32_t, int32_t>, int32_t> dp;
        int32_t maxteams = 0;
        queue<pair<int32_t, int32_t> > Q;
        Q.push(make_pair(0, 0));
        while (Q.size()) {
            // cout << Q.front() << endl;
            auto node = Q.front(); Q.pop();
            if (node.first > n || node.second > e)
                continue;
            maxteams = max(maxteams, dp[node]);
            if ((node.first == e && node.second == n) || (node.first == n && node.second == e)) {
                break;
            }
            auto team1 = make_pair(node.first + 1, node.second + 2);
            auto team2 = make_pair(node.first + 2, node.second + 1);
            if (dp.find(team1) == dp.end() || dp[team1] > dp[node] + 1) {
                dp[team1] = dp[node] + 1;
                Q.push(team1);
            }
            if (dp.find(team2) == dp.end() || dp[team2] > dp[node] + 1) {
                dp[team2] = dp[node] + 1;
                Q.push(team2);
            }
        }
        cout << maxteams << endl;
    }
    return 0;
}
        // map<pair<int32_t, int32_t>, int32_t> cache;
        // function<int32_t (int32_t, int32_t)> acmt = [&] (int32_t x, int32_t y) -> int32_t {
        //     if (x < 0 || y < 0)
        //         return -1;
        //     if (x == 0 || y == 0)
        //         return 0;
        //     if (cache[make_pair(x, y)])
        //         return cache[make_pair(x, y)];
        //     cache[make_pair(x, y)] = max(acmt(x - 2, y - 1), acmt(x - 1, y - 2)) + 1;
        //     return cache[make_pair(x, y)];
        // };
