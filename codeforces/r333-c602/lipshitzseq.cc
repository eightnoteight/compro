#include <bits/stdc++.h>
#ifdef __mr__
    #include "prettyprint.hpp"
#else
    #define endl                                               '\n'
#endif
#define ulong                                                   unsigned long long
#define uint                                                    unsigned int
using namespace std;
const ulong mod = 1000000007ul;

ulong summaxsubarr(vector<ulong>& arr) {
    vector<uint> nine(arr.size()), thre(arr.size());
    stack<uint> util;
    for (int i = 0; i < arr.size(); ++i) {
        while(util.size() && arr[util.top()] <= arr[i])
            util.pop();
        nine[i] = util.empty() ? (i + 1) : (i - util.top());
        util.push(i);
    }
    util = stack<uint>();
    for (int i = arr.size() - 1; i >= 0; --i) {
        while(util.size() && arr[util.top()] < arr[i])
            util.pop();
        thre[i] = util.empty() ? (arr.size() - i) : (util.top() - i);
        util.push(i);
    }
    ulong megasum = 0;
    for (int i = 0; i < arr.size(); ++i) {
        megasum += arr[i] * nine[i] * thre[i];
    }
    return megasum;
}

int main(int argc, char const *argv[]) {
    #ifndef __mr__
        ios::sync_with_stdio(0);cin.tie(0);
    #endif
    ulong n, q;
    cin >> n >> q;
    vector<ulong> arr(n);
    for (ulong i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    for (ulong i = 0; i < n - 1; ++i) {
        arr[i] = (arr[i] > arr[i + 1])?(arr[i] - arr[i + 1]):(arr[i + 1] - arr[i]);
    }
    arr.pop_back();
    for (int i = 0; i < q; ++i) {
        int l, r;
        cin >> l >> r;
        l--;r--;
        vector<ulong> narr(arr.begin() + l, arr.begin() + r);
        cout << summaxsubarr(narr) << endl;
    }
    return 0;
}
