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
		std::string a;
		std::string b;
		std::cin >> a >> b;
		std::reverse(a.begin(), a.end());
		std::reverse(b.begin(), a.end());
		int tmp = std::stoi(a) + std::stoi(b);
		a = std::to_string(tmp);
		std::reverse(a.begin(), a.end());
		std::cout << a << std::endl ;
	}
	return 0;
}