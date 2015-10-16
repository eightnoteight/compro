#include <bits/stdc++.h>
#ifdef __lucy__
    #include "prettyprint.hpp"
#endif
#define endl                                        ('\n')
#define len(x)                                      ((uint32_t)(x).size())
#define umap                                        unordered_map
#define uset                                        unordered_set
using namespace std;

template<class T>
using smpair = pair<T, T>;

struct unionfind {
    size_t length;
    uint32_t *roots, *weights;
    unionfind(size_t n) {
        length = n;
        roots = new uint32_t[n];
        weights = new uint32_t[n];
        for (int i = 0; i < n; ++i) {
            roots[i] = i;
            weights[i] = 1;
        }
    }
    void connect(uint32_t a, uint32_t b) {
        uint32_t aroot = find_root(a);
        uint32_t broot = find_root(b);
        if(aroot == broot)
            return;
        if(weights[aroot] > weights[broot]) {
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
    ~unionfind() {
        delete[] roots;
        delete[] weights;
    }
};

int main() {
    uint32_t n, m;
    cin >> n >> m;
    smpair<uint32_t>* friendships = new smpair<uint32_t>[m];
    uset<uint32_t> known_uset;
    for (uint32_t i = 0; i < m; ++i) {
        cin >> friendships[i].first >> friendships[i].second;
        known_uset.insert(friendships[i].first);
        known_uset.insert(friendships[i].second);
    }
    vector<uint32_t> known(known_uset.begin(), known_uset.end());
    umap<uint32_t, uint32_t> deref;
    for (uint32_t i = 0; i < len(known); ++i)
        deref[known[i]] = i;
    unionfind uf(len(known));
    for (uint32_t i = 0; i < m; ++i)
        uf.connect(deref[friendships[i].first], deref[friendships[i].second]);
    uset<uint32_t> roots;
    for (uint32_t i = 0; i < len(known); ++i)
        roots.insert(uf.find_root(i));
    // cout << n << endl;
    // cout << len(known) << endl;
    // cout << len(roots) << endl;
    cout << n - len(known) + len(roots) << endl;
    return 0;
}

