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

int main(int argc, char const *argv[])
{
	int t;
	std::cin >> t;
	while(t--)
	{
		int n;
		std::cin >> n;
		int a[n];
		for (int i = 0; i < n; ++i)
			std::cin >> a[i];
		int b[n];
		for (int i = 0; i < n; ++i)
			std::cin >> b[i];
		std::sort(a,a+n);
		std::sort(b,b+n);
		long long int sum=0;
		for (int i = 0; i < n; ++i)
			sum+=a[i]*b[i];
		std::cout << sum << std::endl ;
	}
	return 0;
}