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

int mymin(int x, int y) {
    return (x < y) ? x: y;
}

int myabs(int x) {
    return (x >= 0) ? x: (-x);
}

int solution(vector<int> &A) {
    // write your code in C++11 (g++ 4.8.2)
    map<int, int> tree;
    tree.insert(make_pair(0, 0));
    int mas = t_max(int);
    for (int x = 0, s = 0; x < (int)A.size(); ++x) {
        s += A[x];
        auto it = tree.insert(make_pair(s, 0));
        auto iter = it.first;
        if (it.second == false) {
            mas = 0;
        }
        else {
            auto liter = iter;
            auto riter = iter;
            if (iter != tree.begin()) {
                liter--;
                mas = mymin(mas, myabs(iter->first - liter->first));
            }
            if (++riter != tree.end()) {
                mas = mymin(mas, myabs(iter->first - riter->first));
            }
        }
    }
    return mas;
}

int main(int argc, char const *argv[]) {
    #ifndef __mr__
        ios::sync_with_stdio(0);cin.tie(0);
    #endif
    vector<int> arr({2, -4, 6, -3, 9});
    cout << solution(arr) << endl;
    return 0;
}

