#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <cstdlib>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <iterator>

using namespace std;
int main(int argc, char const *argv[])
{
	long long int t;
	cin >> t;
	while(t--)
	{
		long long int n;
		cin >> n;
		long long int zeros=0;
		long long int five=5;
		while(n/five)
		{
			zeros+=n/five;
			five*=5;
		}
		cout << zeros << endl;
	}
	return 0;
}