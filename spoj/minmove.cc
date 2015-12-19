#include <bits/stdc++.h>
#ifdef __mr__
    #include "prettyprint.hpp"
#else
    #define endl                                               '\n'
#endif
#define uint                                                    unsigned int
#define ulong                                                   unsigned long long
using namespace std;

int buildsufarr(char* txt, int n) {
    vector<array<int, 3>> suffixes(n);
    vector<int> findpos(n);
    int prerank;
    for (int i = 0; i < n - 1; ++i)
        suffixes[i] = {i, txt[i] - 'a', txt[i + 1] - 'a'};
    suffixes[n - 1] = {n - 1, txt[n - 1] - 'a', txt[0] - 'a'};
    for (int k = 2; k < 2*n; k += k) {
        stable_sort(suffixes.begin(), suffixes.end(), [](const array<int, 3>& x, const array<int, 3>& y) -> bool {
            return (x[1] == y[1]) ? (x[2] < y[2]) : (x[1] < y[1]);
        });
        prerank = suffixes[0][1];
        suffixes[0][1] = 0;
        for (int i = 1; i < n; ++i) {
            if (suffixes[i][1] == prerank && suffixes[i][2] == suffixes[i - 1][2]) {
                suffixes[i][1] = suffixes[i - 1][1];
            }
            else {
                prerank = suffixes[i][1];
                suffixes[i][1] = suffixes[i - 1][1] + 1;
            }
        }
        for (int i = 0; i < n; ++i)
            findpos[suffixes[i][0]] = i;
        for (int i = 0; i < n; ++i)
            suffixes[i][2] = suffixes[findpos[(suffixes[i][0] + k) % n]][1];
    }
    return suffixes[0][0];
}

int main(int argc, char const *argv[]) {
    #ifndef __mr__
        ios::sync_with_stdio(0);cin.tie(0);
    #endif
    char* str = new char[100001];
    cin >> str;
    cout << buildsufarr(str, strlen(str)) << endl;
    return 0;
}
