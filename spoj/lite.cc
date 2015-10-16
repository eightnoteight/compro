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
    template<class T, long unsigned int N>
    inline IO& operator << (array<T, N>& d) {
        (*this) << "[";
        for (size_t i = 0; i < N; ++i)
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

class lite {
private:
    int n, qi, qj;
    int _query(int i, int j, int idx, int proc) {
        tree[idx][1] = (tree[idx][1] + proc) % 2;
        if (proc)
            tree[idx][0] = j - i - tree[idx][0];
        if (qj <= i || qi >= j)
            return 0;
        if (qi <= i && j <= qj)
            return tree[idx][0];
        int mid = i + ((j - i) / 2);
        int result = _query(i, mid, 2*idx + 1, tree[idx][1]) + _query(mid, j, 2*idx + 2, tree[idx][1]);
        tree[idx][1] = 0;
        tree[idx][0] = tree[2*idx + 1][0] + tree[2*idx + 2][0];
        return result;
    }
    int _toggle(int i, int j, int idx, int proc) {
        tree[idx][1] = (tree[idx][1] + proc) % 2;
        if (proc)
            tree[idx][0] = j - i - tree[idx][0];
        if (qj <= i || qi >= j)
            return tree[idx][0];
        if (qi <= i && j <= qj) {
            tree[idx][0] = j - i - tree[idx][0];
            tree[idx][1] = (tree[idx][1] + 1) % 2;
            return tree[idx][0];
        }
        int mid = i + ((j - i) / 2);
        tree[idx][0] = _toggle(i, mid, 2*idx + 1, tree[idx][1]) +
            _toggle(mid, j, 2*idx + 2, tree[idx][1]);
        tree[idx][1] = 0;
        return tree[idx][0];
    }
    int _tree_size(int n) {
        int i = 1;
        while (i < n)
            i <<= 1;
        return 2*i - 1;
    }
public:
    vector<array<int, 2> > tree;
    lite(int n) {
        this->n = n;
        tree.resize(_tree_size(n));
        for (array<int, 2>& x: tree)
            x[0] = x[1] = 0;
    }
    inline int query(int qi, int qj) {
        this->qi = qi;
        this->qj = qj;
        return _query(0, n, 0, 0);
    }
    inline void toggle(int qi, int qj) {
        this->qi = qi;
        this->qj = qj;
        _toggle(0, n, 0, 0);
    }
};

int main() {
    int n, m;
    cin >> n >> m;
    lite tree(n);
    for (int q = 0; q < m; ++q) {
        int op, si, ei;
        cin >> op >> si >> ei;
        if (op)
            cout << tree.query(si - 1, ei) << endl;
        else
            tree.toggle(si - 1, ei);
    }
    return 0;
}
