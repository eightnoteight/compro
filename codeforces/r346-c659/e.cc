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

int dfs(vector<vector<int>>& graph, vector<int>& visited, int start) {
    stack<pair<int, int>> st;
    st.push({start, -1});
    while(!st.empty()) {
        auto node = st.top();st.pop();
        if (visited[node.first])
            return 0;
        visited[node.first]++;
        for (int i = 0; i < graph[node.first].size(); ++i) {
            if (graph[node.first][i] != node.second) {
                st.push({graph[node.first][i], node.first});
            }
        }
    }
    return 1;
}

int main(int argc, char const *argv[]) {
    #ifndef __mr__
        ios::sync_with_stdio(0);cin.tie(0);
    #endif
    int n, m;
    cin >> n >> m;
    vector<vector<int>> graph(n);
    vector<int> visited(n);
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    int sep = 0;
    for (int i = 0; i < n; ++i)
    {
        if (visited[i] == 0) {
            if (dfs(graph, visited, i)) {
                sep += 1;
            }
        }
        // cout << visited << endl;
    }
    cout << sep << endl;
    return 0;
}
