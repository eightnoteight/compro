#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>
#ifdef __mr__
    #include "prettyprint.hpp"
#endif
#ifndef __mr__
    #define endl                                               '\n'
#endif
#define ulong                                                   unsigned long
using namespace __gnu_pbds;
using namespace std;
const ulong mod = 1000000007ul;
template<typename K>
using orderstatset = tree<K, null_type, less<K>, rb_tree_tag, tree_order_statistics_node_update>;

int mininv(vector<int> arr) {
    orderstatset<int> stat;
    int lo = 0;
    int hi = arr.size() - 1;
    int inversions = 0;
    for (int i = 0; i < arr.size(); ++i) {
        int cur1 = arr[lo], cur2 = arr[hi], xn, yn;
        int x = stat.order_of_key(cur1);
        int y = stat.order_of_key(cur2);
        xn = min(x, (int)stat.size() - x);
        yn = min(y, (int)stat.size() - y);
        if (xn < yn) {
            stat.insert(cur1);
            cout << cur1 << endl;
            inversions += xn;
            lo++;
        }
        else if (yn < xn) {
            stat.insert(cur2);
            cout << cur2 << endl;
            inversions += yn;
            hi--;
        }
        else if (xn == x && yn == y) {
            if (cur1 < cur2) {
                stat.insert(cur1);
                cout << cur1 << endl;
                inversions += xn;
                lo++;
            }
            else {
                stat.insert(cur2);
                cout << cur2 << endl;
                inversions += yn;
                hi--;
            }
        }
        else if ()
    }
    return inversions;
}

int main(int argc, char const *argv[]) {
    #ifndef __mr__
        ios::sync_with_stdio(0);cin.tie(0);
    #endif
    cout << mininv(vector<int>({6, 2, 1, 3, 5, 4})) << endl;
    return 0;
}
