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
int strength(int a)
{
    int i=0;
    while (a)
    {
        a/=10;
        i++;
    }
    return i;
}
int power(int a, int b)
{
    if (b==0)
        return 1;
    return a*power(a,b-1);
}
int main(int argc, const char *argv[])
{
    int t;
    t = get_int();
    char avg[15];
    while(t--)
    {
        scanf("%s", avg);
        int i=0;
        while(avg[i]!='.' && avg[i])
            i++;
        if (avg[i] == 0) {
            printf("1\n");
            continue;
        }
        int dec = atoi(avg+i+1);
        int r = strength(dec);
        int r5 = 0;
        int tmp=dec;
        while(tmp%5 == 0){
            tmp/=5; 
            r5++;
        }
        int r2=0;
        tmp = dec;
        while(tmp%2 == 0){
            tmp/=2;
            r2++;
        }
        if (r2+r5 >= r) {
            printf("%d\n",power(5,r2)*power(2,r5));
            continue;
        }
        printf ("%d\n",power(5,r2)*power(2,r5)*power(10,r-r2-r5));
    }
    return 0;
}
