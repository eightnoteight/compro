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
#define len(x)                                      ((uint32_t)(x).size())
#define empty(x)                                    ((x).empty())
#define esort(x)                                    (sort((x).begin(), (x).end()))
#define ersort(x)                                   (sort((x).rbegin(), (x).rend()))
#define name(x)                                     (#x)
using namespace std;
inline void print() {}
template<typename _p, typename... _args>
inline void print(_p p, _args... args) {cout << p << ' '; print(args...);}
template<typename... _args>
inline void println(_args... args) {print(args...); cout << '\n';}
inline void write() { }
template<typename _p, typename... _args>
inline void write(_p p, _args... args) { cout << p; write(args...); }
inline void scan() { }
template<typename _p, typename... _args>
inline void scan(_p& p, _args&... args) { cin >> p; scan(args...); }

int main() {
    #ifndef __lucy__
        ios::sync_with_stdio(0);cin.tie(0);
    #endif
    cout << fixed << setprecision(6);
    uint32_t n, m;
    scan(n, m);
    vector<vector<uint32_t> > graph(n);
    vector<uint32_t> levels(n);
    while(m--) {
        uint32_t x, k, dep;
        scan(x, k);
        --x;
        levels[x] = 1;
        while(k--) {
            scan(dep);
            graph[--dep].push_back(x);
        }
    }
    for (uint32_t lev= 0; lev < len(levels); ++lev) if (levels[lev] == 0) {
        stack<pair<uint32_t, uint32_t> > travers;
        travers.push(make_pair(lev, 0));
        while(!empty(travers)) {
            auto node = travers.top(); travers.pop();
            levels[node.first] = max(levels[node.first], node.second);
            for (auto x: graph[node.first])
                travers.push(make_pair(x, node.second + 1));
        }
    }
    vector<pair<uint32_t, uint32_t> > order;
    for (uint32_t i = 0; i < len(levels); ++i)
        order.push_back(make_pair(levels[i], i));
    sort(order.begin(), order.end());
    for (uint32_t i = 0; i < len(order); ++i)
        print(++order[i].second);
    println();
    return 0;
}
