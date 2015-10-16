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
int skip_and_insert(int a[],int size, int from, int skip, int insert)
{
	int tmp=0;
	while(tmp!=skip)
	{
		if (a[from++] == 0)
			tmp++;
		if (from >= size)
			from %= size;
	}
	while(a[from]){
		from++;
		if (from >= size)
			from %= size;
	}
	a[from] = insert;
	return from;
}
struct elem {
	int index;
	int value;
	elem(){
		value=0;
	}
};
int main(int argc, const char *argv[])
{
    int test;
    test=get_int();
    while(test > 0)
    {
    	int n;
    	n = get_int();
    	int a[n];
    	std::list<int> filter;
    	for (int i = 0; i < n; ++i)
    	{
    		filter.push_back(i+1);
    	}
    	int ins=1;
    	int skip=1;
    	int j=0;
    	std::list<int>::iterator i=filter.begin();
    	while(j < n)
    	{
    		int tmp_skip=skip;
    		std::advance(i,tmp_skip);
    		a[j++] = *i;
    		std::list<int>::iterator tmp=++i;
    		--i;
    		filter.erase(i);
    		i=tmp;
    		skip++;
    	}
    	for (int i = 0; i < n; ++i)
    	{
    		printf("%d ", a[i]);
    	}
    	printf("\n");
    	test--;
    }
    return 0;
}
