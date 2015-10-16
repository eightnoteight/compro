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
inline long long int get_int(long long int n=0)
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
    long long int t = get_int();
    while(t--)
    {
        long long int n = get_int();
        long long int sum = 0;
        long long int tmp = n;
        while(tmp--){
            sum += get_int()%n;
            sum%=n;
        }
        if (n == 0 || sum%n)
            printf("NO\n");
        else
            printf("YES\n");
    }
    return 0;
}
