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
    ios::sync_with_stdio(0);cin.tie(0);
    array<int32_t, 1001> arr;
    array<int32_t, 1000001> sqrtarr;
    for (int x = 1000; x >= 0; --x) {
        arr[x] = 2*x - 1;
        sqrtarr[x*x] = x;
    }
    array<int32_t, 1001> xarr;
    partial_sum(arr.begin(), arr.end(), xarr.begin(), bit_xor<int32_t>());
    array<array<int32_t, 1001>, 11> nmat;
    for (int x = 0, z = 1; x < 11; x++, z <<= 1) {
        nmat[x][0] = bool(z & arr[0]);
        for (int y = 1; y < 1001; ++y) {
            nmat[x][y] = nmat[x][y - 1] + bool(z & arr[y]);
        }
    }
    int32_t n;
    cin >> n;
    for (int x = 0; x < n; ++x) {
        int32_t a, b;
        cin >> a >> b;
        bitset<11> result(xarr[sqrtarr[a]]^xarr[sqrtarr[b]]);
        for (short y = 0; y < 11; ++y) {
            result[y] = result[y] & (nmat[y][sqrtarr[b]] - nmat[y][sqrtarr[a]] == sqrtarr[b] - sqrtarr[a]);
        }
        cout << result.to_ullong() << endl;
    }
    return 0;
}
