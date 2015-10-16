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
size_t m;

template<typename DT, size_t RWS, size_t CLS, unsigned long long int MOD>
struct matrix {
    array<array<DT, CLS>, RWS> core;
    matrix() {
        for(auto& x: core)
            for(auto& y: x)
                y = DT();
    }
    matrix(initializer_list<initializer_list<DT> > m) {
        size_t i = 0, j = 0;
        for (auto& x: m) {
            j = 0;
            for (auto& y: x) {
                core.at(i).at(j++) = y;
                // throws ➡ std::out_of_range for bad initializer_list's
            }
            i++;
        }
    }
    matrix<DT, RWS, CLS, MOD> operator+(const matrix<DT, RWS, CLS, MOD>& other) {
        matrix<DT, RWS, CLS, MOD> res;
        for (size_t x = 0; x < RWS; ++x)
            for (size_t y = 0; y < CLS; ++y)
                res.core[x][y] = (core[x][y] + other.core[x][y]) % m;
        return res;
    }
    matrix<DT, RWS, CLS, MOD> operator-(const matrix<DT, RWS, CLS, MOD>& other) {
        matrix<DT, RWS, CLS, MOD> res;
        for (size_t x = 0; x < RWS; ++x)
            for (size_t y = 0; y < CLS; ++y)
                res.core[x][y] = (core[x][y] - other.core[x][y]) % m;
        return res;
    }
    void operator+=(const matrix<DT, RWS, CLS, MOD>& other) {
        for (size_t x = 0; x < RWS; ++x)
            for (size_t y = 0; y < CLS; ++y)
                core[x][y] = (core[x][y] + other.core[x][y]) % m;
    }
    void operator-=(const matrix<DT, RWS, CLS, MOD>& other) {
        for (size_t x = 0; x < RWS; ++x)
            for (size_t y = 0; y < CLS; ++y)
                core[x][y] = (core[x][y] - other.core[x][y]) % m;
    }
    template<size_t CLS2>
    matrix<DT, RWS, CLS2, MOD> operator*(const matrix<DT, CLS, CLS2, MOD>& other) {
        matrix<DT, RWS, CLS2, MOD> res;
        for (size_t x = 0; x < RWS; ++x)
            for (size_t y = 0; y < CLS2; ++y)
                for (size_t z = 0; z < CLS; ++z)
                    res.core[x][y] = (res.core[x][y] + core[x][z]*other.core[z][y]) % m;
        return res;
    }
    template<size_t CLS2>
    void operator*=(const matrix<DT, CLS, CLS2, MOD>& other) {
        matrix<DT, RWS, CLS2, MOD> res;
        for (size_t x = 0; x < RWS; ++x)
            for (size_t y = 0; y < CLS2; ++y)
                for (size_t z = 0; z < CLS; ++z)
                    res.core[x][y] = (res.core[x][y] + core[x][z]*other.core[z][y]) % m;
        *this = res;
    }
    matrix<DT, RWS, CLS, MOD>& operator=(const matrix<DT, RWS, CLS, MOD> m) {
        for (size_t x = 0; x < RWS; ++x)
            for (size_t y = 0; y < CLS; ++y)
                core[x][y] = m.core[x][y];
        return *this;
    }
    matrix<int64_t, RWS, CLS, MOD> genIdentity() {
        matrix<int64_t, RWS, CLS, MOD> identity;
        for (size_t i = 0; i < RWS; ++i)
            for (size_t j = 0; j < CLS; ++j)
                identity.core[i][j] = (i == j);
        return move(identity);
    }
    matrix<int64_t, RWS, CLS, MOD> pow(size_t a) {
        if (RWS != CLS)
            throw invalid_argument("RWS should be equal to CLS");
        matrix<int64_t, RWS, RWS, MOD> y = genIdentity();
        auto x = *this;
        while(a) {
            if (a & 1)
                y *= x;
            x *= x;
            a >>= 1;
        }
        return y;
    }
};


int main() {
    ios::sync_with_stdio(0);cin.tie(0);
    cin >> testcases;
    for (int test = 1; test <= testcases; ++test) {
        size_t n;
        cin >> n >> m;
        matrix<int64_t, 4, 1, 1000000009> mm0 = {
            {1},
            {0},
            {1},
            {1}
        };
        matrix<int64_t, 4, 4, 1000000009> imat = {
            {1, 1, 0, 1},
            {1, 0, 0, 0},
            {0, 0, 1, 0},
            {0, 0, 1, 1}
        };
        if (n > 0) {
            matrix<int64_t, 4, 1, 1000000009> result = imat.pow(n - 1)*mm0;
            cout << result.core[0][0] << endl;
        }
        else {
            cout << '0' << endl;
        }
    }
    return 0;
}
