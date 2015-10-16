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

vector<int32_t> sieve(int32_t n)
{
    vector<int32_t> arr(n);
    for (int x = 0; x < n; ++x)
        arr[x] = x;
    for (int32_t x = 4; x < n; x += 2)
        arr[x] = 0;
    int32_t csn = ceil(sqrt(n));
    for (int32_t x = 9; x < n; x += 6)
        arr[x] = 0;
    arr[1] = 0;
    for (int32_t x = 7, y = 5; x < csn + 10; x += 6, y += 6) {
        if(arr[y])
            for (int32_t z = y*y; z < n; z += 2*y)
                arr[z] = 0;
        if(arr[x])
            for (int32_t z = x*x; z < n; z += 2*x)
                arr[z] = 0;
    }
    vector<int32_t> primes;
    primes.push_back(2);
    for (int x = 3; x < n; x += 2)
        if(arr[x])
            primes.push_back(x);
    return move(primes);
}

int main() {
    #ifndef __mr__
        ios::sync_with_stdio(0);cin.tie(0);
    #endif
    vector<int32_t> primes = sieve(100000001);
    cout << primes.size() << endl;
    cin >> testcases;
    for (int32_t test = 1; test <= testcases; ++test) {
        int32_t n, m;
        cin >> n >> m;
        // int32_t csn = ceil(sqrt(n));
        int32_t result = 1;
        for (int32_t x = 1, pxcount = 0; primes[x] <= n; ++x, pxcount = 0) {
            for (int32_t y = primes[x]; y <= n; y *= primes[x])
                pxcount += n / y;
            result = (1ll * result * (pxcount + 1)) % m;
        }
        result = (result - 1) % m;
        if (result < 0)
            result = (result + m) % m;
        cout << result << endl;
    }
    return 0;
}
