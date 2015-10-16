#include <bits/stdc++.h>
#ifdef __mr__
	#include "prettyprint.hpp"
#endif
#ifndef __mr__
	#define endl                                               '\n'
#endif
using namespace std;

struct nthfib {
	unsigned long fmat[2][2] = {{1, 1}, {1, 0}};
	unsigned long tmp[2][2];
	unsigned long mod;
	void matmul(unsigned long amat[2][2], unsigned long bmat[2][2]) {
		tmp[0][0] = (amat[0][0] * bmat[0][0] + amat[0][1] * bmat[1][0]) % mod;
		tmp[0][1] = (amat[0][0] * bmat[0][1] + amat[0][1] * bmat[1][1]) % mod;
		tmp[1][0] = (amat[1][0] * bmat[0][0] + amat[1][1] * bmat[1][0]) % mod;
		tmp[1][1] = (amat[1][0] * bmat[0][1] + amat[1][1] * bmat[1][1]) % mod;
		amat[0][0] = tmp[0][0]; amat[0][1] = tmp[0][1]; 
		amat[1][0] = tmp[1][0]; amat[1][1] = tmp[1][1];
	}
	unsigned long powgen(unsigned n) {
		unsigned long result[2][2] = {{1, 0}, {0, 1}};
		unsigned long base[2][2] = {{fmat[0][0], fmat[0][1]}, {fmat[1][0], fmat[1][1]}};
		while (n) {
			if (n & 1)
				matmul(result, base);
			matmul(base, base);
			n >>= 1;
		}
		return result[1][0];
	}
	unsigned long operator()(unsigned n, unsigned long _mod) {
		mod = _mod;
		return powgen(n);
	}
};


int main(int argc, char const *argv[]) {
	int n;
	cin >> n;
	nthfib fibgen;
	for (int x = 0; x < n; ++x) {
		long s = fibgen(x, 10000);
		if (x % 10000 == 0) 
			cout << s << endl;
	}
	return 0;
}