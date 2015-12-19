#include <bits/stdc++.h>
#ifdef __mr__
    #include "prettyprint.hpp"
#else
    #define endl                                               '\n'
#endif
#define uint                                                    unsigned int
#define ulong                                                   unsigned long long
using namespace std;

template<class T> using maxheap=priority_queue<T, vector<T>, less<T>>;
template<class T> using minheap=priority_queue<T, vector<T>, greater<T>>;

int main(int argc, char const *argv[]) {
    #ifndef __mr__
        ios::sync_with_stdio(0);cin.tie(0);
    #endif
    int testcases;
    cin >> testcases;
    while (testcases--) {
        // efa: estimated fuel amount to reach the target; cfa: current fuel amount
        // tfs: total fuel stops
        uint n, efa, cfa, tfs = 0;
        cin >> n;
        vector<pair<uint, uint>> arr(n + 1);
        for (uint i = 0; i < n; ++i)
            cin >> arr[i].first >> arr[i].second;
        cin >> efa >> cfa;
        for (uint i = 0; i < n; ++i)
            arr[i].first = efa - arr[i].first;
        arr[n] = make_pair(efa, 0);
        sort(arr.begin(), arr.end());
        maxheap<uint> memmax;
        for (uint i = 0; i < arr.size(); ++i) {
            if (cfa >= efa)
                break;
            while (!memmax.empty() && arr[i].first > cfa) {
                cfa += memmax.top(); memmax.pop();
                tfs++;
            }
            if (arr[i].first > cfa)
                efa = 0xffffffffu;
            memmax.push(arr[i].second);
        }
        if (cfa < efa)
            cout << -1 << endl;
        else
            cout << tfs << endl;
    }
    return 0;
}
