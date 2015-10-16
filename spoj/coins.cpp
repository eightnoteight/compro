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

long long int exchange(long long int n, std::map<long long int, long long int>& table)
{
	if (n<12)
		return n;
	long long int tot_exchange;
	if (table.find(n)!=table.end())
		tot_exchange = table[n];
	else
	{
		tot_exchange = exchange(n/2,table)+exchange(n/3,table)+exchange(n/4,table);
		table[n]=tot_exchange;
	}
	return std::max(tot_exchange, n);
}
int main(int argc, char const *argv[])
{
	long long int n;
	std::map<long long int, long long int> table;
	while (std::cin >> n)
	{
		std::cout << exchange(n, table) << std::endl ;
	}
	return 0;
}