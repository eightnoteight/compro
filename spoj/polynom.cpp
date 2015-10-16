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
    int t = gint();
    while(t--)
    {
        int n = gint();
        vector<int> v;
        for (int x = 0; x < n; ++x)
            v.push_back(gint());
        if(n <= 4)
        {
            putchar_unlocked('Y');
            putchar_unlocked('E');
            putchar_unlocked('S');
            putchar_unlocked('\n');
            continue;
        }
        for (int x = 1; x < v.size(); ++x)
            v[x - 1] = v[x] - v[x - 1];
        v.pop_back();
        for (int x = 1; x < v.size(); ++x)
            v[x - 1] = v[x] - v[x - 1];
        v.pop_back();
        for (int x = 1; x < v.size(); ++x)
            v[x - 1] = v[x] - v[x - 1];
        v.pop_back();
        int t = v[0];
        bool bp = true;
        for (int x = 0; x < v.size(); ++x)
        {
            if (v[x] != t)
            {
                putchar_unlocked('N');
                putchar_unlocked('O');
                putchar_unlocked('\n');
                bp = false;
                break;
            }
        }
        if (bp)
        {
            putchar_unlocked('Y');
            putchar_unlocked('E');
            putchar_unlocked('S');
            putchar_unlocked('\n');
        }
    }
    return 0;
}
