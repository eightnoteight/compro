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
using namespace std;
inline void print() {}
template<typename _p, typename... _args>
inline void print(_p p, _args... args) {cout << p << ' '; print(args...);}
template<typename... _args>
inline void println(_args... args) {print(args...); cout << '\n';}
inline void write() { }
template<typename _p, typename... _args>
inline void write(_p p, _args... args) { cout << p; write(args...); }
inline void scan() { }
template<typename _p, typename... _args>
inline void scan(_p& p, _args&... args) { cin >> p; scan(args...); }

uint64_t powmod(uint64_t x, uint64_t a, uint64_t mod) {
    uint64_t y = 1;
    while(a) {
        if (a & 1)
            y = (y * x) % mod;
        x = (x * x) % mod;
        a >>= 1;
    }
    return y;
}

int main() {
    #ifndef __lucy__
        ios::sync_with_stdio(0);cin.tie(0);
    #endif
    uint32_t mod = 1000000007;
    unique_ptr<uint32_t[]> fibs(new uint32_t[10000010]);
    fibs[0] = 0; fibs[1] = 1; fibs[2] = 1;
    for (uint64_t x = 3; x < 10000010; x++)
        fibs[x] = (fibs[x - 1] + fibs[x - 2]) % mod;
    vector<array<uint32_t, 2> > nonfibsgen(50);
    nonfibsgen[0] = {4, 2};
    nonfibsgen[1] = {6, 3};
    nonfibsgen[2] = {9, 5};
    for (uint32_t x = 3; x < 50; ++x)
        nonfibsgen[x] = {
            nonfibsgen[x - 1][0] + nonfibsgen[x - 1][1],
            nonfibsgen[x - 1][1] + nonfibsgen[x - 2][1]};
    reverse(nonfibsgen.begin(), nonfibsgen.end());
    unique_ptr<uint32_t[]> nonfibs(new uint32_t[10000010]);
    for (uint32_t x = 1; x < 10000010; ++x) {
        if (nonfibsgen.back()[1] <= 1)
            nonfibsgen.pop_back();
        nonfibs[x] = nonfibsgen.back()[0];
        ++nonfibsgen.back()[0];
        --nonfibsgen.back()[1];
    }
    uint32_t testcases;
    scan(testcases);
    for (uint32_t test = 0; test < testcases; ++test){
        uint32_t n;
        scan(n);
        println(powmod(nonfibs[n], fibs[n], mod));
    }
    return 0;
}
