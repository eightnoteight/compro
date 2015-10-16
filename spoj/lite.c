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

int count(int* segt, int lo, int hi, int beg, int end, int ind)
{
    if((lo >= beg) && (hi <= end))
        return segt[ind];

    if(((lo < beg) && (hi <= beg)) || ((lo >= end) && (hi > end)))
        return 0;

    int mid = lo + ((hi - lo) / 2);

    return count(segt, lo, mid, beg, end, 2*ind + 1) + \
        count(segt, mid, hi, beg, end, 2*ind + 2);
}

int flip(int* segt, int lo, int hi, int beg, int end, int ind)
{
    if ((hi - lo == 1) && (lo >= beg) && (hi <= end)){
        segt[ind] = 1 - segt[ind];
        return segt[ind];
    }
    if(((lo < beg) && (hi <= beg)) || ((lo >= end) && (hi > end))){
        return segt[ind];
    }
    int mid = lo + ((hi - lo) / 2);

    segt[ind] -= segt[2*ind + 1];
    segt[ind] += flip(segt, lo, mid, beg, end, 2*ind + 1);

    segt[ind] -= segt[2*ind + 2];
    segt[ind] += flip(segt, mid, hi, beg, end, 2*ind + 2);
    return segt[ind];
}

int main(int argc, char *argv[])
{
    int n, m, i, c, l, h, segt[300000];
    n = gint();
    m = gint();
    for (i = 0; i < m; ++i)
    {
        c = gint(); l = gint(); h = gint();
        if(c)
        {
            pint(count(segt, 0, n, l - 1, h, 0));
            putchar_unlocked('\n');
        }
        else
            flip(segt, 0, n, l - 1, h, 0);
    }
    return 0;
}
