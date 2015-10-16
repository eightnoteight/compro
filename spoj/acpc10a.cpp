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
    long long int a=get_int();
    long long int b=get_int();
    long long int c=get_int();
    while(a!=0 or b!=0 or c!=0)
    {
        if (b-a == c-b)
            printf("AP %ld\n", c+c-b);
        else
            printf("GP %ld\n", c*(c/b));
        a = get_int();
        b = get_int();
        c = get_int();
    }
    return 0;
}
