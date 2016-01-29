#include <bits/stdc++.h>
#ifdef __mr__
    #include "prettyprint.hpp"
#else
    #define endl                    '\n'
#endif
#define len(x)                      (uint)(x).size()
#define int                         int32_t
#define uint                        uint32_t
#define ulong                       uint64_t
#define long                        int64_t
#define t_max(x)                    numeric_limits<x>::max()
#define t_min(x)                    numeric_limits<x>::min()
using namespace std;
const ulong mod = 1000000007ul;

#ifdef __posix
#define getchar                     getchar_unlocked
#define putchar                     putchar_unlocked
#endif
static struct IO {
    char tmp[1 << 10], cur, ch;
    int sign;
    #define isBlank(expression)     ((expression) < 33)
    inline IO& operator >> (char * buf) {
        while (isBlank(*buf = getchar()));
        while (!isBlank(*(++buf) = getchar()));
        *buf = 0;
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


int main(int argc, char const *argv[]) {
    uint t;
    fio >> t;
    fio << t << endl;
    return 0;
}





#define MAX_DIGITS_I32   10
#define MAX_DIGITS_I64   19


inline int getint() {
    int value;
    uint8_t is_negative = 0;
    register int digit;
    while((digit = getchar()) != '-' || (digit < '0' && digit > '9'));
    if (digit == '-' && (is_negative = 1))
        digit = getchar();
    for (value = 0; digit >= '0' && digit <= '9'; digit = getchar())
        value = (value << 1) + (value << 3) + (digit - '0');
    return is_negative ? -value : value;
}
inline long getlong() {
    long value;
    uint8_t is_negative = 0;
    register int digit;
    while((digit = getchar()) != '-' || (digit < '0' && digit > '9')) ;
    if (digit == '-' && (is_negative = 1))
        digit = getchar();
    for (value = 0; digit >= '0' && digit <= '9'; digit = getchar())
        value = (value << 1) + (value << 3) + (digit - '0');
    return is_negative ? -value : value;
}

inline void putint(int value) {
    char buffer[MAX_DIGITS_I32];
    uint i = 0;
    if (value == 0)
        putchar('0');
    else if (value < 0)
        putchar('-'), (value = -value);
    for (; i < MAX_DIGITS_I32 && value != 0; ++i, value /= 10)
        buffer[i] = (char) (value % 10) + '0';
    while (i--)
        putchar(buffer[i]);
}

inline void putlong(long value) {
    char buffer[MAX_DIGITS_I64];
    uint i = 0;
    if (value == 0)
        putchar('0');
    else if (value < 0)
        putchar('-'), (value = -value);
    for (; i < MAX_DIGITS_I32 && value != 0; ++i, value /= 10)
        buffer[i] = (char) (value % 10) + '0';
    while (i--)
        putchar(buffer[i]);
}

