#include <bits/stdc++.h>
using namespace std;

int main() {
	vector<int> rowvis(8), colvis(8);
	vector<string> mat;
	int queencount = 0;
	for (int r = 0; r < 8; ++r) {
		string crow;
		cin >> crow;
		mat.push_back(crow);
		for (int c = 0; c < 8; ++c) {
			if (crow[c] == '*') {
				queencount++;
				if (rowvis[r] || colvis[c]) {
					cout << "invalid" << endl;
					return 0;
				}
				int rtmp = r - 1, ctmp = c - 1;
				while(rtmp >= 0 && ctmp >= 0) {
					if (mat[rtmp][ctmp] == '*') {
						cout << "invalid" << endl;
						return 0;
					}
					rtmp--;
					ctmp--;
				}
				rtmp = r - 1;
				ctmp = c + 1;
				while(rtmp >= 0 && ctmp < 8) {
					if (mat[rtmp][ctmp] == '*') {
						cout << "invalid" << endl;
						return 0;
					}
					rtmp--;
					ctmp++;
				}
				rowvis[r] = 1;
				colvis[c] = 1;
			}
		}
	}
	if (queencount == 8)
		cout << "valid" << endl;
	else
		cout << "invalid" << endl;
	return 0;
}
