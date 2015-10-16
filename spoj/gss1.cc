#include <bits/stdc++.h>
using namespace std;
template <class number>
void input(number *ptr){
	register char c = getchar_unlocked();
	bool sign = false;
	while (c < 33)
		c = getchar_unlocked();
	*ptr = 0;
	if (c == '-'){
		sign = true;
		c = getchar_unlocked();
	}
	while (c > 33){
		*ptr = (*ptr * 10) + (c - '0');
		c = getchar_unlocked();
	}
	if (sign)
		*ptr *= -1;

}
void print(const char* format, ...){
	va_list arguments;
	va_start(arguments, format);
	register char c;
	char num[20];
	int i = 0, j;
	long n;
	while (format[i] != '\0'){
		if (format[i] != '{')
			putchar_unlocked(format[i++]);
		else{
			i += 2;
			n = va_arg(arguments, long);
			j = 0;
			do{
				num[j++] = n%10 + 48;
				n /= 10;
			}  while (n != 0);
			j--;
			while (j >= 0)
				putchar_unlocked(num[j--]);
		}
	}
	va_end(arguments);
}
class rangeMaximumQuery {
private:
	int** dp;
	char* logt;  // char: performance hack
	int n;
public:
	vector<int>& arr;
	rangeMaximumQuery(vector<int>& array): arr(array) {
		n = arr.size();
		dp = new int*[n];
		logt = new char[n + 1];
		logt[0] = logt[1] = 0;
		for (int x = 2; x <= n; ++x) {
			logt[x] = logt[x >> 1] + 1;
		}
		for (int x = 0; x < n; ++x) {
			dp[x] = new int[1 + logt[n]];
			dp[x][0] = x;
		}
		for (int x = n - 1; x >= 0 ; --x) {
			for (int y = 1; x + (1 << y) <= n; y++) {
				if (arr[dp[x][y - 1]] > arr[dp[x + (1 << (y - 1))][y - 1]])
					dp[x][y] = dp[x][y - 1];
				else
					dp[x][y] = dp[x + (1 << (y - 1))][y - 1];
			}
		}
	}
	int query(int x, int y) {
		int k = logt[y - x];
		if (arr[dp[x][k]] > arr[dp[y - (1 << k)][k]])
			return arr[dp[x][k]];
		else
			return arr[dp[y - (1 << k)][k]];
	}
	~rangeMaximumQuery() {
		for (int x = 0; x < n; ++x) {
			delete[] dp[x];
		}
		delete[] dp;
		delete[] logt;
	}
};

class maximumSubsequence {
private:
	vector<int>& arr;
	rangeMaximumQuery& leftsumrmq;
	rangeMaximumQuery& rightsumrmq;
	vector<int> tree;
	int minf;
	int n, qi, qj;
	void _generateTree(int lo, int hi, int ind) {
		if (hi - lo == 1) {
			tree[ind] = arr[lo];
			return;
		}
		int mid = lo + ((hi - lo) / 2);
		int lefti = 2*ind + 1;
		int righti = 2*ind + 2;
		_generateTree(lo, mid, lefti);
		_generateTree(mid, hi, righti);
		int total = minf;
		if(lo <= mid && mid <= hi) {
			if (mid < hi){
				if (total == minf)
					total = 0;
				total += leftsumrmq.query(mid, hi);
				if (mid != 0)
					total -= leftsumrmq.arr[mid - 1];
			}
			if (lo < mid) {
				if (total == minf)
					total = 0;
				total += rightsumrmq.query(lo, mid);
				if (mid != n)
					total -= rightsumrmq.arr[mid];
			}
		}

		tree[ind] = max(
			total,
			max(
				tree[lefti],
				tree[righti]));
	}
	inline int _getTreeSize(int n) {
		int x = 1;
		while ((x <<= 1) < n);
		return x;
	}
	int _query(int lo, int hi, int ind) {
		if (qj <= lo || qi >= hi)
			return minf;
		if (qi <= lo && hi <= qj)
			return tree[ind];
		int mid = lo + ((hi - lo) / 2);
		int left = _query(lo, mid, 2*ind + 1);
		int right = _query(mid, hi, 2*ind + 2);
		int total = minf;
		if(qi <= mid && mid <= qj) {
			if (mid < qj){
				if (total == minf)
					total = 0;
				total += leftsumrmq.query(mid, qj);
				if (mid != 0)
					total -= leftsumrmq.arr[mid - 1];
			}
			if (qi < mid) {
				if (total == minf)
					total = 0;
				total += rightsumrmq.query(qi, mid);
				if (mid != n)
					total -= rightsumrmq.arr[mid];
			}
		}
		return max(
			total,
			max(
				left,
				right));
	}
public:
	maximumSubsequence(
		vector<int>& arr,
		rangeMaximumQuery& leftsumrmq,
		rangeMaximumQuery& rightsumrmq)
	: arr(arr), leftsumrmq(leftsumrmq), rightsumrmq(rightsumrmq) {
		minf = numeric_limits<int>::min();
		n = arr.size();
		tree.resize(2*_getTreeSize(n) - 1);
		_generateTree(0, n, 0);
	}
	inline int query(int i, int j) {
		qi = i; qj = j;
		return _query(0, n, 0);
	}
};


int main() {
	int n;
	input(&n);
	vector<int> arr(n);
	for (int x = 0; x < n; ++x){
		input(&arr[x]);
	}
	vector<int> leftsum(n);
	vector<int> rightsum(n);
	leftsum[0] = arr[0];
	rightsum[n - 1] = arr[n - 1];
	for (int x = 1; x < n; ++x) {
		leftsum[x] += leftsum[x - 1] + arr[x];
		rightsum[n - x - 1] += rightsum[n - x] + arr[n - x - 1];
	}
	rangeMaximumQuery lsrmq(leftsum);
	rangeMaximumQuery rsrmq(rightsum);
	maximumSubsequence msubseq(arr, lsrmq, rsrmq);
	int m;
	input(&m);
	for (int x = 0; x < m; ++x) {
		int l, r;
		input(&l); input(&r);
		print("{}\n", msubseq.query(l - 1, r));
	}
	return 0;
}
