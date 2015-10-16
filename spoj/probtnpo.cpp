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
#include <climits>

struct rec{
	int n;
	int len;
};
int cycle_length(int n)
{
	static std::map<int, int> lengths;
	if (lengths.find(n)!=lengths.end())
		return lengths[n];
	long long int m=n;
	std::stack< rec > records;
	int len=0;
	while(m!=1)
	{
		rec t;
		t.n=m;
		t.len=len;
		records.push(t);
		if (lengths.find(m)!=lengths.end())
		{
			len += lengths[m]-1;
			m=1;
		}
		if (m%2)
			m=3*m + 1;
		else
			m/=2;
		len++;
	}
	while(records.size())
	{
		lengths[records.top().n]=len+1-records.top().len;
		records.pop();
	}
	return len+1;
}
int main(int argc, char const *argv[])
{
	int l,h;
	while(std::cin)
	{
		std::cin >> l >> h;
		std::cout << l << ' ' << h << ' ' ;
		int max=INT_MIN;
		for (int i = l; i <= h; ++i)
		{
			int tmp=cycle_length(i);
			if (tmp>max)
				max = tmp;
		}
	}	
	return 0;
}