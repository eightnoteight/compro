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

template<class intType>
intType powmod(intType x, intType a, intType mod) {
    intType y = 1;
    while(a) {
        if (a & 1)
            y = (y * x) % mod;
        x = (x * x) % mod;
        a >>= 1;
    }
    return y;
}

template<class intType>
intType gcd(intType a, intType b) {
    intType tmp;
    while(b) {
        tmp = b;
        b = a % b;
        a = tmp;
    }
    return a;
}
void erathosthenes(int32_t n, vector<int32_t>& nums)
{
    int32_t* sieve = new int32_t[n];
    for (int i = 0; i < n; ++i)
        sieve[i] = i;
    for(int32_t x = 4; x < n; x += 2)
        sieve[x] = 0;
    for(int32_t x = 9; x < n; x += 6)
        sieve[x] = 0;
    int32_t csn = ceil((sqrt(n) + 1) / 6.0) + 1;
    for (int32_t x = 1; x < csn; x++) {
        if (sieve[6*x - 1]) {
            int32_t step = 12*x - 2;
            for(int32_t y = (6*x - 1)*(6*x - 1); y < n; y += step)
                sieve[y] = 0;
        }
        if (sieve[6*x + 1] == 0) {
            int32_t step = 12*x + 2;
            for(int32_t y = (6*x + 1)*(6*x + 1); y < n; y += step)
                sieve[y] = 0;
        }
    }
    for (int32_t x = csn; x >= 2; x--)
        if (sieve[x])
            for(int32_t y = x; y < n; y *= x)
                sieve[y] = y;
    for (int32_t x = 0; x < n; x++)
        if (sieve[x])
            nums.push_back(sieve[x]);
    delete[] sieve;
}

int main() {
    int32_t n, k, m = 1;
    cin >> n >> k;
    vector<array<int32_t, 4> > coprime4(n);
    vector<int32_t> nums;
    erathosthenes(3000003, nums);
    // cout << nums << endl;
    for (int xith = 0; xith < n; ++xith) {
        int32_t x1, x2, x3, x4;
        pop_heap(nums.begin(), nums.end(), greater<int32_t>()); x1 = nums[nums.size() - 1]; nums.pop_back();
        vector<int32_t> tmp;
        while(true) {
            pop_heap(nums.begin(), nums.end(), greater<int32_t>()); x2 = nums[nums.size() - 1]; nums.pop_back();
            if (gcd(x2, x1) == 1) {
                for (int32_t t: tmp) {
                    nums.push_back(t);
                    push_heap(nums.begin(), nums.end(), greater<int32_t>());
                }
                break;
            }
            tmp.push_back(x2);
        }
        tmp.clear();
        while(true) {
            pop_heap(nums.begin(), nums.end(), greater<int32_t>()); x3 = nums[nums.size() - 1]; nums.pop_back();
            if (gcd(x3, x1) == 1 and gcd(x3, x2) == 1) {
                for (int32_t t: tmp) {
                    nums.push_back(t);
                    push_heap(nums.begin(), nums.end(), greater<int32_t>());
                }
                break;
            }
            tmp.push_back(x3);
        }
        tmp.clear();
        while(true) {
            pop_heap(nums.begin(), nums.end(), greater<int32_t>()); x4 = nums[nums.size() - 1]; nums.pop_back();
            if (gcd(x4, x1) == 1 and gcd(x4, x2) == 1 and gcd(x4, x3) == 1) {
                for (int32_t t: tmp) {
                    nums.push_back(t);
                    push_heap(nums.begin(), nums.end(), greater<int32_t>());
                }
                break;
            }
            tmp.push_back(x4);
        }
        coprime4[xith][0] = k*x1; coprime4[xith][1] = k*x2; coprime4[xith][2] = k*x3; coprime4[xith][3] = k*x4;
        m = max(m, k*x1); m = max(m, k*x2); m = max(m, k*x3); m = max(m, k*x4);
    }
    cout << m << endl;
    for (int x = 0; x < n; ++x) {
        cout << coprime4[x][0] << ' ' << coprime4[x][1] << ' ' << coprime4[x][2] << ' ' << coprime4[x][3] << ' ' << endl;
    }
    return 0;
}
