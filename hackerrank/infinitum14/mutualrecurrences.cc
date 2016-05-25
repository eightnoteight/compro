#include <bits/stdc++.h>
#ifdef __mr__
    #include "prettyprint.hpp"
#endif
#define endl                    '\n'
#define len(x)                      (uint)(x).size()
#define int                         int32_t
#define uint                        uint32_t
#define ulong                       uint64_t
#define long                        int64_t
#define t_max(x)                    numeric_limits<x>::max()
#define t_min(x)                    numeric_limits<x>::min()
using namespace std;
const ulong mod = 1000000000ull;

#ifndef FASTIO_CODE
#ifdef __posix
#define getchar  getchar_unlocked
#define putchar  putchar_unlocked
#endif
static struct IO {
    char tmp[1 << 10], cur, ch;
    int sign, buflen;
    #define isBlank(expression)     ((expression) < 33)
    inline IO& operator >> (char * buf) {
        char* tmpbuf = buf;
        while (isBlank(*buf = getchar()));
        while (!isBlank(*(++buf) = getchar())) ;
        *buf = 0;
        buflen = buf - tmpbuf;
        return *this;
    }
    inline IO& operator >> (string & s) {
        while (isBlank(ch = getchar()));
        do {
            s += ch;
        } while (!isBlank(ch = getchar()));
        return *this;
    }
    inline IO& operator >> (double & d) {
        sscanf(tmp, "%lf", &d);
        return *this;
    }
    #define defineInFor(intType) \
        inline IO& operator >>(intType& n) { \
            n = 0; \
            while (isBlank(ch = getchar())); \
            sign = +1; \
            if (ch == '-') \
                sign = -1, ch = getchar(); \
            do { \
                n += n + (n << 3) + ch - '0'; \
            } while(!isBlank(ch = getchar())); \
            n *= sign; \
            return *this; \
        }

    defineInFor(int)
    defineInFor(uint)
    defineInFor(long)
    defineInFor(ulong)

    // fast output routines
    inline IO& operator << (char c) {
        putchar(c);
        return *this;
    }
    inline IO& operator << (const char * s) {
        while (*s)
            putchar(*s++);
        return *this;
    }
    inline IO& operator << (const string & s) {
        for (int i = 0; i < (int)s.size(); ++i)
            putchar(s[i]);
        return *this;
    }
    inline IO& operator << (double d) {
        sprintf(tmp, "%lf%c", d, '\0');
        return (*this) << tmp;
    }

    #define defineOutFor(intType) \
        inline char * toString(intType n) { \
            char * p = (tmp + 30); \
            *p = 0; \
            if (n) { \
                bool isNeg = 0; \
                if (n < 0) \
                    isNeg = 1, n = -n; \
                while (n) \
                    *--p = (n % 10) + '0', n /= 10; \
                if (isNeg) \
                    *--p = '-'; \
            } \
            else { \
                *--p = '0'; \
            } \
            return p; \
        } \
        inline IO& operator << (intType n) { \
            return (*this) << toString(n); \
        }

    defineOutFor(int)
    defineOutFor(uint)
    defineOutFor(long)
    defineOutFor(ulong)

#define fio                         __io__
} __io__;

#endif


ulong** matmul(ulong** mat1, ulong** mat2, uint r1, uint c1, uint r2, uint c2) {
    ulong** mat3 = new ulong*[r1];
    assert(c1 == r2);
    for (uint i = 0; i < r1; ++i) {
        mat3[i] = new ulong[c2];
        mat3[i] = (ulong*)memset(mat3[i], 0, c2*sizeof(ulong));
    }
    for (uint x = 0; x < r1; ++x)
        for (uint y = 0; y < c2; ++y)
            for (uint z = 0; z < c1; ++z)
                mat3[x][y] = (mat3[x][y] +  ((mat1[x][z] * mat2[z][y]) % mod)) % mod;
    return mat3;
}

ulong mypow(ulong b, ulong e) {
    ulong y = 1;
    while(e) {
        if (e & 1)
            y = (y * b) % mod;
        b = (b * b) % mod;
        e >>= 1;
    }
    return y;
}

ulong** powmat(ulong** matrix, ulong e) {
    ulong** result = new ulong*[24];
    for (uint i = 0; i < 24; ++i) {
        result[i] = new ulong[24];
        result[i] = (ulong*)memset(result[i], 0, 24*sizeof(ulong));
        result[i][i] = 1;
    }

    while(e) {
        if (e & 1)
            result = matmul(result, matrix, 24, 24, 24, 24);
        matrix = matmul(matrix, matrix, 24, 24, 24, 24);
        e >>= 1;
    }
    return result;
}


int main(int argc, char const *argv[]) {
    #ifndef __mr__
    #ifndef FASTIO_CODE
        ios::sync_with_stdio(0);cin.tie(0);
    #endif
    #endif
    uint testcases;
    fio >> testcases;
    while (testcases--) {
        ulong a, b, c, d, e, f, g, h, n;
        fio >> a >> b >> c >> d >> e >> f >> g >> h >> n;
        ulong** matrix = new ulong*[24];
        for (uint i = 0; i < 24; ++i) {
            matrix[i] = new ulong[24];
            matrix[i] = (ulong*)memset(matrix[i], 0, 24*sizeof(ulong));
        }
        matrix[0][a - 1] += 1;
        matrix[0][10 + b - 1] += 1;
        matrix[0][10 + c - 1] += 1;
        matrix[10][10 + e - 1] += 1;
        matrix[10][f - 1] += 1;
        matrix[10][g - 1] += 1;
        matrix[1][0] += 1;
        matrix[2][1] += 1;
        matrix[3][2] += 1;
        matrix[4][3] += 1;
        matrix[5][4] += 1;
        matrix[6][5] += 1;
        matrix[7][6] += 1;
        matrix[8][7] += 1;
        matrix[9][8] += 1;
        matrix[11][10] += 1;
        matrix[12][11] += 1;
        matrix[13][12] += 1;
        matrix[14][13] += 1;
        matrix[15][14] += 1;
        matrix[16][15] += 1;
        matrix[17][16] += 1;
        matrix[18][17] += 1;
        matrix[19][18] += 1;
        matrix[0][20] = matrix[0][21] = matrix[20][20] = matrix[20][21] = \
            matrix[21][21] = d;
        matrix[10][22] = matrix[10][23] = matrix[22][22] = matrix[22][23] = \
            matrix[23][23] = h;
        ulong* alpha = new ulong[11];
        ulong* beta = new ulong[11];
        for (uint x = 0; x < 11; ++x) {
            alpha[x] = 0;
            alpha[x] += (x < a) ? ((ulong)1) : alpha[x - a];
            alpha[x] += (x < b) ? ((ulong)1) : beta[x - b];
            alpha[x] += (x < c) ? ((ulong)1) : beta[x - c];
            alpha[x] += x*mypow(d, x);
            beta[x] = 0;
            beta[x] += (x < e) ? ((ulong)1) : beta[x - e];
            beta[x] += (x < f) ? ((ulong)1) : alpha[x - f];
            beta[x] += (x < g) ? ((ulong)1) : alpha[x - g];
            beta[x] += x*mypow(h, x);
            alpha[x] %= mod;
            beta[x] %= mod;
        }
        ulong** colmat = new ulong*[24];
        for (uint i = 0; i < 24; ++i) {
            colmat[i] = new ulong[1];
            if (i < 10)
                colmat[i][0] = alpha[10 - i];
            else if (i < 20)
                colmat[i][0] = beta[20 - i];
        }
        colmat[20][0] = ((ulong)10)*mypow(d, 10);
        colmat[21][0] = mypow(d, 10);
        colmat[22][0] = ((ulong)10)*mypow(h, 10);
        colmat[23][0] = mypow(h, 10);
        if (n <= 10) {
            fio << (alpha[n] % mod) << ' ' << (beta[n] % mod) << endl;
        }
        else {
            ulong** resmat = matmul(powmat(matrix, n - 10), colmat, 24, 24, 24, 1);
            fio << (resmat[0][0] % mod) << ' ' << (resmat[10][0] % mod) << endl;
        }
    }
    return 0;
}
