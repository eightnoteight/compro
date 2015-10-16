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

template <class T>
using min_priority_queue = priority_queue<T, vector<T>, greater<T> >;

struct unionfind {
    size_t length;
    vector<uint32_t> roots, weights;
    unionfind(size_t n) {
        length = n;
        roots.resize(n);
        weights.resize(n);
        for (int i = 0; i < n; ++i) {
            roots[i] = i;
            weights[i] = 1;
        }
    }
    void connect(uint32_t a, uint32_t b) {
        uint32_t aroot = find_root(a);
        uint32_t broot = find_root(b);
        if(aroot == broot) {
            return;
        }
        else if(weights[aroot] > weights[broot]) {
            roots[broot] = aroot;
            weights[aroot] += weights[broot];
            weights[broot] = 0;
        }
        else {
            roots[aroot] = broot;
            weights[broot] += weights[aroot];
            weights[aroot] = 0;
        }
    }
    bool is_connected(uint32_t a, uint32_t b) {
        return find_root(a) == find_root(b);
    }
    int32_t find_root(uint32_t a) {
        while(roots[a] != a) {
            roots[a] = roots[roots[a]];
            a = roots[a];
        }
        return a;
    }
};

uint64_t petya_repair(vector<array<uint32_t, 3> >& Ge, uint32_t n) {
    sort(Ge.begin(), Ge.end(), [](array<uint32_t, 3> a,array<uint32_t, 3> b) {
        return a[2] < b[2];
    });
    uint64_t cost = 0;
    unionfind uf(n);
    for (auto& edge: Ge) {
        if (!uf.is_connected(edge[0], edge[1])) {
            cost += edge[2];
            uf.connect(edge[0], edge[1]);
        }
    }
    for (uint32_t x = 1; x < n; ++x)
        if (!uf.is_connected(0, x))
            return ui64max;
    return cost;
}

int main() {
    #ifndef __lucy__
        ios::sync_with_stdio(0);cin.tie(0);
    #endif
    uint32_t testcases;
    cin >> testcases;
    for(uint32_t test = 1; test <= testcases; ++test) {
        uint32_t n, m;
        cin >> n >> m;
        uint32_t marked[n];
        for_each(marked, marked + n, [](uint32_t& x){
            cin >> x;
        });
        vector<array<uint32_t, 3> > graph;
        for (int x = 0; x < n; ++x)
            if (marked[x])
                graph.push_back({x, n, 0});
        for (int x = 0; x < m; ++x) {
            int32_t u, v, c;
            cin >> u >> v >> c;
            graph.push_back({u - 1, v - 1, c});
        }
        uint64_t cost = petya_repair(graph, n + 1);
        if (cost == ui64max)
            cout << "impossible" << endl;
        else
            cout << cost << endl;
    }
    return 0;
}


