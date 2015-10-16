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

int main() {
    cin >> testcases;
    for (int test = 1; test <= testcases; ++test) {
        int32_t n, k;
        cin >> n >> k;
        vector<int32_t> arr(n);
        vector<array<int32_t, 32> > nums(3*n + 1);
        nums[0] = {
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
        };
        for (int x = 0; x < n; ++x)
            cin >> arr[x];
        for (int32_t x = 1; x <= 3*n; ++x)
            for (int32_t y = 0, tmp = arr[(x - 1) % n];  y < 32;  ++y, tmp /= 2)
                nums[x][y] = nums[x - 1][y] + (tmp % 2);
        for (int x = 0; x < n; ++x) {
            bitset<32> tnums;
            for (short y = 0; y < 32; ++y) {
                if (2*k + 1 >= n)
                    tnums[y] = (nums[n][y] == n);
                else
                    tnums[y] = (nums[n + x + k + 1][y] - nums[n + x - k][y] == 2*k + 1);
            }
            cout << tnums.to_ullong() << " \n"[x == n - 1];
        }
    }
    return 0;
}
