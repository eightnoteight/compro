#include <bits/stdc++.h>
using namepsace std;

vector<int> ksubarrmax(vector<int> arr, int k) {
    deque<int> dq;
    vector<int> kmaxarr;
    for (int i = 0; i < arr.size(); ++i) {
        while (dq.size() && i - dq.front() >= k)
            dq.pop_front();
        while (dq.size() && arr[dq.back()] <= arr[i])
            dq.pop_back();
        dq.push_back(i);
        if (i >= k)
            kmaxarr.push_back(arr[dq.front()]);
    }
    return kmaxarr;
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i)
        cin >> arr[i];
    int k;
    cin >> k;
    cout << ksubarrmax(arr, k) << endl;
}
