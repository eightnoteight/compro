#include <bits/stdc++.h>
#define endl '\n'
#ifdef __mr__
	#include "prettyprint.hpp"
#endif
using namespace std;

uint mod;
long tmp[2][2];

struct matrix {
	long mat[2][2];
	matrix operator * (const matrix& other) {
		matrix result;
		result.mat[0][0] = (mat[0][0] * other.mat[0][0] + mat[0][1] * other.mat[1][0]) % mod;
		result.mat[0][1] = (mat[0][0] * other.mat[0][1] + mat[0][1] * other.mat[1][1]) % mod;
		result.mat[1][0] = (mat[1][0] * other.mat[0][0] + mat[1][1] * other.mat[1][0]) % mod;
		result.mat[1][1] = (mat[1][0] * other.mat[0][1] + mat[1][1] * other.mat[1][1]) % mod;
		return result;
	}
	void operator *= (const matrix& other) {
		tmp[0][0] = (mat[0][0] * other.mat[0][0] + mat[0][1] * other.mat[1][0]) % mod;
		tmp[0][1] = (mat[0][0] * other.mat[0][1] + mat[0][1] * other.mat[1][1]) % mod;
		tmp[1][0] = (mat[1][0] * other.mat[0][0] + mat[1][1] * other.mat[1][0]) % mod;
		tmp[1][1] = (mat[1][0] * other.mat[0][1] + mat[1][1] * other.mat[1][1]) % mod;
		mat[0][0] = tmp[0][0];
		mat[0][1] = tmp[0][1];
		mat[1][0] = tmp[1][0];
		mat[1][1] = tmp[1][1];
	}
};

matrix powmod(matrix base, uint ex) {
	matrix result;
	result.mat[0][0] = result.mat[1][1] = 1;
	result.mat[1][0] = result.mat[0][1] = 0;
	while (ex) {
		if (ex & 1)
			result *= base;
		base *= base;
		ex >>= 1; 
	}
	return result;
}


int main() {
	#ifndef __mr__
		ios::sync_with_stdio(0);cin.tie(0);
	#endif
	int t;
	cin >> t;
	matrix fibgen;
	fibgen.mat[0][0] = fibgen.mat[0][1] = fibgen.mat[1][0] = 1;
	fibgen.mat[1][1] = 0;
	long n;
	while(t--) {
		cin >> n >> mod;
		matrix answer = powmod(fibgen, n + 1);
		if (answer.mat[0][0] == 0)
			cout << mod - 1 << endl;
		else
			cout << (answer.mat[0][0] - 1) % mod << endl;
	}
}
