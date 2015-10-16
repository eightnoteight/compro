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

int main(int argc, char *argv[])
{
    int t = gint();
    int n, m, D, ans, i;
    while(t--)
    {
        n = gint();
        m = gint();
        D = gint();
        ans = 0;
        for (i = 0; i < n; ++i)
            ans += (int)((gint() - 1) / D);
        if(ans >= m)
        {
            putchar_unlocked('Y');
            putchar_unlocked('E');
            putchar_unlocked('S');
        }
        else
        {
            putchar_unlocked('N');
            putchar_unlocked('O');
        }
        putchar_unlocked('\n');
    }
    return 0;
}
