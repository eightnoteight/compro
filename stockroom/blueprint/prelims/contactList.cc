#include <bits/stdc++.h>
#ifdef __mr__
    #include "prettyprint.hpp"
#else
    #define endl                    '\n'
#endif
#define len(x)                      (uint)(x).size()
// #define int                         int32_t
// #define uint                        uint32_t
// #define ulong                       uint64_t
// #define long                        int64_t
#define t_max(x)                    numeric_limits<x>::max()
#define t_min(x)                    numeric_limits<x>::min()
using namespace std;
const ulong mod = 1000000007ul;

struct node {
    node* arr[26];
    int count;
    node() {
        for (uint i = 0; i < 26; ++i) {
            arr[i] = NULL;
        }
        count = 0;
    }
};

struct Trie{
    node *root;
    Trie() {
        root = new node;
    }
    void add(const string& s) {
        node *cur = root;
        for (uint i = 0; i < len(s); ++i) {
            if (cur->arr[s[i] - 'a'] == NULL)
                cur->arr[s[i] - 'a'] = new node;
            cur = cur->arr[s[i] - 'a'];
            cur->count++;
        }
    }
    int find(const string& prefix) {
        node *cur = root;
        for (uint i = 0; i < len(prefix); ++i) {
            if (cur->arr[prefix[i] - 'a'] == NULL)
                return 0;
            cur = cur->arr[prefix[i] - 'a'];
        }
        return cur->count;
    }
};

int main(int argc, char const *argv[]) {
    #ifndef __mr__
        ios::sync_with_stdio(0);cin.tie(0);
    #endif
    int n;
    cin >> n;
    string op, val;
    Trie trie;
    while(n--) {
        cin >> op >> val;
        if (op[0] == 'a') {
            trie.add(val);
        }
        else {
            cout << trie.find(val) << endl;
        }
    }
    return 0;
}
