#include <bits/stdc++.h>
#ifdef __mr__
    #include "prettyprint.hpp"
#else
    #define endl                                               '\n'
#endif
#define uint                                                    unsigned int
#define ulong                                                   unsigned long long
using namespace std;
const ulong mod = 1000000007ul;

struct Graph {
    uint v;
    bool* visited;
    vector<vector<uint>> adjList;
    Graph(uint n): v(n){
        adjList.resize(v);
        visited = new bool[v];
    }
    void addEdge(uint a, uint b) {
        adjList[a].push_back(b);
    }
    template<class Func>
    void bfs(uint root, Func check) {
        queue<uint> Q; Q.push(root);
        memset(visited, false, v);
        visited[root] = true;
        while(!Q.empty()) {
            auto node = Q.front(); Q.pop();
            check(node);
            for (uint child: adjList[node]) {
                if (!visited[child]) {
                    Q.push(child);
                    visited[child] = true;
                }
            }
        }
    }
    template<class Func>
    void dfs(uint root, Func check) {
        stack<uint> S; S.push(root);
        memset(visited, false, v);
        visited[root] = true;
        while(!S.empty()) {
            auto node = S.top(); S.pop();
            check(node);
            for (uint child: adjList[node]) {
                if (!visited[child]) {
                    S.push(child);
                    visited[child] = true;
                }
            }
        }
    }
    ~Graph(){
        delete[] visited;
    }
};

int main(int argc, char const *argv[]) {
    #ifndef __mr__
        ios::sync_with_stdio(0);cin.tie(0);
    #endif
    Graph graph(5);
    graph.addEdge(0, 1);
    graph.addEdge(0, 2);
    graph.addEdge(1, 2);
    graph.addEdge(2, 0);
    graph.addEdge(2, 3);
    graph.addEdge(3, 3);
    graph.bfs(2, [](uint node) {
        cout << node << ' ';
    });
    cout << endl;
    graph.dfs(2, [](uint node) {
        cout << node << ' ';
    });
    cout << endl;
    return 0;
}
