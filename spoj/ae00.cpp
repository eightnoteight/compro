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
    int n;
    n = get_int();
    int i=1;
    long long int number_of_rectangles=0;
    long long int tmp = (n/i) - i + 1;
    while(tmp>0)
    {
        number_of_rectangles += tmp;
        i++;
        tmp = (n/i) - i +1;
    }
    printf("%lld\n", number_of_rectangles);
    return 0;
}
