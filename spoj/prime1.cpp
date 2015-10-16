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
	bool pris[31624];
	vector<long long int> prirootn;
	for (long long int i = 2; i < sqrt(31624); ++i)
		if (!pris[i])
			for (long long int j = i+i, k=1; j < 31624; j+=i)
				pris[j]=1;
	for (long long int i = 31623; i > 1; --i)
		if (!pris[i])
			prirootn.insert(prirootn.begin(),i);
	int t;
	cin >> t;
	while(t--)
	{
		long long int m,n;
		cin >> m >> n;
		if (m < 2)
			m=2;
		if (n <= 31607)
		{
			long long int i=0;
			while(prirootn[i]<m) i++;
			while(prirootn[i]<=n)
			{
				printf("%lld\n", prirootn[i]);
				i++;
			}
			printf("\n");
			break;
		}
		else if (m <= 31607)
		{
			long long int i=0;
			while(prirootn[i++]<m);
			while(prirootn[i]<31607)
			{
				printf("%lld\n", prirootn[i]);
				i++;
			}
			printf("31607\n");
			m=31608;
		}
		bool primes[100010];
		for (long long int i = 0, k; i <= n && k <= sqrt(n); ++i)
		{
			k=prirootn[i];
			if (k==0)
			{
				break;
			}
			long long int temp=k*(m/k);
			for (long long int j = (temp<m)?(temp+k):(temp); j <= n ; j+=k)
			{
				primes[j-m]=1;
			}
		}
		for (long long int i = 0; i < n-m+1; ++i)
			if (!primes[i])
				printf("%lld\n", i+m);
		printf("\n");
	}
			
	return 0;
}