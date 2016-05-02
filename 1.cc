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

bool validate(string s, vector<int>& perm) {
    for (int p = 0, i = 0, j = 1; p < s.size(); ++p, ++i, ++j) {
        if (s[p] == 'X' && perm[i] > perm[j])
            return false;
        if (s[p] == 'Y' && perm[i] < perm[j])
            return false;
    }
    return true;
}

int main(int argc, char const *argv[]) {
    #ifndef __mr__
        ios::sync_with_stdio(0);cin.tie(0);
    #endif
    string s;
    while(cin >> s) {
        vector<int> perm(s.size() + 1);
        assert(perm.size() <= 9);
        for (int i = 0; i < perm.size(); ++i)
            perm[i] = i + 1;
        do {
            if (validate(s, perm)) {
                for (int i = 0; i < perm.size(); ++i)
                    cout << perm[i];
                cout << endl;
                break;
            }
        } while(next_permutation(perm.begin(), perm.end()));
    }
    return 0;
}

