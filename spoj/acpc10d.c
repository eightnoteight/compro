#include <stdio.h>
#include <stdarg.h>

long long int min(int n, ...)
{
    va_list args;
    long long int m, t;
    int i;
    va_start(args, n);
    m = va_arg(args, long long int);
    for (i = 1; i < n; i++)
    {
        t = va_arg(args, long long int);
        if (t < m)
            m = t;
    }
    return m;
}

long long int minpath1(long long int trigraph[][3], long long int n)
{
    return min(3,
            trigraph[0][1] + trigraph[1][1],
            trigraph[0][1] + trigraph[0][2] + trigraph[1][1],
            trigraph[0][1] + trigraph[1][0] + trigraph[1][1]);
}

long long int minpath2(long long int trigraph[][3], long long int n)
{
    long long int x;
    trigraph[n - 2][2] += trigraph[n - 1][1];
    if(trigraph[n - 1][0] < 0)
    {
        trigraph[n - 2][1] += min(2,
                trigraph[n - 2][2],
                trigraph[n - 1][0] + trigraph[n - 1][1]);
        trigraph[n - 2][0] += min(2,
                trigraph[n - 2][1],
                trigraph[n - 1][0] + trigraph[n - 1][1]);
    }
    else
    {
        trigraph[n - 2][1] += min(2,
                trigraph[n - 2][2],
                trigraph[n - 1][1]);
        trigraph[n - 2][0] += min(2,
                trigraph[n - 2][1],
                trigraph[n - 1][1]);
    }
    for (x = n - 3; x > 0; --x)
    {
        trigraph[x][2] += min(2, trigraph[x + 1][2], trigraph[x + 1][1]);
        trigraph[x][1] += min(4, trigraph[x + 1][0], trigraph[x + 1][1], trigraph[x + 1][2], trigraph[x][2]);
        trigraph[x][0] += min(3, trigraph[x + 1][1], trigraph[x + 1][0], trigraph[x][1]);
    }
    return min(2,
            trigraph[0][1] + trigraph[0][2] + min(2,
                trigraph[1][1],
                trigraph[1][2]),
            trigraph[0][1] + min(3,
                trigraph[1][0],
                trigraph[1][1],
                trigraph[1][2]));
}
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
int main(int argc, char *argv[])
{
    long long int t = 1, n, trigraph[100010][3], i;
    while(1)
    {
        n = glong();
        if(n == 0)
            break;
        for (i = 0; i < n; ++i)
        {
            trigraph[i][0] = glong();
            trigraph[i][1] = glong();
            trigraph[i][2] = glong();
        }
        plong(t);
        putchar_unlocked('.');
        putchar_unlocked(' ');
        if(n == 2)
            plong(minpath1(trigraph, n));
        else
            plong(minpath2(trigraph, n));
        putchar_unlocked('\n');
        t++;
    }
    return 0;
}
