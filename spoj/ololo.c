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


int main(int argc, char *argv[])
{
    long long int n = glong();
    long long int ans = 0;
    while (n--){
        ans ^= glong();
    }
    printf("%lld", ans);
    return 0;
}
