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
    int a[2001];
    while(t--)
    {
        int m = 0;
        int mi = 0;
        int n = gint();
        int tmp;
        for(int i = 0; i < 2001; i++)
            a[i] = 0;
        for(int i = 0; i < n; i++){
            tmp = gint();
            a[tmp + 1000]++;
            if(a[tmp + 1000] > m){
                m = a[tmp + 1000];
                mi = tmp;
            }
        }
        if(m <= n / 2)
            printf("NO\n");
        else
            printf("YES %d\n", mi);
    }
    return 0;
}
