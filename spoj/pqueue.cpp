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
#define loop_1(end)                                 for (int32_t __i = 1; __i <= ((int32_t)end); __i++)
#define loop_2(var, end)                            for (int32_t var = 0; var < ((int32_t)end); var++)
#define loop_3(var, start, end)                     for (int32_t var = (start); var < ((int32_t)end); var++)
#define loop_4(var, start, end, step)               for (int32_t var = (start); (step) > 0 ? var < ((int32_t)end) : var > ((int32_t)end); var += (step))
#define loop_x(arg1, arg2, arg3, arg4, arg5, ...)   arg5
#define loop_choose(...)                            loop_x(__VA_ARGS__, loop_4, loop_3, loop_2, loop_1)
#define loop(...)                                   loop_choose(__VA_ARGS__)(__VA_ARGS__)
#define len(x)                                      ((int32_t)(x).size())
#define esort(x)                                    (sort((x).begin(), (x).end()))
#define ersort(x)                                   (sort((x).rbegin(), (x).rend()))
#define name(x)                                     (#x)
using namespace std;
inline void print() { cout << '\n'; }
template<typename _p, typename... _args>
inline void print(_p p, _args... args) {cout << p << ' '; print(args...);}
inline void write() { }
template<typename _p, typename... _args>
inline void write(_p p, _args... args) { cout << p; write(args...); }
template <typename _p>
inline _p getit() { _p p; cin >> p; return move(p); }
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
    int32_t testcases = getint32();
    loop (test, 1, testcases + 1) {
        int32_t n = getint32(), m = getint32();
        queue<pair<int32_t, bool> > arr;
        vector<int32_t> counts(10);
        loop(x, n) {
            arr.push(make_pair(getint32(), x == m));
            counts[arr.back().first]++;
        }
        int32_t steps = 0;
        while(len(arr)) {
            loop(z, arr.front().first + 1, 10)
                if (counts[z])
                    goto ahead;
            steps++;
            counts[arr.front().first]--;
            if (arr.front().second)
                goto presult;
            arr.pop();
            continue;
            ahead:
            arr.push(arr.front());
            arr.pop();
        }
        presult:
                print(steps);
    }
    return 0;
}
