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
inline int get_int(int n=0)
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
void reverse(char* begin, char* end)
{
	while(begin<end)
	{
		std::swap( *begin, *end );
		begin++;
		end--;
	}
}
int main(int argc, const char *argv[])
{
    int n;
    while((n=get_int())!=0)
    {
    	char msg[201];
    	std::cin >> msg;
    	int i=n;
    	while(i < strlen(msg))
    	{
    		reverse(msg+i,msg+i+n-1);
    		i += 2*n;
    	}
    	for (int j = 0; j < n; ++j)
    	{
    		i=j;
    		while(i<strlen(msg))
    		{
    			putchar(msg[i]);
    			i+=n;
    		}
    	}
    	std::cout << std::endl ;
    }
    return 0;
}