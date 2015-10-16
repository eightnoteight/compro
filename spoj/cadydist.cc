#include <bits/stdc++.h>
using namespace std;
/*input

*/


int main(int argc, char const *argv[])
{
	while(true)
	{
		int64_t n;
		cin >> n;
		if(not n)
			break;
		int64_t students[n];
		for (int32_t i = 0; i < n; ++i)
			cin >> students[i];
		int64_t prices[n];
		for (int32_t i = 0; i < n; ++i)
			cin >> prices[i];
		sort(students, students + n);
		sort(prices, prices + n, greater<int64_t>());
		int64_t sum = 0;
		for (int32_t i = 0; i < n; ++i)
			sum += *(students + i)**(prices + i);
		cout << sum << '\n';
	}
	return 0;
}