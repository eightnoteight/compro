#include <stdio.h>


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
inline void pint(int a)
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

int main(int argc, char *argv[])
{
    int n = gint(), i, x, y;
    long long int a[2020], dp[2020];
    for (i = 0; i < n; ++i){
        a[i] = gint();
        dp[i] = a[i] * n;
    }
    for (x = n - 1; x > 0; --x)
        for(y = 0; y < x; ++y)
            dp[y] = (((dp[y] + x*a[y + n - x]) > (dp[y + 1] + x*a[y])) ? (dp[y] + x*a[y + n - x]) : (dp[y + 1] + x*a[y]));
    pint(dp[0]);
    return 0;
}
