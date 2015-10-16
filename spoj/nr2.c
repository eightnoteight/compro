#include <stdio.h>

inline long long int get_int(long long int n)
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
    long long int n, a, b, i, t;
    n = get_int(0);
    a = b = get_int(0);
    for (i = 0; i < n - 1; i++) 
    {
        t = get_int(0);
        a |= t;
        b &= t;
    }
    printf("%lld", a & (~b));
    return 0;
}
