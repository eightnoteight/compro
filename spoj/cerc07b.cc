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
#define uint                                        uint32_t
#define int                                         int32_t
#define ulong                                       uint64_t
#define long                                        int64_t
using namespace std;

void inverse(uint** mat, uint n) {

}

void solveSysEq(uint** A, uint* D, uint* X, uint n) {
    inverse(A, n);
    for (int x = 0; x < n; ++x)
        for (int y = 0; y < n; ++y)
            X[x] = A[x][y] * D[y];
}

int main() {
    #ifndef __lucy__
        ios::sync_with_stdio(0);cin.tie(0);
    #endif
    uint r, c;
    char tmp[100];
    cin >> r >> c;
    while (r && c) {
        uint genmatrix[r*c][r][c];
        for (int x = 0; x < r*c; ++x)
            for (int i = 0; i < r; ++i)
                for (int j = 0; j < c; ++j)
                    genmatrix[x][i][j] = 0;
        for (int x = 0; x < r; ++x)
            for (int y = 0; y < c; ++y)
                for (int i = 0; i < r; ++i)
                    for (int j = 0; j < c; ++j)
                        genmatrix[x*c + y][i][j] += (abs(x - i) + abs(y - j) <= 1);
        uint amatrix[r*c][r*c];
        for (int y = 0; y < r; ++y)
            for (int z = 0; z < c; ++z)
                for (int x = 0; x < r*c; ++x)
                    amatrix[x][y*c + z] = genmatrix[x][y][z];
        uint dmat[r*c];
        for (int x = 0; x < r; ++x) {
            cin >> tmp;
            for (int y = 0; y < c; ++y)
                dmat[x*c + y] = 1*(tmp[y] == 'X')
        }
        uint xmat[r*c];
        try {
            solveSysEq(amatrix, dmat, xmat, r*c);
            cout << count(xmat, xmat + r*c, 1) << endl;
        }
        catch (uint _) {
            cout << "Damaged billboard." << endl;
        }

        cin >> r >> c;
    }
    return 0;
}

