#include <map>
#include <set>
#include <list>
#include <cmath>
#include <cstring>
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
void add_strings(char* a, char* b, char* res)
{
	int len1=strlen(a);
	int len2=strlen(b);
	char carry[50];
	for (int i = 0; i < 50; ++i)
		carry[i]='0';
	int i=0;
	while(len1 && len2)
	{
		len2--; len1--;
		int tempres=a[i]+b[i]+carry[i]-'0'-'0'-'0';
		res[i] = (tempres%10) + '0';
		carry[i+1] += int(tempres/10) ;
		i++;
	}
	while(len1 > 0)
	{
		len1--;
		int tempres=a[i]+carry[i]-'0'-'0';
		res[i] = (tempres%10) + '0';
		carry[i+1] += int(tempres/10) ;
		i++;
	}
	while(len2 > 0)
	{
		len2--;
		int tempres=b[i]+carry[i]-'0'-'0';
		res[i] = (tempres%10) + '0';
		carry[i+1] += int(tempres/10) ;
		i++;
	}
	if (carry[i]!='0')
	{
		res[i]=carry[i++];
	}
	res[i]='\0';
}
int main(int argc, char const *argv[])
{
	int t;
	cin >> t;
	while(t--)
	{
		char rnum1[50];
		char rnum2[50];
		scanf("%s%s", rnum1, rnum2);
		char rresult[50];
		add_strings(rnum1, rnum2, rresult);
		int k=0;
		while(rresult[k] == '0')
			k++;
		printf("%s\n", rresult+k);
	}
	return 0;
}