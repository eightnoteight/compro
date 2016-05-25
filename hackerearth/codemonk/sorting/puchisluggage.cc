#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>

#ifdef __lucy__
    #include "prettyprint.hpp"
#endif
#define endl                                        ('\n')
#define i32max                                      (0x7fffffff)
#define i32min                                      (-0x7fffffff-1)
#define i64max                                      (0x7fffffffffffffff)
#define i64min                                      (-0x7fffffffffffffff-1)
#define ui32max                                     (0xffffffffu)
#define ui64max                                     (0xffffffffffffffffu)
#define bitcounti32                                 __builtin_popcount
#define bitcounti64                                 __builtin_popcountll
#define len(x)                                      ((uint32_t)(x).size())
#define esort(x)                                    (sort((x).begin(), (x).end()))
#define ersort(x)                                   (sort((x).rbegin(), (x).rend()))
#define name(x)                                     (#x)
#define uint                                        uint32_t
#define int                                         int32_t
#define ulong                                       uint64_t
#define long                                        int64_t

using namespace std;
using namespace __gnu_pbds;

template<typename K>
using statisticset = tree< \
    K,
    null_type,
    less<K>,
    rb_tree_tag,
    tree_order_statistics_node_update>;


int main() {
    #ifndef __lucy__
        ios::sync_with_stdio(0);cin.tie(0);
    #endif
    uint testcases;
    cin >> testcases;
    for(uint test = 1; test <= testcases; ++test) {
        uint n;
        cin >> n;
        vector<uint> arr(n);
        for (auto& x: arr)
            cin >> x;
        statisticset<uint> worker;
        vector<uint> answers;
        for (int x = n - 1; x > -1; --x) {
            answers.push_back(worker.order_of_key(arr[x]));
            worker.insert(arr[x]);
        }
        for (int x = n - 1; x > -1; --x) {
            cout << answers[x] << ' ';
        }
        cout << endl;
    }
    return 0;
}

