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

template<typename intType>
intType gcd(intType a, intType b) {
    while(b) {
        intType tmp = b;
        b = a % b;
        a = tmp;
    }
    return a;
}

int main() {
    // ios::sync_with_stdio(0);cin.tie(0);
    int n;
    while((cin >> n) && n) {
        vector<pair<int, int> > arr(n);
        for (int x = 0; x < n; ++x)
            cin >> arr[x].first >> arr[x].second;
        set<pair<int, int> > slopes;
        for (int x = 0; x < n; ++x) {
            for (int y = x + 1; y < n; ++y) {
                int xcept = arr[y].first - arr[x].first;
                int ycept = arr[y].second - arr[x].second;
                tie(xcept, ycept) = make_tuple(xcept / gcd(xcept, ycept), ycept / gcd(xcept, ycept));
                if (xcept == 0)
                    slopes.insert(make_pair(0, 1));
                else if (ycept == 0)
                    slopes.insert(make_pair(1, 0));
                else if (xcept < 0 && ycept < 0)
                    slopes.insert(make_pair(-xcept, -ycept));
                else if (xcept < 0 || ycept < 0)
                    slopes.insert(make_pair(-abs(xcept), abs(ycept)));
                else
                    slopes.insert(make_pair(xcept, ycept));
            }
        }
        cout << slopes.size() << endl;
    }
    return 0;
}
