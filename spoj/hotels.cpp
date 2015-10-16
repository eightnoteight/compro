#include <cstdio>
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
    int n, m, lo, hi;
    long long int s, gt;
    n = gint();
    m = gint();
    int hotels[n];
    s = 0;
    gt = 0;
    lo = 0;
    for (int i = 0; i < n; ++i)
    {
        hotels[i] = gint();
        if(s + hotels[i] <= m)
        {
            s += hotels[i];
            if(gt < s)
                gt = s;
        }
        else
        {
            while((lo <= i) && ((s + hotels[i]) > m))
            {
                s -= hotels[lo];
                lo++;
            }
            s += hotels[i];
            if(gt < s)
                gt = s;
        }
    }
    printf("%lld\n", gt);
    return 0;
}
