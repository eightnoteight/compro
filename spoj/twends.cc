#include <bits/stdc++.h>
#ifdef __lucy__
    #include "prettyprint.hpp"
#endif
#define endl                                        ('\n')
using namespace std;

int32_t* arr = new int32_t[1001];
int32_t* dp = new int32_t[1001];
uint32_t n;

template<class Function1, class Function2>
int32_t twends_dp(Function1 player1, Function2 player2) {
    for (uint32_t y = 0; y <= n - 1; ++y)
        dp[y] = player1(0, 0, y, y + 1);
    for (uint32_t x = 2; x <= n; ++x) {
        if (x % 2)
            for (uint32_t y = 0; y <= n - x; ++y)
                dp[y] = player1(dp[y], dp[y + 1], y, y + x);
        else
            for (uint32_t y = 0; y <= n - x; ++y)
                dp[y] = player2(dp[y], dp[y + 1], y, y + x);
    }
    return dp[0];
}

int main() {
    #ifndef __lucy__
        ios::sync_with_stdio(0);cin.tie(0);
    #endif
    uint32_t test = 1;
    while ((cin >> n) && n) {
        for (uint32_t x = 0; x < n; ++x)
            cin >> arr[x];
        uint32_t sumarr = accumulate(arr, arr + n, 0);
        auto maxStratergy = [](uint32_t lpart, uint32_t rpart, uint32_t lo, uint32_t hi) -> uint32_t {
            return min(lpart, rpart);
        };
        auto greedyStratergy = [](uint32_t lpart, uint32_t rpart, uint32_t lo, uint32_t hi) -> uint32_t {
            if (arr[hi - 1] > arr[lo])
                return lpart + arr[hi - 1];
            else
                return rpart + arr[lo];
        };
        cout << "In game " << test++
            << ", the greedy strategy might lose by as many as ";
        if (n % 2)
            cout << sumarr - 2*twends_dp(maxStratergy, greedyStratergy);
        else
            cout << sumarr - 2*twends_dp(greedyStratergy, maxStratergy);
        cout << " points." << endl;
    }
    return 0;
}

