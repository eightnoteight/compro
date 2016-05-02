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
#define umap                        unordered_map


template<class Func>
int bsearch(int lo, int hi, Func check) {
    int mid;
    while(lo < hi) {
        mid = lo + ((hi - lo) / 2);
        if (check(mid))
            hi = mid;
        else
            lo = mid + 1;
    }
    return lo;
}

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
#define cin                         __io__
#define cout                        __io__
} __io__;


int main(int argc, char const *argv[]) {
    int n;
    cout >> n;
    vector<array<int, 2>> segments(n);
    for (int i = 0; i < n; ++i)
        cout >> segments[i][0] >> segments[i][1];
    set<int> nums;
    for (auto x: segments)
        nums.insert(x[0]), nums.insert(x[1]);
    umap<int, int> nummap;
    for (int i = 0; i < nums.size(); ++i) {
        static auto it = nums.begin();
        nummap[*(it++)] = i;
    }
    // cout << nums << endl;
    // cout << nummap << endl;
    for (int i = 0; i < n; ++i) {
        segments[i][0] = nummap[segments[i][0]];
        segments[i][1] = nummap[segments[i][1]];
    }
    vector<array<int, 2>> order(segments.begin(), segments.end());
    sort(segments.begin(), segments.end());
    vector<int> sqends(n);
    for (int i = 0; i < n; ++i) {
        sqends[i] = segments[i][1];
    }
    int sqn = sqrt(segments.size());
    for (int i = 0, j = sqn; i < n; i += sqn, j += sqn) {
        sort(sqends.begin() + i,
             sqends.begin() + min(j, n));
    }
    // cout << segments << endl;
    // cout << "hh" << endl << flush;
    for (int i = 0; i < n; ++i) {
        int a = order[i][0];
        int b = order[i][1];
        int ss = bsearch(0, n, [&segments, &a](int x) -> bool {
            return segments[x][0] >= a;
        });
        int es = bsearch(0, n, [&segments, &b](int x) -> bool {
            return segments[x][0] >= b;
        });
        int count = 0;
        if (es - ss <= 2 * sqn) {
            // cout << ss << " " << es << endl << flush;
            for (int i = ss; i < es; ++i)
                if (a <= segments[i][1] && segments[i][1] < b)
                    count++;
        }
        else {
            int ss_e = ((ss / sqn) + 1) * sqn;
            for (int i = ss; i < ss_e; ++i)
                if (a <= segments[i][1] && segments[i][1] < b)
                    count++;
            int es_s = (es / sqn) * sqn;
            for (int i = es_s; i < es; ++i)
                if (a <= segments[i][1] && segments[i][1] < b)
                    count++;
            for (int i = ss_e; i < es_s; i += sqn) {
                count += bsearch(0, sqn, [&sqends, &b, &i](int x) -> bool {
                        return sqends[i + x] >= b;
                    }) - bsearch(0, sqn, [&sqends, &a, &i](int x) -> bool {
                        return sqends[i + x] >= a;
                    });
            }
        }
        // cout << ss << es << count << endl;
        cout << count << '\n';
    }
    return 0;
}

