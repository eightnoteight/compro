#include <bits/stdc++.h>
#ifdef __mr__
    #include "prettyprint.hpp"
#else
    #define endl                                               '\n'
#endif
#define len(x)                                                  (uint)(x).size()
#define int                                                     int32_t
#define uint                                                    uint32_t
#define ulong                                                   uint64_t
#define long                                                    int64_t
using namespace std;
const ulong mod = 1000000007ul;

int main(int argc, char const *argv[]) {
    #ifndef __mr__
        ios::sync_with_stdio(0);cin.tie(0);
    #endif
    int h, w;
    cin >> h >> w;
    char grid[h][w + 1];
    for (uint i = 0; i < h; ++i)
        cin >> grid[i];
    int hor[h][w];
    for (uint i = 0; i < h; ++i) {
        hor[i][0] = (grid[i][0] == '.' && grid[i][1] == '.') ? 1 : 0;
        for (uint j = 1; j < w - 1; ++j)
            hor[i][j] = ((grid[i][j] == '.' && grid[i][j + 1] == '.') ? 1 : 0) + hor[i][j - 1];
        if (w > 1)
            hor[i][w - 1] = hor[i][w - 2];
    }
    int ver[h][w];
    for (uint i = 0; i < h - 1; ++i) {
        ver[i][0] = (grid[i][0] == '.' && grid[i + 1][0] == '.') ? 1 : 0;
        for (uint j = 1; j < w; ++j) {
            ver[i][j] = ((grid[i][j] == '.' && grid[i + 1][j] == '.') ? 1 : 0) + ver[i][j - 1];
        }
    }
    for (uint j = 0; j < w; ++j) {
        ver[h - 1][j] = 0;
    }
    for (uint j = 0; j < w; ++j) {
        for (uint i = 1; i < h; ++i) {
            hor[i][j] += hor[i - 1][j];
        }
    }
    for (uint j = 0; j < w; ++j) {
        for (uint i = 1; i < h; ++i) {
            ver[i][j] += ver[i - 1][j];
        }
    }
    int q;
    cin >> q;
    for (uint k = 0; k < q; ++k) {
        int r1, r2, c1, c2;
        cin >> r1 >> c1 >> r2 >> c2;
        r1--; c1--; r2--; c2--;
        uint count = ver[r2][c2] + hor[r2][c2];
        if (r1 != 0 && c1 != 0)
            count += ver[r1 - 1][c1 - 1];
        if (r1 != 0)
            count -= ver[r1 - 1][c2] + hor[r1 - 1][c2];
        if (r2 != 0)
            count -= ver[r2][c1 - 1] + hor[r2][c1 - 1];
        for (uint i = r1; i <= r2; ++i) {
            if (c1 == 0) {
                if (c2 != 0)
                    count += hor[i][c2 - 1];
                if (i != r2)
                    count += ver[i][c2];
            }
            else {
                if (c2 != 0)
                    count += hor[i][c2 - 1] - hor[i][c1 - 1];
                if (i != r2)
                    count += ver[i][c2] - ver[i][c1 - 1];
            }
        }
        cout << count << endl;
    }
    return 0;
}
