#include <bits/stdc++.h>
#ifdef __mr__
    #include "prettyprint.hpp"
#else
    #define endl                                               '\n'
#endif
#define uint                                                    unsigned int
#define ulong                                                   unsigned long long
using namespace std;
const ulong mod = 1000000007ul;
vector<vector<DT>> tmpmu;

template<class DT>
struct MatrixMod {
    vector<vector<DT>> mat;
    uint rows, cols;
    MatrixMod(uint n, uint m) : rows(n), cols(m) {
        mat.resize(n);
        for (uint i = 0; i < n; ++i)
            mat[i].resize(m);
    }
    MatrixMod<DT> operator * (const MatrixMod<DT>& other) {
        assert(this->cols == other.rows);
        MatrixMod<DT> result(this->rows, other.cols);
        for (uint i = 0; i < result.rows; ++i)
            for (uint j = 0; j < result.cols; ++j)
                for (uint k = 0; k < this->cols; ++k)
                    result.mat[i][j] += (this->mat[i][k] * other.mat[k][j]) % mod;
        return result;
    }
    void operator *= (const MatrixMod<DT>& other) {
        assert(this->cols == other.rows);
        tmpmu.resize(this->rows);
        if (tmpmu[0].size() < other.cols)
            for (uint i = 0; i < this->rows; ++i)
                tmpmu[i].resize(other.cols)
        MatrixMod<DT> result(this->rows, other.cols);
        for (uint i = 0; i < result.rows; ++i)
            for (uint j = 0; j < result.cols; ++j)
                for (uint k = 0; k < this->cols; ++k)
                    result.mat[i][j] = (result.mat[i][j] + this->mat[i][k] * other.mat[k][j]) % mod;
    }
    MatrixMod<DT> pow(MatrixMod<DT>& mat, uint n) {

    }
};


int main(int argc, char const *argv[]) {
    MatrixMod
    return 0;
}
