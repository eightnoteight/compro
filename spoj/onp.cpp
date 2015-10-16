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
	int t;
	cin >> t;
	while(t--)
	{
		string expression;
		cin >> expression;
		stack<char> operands;
		for (int i = 0; i < expression.length(); ++i)
		{
			if (expression[i]=='(')
				continue;
			else if (expression[i]>='a' && expression[i]<='z')
				cout << expression[i];
			else if (expression[i]==')')
			{
				cout << operands.top();
				operands.pop();
			}
			else
				operands.push(expression[i]);
		}
		while(!operands.empty())
		{
			cout << operands.top();
			operands.pop();
		}
		cout << endl;
	}

	return 0;
}