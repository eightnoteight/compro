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
int main(int argc, char *argv[])
{
    int t = gint();
    string s;
    int ll;
    while(t--)
    {
        int minop = INFINITY;
        int m = gint();
        cin >> s;
        vector<int> l;
        for(int i = 0; i < s.size(); i++)
            if(s[i] == '1')
                l.push_back(i);
        for(int i = m - 1; i < l.size(); i++)
            minop = min(l[i] - l[i - m + 1], minop);
        pint(minop + 1 - m);
    }
    return 0;
}
