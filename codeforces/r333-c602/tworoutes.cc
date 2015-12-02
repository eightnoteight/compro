#include <bits/stdc++.h>
#ifdef __mr__
    #include "prettyprint.hpp"
#else
    #define endl                                               '\n'
#endif
#define ulong                                                   unsigned long
using namespace std;
const ulong mod = 1000000007ul;

#define uset unordered_set

int bfs(vector<vector<int>>& graph, int src, int dest) {
    int dist = 0;
    queue<int> Q;
    Q.push(src);
    Q.push(-1);
    uset<int> visited;
    while (Q.size() > 1) {
        int node = Q.front(); Q.pop();
        if (node == -1) {
            dist++;
            Q.push(-1);
            continue;
        }
        if (visited.find(node) != visited.end())
            continue;
        if (node == dest)
            return dist;
        visited.insert(node);
        for (int x = 0; x < graph[node].size(); ++x)
            if (graph[node][x])
                Q.push(x);
    }
    return -1;
}

int main(int argc, char const *argv[]) {
    #ifndef __mr__
        ios::sync_with_stdio(0);cin.tie(0);
    #endif
    int n, m;
    cin >> n >> m;
    vector<vector<int>> road(n, vector<int>(n, 1));
    vector<vector<int>> railway(n, vector<int>(n));
    for (int x = 0; x < m; ++x) {
        int ex, ey;
        cin >> ex >> ey;
        road[ex - 1][ey - 1] = 0;
        road[ey - 1][ex - 1] = 0;
        railway[ex - 1][ey - 1] = 1;
        railway[ey - 1][ex - 1] = 1;
    }
    int rox = bfs(road, 0, n - 1);
    int rax = bfs(railway, 0, n - 1);
    if (rox == -1 || rax == -1) {
        cout << -1 << endl;
    }
    else {
        cout << max(rox, rax) << endl;
    }
    return 0;
}
