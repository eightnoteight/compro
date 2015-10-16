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
using namespace std;
inline int gint()
{
    int n = 0;
    int sign=1;
    register char c=0;
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
int main(int argc, char *argv[])
{
    int n;
    n = gint();
    int arr[4][n + 10];
    vector<int> apb;
    vector<int> cpd;
    for (int i = 0; i < n; ++i)
    {
        arr[0][i] = gint();
        arr[1][i] = gint();
        arr[2][i] = gint();
        arr[3][i] = gint();
    }
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            apb.push_back(arr[0][i] + arr[1][j]);
            cpd.push_back(arr[2][i] + arr[3][j]);
        }
    }
    long long int ans = 0;
    sort(apb.begin(), apb.end());
    sort(cpd.begin(), cpd.end());
    pair<vector<int>::iterator, vector<int>::iterator> bounds;
    for (vector<int>::iterator i = apb.begin(); i != apb.end(); ++i)
    {
        bounds = equal_range(cpd.begin(), cpd.end(), -(*i));
        ans += distance(bounds.first, bounds.second);
    }
    printf("%lld\n", ans);
    return 0;
}
