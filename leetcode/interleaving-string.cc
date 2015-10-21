#include <bits/stdc++.h>
#ifdef __mr__
    #include "prettyprint.hpp"
#endif
#ifndef __mr__
    #define endl                                               '\n'
#endif
using namespace std;
class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        vector<vector<bool> > dp(s1.size() + 1, vector<bool>(s2.size() + 1, false));
        dp[0][0] = true;
        for (int i = 1; i <= s2.size(); ++i) {
            dp[0][i] = (dp[0][i - 1] && (s2[i - 1] == s3[i - 1]));
        }
        for (int r = 1; r <= s1.size(); ++r) {
            dp[r][0] = dp[r - 1][0] && s1[r - 1] == s3[r - 1];
            for (int c = 1; c <= s2.size(); ++c) {
                dp[r][c] = (dp[r - 1][c] && s1[r - 1] == s3[r + c - 1]) || (dp[r][c - 1] && s2[c - 1] == s3[r + c - 1]);
            }
        }
        return dp[s1.size()][s2.size()];
    }
};
int main(int argc, char const *argv[]) {
    Solution test;
    string s1, s2, s3;
    cin >> s1 >> s2 >> s3;
    cout << test.isInterleave(s1, s2, s3) << endl;
    return 0;
}
