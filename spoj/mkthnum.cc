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
template <typename _p>
inline _p getit() {_p p; cin >> p; return move(p);}
auto getint32 = getit<int32_t>; auto getuint32 = getit<uint32_t>;
auto getint64 = getit<int64_t>; auto getuint64 = getit<uint64_t>;
auto getstr = getit<string>; auto getcharacter = getit<char>;
inline void scan() { }
template<typename _p, typename... _args>
inline void scan(_p& p, _args&... args) { cin >> p; scan(args...); }

int main() {
    #ifndef __lucy__
        ios::sync_with_stdio(0);cin.tie(0);
    #endif
    cout << fixed << setprecision(6);
    int32_t testcases = getint32();
    loop (test, 1, testcases + 1) {

    }
    return 0;
}

