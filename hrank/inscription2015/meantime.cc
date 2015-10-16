#include <bits/stdc++.h>
#define endl '\n'
#ifdef __mr__
	#include "prettyprint.hpp"
#endif
using namespace std;

int main(int argc, char const *argv[]) {
	#ifndef __mr__
		ios::sync_with_stdio(0); cin.tie(0);
	#endif
	cout << fixed << setprecision(6);
	int n;
	cin >> n;
	unsigned long *arr = new unsigned long[n + 1];
	for (int x = 1; x <= n; ++x)
		cin >> arr[x];
	arr[0] = 0;
	partial_sum(arr + 1, arr + n + 1, arr + 1);
	int q;
	cin >> q;
	while(q--) {
		int l, r;
		cin >> l >> r;
		cout << (double)(arr[r] - arr[l - 1]) / (r - l + 1) << endl;
	}
	return 0;
}
