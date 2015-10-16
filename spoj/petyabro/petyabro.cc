#include <bits/stdc++.h>
#ifdef __lucy__
    #include "prettyprint.hpp"
#endif
#define endl                                        ('\n')
#define i32max                                      (0x7fffffff)
#define i32min                                      (-0x7fffffff-1)
#define i64max                                      (0x7fffffffffffffff)
#define i64min                                      (-0x7fffffffffffffff-1)
#define ui32max                                     (0xffffffffu)
#define ui64max                                     (0xffffffffffffffffu)
#define bitcounti32                                 __builtin_popcount
#define bitcounti64                                 __builtin_popcountll
#define len(x)                                      ((uint64_t)(x).size())
#define esort(x)                                    (sort((x).begin(), (x).end()))
#define ersort(x)                                   (sort((x).rbegin(), (x).rend()))
#define name(x)                                     (#x)
using namespace std;

static struct IO {
    char tmp[50];
    inline static bool isBlank(char c) {
        return (c < '-' && c > 0);
    }
    inline IO& operator >> (char & c) {
        while(isBlank(c = getchar_unlocked()));
        return *this;
    }
    #define defineInFor(intType) \
        inline IO& operator >>(intType & n) { \
            char c = getchar_unlocked(); \
            while (c < 33) \
                c = getchar_unlocked(); \
            n = 0; \
            while (c > 33){ \
                n = (n * 10) + (c - '0'); \
                c = getchar_unlocked(); \
            } \
            return *this; \
        }
    defineInFor(int32_t)
    defineInFor(int64_t)
    defineInFor(uint32_t)
    defineInFor(uint64_t)
    #define defineOutFor(intType) \
        inline IO& operator << (intType n) { \
            char* p = tmp + 30; \
            *p = 0; \
            if (n) { \
                bool isNeg = 0; \
                if (n < 0) isNeg = 1, n = -n; \
                while (n) \
                    *--p = (n % 10) + '0', n /= 10; \
                if (isNeg) *--p = '-'; \
            } else *--p = '0'; \
            *this << p; \
            return *this; \
        }
    defineOutFor(int32_t)
    defineOutFor(int64_t)
    defineOutFor(uint32_t)
    defineOutFor(uint64_t)

    inline IO& operator << (const char * s) {
        while (*s) putchar_unlocked(*s++);
        return *this;
    }
    inline IO& operator << (const char c) {
        putchar_unlocked(c);
        return *this;
    }
    #define cout __io__
    #define cin __io__
} __io__;

template <class T>
using min_priority_queue = priority_queue<T, vector<T>, greater<T> >;

int main() {
    uint32_t n, m;
    cin >> n >> m;
    uint64_t* marked = new uint64_t[n];
    vector<pair<uint32_t, uint32_t> >* graph = new vector<pair<uint32_t, uint32_t> >[n];
    for (uint32_t x = 0; x < n; ++x) {
        cin >> marked[x];
        marked[x] = marked[x]?0:0xfffffffffffffffful;
    }
    for (int x = 0; x < m; ++x) {
        uint32_t u, v, c;
        cin >> u >> v >> c;
        graph[u - 1].push_back(make_pair(v - 1, c));
        graph[v - 1].push_back(make_pair(u - 1, c));
    }
    min_priority_queue<pair<uint64_t, pair<uint32_t, uint32_t> > > pqueue;
    for (uint32_t x = 0; x < n; ++x)
        if (marked[x] == 0)
            for (auto edge: graph[x])
                pqueue.push({edge.second, edge});
    uint64_t mincost = 0;
    while(!pqueue.empty()) {
        auto top = pqueue.top(); pqueue.pop();
        if (marked[top.second.first] <= top.first)
            continue;
        mincost = mincost + top.second.second;
        marked[top.second.first] = top.first;
        for (auto edge: graph[top.second.first])
            if (marked[edge.first] > edge.second + top.first)
                pqueue.push({edge.second + top.first, edge});
    }
    bool flag = true;
    for (uint64_t x = 0; x < n; ++x) {
        if (marked[x] == 0xfffffffffffffffful) {
            cout << "impossible" << endl;
            flag = false;
            break;
        }
    }
    if (flag) {
        cout << mincost << endl;
    }
    return 0;
}
