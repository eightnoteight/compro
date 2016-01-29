#include <bits/stdc++.h>
#ifdef __mr__
    #include "prettyprint.hpp"
#else
    #define endl                    '\n'
#endif
#define len(x)                      (uint)(x).size()
#define int                         int32_t
#define uint                        uint32_t
#define long                        int64_t
#define ulong                       uint64_t
#define t_max(x)                    numeric_limits<x>::max()
#define t_min(x)                    numeric_limits<x>::min()
using namespace std;
const ulong mod = 1000000007ul;
#define umap                        unordered_map

int main(int argc, char const *argv[]) {
    #ifndef __mr__
        ios::sync_with_stdio(0);cin.tie(0);
    #endif
    int testcases;
    cin >> testcases;
    while(testcases--) {
        int n;
        cin >> n;
        umap<int, int> counter;
        for (int i = 0; i < n; ++i) {
            int tmp;
            cin >> tmp;
            counter[tmp]++;
        }
        vector<int> arr(len(counter));
        auto y = counter.begin();
        for (auto x = arr.begin(); x != arr.end(); ++x, ++y)
            *x = y->second;
        make_heap(arr.begin(), arr.end());
        ulong count = 0;
        while (len(arr) > 1) {
            pop_heap(arr.begin(), arr.end());
            int n1 = arr.back(); arr.pop_back();
            pop_heap(arr.begin(), arr.end());
            int n2 = arr.back(); arr.pop_back();
            count += 1;
            if (n1 - 1 > 0) {
                arr.push_back(n1 - 1);
                push_heap(arr.begin(), arr.end());
            }
            if (n2 - 1 > 0) {
                arr.push_back(n2 - 1);
                push_heap(arr.begin(), arr.end());
            }
        }
        cout << count + (len(arr)?arr[0]:0) << endl;
    }
    return 0;
}
