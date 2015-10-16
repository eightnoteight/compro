#include <bits/stdc++.h>
using namespace std;

int maxSubarrSum(const vector<int>& arr) {
    int still = 0;
    int smax = arr[0];
    for (int x: arr) {
        still = max(still + x, x);
        smax = max(smax, still);
    }
    return smax;
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i)
        cin >> arr[i];
    cout << maxSubarrSum(arr) << endl;
}
