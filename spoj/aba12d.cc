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
#define len(x)                                      ((uint32_t)(x).size())
#define esort(x)                                    (sort((x).begin(), (x).end()))
#define ersort(x)                                   (sort((x).rbegin(), (x).rend()))
#define name(x)                                     (#x)
#define uint32_t                                    unsigned int
#define uint8_t                                     unsigned short
using namespace std;
template <class number>
inline void input(number& p){
    register char c = getchar_unlocked();
    bool sign = false;
    while (c < 33)
        c = getchar_unlocked();
    p = 0;
    if (c == '-'){
        sign = true;
        c = getchar_unlocked();
    }
    while (c > 33){
        p = (p * 10) + (c - '0');
        c = getchar_unlocked();
    }
    if (sign)
        p *= -1;
}
inline void print(const char* format, ...){
    va_list arguments;
    va_start(arguments, format);
    register char c;
    char num[20];
    int i = 0, j;
    long n;
    while (format[i] != '\0'){
        if (format[i] != '{')
            putchar_unlocked(format[i++]);
        else{
            i += 2;
            n = va_arg(arguments, uint32_t);
            j = 0;
            do{
                num[j++] = n%10 + 48;
                n /= 10;
            }  while (n != 0);
            j--;
            while (j >= 0)
                putchar_unlocked(num[j--]);
        }
    }
    va_end(arguments);
}
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

void genprimes(uint32_t n, vector<uint32_t>& primes, vector<uint8_t>& sieve) {
    sieve.resize(n); fill(sieve.begin(), sieve.end(), 1);
    uint32_t sqrt_limit = static_cast<uint32_t>(sqrt(n));
    sieve[0] = sieve[1] = 0;
    for (uint32_t x = 2; x < sqrt_limit; ++x)
        if (sieve[x])
            for (uint32_t y = x*x; y < n; y += x)
                sieve[y] = 0;
    for (uint32_t x = 0; x < n; ++x)
        if (sieve[x])
            primes.push_back(x);
}
uint32_t divsum(uint32_t x, vector<uint32_t>& primes) {
    uint32_t result = 1, s, k;
    for(uint32_t _ = 0, p = primes[0]; _ < primes.size(); p = primes[++_]) {
        if (p * p > x)
            break;
        s = 0, k = 1;
        while (x % k == 0) {
            s += k;
            k *= p;
        }
        result *= s;
    }
    return result;
}
int main() {
    vector<uint32_t> primes;
    vector<uint8_t> sieve;
    genprimes(4400044, primes, sieve);
    vector<uint32_t> spnum(1000001);
    spnum[2] = 1;
    for (uint32_t x = 2, y = 4; y < 1000001; y = ++x * x)
        spnum[y] = sieve[divsum(y, primes)];
    partial_sum(spnum.begin(), spnum.end(), spnum.begin());


    uint32_t testcases;
    input(testcases);
    for (uint32_t _ = 0; _ < testcases; ++_) {
        uint32_t lo, hi;
        input(lo); input(hi);
        print("{}\n", spnum[hi] - spnum[lo - 1]);
    }
    return 0;
}
