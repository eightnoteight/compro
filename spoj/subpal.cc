#include <bits/stdc++.h>
#ifdef __mr__
	#include "prettyprint.hpp"
#define endl                                               '\n'
#endif
using namespace std;

int main(int argc, char const *argv[]) {
	int t;
	cin >> t;
	for (int _t = 1; _t <= t; ++_t) {
		string subpal;
		cin >> subpal;
		int pal[26];
		for (int i = 0; i < 26; ++i)
			pal[i] = 0;
		int bpal = 0;
		int msubpal = 0;
		for(char c: subpal) {
			int y = c - 'a';
			for (int x = 0; x < 26; ++x)
				if (x != y)
					pal[x] = 0;
			if (pal[y] == 0) {
				bpal = 0;
				pal[y] = 1;
			}
			else
				tie(bpal, pal[y]) = make_tuple(pal[y] + 1, bpal + 1);
			msubpal = max(msubpal, max(bpal, pal[y]));
		}
		cout << "Case " << _t << ": " << msubpal << endl;
	}
	return 0;
}