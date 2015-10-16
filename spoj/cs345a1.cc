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
using ordermultiset = tree<K, null_type, less<K>, rb_tree_tag, tree_order_statistics_node_update>;


int main() {
    #ifndef __lucy__
        ios::sync_with_stdio(0);cin.tie(0);
    #endif
    uint32_t n;
    cin >> n;
    vector<array<float, 3> > bsegs(n), rsegs(n);
    vector<float> rfalls(n);
    for (int x = 0; x < n; ++x) {
        cin >> bsegs[x][0] >> bsegs[x][1] >> bsegs[x][2];
        tie(bsegs[x][0], bsegs[x][1]) = make_tuple(min(bsegs[x][0], bsegs[x][1]), max(bsegs[x][0], bsegs[x][1]));
    }
    for (int x = 0; x < n; ++x) {
        cin >> rsegs[x][0] >> rsegs[x][1] >> rsegs[x][2];
        tie(rsegs[x][0], rsegs[x][1]) = make_tuple(min(rsegs[x][0], rsegs[x][1]), max(rsegs[x][0], rsegs[x][1]));
        rfalls[x] = rsegs[x][2];
    }
    sort(bsegs.begin(), bsegs.end(), [](const array<float, 3>& x, const array<float, 3>& y) {
        if (x[0] != y[0])
            return x[0] < y[0];
        return x[1] < y[1];
    });
    sort(rsegs.begin(), rsegs.end(), [](const array<float, 3>& x, const array<float, 3>& y) {
        return x[2] < y[2];
    });
    sort(rfalls.begin(), rfalls.end());

    ordermultiset<pair<float, int> > rstarts, rends;
    ulong intersections = 0;
    map<float, int> startcounts, endcounts;
    // cout << rsegs << endl;
    for (uint rd = 0, ra = 0, bx = 0; bx < n; ++bx) {
        // while (rsegs[rd][2] < bsegs[bx][0] && rd < ra && rd < n) {
        //     rstarts.erase(make_pair(rsegs[rd][0], --startcounts[rsegs[rd][0]]));
        //     rends.erase(make_pair(rsegs[rd][1], --endcounts[rsegs[rd][1]]));
        //     rd++;
        // }
        while (rsegs[rd][2] < bsegs[bx][0] && rd < ra && rd < n) {
            rstarts.erase(make_pair(rsegs[rd][0], --startcounts[rsegs[rd][0]]));
            rends.erase(make_pair(rsegs[rd][1], --endcounts[rsegs[rd][1]]));
            rd++;
        }
        while (rsegs[ra][2] <= bsegs[bx][1] && ra < n) {
            rstarts.insert(make_pair(rsegs[ra][0], startcounts[rsegs[ra][0]]++));
            rends.insert(make_pair(rsegs[ra][1], endcounts[rsegs[ra][1]]++));
            ra++;
        }
        while (rsegs[rd][2] < bsegs[bx][0] && rd < ra && rd < n) {
            rstarts.erase(make_pair(rsegs[rd][0], --startcounts[rsegs[rd][0]]));
            rends.erase(make_pair(rsegs[rd][1], --endcounts[rsegs[rd][1]]));
            rd++;
        }
        // cout << ra << " " << rd << endl;
        // cout << startcounts << endl;
        // cout << endcounts << endl;
        // cout << "rstarts = " << rstarts << endl;
        // cout << "rends = " << rends << endl;
        // cout << bsegs[bx] << " => " << rstarts.order_of_key(make_pair(bsegs[bx][2], startcounts[bsegs[bx][2]])) << " : " << rends.order_of_key(make_pair(bsegs[bx][2], -1)) << endl;
        intersections += rstarts.order_of_key(make_pair(bsegs[bx][2], startcounts[bsegs[bx][2]])) - rends.order_of_key(make_pair(bsegs[bx][2], -1));
    }
    cout << intersections << endl;
    return 0;
}
