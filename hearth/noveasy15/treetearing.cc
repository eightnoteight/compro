#include <bits/stdc++.h>
#ifdef __mr__
    #include "prettyprint.hpp"
#else
    #define endl                                               '\n'
#endif
#define ulong                                                   unsigned long
using namespace std;
const ulong mod = 1000000007ul;
vector<int>* tree;
uint k, n, tmp;
uint comp = 0;
int answer(uint v, uint p) {
    int cntn = 0;
    for (int node: tree[v]) 
        if (node != p) 
            cntn += answer(node, v);
    // cout << v << ", " << p << ", " << cntn << ", " << endl;
    if (cntn >= k) {
        comp++;
        return 0;
    }
    else {
        return cntn + 1;
    }
}

int main(int argc, char const *argv[]) {
    #ifndef __mr__
        ios::sync_with_stdio(0);cin.tie(0);
    #endif
    cin >> k >> n;
    --k;
    tree = new vector<int>[n];
    for (uint i = 1; i < n; ++i) {
        cin >> tmp;
        tree[--tmp].push_back(i);
    }
    // cout << "pool" << endl;
    // for (uint i = 0; i < n; ++i) {
    //     cout << i << ": " << tree[i] << endl;
    // }
    answer(0, -1);
    cout << comp << endl;
    return 0;
}
