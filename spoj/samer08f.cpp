#include <functional>
#include <numeric>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <cassert>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <bitset>
#include <sstream>
#include <algorithm>
inline long long int get_long_int(long long int n=0)
{
	int sign=1;
	char c=0;
	while(c<33)
		c=getchar_unlocked();
	if (c=='-')
	{
		sign=-1;
		c=getchar_unlocked();
	}
	while(c>='0'&&c<='9')
	{
		n=(n<<3)+(n<<1)+(c-'0');
		c=getchar_unlocked();
	}
	return n*sign;
}
int main(int argc, const char *argv[])
{
    long long int tmp;
    while ((tmp=get_long_int()) != 0)
    {
        long long int n =tmp;
        std::cout << (n*(n+1)*(2*n +1))/6  << std::endl ;
    }
    return 0;
}
