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
using namespace std;
int testcases;


int main() {
    // ios::sync_with_stdio(0);cin.tie(0);
    cin >> testcases;
    for (int test = 1; test <= testcases; ++test) {
        int r, c;
        cin >> c >> r;
        int oilgrid[r][c];
        int maxoutput[r + c + 1][c];
        for (int x = 0; x < r + c + 1; ++x)
            for (int y = 0; y < c; ++y)
                maxoutput[x][y] = 0;
        for (int x = 0; x < r; ++x)
            for (int y = 0; y < c; ++y)
                cin >> oilgrid[x][y];
        vector<set<pair<int, int> > > dpstorage1(c);
        vector<set<pair<int, int> > > dpstorage2(c);
        auto& prev = dpstorage1;
        auto& dp = dpstorage2;
        for (int x = 0; x < c; ++x) {
            prev[x] = {{0, x}};
            maxoutput[0][x] = oilgrid[0][x];
        }
        cout << prev << endl;
        cout << dp << endl;
        for (int x = 1; x < r; ++x) {
            for (int y = 0; y < c; ++y) {
                dp[y].clear();
                if (y == 0) {
                    dp[y].insert(prev[y + 1].begin(), prev[y + 1].end());
                }
                else if (y == c - 1) {
                    dp[y].insert(prev[y - 1].begin(), prev[y - 1].end());
                }
                else {
                    dp[y].insert(prev[y + 1].begin(), prev[y + 1].end());
                    dp[y].insert(prev[y - 1].begin(), prev[y - 1].end());
                }
                dp[y].insert(make_pair(x, y));
                for (auto& it: dp[y])
                    maxoutput[x][y] += oilgrid[it.first][it.second];
                if (maxoutput[x][y] < maxoutput[x - 1][y]) {
                    dp[y].clear();
                    dp[y].insert(prev[y].begin(), prev[y].end());
                    maxoutput[x][y] = maxoutput[x - 1][y];
                }
            }
            swap(dp, prev);
        }
        for (int x = r; x < r + c + 1; ++x) {
            for (int y = 0; y < c; ++y) {
                dp[y].clear();
                if (y == 0) {
                    dp[y].insert(prev[y + 1].begin(), prev[y + 1].end());
                }
                else if (y == c - 1) {
                    dp[y].insert(prev[y - 1].begin(), prev[y - 1].end());
                }
                else {
                    dp[y].insert(prev[y + 1].begin(), prev[y + 1].end());
                    dp[y].insert(prev[y - 1].begin(), prev[y - 1].end());
                }
                for (auto& it: dp[y])
                    maxoutput[x][y] += oilgrid[it.first][it.second];
                if (maxoutput[x][y] < maxoutput[x - 1][y]) {
                    dp[y].clear();
                    dp[y].insert(prev[y].begin(), prev[y].end());
                    maxoutput[x][y] = maxoutput[x - 1][y];
                }
            }
            swap(dp, prev);
        }
        cout << "Case " << test << ": " << *max_element(maxoutput[r + c], maxoutput[r + c] + c) << endl;
    }
    return 0;
}
