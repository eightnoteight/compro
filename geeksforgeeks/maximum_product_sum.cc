#include <bits/stdc++.h>
using namespace std;

int maximumSubarrayProduct(const vector<int>& arr) {
    int maxprod = *max_element(arr.begin(), arr.end());
    int mpos = 1, mneg = numeric_limits<int>::min();
    int ptill = 1;
    for (int i = 0; i < arr.size(); ++i) {
        if (arr[i] == 0) {
            ptill = mpos = 1;
            mneg = numeric_limits<int>::min();
        }
        else {
            ptill *= arr[i];
            if (ptill > 0 && maxprod < (ptill / mpos))
                maxprod = ptill / mpos;
            else if (ptill < 0 && maxprod < (ptill / mneg))
                maxprod = ptill / mneg;
            if (arr[i] < 0)
                mneg = max(mneg, arr[i]);
            else
                mpos = min(mpos, arr[i]);
        }
    }
	return maxprod;
}

int main() {
	int n;
	cin >> n;
	vector<int> arr(n);
	for (int i = 0; i < n; ++i)
		cin >> arr[i];
    cout << maximumSubarrayProduct(arr) << endl;
}
