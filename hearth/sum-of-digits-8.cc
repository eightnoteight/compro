/*
 * https://www.hackerearth.com/problem/algorithm/sum-of-digits-8/
 */
#include <bits/stdc++.h>
#ifdef __mr__
    #include "prettyprint.hpp"
#else
    #define endl                                               '\n'
#endif
#define uint                                                    unsigned int
#define ulong                                                   unsigned long long
using namespace std;
const ulong mod = 1000000007ul;

uint s;
ulong a, b;
ulong num = 0xffffffffffffffff;
vector<vector<ulong>> summat;

ulong genoutput (uint pos, int csum, ulong cnum) {
    if (csum == 0 && pos == a.size())
        return 1;
    else if (csum < 0 || pos == a.size())
        return 0;
    ulong count = 0;
    count += genoutput(pos + 1, csum - (a[pos] - '0'), cnum * 10 + (a[pos] - '0'));
    if (((csum - (a[pos] - '0')) == 0) && (a.size() - (pos + 1) == 0))
        num = min(num, cnum * 10 + (a[pos] - '0'));
    for (char i = a[pos] + 1; i < b[pos]; ++i) {
    cout << pos << ' ' << csum << endl;
        if (((csum - (i - '0')) >= 0) && (a.size() - (pos + 1) >= 0)) {
            cout << count << endl;
            count += genoutput(pos + 1, csum - (i - '0'), cnum * 10 + (i - '0')) + \
                summat[a.size() - pos - 1][csum - (i - '0')];
            cout << count << endl;
        }
        if (((csum - (i - '0')) == 0) && (a.size() - (pos + 1) == 0))
            num = min(num, cnum * 10 + (i - '0'));
    }
    count += genoutput(pos + 1, csum - (b[pos] - '0'), cnum * 10 + (b[pos] - '0'));
    if (((csum - (b[pos] - '0')) == 0) && (a.size() - (pos + 1) == 0))
        num = min(num, cnum * 10 + (b[pos] - '0'));
    return count;
}

int main(int argc, char const *argv[]) {
    #ifndef __mr__
        ios::sync_with_stdio(0);cin.tie(0);
    #endif
    uint s;
    cin >> a >> b >> s;
    summat(a.size(), vector<ulong>(s + 1));
    for (uint j = 0; j <= s; ++j)
        summat[0][j] = (j <= 9) ? 1 : 0;
    for (uint i = 1; i < a.size(); ++i) {
        summat[i][0] = 1;
        for (uint j = 1; j <= s; ++j) {
            summat[i][j] = summat[i - 1][j];
            for (uint k = 1; k <= min({9u, j}); ++k)
                summat[i][j] += summat[i][j - k];
        }
    }
    cout << genoutput(0, s, 0) << endl;
    cout << num << endl;
    return 0;
}
