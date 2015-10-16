#include <bits/stdc++.h>
using namespace std;
static int agnes[2002];
static int tom[2002];

int32_t testcases;

static struct IO {
    char tmp[1 << 10];
    char cur;
    inline char nextChar() {
        return cur = getc_unlocked(stdin);
    }
    inline char peekChar() {
        return cur;
    }
    inline operator bool() {
        return peekChar();
    }
    inline static bool isBlank(char c) {
        return (c < '-' && c > 0);
    }
    inline bool skipBlanks() {
        while (isBlank(nextChar()));
        return peekChar() > 0;
    }
    inline IO& operator >> (char & c) {
        c = nextChar();
        return *this;
    }
    inline IO& operator >> (char * buf) {
        if (skipBlanks()) {
            if (peekChar()) {
                *(buf++) = peekChar();
                while (!isBlank(nextChar()))
                    *(buf++) = peekChar();
            }
            *(buf++) = 0;
        }
        return *this;
    }
    inline IO& operator >> (string & s) {
        if (skipBlanks()) {
            s.clear();
            s += peekChar();
            while (!isBlank(nextChar()))
                s += peekChar();
        }
        return *this;
    }
    inline IO& operator >> (double & d) {
        if ((*this) >> tmp)
            sscanf(tmp, "%lf", &d);
        return *this;
    }
    #define defineInFor(intType) \
        inline IO& operator >>(intType & n) { \
            if (skipBlanks()) { \
                int sign = +1; \
                if (peekChar() == '-') { \
                    sign = -1; \
                    n = nextChar() - '0'; \
                } else \
                    n = peekChar() - '0'; \
                while (!isBlank(nextChar())) { \
                    n += n + (n << 3) + peekChar() - 48; \
                } \
                n *= sign; \
            } \
            return *this; \
        }
    defineInFor(int32_t)
    defineInFor(int64_t)
        inline void putChar(char c) {
            putc_unlocked(c, stdout);
        }
        inline IO& operator << (char c) {
            putChar(c);
            return *this;
        }
        inline IO& operator << (const char * s) {
            while (*s) putChar(*s++);
            return *this;
        }
        inline IO& operator << (const string & s) {
            for (int i = 0; i < (int)s.size(); ++i)
                putChar(s[i]);
            return *this;
        }
        char * toString(double d) {
            sprintf(tmp, "%lf%c", d, '\0');
            return tmp;
        }
        inline IO& operator << (double d) {
            return (*this) << toString(d);
        }
    #define defineOutFor(intType) \
        inline char * toString(intType n) { \
            char * p = (tmp + 30); \
            if (n) { \
                bool isNeg = 0; \
                if (n < 0) isNeg = 1, n = -n; \
                while (n) \
                    *--p = (n % 10) + '0', n /= 10; \
                if (isNeg) *--p = '-'; \
            } else *--p = '0'; \
            return p; \
        } \
        inline IO& operator << (intType n) { return (*this) << toString(n); }
    defineOutFor(int32_t)
    defineOutFor(int64_t)
    #define endl ('\n')
    #define cout __io__
    #define cin __io__

    // dict output
    template<class T, class U>
    inline IO& operator << (map<T, U>& p) {
        (*this) << "{";
        for (typename map<T, U>::iterator it = p.begin(); it != p.end(); it++) {
            (*this) << it->first << ": " << it->second << ", ";
        }
        (*this) << "}";
        return *this;
    }

    // pair input
    template<class T, class U>
    inline IO& operator >> (pair<T, U>& p) {
        (*this) >> p.first >> p.second;
        return *this;
    }
    // pair output
    template<class T, class U>
    inline IO& operator << (pair<T, U>& p) {
        (*this) << '(' << p.first << ", " << p.second << ')';
        return *this;
    }
    // pair input
    template<class T, class U>
    inline IO& operator >> (const pair<T, U>& p) {
        (*this) >> p.first >> p.second;
        return *this;
    }
    // pair output
    template<class T, class U>
    inline IO& operator << (const pair<T, U>& p) {
        (*this) << '(' << p.first << ", " << p.second << ')';
        return *this;
    }
    // vector input
    template<class T>
    inline IO& operator >> (vector<T>& d) {
        for (size_t i = 0; i < d.size(); ++i)
            (*this) >> d[i];
        return *this;
    }
    // vector output
    template<class T>
    inline IO& operator << (vector<T>& d) {
        (*this) << "[";
        for (size_t i = 0; i < d.size(); ++i)
            (*this) << d[i] << ", ";
        (*this) << "]";
        return *this;
    }
} __io__;


int64_t powmod(int64_t x, int64_t a, int64_t mod) {
    int64_t y = 1;
    while(a) {
        if (a & 1)
            y = (y * x) % mod;
        x = (x * x) % mod;
        a >>= 1;
    }
    return y;
}

int64_t gcd(int64_t a, int64_t b) {
    int64_t tmp;
    while(b) {
        tmp = b;
        b = a % b;
        a = tmp;
    }
    return a;
}

template<class arrayType>
int longestCommonSubsequence(arrayType& arr1, arrayType& arr2, size_t n, size_t m) {
    int* lcs[2];
    lcs[0] = new int[m + 1](); lcs[1] = new int[m + 1]();
    for (size_t x = 1; x <= n; ++x) {
        lcs[0][0] = lcs[1][0] = 0;
        for (size_t y = 1; y <= m; ++y) {
            lcs[0][y] = max(lcs[1][y], lcs[0][y - 1]);
            if (arr1[x - 1] == arr2[y - 1] && lcs[0][y] < lcs[1][y - 1] + 1)
                lcs[0][y] = lcs[1][y - 1] + 1;
        }
        swap(lcs[0], lcs[1]);
    }
    int result = lcs[1][m];
    delete[] lcs[0]; delete[] lcs[1];
    return result;
}

int main() {
    cin >> testcases;
    for (int test = 1; test <= testcases; ++test) {
        int i = 0, ans = 0;
        int j = 0;
        do {
            cin >> agnes[i];
        } while(agnes[i++]);
        do {
            j = 0;
            do {
                cin >> tom[j];
            } while(tom[j++]);
            ans = max(ans, longestCommonSubsequence(agnes, tom, i - 1, j - 1));
        } while(j > 1);
        cout << ans << endl;
    }
    return 0;
}
