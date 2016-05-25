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

#define uset                        unordered_set

int main(int argc, char const *argv[]) {
    #ifndef __mr__
        ios::sync_with_stdio(0);cin.tie(0);
    #endif
    int t;
    cin >> t;
    label:
    while(t--) {
        int n, c;
        cin >> n >> c;
        vector<uset<int>> graph(n);
        vector<pair<int, int>> edges;
        bool flag = false;
        for (int i = 0; i < c; ++i) {
            int a, b;
            cin >> a >> b; --a; --b;
            if (graph[a].find(b) != graph[a].end() || graph[b].find(a) != graph[b].end()) {
                flag = true;
            }
            graph[a].insert(b);
            graph[b].insert(a);
        }
        if (flag) {
            cout << "No" << endl;
            goto label;
        }
        uset<int> asgard;
        for (int i = 0; i < n; ++i) {
            if (graph[i].size() == n - 1) {
                asgard.insert(i);
            }
            else if (graph[i].size() != 3) {
                cout << "No" << endl;
                goto label;
            }
        }
        for (int x: asgard) {
            for (int i = 0; i < n; ++i) {
                graph[i].erase(x);
            }
        }
        uset<int> vanaheim;
        uset<int> midgard;
        int groupcount = 0;
        for (int i = 0; i < n; ++i) {
            if (asgard.find(i) == asgard.end() && vanaheim.find(i) == vanaheim.end() && midgard.find(i) == midgard.end()) {
                groupcount++;
                if (groupcount > 2) {
                    cout << "No" << endl;
                    goto label;
                }
                if (groupcount == 1) {
                    queue<int> Q;
                    Q.push(i);
                    while (Q.size()) {
                        int node = Q.front(); Q.pop();
                        if (vanaheim.find(node) != vanaheim.end())
                            continue;
                        vanaheim.insert(node);
                        for (int lli: graph[node]) {
                            Q.push(lli);
                        }
                    }
                }
                else {
                    queue<int> Q;
                    Q.push(i);
                    while (Q.size()) {
                        int node = Q.front(); Q.pop();
                        if (midgard.find(node) != midgard.end())
                            continue;
                        midgard.insert(node);
                        for (int lli: graph[node]) {
                            Q.push(lli);
                        }
                    }
                }
            }
        }
        for (int x: vanaheim) {
            if (graph[x].size() != 2) {
                cout << "No" << endl;
                goto label;
            }
            for (int y: graph[x]) {
                if (vanaheim.find(y) == vanaheim.end()) {
                    cout << "No" << endl;
                    goto label;
                }
            }
        }
        for (int x: midgard) {
            if (graph[x].size() != 2) {
                cout << "No" << endl;
                goto label;
            }
            for (int y: graph[x]) {
                if (midgard.find(y) == midgard.end()) {
                    cout << "No" << endl;
                    goto label;
                }
            }
        }
        if (vanaheim.size() + midgard.size() + asgard.size() != n) {
            cout << "No" << endl;
            goto label;
        }
        cout << "Yes" << endl;
    }
    return 0;
}
