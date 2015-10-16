#include <bits/stdc++.h>
#ifdef __lucy__
    #include "prettyprint.hpp"
#endif
#define endl                                        ('\n')
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

using namespace std;



int main() {
    #ifndef __lucy__
        ios::sync_with_stdio(0);cin.tie(0);
    #endif
    int32_t r, c;
    char maze[r][c + 1];
    cin >> r >> c;
    loop(x, r)
        cin >> maze[x];

    // finding Jerry and Tom
    int32_t jerry = 0, tom = 0; // not yet found
    loop(x, r) {
        if (jerry && strchr(maze[x], 'J') != NULL)
            jerry = strchr(maze[x], 'J') - maze[x];
        if (tom && strchr(maze[x], 'T') != NULL)
            tom = strchr(maze[x], 'T') - maze[x];
    }
    loop(x, 1, r*c + 1) {
        // can jerry get out with x seconds i.e jerry bfs depth=x; and tom bfs depth=x;
        // if jerry's bfs has completely covered by tom's bfs then tom just caught jerry; BREAK
        // else check if there is an exit position in the jerry's bfs; BREAK
        // else continue the loop
    }
    return 0;
}
