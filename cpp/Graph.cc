#include <bits/stdc++.h>
#ifdef __mr__
    #include "prettyprint.hpp"
#else
    #define endl                                               '\n'
#endif
#define ushort                                                  unsigned short
#define uint                                                    unsigned int
#define ulong                                                   unsigned long long
#define uset                                                    unordered_set
using namespace std;

class Graph {
private:
    vector<vector<uint>> adjlist;
public:
    Graph (uint num_nodes) {
        adjlist.resize(num_nodes);
    }
    uint size() {
        return adjlist.size();
    }
    void addEdge(uint a, uint b) {
        adjlist[a].push_back(b);
        adjlist[b].push_back(a);
    }
    template<class Func>
    void _traverse_bfs_a(Func check) {
        queue<uint> Q;
        Q.push(0);
        uset<uint> visited;
        while (Q.size()) {
            auto node = Q.front(); Q.pop();
            if (visited.find(node) != visited.end())
                continue;
            visited.insert(node);
            check(node);
            for (auto chnode: adjlist[node])
                Q.push(chnode);
        }
    }
    template<class Func>
    void _traverse_bfs_b(Func check) {
        queue<uint> Q;
        Q.push(0);
        bool *visited = new bool[adjlist.size()];
        memset(visited, false, adjlist.size()*sizeof(bool));
        while (Q.size()) {
            auto node = Q.front(); Q.pop();
            if (visited[node])
                continue;
            visited[node] = true;
            check(node);
            for (auto chnode: adjlist[node])
                Q.push(chnode);
        }
        delete[] visited;
    }
    template<class Func>
    void _traverse_dfs_a(Func check) {
        stack<uint> st;
        st.push(0);
        uset<uint> visited;
        while (st.size() > 0) {
            auto node = st.top(); st.pop();
            if (visited.find(node) != visited.end())
                continue;
            visited.insert(node);
            check(node);
            for (auto chnode: adjlist[node])
                st.push(chnode);
        }
    }
};

int main(int argc, char const *argv[]) {
    #ifndef __mr__
        ios::sync_with_stdio(0);cin.tie(0);
    #endif
    Graph graph(5);
    graph.addEdge(0, 1);
    graph.addEdge(1, 2);
    graph.addEdge(2, 3);
    graph.addEdge(3, 4);
    graph.addEdge(4, 0);
    graph._traverse_dfs_a([](uint node) {
        cout << node << ' ';
    });
    cout << endl;
    graph._traverse_bfs_a([](uint node) {
        cout << node << ' ';
    });
    cout << endl;
    graph._traverse_bfs_b([](uint node) {
        cout << node << ' ';
    });
    cout << endl;
    return 0;
}
