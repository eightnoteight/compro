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
inline int get_int(int n=0)
{   
    int sign=1;
    char c=0;
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
int main(int argc, const char *argv[])
{
    int n=get_int();
    int a[10001];
    while(n!=-1)
    {
        long long int average=0;
        for (int i = 0; i < n; i++) {
            a[i] = get_int();
            average += a[i];
        }
        if (average%n) {
            printf("-1\n");
            n=get_int();
            continue;
        }
        average/=n;
        long long int tot_deviation=0;
        for (int i = 0; i < n; i++)
            tot_deviation += abs(average-a[i]);
        printf("%lld\n", tot_deviation/2);
        n=get_int();
    }
    return 0;
}
