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
long long int get_line(char* a)
{
	char* tmp = a;
	while((((*a++)=getchar_unlocked())!='\n') and (*(a-1) != EOF));
	*(a-1) = '\0';
	return a-tmp-1;
}
bool incre_mid2(char* a, int i1, int i2,long long int length)
{
	if (*(a+i1) =='\0' or *(a+i2) == '\0')
	{
		*(a) = '1';
		return false;
	}
	if (*(a+i1) == '9' and *(a+i2) == '9')
	{
		*(a+i1) = '0';
		*(a+i2) = '0';
		return incre_mid2(a, i1-1, i2+1,length);
	}
	else
	{
		++*(a+i1);
		++*(a+i2);
		return true;
	}
}
bool incre_mid1(char* a, int i1,long long int length)
{
	if (*(a+i1) =='\0')
	{
		*(a) = '1';
		return false;
	}
	if (*(a+i1) != '9')
	{
		++*(a+i1);
		return true;
	}
	*(a+i1) ='0';
	return incre_mid2(a,i1-1,i1+1,length);
}
bool make_plain(char* a, long long int length)
{
	long long int i=0;
	long long int j=length-1;
	bool ret;
	while(i<j)
	{
		if (*(a+i) > *(a+j))
			ret=true;
		else
			ret = false;
		*(a+j) = *(a+i);
		i++;
		j--;
	}
	return ret;
}
int main(int argc, char const *argv[])
{
	int t;
	char a[1000009];
	t = get_int();
	while(t--)
	{
		long long int length = get_line(a);
		if (length ==1)
		{
			printf("11\n");
			continue;
		}
		if(make_plain(a,length))
		{
			printf("%s\n", a);
			continue;
		}
		if (length%2)
		{
			bool tmp = incre_mid1(a,length/2,length);
			printf("%s", a);
			if (!tmp)
				printf("1");
			printf("\n");
		}
		else
		{
			bool tmp = incre_mid2(a,length/2 -1,length/2,length);
			printf("%s", a);
			if (!tmp)
				printf("1");
			printf("\n");
		}
	}
	return 0;
}