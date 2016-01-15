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
#define len(x)                      ((int)((x).size()))
#define bitcounti32                 __builtin_popcount
#define bitcounti64                 __builtin_popcountll
using namespace std;

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

int testcases;
int indices[50005], ranks[50005], subranks[50005], newranks[50005], locations[50005], lcp[50005];
char subst1[50005];
int subst1_len;

int* getSuffixArray(char *str) {
    for (int x = 0; x < subst1_len; ++x)
        indices[x] = x;
    sort(indices, indices + subst1_len, [&str](int i, int j) {
        return str[i] < str[j];
    });
    ranks[0] = newranks[0] = 0;
    for (int x = 1; x < subst1_len; ++x)
        ranks[x] = ranks[x - 1] + (str[indices[x]] != str[indices[x - 1]]);
    for (int x = 1; x <= subst1_len; x <<= 1) {
        for (int y = 0; y < subst1_len; ++y)
            locations[indices[y]] = y;
        for (int y = 0; y < subst1_len; ++y)
            subranks[y] = (indices[y] + x < subst1_len) ? ranks[locations[indices[y] + x]] : -1;
        sort(indices, indices + subst1_len, [&ranks, &subranks, &locations](int i, int j) {
            if (ranks[locations[i]] != ranks[locations[j]])
                return ranks[locations[i]] < ranks[locations[j]];
            return subranks[locations[i]] < subranks[locations[j]];
        });
        for (int y = 1; y < subst1_len; ++y)
            newranks[y] = newranks[y - 1] + (
                ranks[locations[indices[y]]] != ranks[locations[indices[y - 1]]] ||
                subranks[locations[indices[y]]] != subranks[locations[indices[y - 1]]]);
        memcpy(ranks, newranks, subst1_len*sizeof(int));
    }
    return indices;
}

int* getLongestCommonPrefixArray(char *str, int *sufarr) {
    for (int x = 0; x < subst1_len; ++x)
        locations[sufarr[x]] = x;
    for (int x = 0, k = 0; x < subst1_len; ++x) {
        if (locations[x] + 1 < subst1_len) {
            for (int y = sufarr[locations[x] + 1];  str[x + k] == str[y + k]; )
                k++;
            lcp[locations[x]] = k;
            k ? k--: 0;
        }
    }
    memmove(lcp + 1, lcp, sizeof(int)*(subst1_len - 1));
    lcp[0] = 0;
    return lcp;
}


int main() {
    #ifndef __mr__
    #ifndef FASTIO_CODE
        ios::sync_with_stdio(0);cin.tie(0);
    #endif
    #endif

    fio >> testcases;
    for (int test = 1; test <= testcases; ++test) {
        fio >> subst1;
        subst1_len = fio.buflen;
        int *sufarr = getSuffixArray(subst1);
        int *lcparr = getLongestCommonPrefixArray(subst1, sufarr);
        int distinct = 0;
        for (int x = 0; x < subst1_len; ++x) {
            distinct += subst1_len - sufarr[x] - lcparr[x];
        }
        fio << distinct << endl;
    }
    return 0;
}
