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
	int cont=0;
	int p;
	while(cin >> p)
	{
		if (p==42)
			cont=1;
		if (cont)
			continue;
		cout << p << endl;
	}
	return 0;
}