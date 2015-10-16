#include <bits/stdc++.h>
#ifdef __lucy__
    #include "prettyprint.hpp"
#endif
#define endl                                        ('\n')
#define i32max                                      (0x7fffffff)
#define i32min                                      (-0x7fffffff-1)
using namespace std;

int main() {
    #ifndef __lucy__
        ios::sync_with_stdio(0);cin.tie(0);
    #endif
    string arr;
    cin >> arr;
    int32_t oezs[5] = {i32min, i32min, i32min, i32min, 0};
    int32_t oezsf[10] = {2, 0, 0, 0, 0, 0, 0, 3,  1, 0};
    for (auto x = arr.rbegin(); x != arr.rend(); ++x) {
        int32_t y = *x - '0';
        oezs[oezsf[y]] = max(oezs[oezsf[y]] + 1, oezs[oezsf[y] + 1] + 1);
    }
    cout << max(oezs[0], 0) << endl;
    return 0;
}

