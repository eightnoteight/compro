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
int indices[550055];
int lcp[550055];
int ranks[550055];
int newranks[550055];
int subranks[550055];
int locations[550055];
int subst1_len = 0;

int* getSuffixArray(char *str) {
    for (int x = 0; x < subst1_len; ++x)
        indices[x] = x;
    stable_sort(indices, indices + subst1_len, [&str](int i, int j) {
        return str[i] < str[j];
    });
    ranks[0] = newranks[0] = 0;
    for (int x = 1; x < subst1_len; ++x)
        ranks[x] = ranks[x - 1] + (str[indices[x]] != str[indices[x - 1]]);
    for (int x = 1; x <= subst1_len; x <<= 1) {
        for (int y = 0; y < subst1_len; ++y)
            locations[indices[y]] = y;
        for (int y = 0; y < subst1_len; ++y)
            subranks[y] = (indices[y] + x < subst1_len) ? ranks[locations[indices[y] + x]] : -1;
        stable_sort(indices, indices + subst1_len, [&ranks, &subranks, &locations](int i, int j) {
            if (ranks[locations[i]] != ranks[locations[j]])
                return ranks[locations[i]] < ranks[locations[j]];
            return subranks[locations[i]] < subranks[locations[j]];
        });
        for (int y = 1; y < subst1_len; ++y)
            newranks[y] = newranks[y - 1] + (
                ranks[locations[indices[y]]] != ranks[locations[indices[y - 1]]] ||
                subranks[locations[indices[y]]] != subranks[locations[indices[y - 1]]]);
        memcpy(ranks, newranks, subst1_len*sizeof(int));
    }
    return indices;
}

int* getLongestCommonPrefixArray(char *str, int *sufarr) {
    for (int x = 0; x < subst1_len; ++x)
        locations[sufarr[x]] = x;
    for (int x = 0, k = 0; x < subst1_len; ++x) {
        if (locations[x] + 1 < subst1_len) {
            for (int y = sufarr[locations[x] + 1];  str[x + k] == str[y + k]; )
                k++;
            lcp[locations[x]] = k;
            k ? k--: 0;
        }
    }
    // memmove(lcp + 1, lcp, sizeof(int)*(subst1_len - 1));
    // lcp[0] = 0;
    return lcp;
}


template<class Func>
int bsearch(int lo, int hi, Func check) {
    int mid;
    while(lo < hi) {
        mid = lo + ((hi - lo) / 2);
        if (check(mid))
            hi = mid;
        else
            lo = mid + 1;
    }
    return lo;
}

int main(int argc, char const *argv[]) {
    #ifndef __mr__
        ios::sync_with_stdio(0);cin.tie(0);
    #endif
    char* s = new char[550055];
    int k;
    cin >> s >> k;
    if (k == 1) {
        cout << s << endl;
        return 0;
    }
    int n = strlen(s);
    subst1_len = n;
    int* sufarr = getSuffixArray(s);
    int* lcp = getLongestCommonPrefixArray(s, sufarr);
    vector<int> st;
    int ans_i = -1;
    int ans_l = 0;
    for (int i = n - 1; i >= 0; --i) {
        while (!st.empty() && lcp[st.back()] >= lcp[i])
            st.pop_back();
        st.push_back(i);
        int lens = min(n - sufarr[i], lcp[i]);
        int cans = 0;
        if (st.size() == 1) {
            if (lcp[i] != 0) {
                cans = (n - i >= k) ? lens : 0;
            }
        }
        else {
            cans = bsearch(1, lens + 1, [&](int m) {
                int bi = bsearch(0, st.size(), [&](int m1) {
                    return lcp[st[m1]] >= m;
                });
                if (bi != 0) {
                    return !(st[bi - 1] - i + 1 >= k);
                }
                else if (lcp[i] != 0) {
                    return !(n - i >= k);
                }
                return true;
            }) - 1;
        }
        if (cans >= ans_l) {
            ans_l = cans;
            ans_i = sufarr[i];
        }
    }
    if (ans_l == 0) {
        cout << -1 << endl;
    }
    else {
        cout << string(s + ans_i, s + ans_i + ans_l) << endl;
    }
    return 0;
}
