#include <bits/stdc++.h>
#ifdef __mr__
    #include "prettyprint.hpp"
#endif
#define endl                        ('\n')
#define i32inf                      (0x7fffffff)
#define i32_inf                     (-0x7fffffff-1)
#define i64inf                      (0x7fffffffffffffff)
#define i64_inf                     (-0x7fffffffffffffff-1)
#define ui32inf                     (0xffffffffu)
#define ui64inf                     (0xffffffffffffffffu)
#define bitcounti32                 __builtin_popcount
#define bitcounti64                 __builtin_popcountll
using namespace std;
int testcases;

vector<int32_t> getSuffixArray(const string& str) {
    vector<int32_t> ranks(str.size()), subranks(str.size()),
        indices(str.size()), newranks(str.size()), locations(str.size());
    for (size_t x = 0; x < str.size(); ++x)
        indices[x] = x;
    sort(indices.begin(), indices.end(), [&str](int32_t i, int32_t j) {
        return str[i] < str[j];
    });
    for (size_t x = 1; x < str.size(); ++x)
        ranks[x] = ranks[x - 1] + (str[indices[x]] != str[indices[x - 1]]);
    for (size_t x = 1; x <= str.size(); x <<= 1) {
        for (size_t y = 0; y < str.size(); ++y)
            locations[indices[y]] = y;
        for (size_t y = 0; y < str.size(); ++y)
            subranks[y] = (indices[y] + x < str.size()) ? ranks[locations[indices[y] + x]] : -1;
        sort(indices.begin(), indices.end(), [&ranks, &subranks, &locations](int32_t i, int32_t j) {
            if (ranks[locations[i]] != ranks[locations[j]])
                return ranks[locations[i]] < ranks[locations[j]];
            return subranks[locations[i]] < subranks[locations[j]];
        });
        for (size_t y = 1; y < str.size(); ++y)
            newranks[y] = newranks[y - 1] + (
                ranks[locations[indices[y]]] != ranks[locations[indices[y - 1]]] ||
                subranks[locations[indices[y]]] != subranks[locations[indices[y - 1]]]);
        copy(newranks.begin(), newranks.end(), ranks.begin());
    }
    return move(indices);
}

vector<int32_t> getLongestCommonPrefixArray(const string& str, const vector<int32_t>& sufarr) {
    vector<int32_t> locations(str.size());
    vector<int32_t> lcp(str.size());
    for (size_t x = 0; x < str.size(); ++x)
        locations[sufarr[x]] = x;
    for (size_t x = 0, k = 0; x < str.size(); ++x) {
        if (locations[x] + 1 < str.size()) {
            for (size_t y = sufarr[locations[x] + 1];  str[x + k] == str[y + k]; )
                k++;
            lcp[locations[x]] = k;
            k ? k--: 0;
        }
    }
    for (int x = str.size() - 1; x > 0; --x)
        lcp[x] = lcp[x - 1];
    lcp[0] = 0;
    return move(lcp);
}


int main() {
    ios::sync_with_stdio(0);cin.tie(0);
    string uniq;
    cin >> uniq;
    int32_t q;
    cin >> q;
    for (int x = 0; x < q; ++x)
    {
        int32_t l, r;
        cin >> l >> r;
        l--;
        string subt = uniq.substr(l, r - l);
        vector<int32_t> sufarr = getSuffixArray(subt);
        vector<int32_t> lcparr = getLongestCommonPrefixArray(subt, sufarr);
        int32_t distinct = 0;
        for (int32_t x = 0; x < uniq.size(); ++x) {
            distinct += uniq.size() - sufarr[x] - lcparr[x];
        }
        cout << distinct << endl;
    }
    return 0;
}
