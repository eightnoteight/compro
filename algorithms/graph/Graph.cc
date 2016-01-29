#include <bits/stdc++.h>
#ifdef __mr__
    #include "prettyprint.hpp"
#else
    #define endl                                                '\n'
#endif
#define len(x)                                                  (uint)(x).size()
#define int                                                     int32_t
#define uint                                                    uint32_t
#define ulong                                                   uint64_t
#define long                                                    int64_t
using namespace std;
const ulong mod = 1000000007ul;

struct UdiGraph {
    vector<uint> adj;
    UdiGraph(uint V) {
        adj.resize(V);
    }
    inline void addEdge(uint a, uint b) {
        adj[a].push_back(b);
    }
}
struct DiGraph {
    vector<uint> adj;
    DiGraph(uint V) {
        adj.resize(V);
    }
    inline void addEdge(uint a, uint b) {
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
}

int main(int argc, char const *argv[]) {
    #ifndef __mr__
        ios::sync_with_stdio(0);cin.tie(0);
    #endif
    // code
    return 0;
}
