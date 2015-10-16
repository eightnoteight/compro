#include <bits/stdc++.h>
using namespace std;


class unionfind
{
public:
    int32_t length;
    vector<int32_t> roots;
    vector<int32_t> weights;
    unionfind(int32_t n) {
        length = n;
        roots.resize(n);
        weights.resize(n);
        for (int i = 0; i < n; ++i) {
            roots[i] = i;
            weights[i] = 1;
        }
    }
    ~unionfind(){
        roots.clear();
        weights.clear();
    }
    void connect(int32_t a, int32_t b) {
        int32_t aroot = find_root(a);
        int32_t broot = find_root(b);
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
    bool is_connected(int32_t a, int32_t b) {
        return find_root(a) == find_root(b);
    }

    int32_t find_root(int32_t a) {
        while(roots[a] != a) {
            roots[a] = roots[roots[a]];
            a = roots[a];
        }
        return a;
    }
};

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(0);cin.tie(0);
    int32_t t;
    cin >> t;
    while(t--) {
        int32_t n, e;
        cin >> n >> e;
        unionfind uf(n);
        for (int32_t i = 0; i < e; ++i) {
            int32_t a, b;
            cin >> a >> b;
            uf.connect(a, b);
        }
        int32_t count = 0;
        for (int i = 0; i < n; ++i)
            if (uf.weights[i])
                count++;
        cout << count << '\n';
    }
    return 0;
}
