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
#define loop_1(end)                                 for (size_t __i = 1; __i <= (end); __i++)
#define loop_2(var, end)                            for (size_t var = 0; var < (end); var++)
#define loop_3(var, start, end)                     for (size_t var = (start); var < (end); var++)
#define loop_4(var, start, end, step)               for (int32_t var = (start); (step) > 0 ? var < (end) : var > (end); var += (step))
#define loop_x(arg1, arg2, arg3, arg4, arg5, ...)   arg5
#define loop_choose(...)                            loop_x(__VA_ARGS__, loop_4, loop_3, loop_2, loop_1)
#define loop(...)                                   loop_choose(__VA_ARGS__)(__VA_ARGS__)
#define len(x)                                      (x.size())
#define esort(x)                                    (sort(x.begin(), x.end()))
#define ersort(x)                                   (sort(x.rbegin(), x.rend()))
using namespace std;
size_t testcases;

int main() {
    #ifndef __lucy__
        ios::sync_with_stdio(0);cin.tie(0);
    #endif
    cin >> testcases;
    loop (test, 1, testcases + 1) {
        int64_t n, k;
        cin >> n >> k;
        if (bitcounti64(k - 1) % 2)
            cout << "Female" << endl;
        else
            cout << "Male" << endl;
    }
    return 0;
}
