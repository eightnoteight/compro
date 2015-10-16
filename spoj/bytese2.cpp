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

void pint(int a)
{
    register char c;
    char num[20];
    int i = 0;
    if(a < 0){
        putchar_unlocked('-');
        a *= -1;
    }
    do
    {
        num[i++] = a%10 + 48;
        a /= 10;
    }  while (a != 0);
    i--;
    while (i >= 0)
        putchar_unlocked(num[i--]);
    putchar_unlocked('\n');
}

int bytese2(vector< pair<int, int> > entries)
{
    vector<int> times;
    for (vector< pair<int, int> >::iterator x = entries.begin(); x != entries.end(); ++x)
    {
        times.push_back((*x).first);
        times.push_back((*x).second);
    }
    int mc = numeric_limits<int>::min();
    for (vector<int>::iterator x = times.begin(); x != times.end(); ++x)
    {
        int c = 0;
        for (vector< pair<int, int> >::iterator entry = entries.begin(); entry != entries.end(); ++entry)
            if (((*x) <= ((*entry).first)) and ((*x) >= ((*entry).second)))
                c++;
        mc = max(c, mc);
    }
    return mc;
    
}

int main(int argc, char *argv[])
{
    int t = gint();
    while(t--)
    {
        vector< pair<int, int> > entries;
        int n = gint();
        for (int x = 0; x < n; ++x)
            entries.push_back(pair<int, int>(gint(), gint()));
        pint(bytese2(entries));
    }
    return 0;
}
