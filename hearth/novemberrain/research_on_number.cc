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

// problem: https://www.hackerearth.com/problem/algorithm/research-on-numbers-1

template<class etype, class etypearr>
class rangeminimumquery {
private:
    etypearr& arr;
    uint n;
    uint* logt;
    uint** sparset;
public:
    rangeminimumquery(etypearr& arri, uint ni) : arr(arri), n(ni) {
        // Generate Log Table
        logt = new uint[n + 1];
        logt[1] = logt[0] = 0;
        for (uint x = 2; x < n + 1; ++x)
            logt[x] = logt[x >> 1] + 1;
        // Generate Sparse Table
        sparset = new uint*[n];
        for (uint x = 0; x < n; ++x) {
            sparset[x] = new uint[logt[n] + 1];
            sparset[x][0] = x;
        }
        for (int x = n - 1; x > -1; --x) {
            for (int y = 1; y < logt[n - x] + 1; ++y) {
                if (arr[sparset[x][y - 1]] < arr[sparset[x + (1 << (y - 1))][y - 1]])
                    sparset[x][y] = sparset[x][y - 1];
                else
                    sparset[x][y] = sparset[x + (1 << (y - 1))][y - 1];
            }
        }
    }
    etype query(uint i, uint j) {
        uint k = logt[j - i];
        if (arr[sparset[i][k]] < arr[sparset[j - (1 << k)][k]])
            return sparset[i][k];
        else
            return sparset[j - (1 << k)][k];
    }
    etype query_value(uint i, uint j) {
        uint k = logt[j - i];
        return min(
            arr[sparset[i][k]],
            arr[sparset[j - (1 << k)][k]]);
    }
    ~rangeminimumquery() {
        delete[] logt;
        for (int x = 0; x < n; ++x)
            delete[] sparset[x];
        delete[] sparset;
    }
};


int main(int argc, char const *argv[]) {
    #ifndef __mr__
        ios::sync_with_stdio(0);cin.tie(0);
    #endif
    ulong mod = 1000000007;
    int testcases;
    cin >> testcases;
    while(testcases--) {
        int q, k;
        cin >> q >> k;
        vector<ulong> b(k);
        vector<ulong> c(k);
        int n = 1000000;
        vector<ulong> arr(n);
        for (uint i = 0; i < k; ++i) {
            cin >> b[i];
        }
        for (uint i = 0; i < k; ++i) {
            cin >> c[i];
        }
        for (uint i = 0; i < k; ++i) {
            arr[i] = b[i];
        }
        for (uint x = k; x < n; ++x) {
            for (uint y = 0; y < k; ++y) {
                arr[x] += arr[x - y - 1] * c[y];
            }
            arr[x] %= 1000000007;
        }
        rangeminimumquery<ulong, vector<ulong>> rmq(arr, n);
        for (uint i = 0; i < q; ++i) {
            int l, r;
            cin >> l >> r;
            --l;
            vector<pair<int, int>> univ;
            univ.push_back({l, r});
            for (uint j = 0; j < 100; ++j) {
                pair<int, int> mipos = {-1, -1};
                for (uint ind = 0; ind < len(univ); ++ind) {
                    if (mipos.first == -1 || arr[mipos.first] > arr[rmq.query(univ[ind].first, univ[ind].second)]) {
                        mipos = {rmq.query(univ[ind].first, univ[ind].second), ind};
                    }
                }
                if (mipos.first == -1) {
                    break;
                }
                cout << arr[mipos.first] << ' ';
                auto split = univ[mipos.second];
                univ.erase(univ.begin() + mipos.second);
                if (mipos.first > split.first) {
                    univ.push_back({split.first, mipos.first});
                }
                if (mipos.first + 1 < split.second) {
                    univ.push_back({mipos.first + 1, split.second});
                }
            }
            cout << endl;
        }
    }
    return 0;
}
