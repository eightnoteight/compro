/*TIMEOUT!!!!!!!!!!!!!!!!!!!!*/
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
#include <stddef.h>


inline long long int glong()
{
    long long int n = 0;
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
void plong(long long int a)
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
}
long long int factlen(long long int n)
{
    if(n == 0)
        return 1;
    return (long long int)(((log(6.283185307179586*n)/2.0 + n*(log(n) - 1))/2.302585092994046) + 1);
}
int main(int argc, char *argv[])
{
    long long int t = glong(), x;
    long long int lo, hi, n, l;
    while(t--)
    {
        x = glong();
        lo = 0;
        hi = 1000000001;
        while(lo < hi)
        {
            n = lo + (hi - lo) / 2;
            l = factlen(n);
            if(l == x || n == lo || n == hi)
                break;
            else if(l < x)
                lo = n;
            else
                hi = n;
        }
        while(l > x)
        {
            n--;
            l = factlen(n);
        }
        while(l <= x)
        {
            n++;
            l = factlen(n);
        }
        plong(n - 1);
        putchar_unlocked('\n');
    }
    return 0;
}
