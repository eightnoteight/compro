#include <bits/stdc++.h>
#ifdef __lucy__
    #include "prettyprint.hpp"
#endif
// #define endl                                        ('\n')
#define i32inf                                      (0x7fffffff)
#define i32_inf                                     (-0x7fffffff-1)
#define i64inf                                      (0x7fffffffffffffff)
#define i64_inf                                     (-0x7fffffffffffffff-1)
#define ui32inf                                     (0xffffffffu)
#define ui64inf                                     (0xffffffffffffffffu)
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
namespace itertools {
    template<class DT>
    vector<DT> groupby(vector<DT> data) {
        sort(data.begin(), data.end());
        data.resize(distance(data.begin(), unique(data.begin(), data.end())));
        return move(data);
    }
}
int32_t testcases;

template<typename intType>
intType gcd(intType a, intType b) {
    while(b) {
        intType tmp = b;
        b = a % b;
        a = tmp;
    }
    return a;
}

vector<int32_t> sieve(int32_t n) {
    vector<int32_t> primes(n);
    for (int x = 0; x < n; ++x)
        primes[x] = x;
    primes[1] = 0;
    for(int32_t x = 4; x < n; x += 2)
        primes[x] = 0;
    for(int32_t x = 9; x < n; x += 6)
        primes[x] = 0;
    int32_t csn = ceil(sqrt(n));
    for (int32_t x = 1; 6*x + 1 < csn; x++) {
        if (primes[6*x - 1])
            for(int32_t y = (6*x - 1)*(6*x - 1); y < n; y += 2*(6*x - 1))
                primes[y] = 0;
        if (primes[6*x + 1])
            for(int32_t y = (6*x + 1)*(6*x + 1); y < n; y += 2*(6*x + 1))
                primes[y] = 0;
    }
    primes.resize(distance(primes.begin(), remove(primes.begin(), primes.end(), 0)));
    return move(primes);
}

int main() {
    #ifndef __lucy__
        ios::sync_with_stdio(0);cin.tie(0);
    #endif
    cin >> testcases;
    auto lcm = [](int64_t x, int64_t y) {
        return x*y / gcd(x, y);
    };
    auto primes = sieve(65556);
    loop (test, 1, testcases + 1) {
        int64_t n, m;
        cin >> n >> m;
        int64_t k = n*m / gcd(n, m);
        int64_t z = gcd(n, m);
        for (int32_t x = 0; x < len(primes) && primes[x] <= z; ++x) {
            while (z % primes[x] == 0) {
                int64_t knew = k / primes[x];
                if (lcm(n, knew) % m != 0 || lcm(m, knew) % n != 0)
                    break;
                k = knew;
                z /= primes[x];
            }
        }
        k /= z;
        if (lcm(n, k) % m != 0 || lcm(m, k) % n != 0)
            k *= z;
        cout << k << endl;
    }
    return 0;
}
