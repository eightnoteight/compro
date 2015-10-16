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
#include <stack>
#include <limits>
#include <set>
#include <deque>
#include <queue>
#include <bitset>
#include <sstream>
#include <algorithm>

using namespace std;

int modulus11(int a,int b)
{
    if (a < 0)
        return b - (-a % b);
    return a % b;
}
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
    vector<bool> winners(1000021, true);
    int k, l, m;
    k = gint();
    l = gint();
    m = gint();
    for (int x = 0; x < 1000001; ++x)
        if(\
                (x != 1) and \
                (x != k) and \
                (x != l) and \
                winners[modulus11(x - 1, 1000001)] and \
                winners[modulus11(x - l, 1000001)] and \
                winners[modulus11(x - k, 1000001)])
            winners[x] = false;
    for (int x = 0; x < m; ++x)
        putchar_unlocked(winners[gint()] ? 'A':'B');
    return 0;
}
