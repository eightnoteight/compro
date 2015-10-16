#include <bits/stdc++.h>
using namespace std;
#define builtin_gcd __gcd
double exchanges[33][33];

static struct IO {
    char tmp[1 << 10];
    // fast input routines
    char cur;

    // #define nextChar() (cur = getc_unlocked(stdin))
    // #define peekChar() (cur)
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
        return (c < '-' && c);
    }
    inline bool skipBlanks() {
        while (isBlank(nextChar()));
        return peekChar() != 0;
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

    defineInFor(int)
    defineInFor(unsigned int)
    defineInFor(long long)

        // fast output routines

        //#define putChar(c) putc_unlocked((c), stdout)
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

    defineOutFor(int)
    defineOutFor(long long)

    #define endl ('\n')
    #define cout __io__
    #define cin __io__
} __io__;

bool detectArbitrag(int32_t n) {
    for (int32_t i = 0; i < n; ++i) {
        for (int32_t j = 0; j < n; ++j) {
            for (int32_t k = 0; k < n; ++k) {
                exchanges[i][j] = max(exchanges[i][j], exchanges[i][k]*exchanges[k][j]);
            }
        }
    }
    for (int i = 0; i < n; ++i) {
            if(exchanges[i][i] > 1.0)
                return true;
    }
    return false;
}

int main() {
    int32_t n;
    cin >> n;
    int32_t tc = 1;
    while(n) {
        map<string, int32_t> citydict;
        string city;
        for (int32_t i = 0; i < n; ++i){
            cin >> city;
            citydict[city] = i;
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                exchanges[i][j] = 0.0;
            }
        }
        int32_t m;
        cin >> m;
        for (int32_t i = 0; i < m; ++i) {
            string from, to;
            double rate;
            cin >> from >> rate >> to;
            exchanges[citydict[from]][citydict[to]] = rate;
        }
        cout << "Case " << tc << (detectArbitrag(n) ? (": Yes\n") : (": No\n"));


        cin >> n;
        tc++;
    }
    return 0;
}
