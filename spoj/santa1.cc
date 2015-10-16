#include <bits/stdc++.h>
using namespace std;
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

int main() {
    int32_t q;
    map<string, pair<int32_t, int32_t> > np;
    map<pair<int32_t, int32_t>, string> pn;
    int64_t productivity = 0;
    cin >> q;
    while(q--) {
        char op;
        string name;
        pair<int32_t, int32_t> val;
        cin >> op >> name;
        if (op == 'A') {
            cin >> val;
            np[name] = val;
            pair<map<pair<int32_t, int32_t>, string>::iterator, bool> status = pn.insert(make_pair(val, name));
            map<pair<int32_t, int32_t>, string>::iterator it = status.first;
            if (pn.size() <= 1) {
                productivity = 0;
            }
            else if (it == pn.begin()) {
                int64_t extra = it->first.second; it++;
                extra *= it->first.second;
                productivity += extra;
            }
            else if (it == --pn.end()) {
                int64_t extra = it->first.second; it--;
                extra *= it->first.second;
                productivity += extra;
            }
            else {
                int64_t left = it->first.second;
                int64_t right = it->first.second;
                it--;
                int64_t prev = it->first.second;
                left *= it->first.second;
                it++; it++;
                prev *= it->first.second;
                right *= it->first.second;
                productivity += left + right - prev;
            }
        }
        else {
            val = np[name];
            np.erase(name);
            map<pair<int32_t, int32_t>, string>::iterator it = pn.find(val);
            if(it != pn.end()) {
                if (pn.size() <= 2) {
                    productivity = 0;
                    pn.erase(it);
                }
                else if (it == pn.begin()) {
                    int64_t rem = it->first.second;
                    it++;
                    productivity -= rem * (it->first.second);
                    it--;
                    pn.erase(it);
                }
                else if (it == --pn.end()) {
                    int64_t rem = it->first.second;
                    it--;
                    productivity -= rem * (it->first.second);
                    it++;
                    pn.erase(it);
                }
                else {
                    int64_t left = it->first.second;
                    int64_t right = it->first.second;
                    it--;
                    left *= it->first.second;
                    int64_t nmid = it->first.second;
                    it++; it++;
                    right *= it->first.second;
                    nmid *= it->first.second;
                    it--;
                    pn.erase(it);
                    productivity -= left + right - nmid;
                }
            }
        }
        cout << productivity << endl;
    }
    return 0;
}
