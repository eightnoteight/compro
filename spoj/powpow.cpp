#include <bits/stdc++.h>
#ifdef __lucy__
    #include "prettyprint.hpp"
#endif
#define endl                                        ('\n')
#define i32max                                      (0x7fffffff)
#define i32min                                      (-0x7fffffff-1)
#define i64max                                      (0x7fffffffffffffff)
#define i64min                                      (-0x7fffffffffffffff-1)
#define ui32max                                     (0xffffffffu)
#define ui64max                                     (0xffffffffffffffffu)
#define bitcounti32                                 __builtin_popcount
#define bitcounti64                                 __builtin_popcountll
#define loop_1(end)                                 for (int32_t __i = 1; __i <= (end); __i++)
#define loop_2(var, end)                            for (int32_t var = 0; var < (end); var++)
#define loop_3(var, start, end)                     for (int32_t var = (start); var < (end); var++)
#define loop_4(var, start, end, step)               for (int32_t var = (start); (step) > 0 ? var < (end) : var > (end); var += (step))
#define loop_x(arg1, arg2, arg3, arg4, arg5, ...)   arg5
#define loop_choose(...)                            loop_x(__VA_ARGS__, loop_4, loop_3, loop_2, loop_1)
#define loop(...)                                   loop_choose(__VA_ARGS__)(__VA_ARGS__)
#define len(x)                                      (x.size())
#define esort(x)                                    (sort(x.begin(), x.end()))
#define ersort(x)                                   (sort(x.rbegin(), x.rend()))
using namespace std;
int32_t testcases;

int64_t powmod(int64_t x, int64_t a, int64_t mod) {
    int64_t y = 1;
    while(a) {
        if (a & 1)
            y = (y * x) % mod;
        x = (x * x) % mod;
        a >>= 1;
    }
    return y;
}

inline int64_t modinv(int64_t a, int64_t p) {
    return powmod(a, p - 2, p);
}

int main() {
    #ifndef __lucy__
        ios::sync_with_stdio(0);cin.tie(0);
    #endif
    int64_t mod = 1000000007;
    int64_t p = 500000003; // (mod - 1) / 2
    int64_t imod2p = modinv(2, p);
    vector<int64_t> factmodp = {1};
    loop(x, 1, 200002)
        factmodp.push_back((factmodp.back() * x) % p);
    auto modBinomial = [&factmodp, &p, &mod, &imod2p] (int64_t n, int64_t r) -> int64_t {
        // by chinese remainder theorem; https://en.wikipedia.org/wiki/Chinese_remainder_theorem; for k = 2 condition
        // x % (2*500000003) = (x mod 2)*500000003*modinv(500000003, 2) + (x mod 500000003)*2*modinv(2, 500000003)
        // as x = 2nCn, so x mod 2 will always be 0
        // hence
        // x % (2*500000003) = (x mod 500000003)*2*modinv(2, 500000003)
        int64_t ans = (factmodp[n] * modinv((factmodp[r] * factmodp[n - r]) % p, p)) % p;
        ans = (2 * ans * imod2p) % (mod - 1);
        return ans;
    };
    cin >> testcases;
    loop (test, 1, testcases + 1) {
        int64_t a, b, n;
        cin >> a >> b >> n;
        int64_t answer = powmod(a, powmod(modBinomial(2*n, n), b, mod - 1), mod);
        cout << answer << endl;
    }
    return 0;
}
